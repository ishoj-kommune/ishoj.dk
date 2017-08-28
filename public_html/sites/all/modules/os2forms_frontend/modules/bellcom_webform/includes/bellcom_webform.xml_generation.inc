<?php

/**
 * This function generates the SBSYS XML, fills it with values and returns is as string
 *
 * @param $params
 * @return string
 */
function bellcom_webform_module_sbsys_xml($params) {
  $nemid_cpr = bellcom_webform_module_sbsys_xml_get_value_by_type('nemid_cpr', $params);

  $message = vcv_serviceplatformen_get_address($nemid_cpr);
  $nemid_name = $message['name'];
  $nemid_address = $message['road'] . ' ' . $message['road_no'] . ' ' . $message['floor'] . ' ' . $message['door'];
  $nemid_city = $message['city'];
  $nemid_zipcode = $message['zipcode'];

  $config = bellcom_webform_get_setting($params['node']->nid);
  $os2formsId = bellcom_webform_get_setting_value('os2formsId', $config, $params);
  $kle = bellcom_webform_get_setting_value('kle', $config, $params);
  $sagSkabelonId = bellcom_webform_get_setting_value('sagSkabelonId', $config, $params);
  $bodyText = bellcom_webform_get_setting_value('bodyText', $config, $params);

  $webform = node_load($params['node']->nid);
  $webform_title = $webform->title;

  $xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<os2formsFormular>
  <OS2FormsId>$os2formsId</OS2FormsId>
  <SBSYSJournalisering>
    <PrimaerPartCprNummer>$nemid_cpr</PrimaerPartCprNummer>
    <PrimaerPartCvrNummer></PrimaerPartCvrNummer>
    <KLe>$kle</KLe>
    <SagSkabelonId>$sagSkabelonId</SagSkabelonId>
  </SBSYSJournalisering>
  <DigitalForsendelse>
    <Slutbruger>
      <CprNummer>$nemid_cpr</CprNummer>
      <CvrNummer></CvrNummer>
      <Navn>$nemid_name</Navn>
      <Adresse>$nemid_address</Adresse>
      <Postnr>$nemid_zipcode</Postnr>
      <Postdistrikt>$nemid_city</Postdistrikt>
    </Slutbruger>
    <Kvittering>
      <TitelTekst>$webform_title</TitelTekst>
      <BodyTekst>$bodyText</BodyTekst>
    </Kvittering>
    <MaaSendesTilDFF>ja</MaaSendesTilDFF>
  </DigitalForsendelse>
  <FormularData>";
  foreach (bellcom_webform_module_sbsys_xml_get_fields_to_list($params) as $field_name => $field_value) {
    $xml .= "<$field_name>$field_value</$field_name>";
  }
  $xml .= "</FormularData>
</os2formsFormular>";
  return $xml;
}

/**
 * Helper function to get element component ID (CID) from the element type
 *
 * @param $type
 * @param $params
 * @return int|string
 */
function bellcom_webform_module_sbsys_xml_get_cid_by_type($type, $params) {
  $components = $params['node']->webform['components'];

  foreach($components as $cid => $component) {
    if ($component['type'] == $type) {
      return $cid;
    }
  }
}

/**
 * Helper function to get element component ID (CID) from the element form_key
 *
 * @param $type
 * @param $params
 * @return int|string
 */
function bellcom_webform_module_sbsys_xml_get_cid_by_form_key($form_key, $params) {
  $components = $params['node']->webform['components'];

  foreach($components as $cid => $component) {
    if ($component['form_key'] == $form_key) {
      return $cid;
    }
  }
}


/**
 * Helper function to get element submitted value from the the element type
 *
 * @param $type
 * @param $params
 * @return mixed
 */
function bellcom_webform_module_sbsys_xml_get_value_by_type($type, $params) {
  $data = $params['submission']->data;

  $cid = bellcom_webform_module_sbsys_xml_get_cid_by_type($type, $params);
  if ($cid) {
    return reset($data[$cid]);
  }
}

/**
 * Helper function to get element submitted value from the the element form_key
 *
 * @param $form_key
 * @param $params
 * @return mixed
 */
function bellcom_webform_module_sbsys_xml_get_value_by_form_key($form_key, $params) {
  $data = $params['submission']->data;

  $cid = bellcom_webform_module_sbsys_xml_get_cid_by_form_key($form_key, $params);
  if ($cid) {
    return reset($data[$cid]);
  }
}

/**
 * Helper function the returns the list of the fields and their values as an array.
 * All field except the field with type markup (used for formatting) are returned
 *
 * @param $params
 * @return array
 */
function bellcom_webform_module_sbsys_xml_get_fields_to_list($params) {
  $fields_to_list = array();
  $data = $params['submission']->data;
  foreach($params['node']->webform['components'] as $cid => $element) {
    $field_name = $element['form_key'];
    $field_name = preg_replace('/\W/', '_', $field_name);
     if ($element['type'] == 'markup') {
      $fields_to_list[$field_name] = $element['value'];
     }
     else {
      $fields_to_list[$field_name] = reset($data[$cid]);
    }
  }
  return $fields_to_list;
}
