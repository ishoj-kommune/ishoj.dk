<?php
/**
 * @file
 * ishoj_selvbetjeningsteaser_til_forsiden.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ishoj_selvbetjeningsteaser_til_forsiden_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ishoj_selvbetjeningsteaser_til_forsiden_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ishoj_selvbetjeningsteaser_til_forsiden_image_default_styles() {
  $styles = array();

  // Exported image style: ishoj_forside_selvbtj_teaserfoto
  $styles['ishoj_forside_selvbtj_teaserfoto'] = array(
    'name' => 'ishoj_forside_selvbtj_teaserfoto',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '1568',
          'height' => '337',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ishoj_selvbetjeningsteaser_til_forsiden_node_info() {
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
