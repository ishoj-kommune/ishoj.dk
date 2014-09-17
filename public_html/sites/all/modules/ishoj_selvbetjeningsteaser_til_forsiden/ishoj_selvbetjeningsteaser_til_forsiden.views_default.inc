<?php
/**
 * @file
 * ishoj_selvbetjeningsteaser_til_forsiden.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ishoj_selvbetjeningsteaser_til_forsiden_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'view_selvbetjeningsteaser_til_forsiden';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Selvbetjeningsteaser til forsiden';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'teaserSwap';
  $handler->display->display_options['style_options']['class'] = 'teaser slides';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  /* Field: Content: Baggrundsfoto */
  $handler->display->display_options['fields']['field_baggrundsfoto']['id'] = 'field_baggrundsfoto';
  $handler->display->display_options['fields']['field_baggrundsfoto']['table'] = 'field_data_field_baggrundsfoto';
  $handler->display->display_options['fields']['field_baggrundsfoto']['field'] = 'field_baggrundsfoto';
  $handler->display->display_options['fields']['field_baggrundsfoto']['label'] = '';
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['text'] = '<img class="teaserImg round3" src="[field_baggrundsfoto-fid]" alt="[field_baggrundsfoto-alt]" />';
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_baggrundsfoto']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_baggrundsfoto']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_baggrundsfoto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_baggrundsfoto']['settings'] = array(
    'image_style' => 'ishoj_forside_selvbtj_teaserfoto',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_baggrundsfoto']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="teaserText">
   <h1>[title]</h1>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Underoverskrift */
  $handler->display->display_options['fields']['field_underoverskrift']['id'] = 'field_underoverskrift';
  $handler->display->display_options['fields']['field_underoverskrift']['table'] = 'field_data_field_underoverskrift';
  $handler->display->display_options['fields']['field_underoverskrift']['field'] = 'field_underoverskrift';
  $handler->display->display_options['fields']['field_underoverskrift']['label'] = '';
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['text'] = '<h2>[field_underoverskrift]</h2>';
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_underoverskrift']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_underoverskrift']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_underoverskrift']['field_api_classes'] = 0;
  /* Field: Field: Ekstern URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['label'] = '';
  $handler->display->display_options['fields']['field_external_url']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_external_url']['alter']['text'] = '   <a href="[field_external_url-url]" title="[field_external_url-title]" class="linkGaaTil box">[field_external_url-title]</a> 
</div>';
  $handler->display->display_options['fields']['field_external_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_external_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_external_url']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_external_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_external_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_external_url']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_external_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_external_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_external_url']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_url']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'selvbetjeningsteaser_til_forside' => 'selvbetjeningsteaser_til_forside',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['view_selvbetjeningsteaser_til_forsiden'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<img class="teaserImg round3" src="[field_baggrundsfoto-fid]" alt="[field_baggrundsfoto-alt]" />'),
    t('<div class="teaserText">
   <h1>[title]</h1>'),
    t('<h2>[field_underoverskrift]</h2>'),
    t('   <a href="[field_external_url-url]" title="[field_external_url-title]" class="linkGaaTil box">[field_external_url-title]</a> 
</div>'),
    t('Content pane'),
    t('View panes'),
  );
  $export['view_selvbetjeningsteaser_til_forsiden'] = $view;

  return $export;
}
