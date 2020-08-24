<?php
/**
 * @file
 * ishoj_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ishoj_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nyhedsliste';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nyhedsliste';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Felt: Felt: Intro / resumé (bruges også til tekst til søgemaskiner) (max 2 linier)  */
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['id'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['table'] = 'field_data_field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['field'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_default_classes'] = FALSE;
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$alias = "/" . drupal_get_path_alias("node/" . $data->nid);


print "<li class=\\"grid-third\\"><a title=\\"" . $data->node_title . "\\" href=\\"" . $alias . "\\">";

//dsm($data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Indhold: Foto */
  $handler->display->display_options['fields']['field_os2web_base_field_image']['id'] = 'field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['table'] = 'field_data_field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['field'] = 'field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['settings'] = array(
    'picture_mapping' => 'nyhedsliste_picture_mappings',
    'fallback_image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_base_field_image']['delta_offset'] = '0';
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$resume = "";
if($data->field_field_os2web_base_field_summary) {
   $resume = $data->field_field_os2web_base_field_summary[0][\'raw\'][\'value\'];
}

print "<h3>" . $data->node_title . "</h3><p>" . $resume . "</p></a></li>";

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Sorteringskriterie: Indhold: Klæbrig */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontekstuelt filter: Indhold: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'os2web_base_contentpage' => 'os2web_base_contentpage',
  );
  /* Filterkriterie: Indhold: Indholdstype (field_indholdstype) */
  $handler->display->display_options['filters']['field_indholdstype_tid']['id'] = 'field_indholdstype_tid';
  $handler->display->display_options['filters']['field_indholdstype_tid']['table'] = 'field_data_field_indholdstype';
  $handler->display->display_options['filters']['field_indholdstype_tid']['field'] = 'field_indholdstype_tid';
  $handler->display->display_options['filters']['field_indholdstype_tid']['value'] = array(
    0 => '2647',
  );
  $handler->display->display_options['filters']['field_indholdstype_tid']['vocabulary'] = 'indholdstype';
  /* Filterkriterie: Indhold: Forfremmet til forside */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Nyhedsliste vis nyhed */
  $handler = $view->new_display('panel_pane', 'Nyhedsliste vis nyhed', 'panel_pane_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$alias = "/" . drupal_get_path_alias("node/" . $data->nid);
print "<li class=\\"active-trail\\"><a title=\\"" . $data->node_title . "\\" href=\\"" . $alias . "\\">" . $data->node_title . "</a></li>";

//dsm($data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';

  /* Display: Nyhedsliste forside */
  $handler = $view->new_display('panel_pane', 'Nyhedsliste forside', 'panel_pane_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Felt: Felt: Intro / resumé (bruges også til tekst til søgemaskiner) (max 2 linier)  */
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['id'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['table'] = 'field_data_field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['field'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_default_classes'] = FALSE;
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$alias = "/" . drupal_get_path_alias("node/" . $data->nid);


print "<div class=\\"swiper-slide\\"><a title=\\"" . $data->node_title . "\\" href=\\"" . $alias . "\\">";
print "<div>";
//dsm($data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Indhold: Foto */
  $handler->display->display_options['fields']['field_os2web_base_field_image']['id'] = 'field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['table'] = 'field_data_field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['field'] = 'field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['settings'] = array(
    'picture_mapping' => 'nyhedsliste_picture_mappings',
    'fallback_image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_base_field_image']['delta_offset'] = '0';
  /* Felt: Indhold: Indlejringskode fra videotjeneste */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = '';
  $handler->display->display_options['fields']['field_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'trim_length' => '600',
  );
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
if (empty($data->field_field_os2web_base_field_image) && !empty($data->field_field_video)) {
print \'<div class="video-responsive">\';
print ( $data->field_field_video[0][\'raw\'][\'value\']);
print \'</div>\';
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print "</div>";
$resume = "";
if($data->field_field_os2web_base_field_summary) {
   $resume = $data->field_field_os2web_base_field_summary[0][\'raw\'][\'value\'];
}

print "<h4>" . $data->node_title . "</h4><p>" . $resume . "</p></a></div>";

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Nyhedsliste forside (klon) */
  $handler = $view->new_display('panel_pane', 'Nyhedsliste forside (klon)', 'panel_pane_3');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Youtube-liste forside */
  $handler = $view->new_display('panel_pane', 'Youtube-liste forside', 'youtubeliste_forside');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Felt: Indhold: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$alias = "/" . drupal_get_path_alias("node/" . $data->nid);


print "<div class=\\"swiper-slide\\"><a title=\\"" . $data->node_title . "\\" href=\\"" . $alias . "\\">";
print "<div>";
print "<div class=\\"youtube-play\\"></div>";
print "<div class=\\"tvi-logo\\"></div>";
//dsm($data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Indhold: Thumbnail */
  $handler->display->display_options['fields']['field_youtubethumbnail']['id'] = 'field_youtubethumbnail';
  $handler->display->display_options['fields']['field_youtubethumbnail']['table'] = 'field_data_field_youtubethumbnail';
  $handler->display->display_options['fields']['field_youtubethumbnail']['field'] = 'field_youtubethumbnail';
  $handler->display->display_options['fields']['field_youtubethumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_youtubethumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtubethumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_youtubethumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtubethumbnail']['type'] = 'picture';
  $handler->display->display_options['fields']['field_youtubethumbnail']['settings'] = array(
    'picture_mapping' => 'nyhedsliste_picture_mappings',
    'fallback_image_style' => '',
    'image_link' => '',
  );
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print "</div>";
$resume = "";
if($data->field_body) {
   $resume = $data->field_body[0][\'raw\'][\'value\'];
}

print "<h4>" . $data->node_title . "</h4><p>" . $resume . "</p></a></div>";

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteringskriterie: Indhold: published (field_youtube_published) */
  $handler->display->display_options['sorts']['field_youtube_published_value']['id'] = 'field_youtube_published_value';
  $handler->display->display_options['sorts']['field_youtube_published_value']['table'] = 'field_data_field_youtube_published';
  $handler->display->display_options['sorts']['field_youtube_published_value']['field'] = 'field_youtube_published_value';
  $handler->display->display_options['sorts']['field_youtube_published_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tvishoj_indslag' => 'tvishoj_indslag',
  );

  /* Display: Youtube-liste forside */
  $handler = $view->new_display('panel_pane', 'Youtube-liste forside', 'panel_pane_4');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Felt: Felt: Intro / resumé (bruges også til tekst til søgemaskiner) (max 2 linier)  */
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['id'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['table'] = 'field_data_field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['field'] = 'field_os2web_base_field_summary';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_summary']['element_default_classes'] = FALSE;
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$alias = "/" . drupal_get_path_alias("node/" . $data->nid);


print "<div class=\\"swiper-slide\\"><a title=\\"" . $data->node_title . "\\" href=\\"" . $alias . "\\">";
print "<div>";
print "<div class=\\"youtube-play\\"></div>";
print "<div class=\\"tvi-logo\\"></div>";
//dsm($data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Indhold: Foto */
  $handler->display->display_options['fields']['field_os2web_base_field_image']['id'] = 'field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['table'] = 'field_data_field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['field'] = 'field_os2web_base_field_image';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['label'] = '';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_os2web_base_field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_os2web_base_field_image']['settings'] = array(
    'picture_mapping' => 'nyhedsliste_picture_mappings',
    'fallback_image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_os2web_base_field_image']['delta_offset'] = '0';
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print "</div>";
$resume = "";
if($data->field_field_os2web_base_field_summary) {
   $resume = $data->field_field_os2web_base_field_summary[0][\'raw\'][\'value\'];
}

print "<h3>" . $data->node_title . "</h3><p>" . $resume . "</p></a></div>";

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $translatables['nyhedsliste'] = array(
    t('Master'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Alle'),
    t('Nyhedsliste vis nyhed'),
    t('View panes'),
    t('Nyhedsliste forside'),
    t('Nyhedsliste forside (klon)'),
    t('Youtube-liste forside'),
  );
  $export['nyhedsliste'] = $view;

  return $export;
}
