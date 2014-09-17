<?php
/**
 * @file
 * ishoj_selvbetjeningsteaser_til_forsiden.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ishoj_selvbetjeningsteaser_til_forsiden_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_kriseinformation';
  $strongarm->value = '0';
  $export['language_content_type_kriseinformation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_kriseinformation';
  $strongarm->value = array();
  $export['menu_options_kriseinformation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_kriseinformation';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_kriseinformation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_kriseinformation';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_kriseinformation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_kriseinformation';
  $strongarm->value = '2';
  $export['node_preview_kriseinformation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_kriseinformation';
  $strongarm->value = 1;
  $export['node_submitted_kriseinformation'] = $strongarm;

  return $export;
}
