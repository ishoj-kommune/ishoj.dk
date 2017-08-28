<?php

define('DEFAULT_COUNTRY', 'DANMARK');
define('DEFAULT_EMAIL', 'WEBTEST@bellcom.dk');
define('DEFAULT_PASSWORD', 'retmig');
define('DEFAULT_OFFER_BY_EMAIL', 0);
define('DEFAULT_COMPANY_NO', 99);
define('DEFAULT_COMPANY_NO_PAY_IN', 9);
define('DEFAULT_NO_OF_YEARS', 1);
define('DEFAULT_STATUS', 0);
define('DEFAULT_TENANCY_TYPE', 1);
define('DEFAULT_TYPE_UPDATE', 'I');
define('DEFAULT_TYPE_CREATE', 'A');
define('DEFAULT_MIN_FLOOR', 1);
define('DEFAULT_MAX_FLOOR', 99);
define('DEFAULT_MIN_SQM', 1);
define('DEFAULT_MAX_SQM', 9999);

/**
 * Gets a member object from the webservice based on CPR
 *
 * @return member object, or null if no member is found
 */
function egbolig_webform_ws_get_member_by_cpr($cpr) {
  $client = new SoapClient(variable_get('soap_webservice'));
  $response = $client->MemberGetListByCprNo(
    array(
      'cprNo' => $cpr
    )
  );
  $result = $response->MemberGetListByCprNoResult;
  if (!empty((array) $result)) {
    return $result->Member;
  }
  return NULL;
}

/**
 * Creates a member object via the webservice;
 */
function egbolig_webform_ws_create_member($member) {
  $member->Type = DEFAULT_TYPE_CREATE;

  $client = new SoapClient(variable_get('soap_webservice'));
  $response = $client->PaymentNewMember(
    [
      'paymentDetails' => [
        'NewAmounts' => [
          'Payment.NewAmount' => [
            'CompanyNo' => DEFAULT_COMPANY_NO,
            'CompanyNoToPayIn' => DEFAULT_COMPANY_NO_PAY_IN,
            'NoOfYears' => DEFAULT_NO_OF_YEARS,
            'Status' => DEFAULT_STATUS,
            'TenancyTypes' => [DEFAULT_TENANCY_TYPE]
          ]
        ]
      ],
      'member' => $member,
    ]
  );
}

/**
 * Updates the member via the webservice.
 * Internally calls _egbolig_ws_update_education
 */
function egbolig_webform_ws_update_member($member) {
  $member->Type = DEFAULT_TYPE_UPDATE;
  $member_array = (array) $member;
  //unsetting the EdgiNo, this sabotages the submission
  unset($member_array['EgdiNo']);

  $client = new SoapClient(variable_get('soap_webservice'));

  //update member
  $response = $client->MemberUpdate(
    array(
      'member' => $member_array,
    )
  );

  //update criteria
  $response = $client->MemberUpdateCriterias(
    array(
      'member' => $member_array,
    )
  );
  _egbolig_webform_ws_update_education($member_array);
}

/**
 * Updates the children via the webservice.
 * Internally calls _egbolig_ws_update_education
 */
function egbolig_webform_ws_add_children($member, $form_state) {
  $v = $form_state['values']['submitted'];
  $tree = $form_state['webform']['component_tree']['children'];
  $childrenList = _egbolig_webform_get_children_by_member($member->MemberNo, $member->MemberCompanyNo);
  $client = new SoapClient(variable_get('soap_webservice'));
  for ($i = 1; $i <= 10; $i++) {
    $child_cpr = $v[_egbolig_webform_get_webform_cid($tree, 'child_cpr_nr_' . (string) $i)];
    if (!empty($child_cpr) && !egbolig_webform_is_child_exists($child_cpr, $childrenList)) {
      $child = array(
        'CompanyNo' => $member->MemberCompanyNo,
        'Cpr4' => substr($child_cpr, -4),
        'Cpr6' => substr($child_cpr, 0, 6),
        'MemberNo' => $member->MemberNo,
        'Name' => $member->Name
      );
      $response = $client->ChildAdd(
        array(
          'child' => $child
        )
      );
    }
  }
}

/**
 * Populates the member object with the values from the form submission.
 * Note: $member param is nullable. In this case a new member class instance is created with the default settings.
 *
 * @return populated member object
 */
function egbolig_webform_populate_member($member, $form_state) {
  $v = $form_state['values']['submitted'];
  $tree = $form_state['webform']['component_tree']['children'];

  //check if member is empty, create a new member and populate some default fields
  if ($member == NULL) {
    $member = new stdClass();
    //TODO: check default fields
    $member->Password = DEFAULT_PASSWORD;
    $member->OfferByEmail = DEFAULT_OFFER_BY_EMAIL;
    $member->CprNo = $v[_egbolig_webform_get_webform_cid($tree, 'cpr')];
    $member->MemberNo = $v[_egbolig_webform_get_webform_cid($tree, 'cpr')];
  }
  $member->Email = $v[_egbolig_webform_get_webform_cid($tree, 'email')];
  $member->Name = $v[_egbolig_webform_get_webform_cid($tree, 'name')];
  $member->Address = $v[_egbolig_webform_get_webform_cid($tree, 'addresse')];
  $member->HomePhone = $v[_egbolig_webform_get_webform_cid($tree, 'phone_nr')];
  $member->CoAddress = $v[_egbolig_webform_get_webform_cid($tree, 'c_o_addresse')];
  $member->MobilePhone = $v[_egbolig_webform_get_webform_cid($tree, 'telefonnummer_mobil')];
  $member->PostalCodeCity = $v[_egbolig_webform_get_webform_cid($tree, 'post_nr___by')];
  $member->Country = DEFAULT_COUNTRY;
  $member->Adults = 1 + $v[_egbolig_webform_get_webform_cid($tree, 'has_partner')][0]; //with or without the partner

  if (empty($v[_egbolig_webform_get_webform_cid($tree, 'has_children')][0])) {
    $member->Children = 0;
  }
  $member->Education = $v[_egbolig_webform_get_webform_cid($tree, 'education_name')];
  $member->EducationStart = !empty($v[_egbolig_webform_get_webform_cid($tree, 'education_start_date')]) ? date("Y-m-d", strtotime(str_replace('/', '.', $v[_egbolig_webform_get_webform_cid($tree, 'education_start_date')]))) : NULL;
  $member->EducationEnd = !empty($v[_egbolig_webform_get_webform_cid($tree, 'education_end_date')]) ? date("Y-m-d", strtotime(str_replace('/', '.', $v[_egbolig_webform_get_webform_cid($tree, 'education_end_date')]))) : NULL;
  $member->EducationExpectedEnd = !empty($v[_egbolig_webform_get_webform_cid($tree, 'education_end_date')]) ? date("Y-m-d", strtotime(str_replace('/', '.', $v[_egbolig_webform_get_webform_cid($tree, 'education_end_date')]))) : NULL;
  $member->EducationDocumentationReceived = ($v[_egbolig_webform_get_webform_cid($tree, 'education_doc')] > 0); //TODO: not working with WS
  $member->EducationalInstitution = $v[_egbolig_webform_get_webform_cid($tree, 'institution_name')];
  $member->MaximumRent = $v[_egbolig_webform_get_webform_cid($tree, 'husleje_max')];
  $member->Pet = $v[_egbolig_webform_get_webform_cid($tree, 'husdyr')];
  $member->Criteria1 = $v[_egbolig_webform_get_webform_cid($tree, 'status')];
  if ($v[_egbolig_webform_get_webform_cid($tree, 'status')] == 11) {
    $member->Criteria2 = $v[_egbolig_webform_get_webform_cid($tree, 'arsog')];
  }


  //$member->Pet TODO: fix the Pets list

  return $member;
}

/**
 * Returns a list of educations from webservice
 *
 * @return array of educations
 */
function education_get_list() {
  $client = new SoapClient(variable_get('soap_webservice'));
  $educations = $client->EducationGetList()->EducationGetListResult->Education;
  $edulist = array();

  foreach ($educations as $education) {
    if (!in_array($education->Id, array(1, 2, 3))) {
      continue;
    }
    elseif (strlen($education->Name) == 1) {
      continue;
    }
    elseif ($education->Name == 'æ' || $education->Name == 'ø' || $education->Name == 'å') {
      continue;
    }
    else {
      $edulist[$education->Id] = mb_convert_case($education->Name, MB_CASE_TITLE, "UTF-8");
    }
  }

  return $edulist;
}

/**
 * Updates the member education via the webservice.
 *
 */
function _egbolig_webform_ws_update_education($member) {
  $client = new SoapClient(variable_get('soap_webservice'));
  $response = $client->MemberUpdateEducation(
    array(
      'member' => $member,
    )
  );
}

/**
 * Updates the member partner via the webservice.
 *
 */
function _egbolig_webform_ws_update_partner($member, $form_state) {
  $v = $form_state['values']['submitted'];
  $tree = $form_state['webform']['component_tree']['children'];
  if ((int) $v[_egbolig_webform_get_webform_cid($tree, 'has_partner')][0]) {
    $partner_cpr = $v[_egbolig_webform_get_webform_cid($tree, 'parner_cpr_nr')];
    $member->Cpr62 = substr($partner_cpr, 0, 6);
    $member->Cpr42 = substr($partner_cpr, -4);
    $partner_name = "";
    if (module_exists('vcv_serviceplatformen')) {
      $partner = vcv_serviceplatformen_get_address($partner_cpr);
      $partner_name = $partner['name'];
    }
    $client = new SoapClient(variable_get('soap_webservice'));
    $partner_array = array(
      'memberCompanyNo' => $member->MemberCompanyNo,
      'memberNo' => $member->MemberNo,
      'name' => $partner_name,
      'cpr62' => substr($member->Cpr62, 0, 6),
      'cpr42' => substr($member->Cpr42, -4),
    );

    $response = $client->MemberUpdatePartner($partner_array);
  }
}

/**
 * Returns a list of education places from webservice
 *
 * @return array of education places
 */
function education_places() {
  $placeslist = array();
  $client = new SoapClient(variable_get('soap_webservice'));
  $education_places = $client->EducationalInstitutionGetList()->EducationalInstitutionGetListResult->EducationalInstitution;
  if (count($education_places) > 0) {
    foreach ($education_places as $place) {
      $placeslist[$place->Id] = $place->Name;
    }
  }
  else {
    $placeslist[] = 'Ingen uddannelsessteder';
  }
  return $placeslist;
}

/**
 * Returns a list of accommodations from webservice
 *
 * @return array of accommodations
 */
function accommodation_types() {
  $accommodationlist = array();
  $client = new SoapClient(variable_get('soap_webservice'));
  $apartment_types = $client->TenancyTypeGetList()->TenancyTypeGetListResult->TenancyType;
  foreach ($apartment_types as $type) {
    $accommodationlist[] = $type->Text;
  }
  return $accommodationlist;
}

function _egbolig_webform_get_webform_cid($tree, $form_key) {
  foreach ($tree as $child) {
    if ($child['form_key'] === $form_key) {
      return $child['cid'];
    }
    else {
      if ($child['children']) {
        $cid = _egbolig_webform_get_webform_cid($child['children'], $form_key);
        if ($cid) {
          return $cid;
        }
      }
    }
  }
}

/**
 * Returns a list of professions from webservice
 *
 * @return array of professions
 */
function profession_get_list() {
  $professionList = array();
  $client = new SoapClient(variable_get('soap_webservice'));
  $professions = $client->ProfessionGetList()->ProfessionGetListResult->Profession;
  foreach ($professions as $prof) {
    $professionList[$prof->Id] = $prof->Name;
  }
  return $professionList;
}

/**
 * Returns a list of children from webservice
 *
 * @return array of children
 */
function _egbolig_webform_get_children_by_member($memberNo, $companyNo) {
  $childrenList = array();
  $client = new SoapClient(variable_get('soap_webservice'));
  $children = $client->ChildGetByMember(array(
    'companyNo' => $companyNo,
    'memberNo' => $memberNo
  ))->ChildGetByMemberResult->Child;
  if (is_array($children)) {
    foreach ($children as $child) {
      $childrenList[] = array('Cpr6' => $child->Cpr6, 'Cpr4' => $child->Cpr4);
    }
  }
  else {
    $childrenList[] = array('Cpr6' => $children->Cpr6, 'Cpr4' => $children->Cpr4);
  }

  return $childrenList;
}

/*
 * checks if child added to the member
 */

function egbolig_webform_is_child_exists($child_cpr, $childrenList) {
  foreach ($childrenList as $child) {
    if ($child['Cpr4'] == substr($child_cpr, -4) && $child['Cpr6'] == substr($child_cpr, 0, 6)) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Added wishes
 *
 */
function egbolig_webform_ws_add_wishes($member, $form_state) {
  $v = $form_state['values']['submitted'];
  $tree = $form_state['webform']['component_tree']['children'];
  $client = new SoapClient(variable_get('soap_webservice'));
  $minRoom = (int) $v[_egbolig_webform_get_webform_cid($tree, 'antal_rum_min')];
  $maxRoom = (int) $v[_egbolig_webform_get_webform_cid($tree, 'antal_rum_max')];
  $wishes = array();
  //delete all wishes before add

  $response = $client->WishDeleteByMember(array(
    'memberNo' => $member->MemberNo,
    'memberCompanyNo' => $member->MemberCompanyNo,
  ));

  $submittedRegions = array();
  for ($i = 1; $i <= 4; $i++) {
    // get region IDs
    $regionNo = $v[_egbolig_webform_get_webform_cid($tree, 'priority_' . (string) $i)];
    if (!empty($regionNo)) {

      //skipping duplicates
      if (!in_array($regionNo, $submittedRegions)) {
        $submittedRegions[] = $regionNo;
      }
      else {
        continue;
      }

      $departments_array = array(
        'regionNo' => $regionNo
      );
      $response = $client->DepartmentGetListByRegion($departments_array);
      foreach ($response->DepartmentGetListByRegionResult->Department as $key => $department) {
        for ($j = $minRoom; $j <= $maxRoom; $j++) {
          $wishes[] = array(
            'CompanyNo' => $department->CompanyNo,
            'MemberCompanyNo' => $member->MemberCompanyNo,
            'DepartmentNo' => $department->DepartmentNo,
            'Room' => $j,
            'FloorMax' => DEFAULT_MAX_FLOOR,
            'FloorMix' => DEFAULT_MIN_FLOOR,
            'SqmMax' => DEFAULT_MAX_SQM,
            'SqmMin' => DEFAULT_MIN_SQM,
            'MemberNo' => $member->MemberNo,
            'TenancyType' => 1
          );
        }
      }
    }
  }
  $wish_response = $client->WishAddList(array(
      'wishes' => $wishes
    )
  );
}
