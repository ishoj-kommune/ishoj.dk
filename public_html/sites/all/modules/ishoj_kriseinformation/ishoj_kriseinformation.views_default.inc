<?php
/**
 * @file
 * ishoj_kriseinformation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ishoj_kriseinformation_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'view_kriseinformation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Kriseinformation';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h1>[title]</h1>';
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
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  /* Field: Content: Tekst til link */
  $handler->display->display_options['fields']['field_tekst_til_link']['id'] = 'field_tekst_til_link';
  $handler->display->display_options['fields']['field_tekst_til_link']['table'] = 'field_data_field_tekst_til_link';
  $handler->display->display_options['fields']['field_tekst_til_link']['field'] = 'field_tekst_til_link';
  $handler->display->display_options['fields']['field_tekst_til_link']['label'] = '';
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['text'] = '<p>[field_tekst_til_link]</p>';
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tekst_til_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tekst_til_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_tekst_til_link']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'kriseinformation' => 'kriseinformation',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['view_kriseinformation'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<h1>[title]</h1>'),
    t('<h2>[field_underoverskrift]</h2>'),
    t('<p>[field_tekst_til_link]</p>'),
    t('Block'),
  );
  $export['view_kriseinformation'] = $view;

  return $export;
}
