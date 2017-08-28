<?php
/**
 * Renders custom setting for SBSYS form
 *
 * @param $form
 * @param $form_state
 * @param $node
 * @return mixed
 */
function bellcom_webform_sbsys_settings_form($form, $form_state, $node) {
  $components_options = array();
  foreach ($node->webform['components'] as $id => $component) {
    $components_options[$component['form_key']] = $component['name'];
  }
  $components_options['custom'] = t('Custom text') . '...';

  $default = bellcom_webform_get_setting($node->nid);

  if (!$default) {
    $default['enabled'] = 0;
  }

  $form['enabled'] = array(
    '#default_value' => $default['enabled'],
    '#type' => 'checkbox',
    '#title' => t('Send SBSYS XML'),
  );

  $form['fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        'input[name="enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  //adding os2formsId
  bellcom_webform_sbsys_settings_add_field($form, 'os2formsId', $default, $components_options);
  //adding kle
  bellcom_webform_sbsys_settings_add_field($form, 'kle', $default, $components_options);
  //adding sagSkabelonId
  bellcom_webform_sbsys_settings_add_field($form, 'sagSkabelonId', $default, $components_options);
  //adding bodyText
  bellcom_webform_sbsys_settings_add_field($form, 'bodyText', $default, $components_options);

  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  if (!isset($default['nid'])) {
    $form['new'] = array(
      '#type' => 'value',
      '#value' => 1,
    );
  }

  return $form;
}

/**
 * Generates a field pair - selectbox + custom text field
 *
 * @param $form
 * @param $field_name
 * @param $default
 * @param $components_options
 */
function bellcom_webform_sbsys_settings_add_field(&$form, $field_name, $default, $components_options) {
  $form['fields'][$field_name] = array(
    '#type' => 'select',
    '#title' => t('@field_name value', array('@field_name' => $field_name)),
    '#options' => $components_options,
    '#default_value' => $default[$field_name],
    '#description' => t('Select a value from form submitted fields or provide a custom static value'),
  );
  $form['fields'][$field_name . '_custom'] = array(
    '#type' => 'textfield',
    '#title' => t('@field_name custom text', array('@field_name' => $field_name)),
    '#default_value' => $default[$field_name . '_custom'],
    '#size' => 60,
    '#maxlength' => 128,
    '#states' => array(
      'visible' => array(
        ':input[name="' . $field_name . '"]' => array('value' => 'custom'),
      ),
    ),
    '#description' => t('Provide a custom static value'),
  );
  $form['fields'][] = array('#markup' => '<hr/>');
}

/**
 * bellcom_webform_sbsys_settings_form_submit: Implements submit hook
 *
 * @param $form
 * @param $form_state
 */
function bellcom_webform_sbsys_settings_form_submit($form, &$form_state) {
  $save = $form_state['values'];
  unset($save['nid']);
  unset($save['enabled']);
  unset($save['submit']);
  unset($save['reset']);
  unset($save['form_build_id']);
  unset($save['form_token']);
  unset($save['form_id']);
  unset($save['op']);

  // First enabled
  if (isset($form_state['values']['new'])) {
    unset($save['new']);

    if ($form_state['values']['enabled']) {

      $bellcom_webform_sbsys_settings['nid'] = $form_state['values']['nid'];
      $bellcom_webform_sbsys_settings['enabled'] = $form_state['values']['enabled'];
      $bellcom_webform_sbsys_settings['data'] = $save;

      drupal_write_record('bellcom_webform', $bellcom_webform_sbsys_settings);
    }
  }

  if (!isset($form_state['values']['new'])) {
    // update settings
    $bellcom_webform_sbsys_settings['nid'] = $form_state['values']['nid'];
    $bellcom_webform_sbsys_settings['enabled'] = $form_state['values']['enabled'];
    $bellcom_webform_sbsys_settings['data'] = $save;
    drupal_write_record('bellcom_webform', $bellcom_webform_sbsys_settings, 'nid');
  }
}

/**
 * Get bellcom_webform setting for the specified nid.
 *
 * @param $nid
 * @return array
 */
function bellcom_webform_get_setting($nid) {
  $default = db_select('bellcom_webform', 'bw')
    ->fields('bw')
    ->condition('nid', $nid, '=')
    ->execute()
    ->fetchAssoc();

  if ($default) {
    $data = unserialize($default['data']);
    unset($default['data']);

    return array_merge($default, $data);
  }

  return array();
}

/**
 * Gets the actual value of the setting by name.
 * If custom text is used, then the custom text will be returned
 *
 * @param $name
 * @param $config
 * @param $params
 * @return mixed
 */
function bellcom_webform_get_setting_value($name, $config, $params) {
  if ($config[$name] != 'custom') {
    return bellcom_webform_module_sbsys_xml_get_value_by_form_key($config[$name], $params);
  } else {
    return $config[$name . "_custom"];
  }
}