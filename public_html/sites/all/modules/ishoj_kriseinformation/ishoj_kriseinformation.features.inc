<?php
/**
 * @file
 * ishoj_kriseinformation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ishoj_kriseinformation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ishoj_kriseinformation_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ishoj_kriseinformation_node_info() {
  $items = array(
    'kriseinformation' => array(
      'name' => t('Kriseinformation'),
      'base' => 'node_content',
      'description' => t('Information i en "krisesituation", der vedrører borgerne i Ishøj. Det kunne fx være et giftudslip, oversvømmelse, problemer med fjernvarmen o.lign.
Bemærk: Denne type information vises på alle sider under www.ishoj.dk
'),
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => t('Kriseinformationens overskrift'),
    ),
  );
  return $items;
}
