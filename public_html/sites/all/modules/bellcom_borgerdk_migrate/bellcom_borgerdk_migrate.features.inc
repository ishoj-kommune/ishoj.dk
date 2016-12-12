<?php
/**
 * @file
 * bellcom_borgerdk_migrate.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bellcom_borgerdk_migrate_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bellcom_borgerdk_migrate_node_info() {
  $items = array(
    'borger_dk_article' => array(
      'name' => t('Borger.dk Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
