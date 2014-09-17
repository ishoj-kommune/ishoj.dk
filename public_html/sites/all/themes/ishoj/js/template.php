<?php


// Implementation of hook_preprocess_page()  /  tho
function ishoj_preprocess_page(&$vars) {  

  if ($vars['is_front']) {
    drupal_add_js(drupal_get_path('theme', 'ishoj')  . '/js/jquery.colorbox-min.js');
    drupal_add_css(drupal_get_path('theme', 'ishoj') . '/css/colorbox.css', array('group' => CSS_THEME, 'weight' => 115));
    //	drupal_add_css(drupal_get_path('theme', 'ishoj') . '/css/ie/ie-7.css', array('group' => CSS_THEME, 'weight' => 115, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
  }

  $vars['path_to_theme'] = drupal_get_path('theme', 'ishoj') . '/';
  $path = drupal_get_path_alias(); 
  $urlPath = $path;

  // hvis path'en indeholder strengen 'infotv'
  if(strpos($urlPath, 'infotv') !== false) {
     $urlPath = 'infotv';
  } 
  
  switch ($urlPath) {
  
    case 'infotv':
      // Tilføjer styelsheets
      drupal_add_css($vars['path_to_theme'] . 'css/reset.css', array('group' => CSS_THEME, 'weight' => 100));
      drupal_add_css($vars['path_to_theme'] . 'css/flexslider.css', array('group' => CSS_THEME, 'weight' => 100));
      drupal_add_css($vars['path_to_theme'] . 'css/infotv.css', array('group' => CSS_THEME, 'weight' => 100));
      // Tilføjer javascripts
      
      // exclude backend pages to avoid core js not working anymore
      // you could also just use a backend theme to avoid this
/*      if (arg(0) != 'admin' || !(arg(1) == 'add' && arg(2) == 'edit') || arg(0) != 'panels' || arg(0) != 'ctools') {
        $scripts = drupal_add_js();
        $new_jquery = array(drupal_get_path('theme', 'ishoj') . '/js/jquery-2.0.3.min.js' => $scripts['core']['misc/jquery.js']);
        $scripts['core'] = array_merge($new_jquery, $scripts['core']);
        unset($scripts['core']['misc/jquery.js']);
        $variables['scripts'] = drupal_get_js('header', $scripts);
      }    */
  
      //hvis det er demo-info-tv
//      if (arg(1) == 'demo') {
//        drupal_add_js($vars['path_to_theme'] . 'js/Chart.min.js', array('weight' => 1000));
        
//      }  
      unset($vars['misc/jquery.js']);
      drupal_add_js($vars['path_to_theme'] . 'js/jquery-1.6.4.min.js', array('weight' => 1000));
    
      drupal_add_js($vars['path_to_theme'] . 'js/jquery.flexslider-min.js', array('weight' => 1000));
      drupal_add_js($vars['path_to_theme'] . 'js/jquery.easing.1.3.js', array('weight' => 1000));
      drupal_add_js($vars['path_to_theme'] . 'js/infotv.js', array('weight' => 1000));
      break;	
		
    default:
      // Tilføjer styelsheets  
      drupal_add_css($vars['path_to_theme'] . 'css/reset.css', array('group' => CSS_THEME, 'weight' => 100));
      drupal_add_css($vars['path_to_theme'] . 'css/default.css', array('group' => CSS_THEME, 'weight' => 101));
      drupal_add_css($vars['path_to_theme'] . 'css/flexslider.css', array('group' => CSS_THEME, 'weight' => 102));
      drupal_add_css($vars['path_to_theme'] . 'css/responsive.css', array('group' => CSS_THEME, 'weight' => 103));
      // Tilføjer javascripts
      drupal_add_js($vars['path_to_theme'] . 'js/modernizr.custom.60073.js', array('weight' => 100));
      drupal_add_js($vars['path_to_theme'] . 'js/jquery.easing.1.3.js', array('weight' => 101));
      drupal_add_js($vars['path_to_theme'] . 'js/jquery.hoverIntent.minified.js', array('weight' => 102));
      drupal_add_js($vars['path_to_theme'] . 'js/jquery.timer.js', array('weight' => 103));
      drupal_add_js($vars['path_to_theme'] . 'js/jquery.flexslider-min.js', array('weight' => 104));
      drupal_add_js($vars['path_to_theme'] . 'js/jquery.cookie.js', array('weight' => 105));
      drupal_add_js($vars['path_to_theme'] . 'js/pages.js', array('weight' => 106));
      drupal_add_js($vars['path_to_theme'] . 'js/front.js', array('weight' => 107));
      break;
  }
  
  // Page is a panel.
 // $vars['is_panel'] = function_exists('panels_get_current_page_display') && panels_get_current_page_display();
}

 

global $user;
// Hvis man er logget ind (webredaktører), indlæses dette javascript
if($user->uid != 0) {
    drupal_add_js(drupal_get_path('theme', 'ishoj')  . '/js/admin.js');
}

// Implementation of hook_preprocess_node()
// Se http://api.drupal.org/api/drupal/modules%21node%21node.module/function/template_preprocess_node/7
//function ishoj_preprocess_node(&$variables) {

  // Display post information only on certain node types.
//  if (variable_get('node_submitted_' . $node->type, TRUE)) {
 //  if($variables['display_submitted']) {
//    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['date']));
//    $variables['submitted'] = t('Senest redigeret !datetime', array('!datetime' => $variables['date']));	
    //$variables['user_picture'] = theme_get_setting('toggle_node_user_picture') ? theme('user_picture', array('account' => $node)) : '';
//  }
/*  else {
    $variables['display_submitted'] = FALSE;
    $variables['submitted'] = '';
    $variables['user_picture'] = '';
  }
*/
//}

// Tilføjer javascript til en specifik path
/*function ishoj_preprocess_html(&$variables) {*/
//  $theme_path = path_to_theme();
//  $url = request_uri();

/*  if ($url == '/home') {
    drupal_add_js($theme_path . '/js/eureka.js');
  }*/
  

/*if(strpos(request_uri(), "/selvbetjening")) {

	drupal_add_js(path_to_theme() . '/js/selvbetjening.js');
}*/
/*  if ($url == '/selvbetjening') {
    drupal_add_js($vars['path_to_theme'] . '/js/selvbetjening.js');
  }
*/
/*}*/

function ishoj_preprocess_username(&$vars) {
  if (isset($vars['link_path']) && isset($vars['surpress_link']) && $vars['surpress_link']) {
    unset($vars['link_path']);
  }
}


function ishoj_preprocess_node(&$variables) {
  $node = $variables['node'];

  // Only add the revision information if the node is configured to display
//  if ($variables['display_submitted'] && ($node->revision_uid != $node->uid || $node->revision_timestamp != $node->created)) {
  if ($variables['display_submitted']) {
    // Append the revision information to the submitted by text.
    $revision_account = user_load($node->revision_uid);
//    $variables['revision_name'] = theme('username', array('account' => $revision_account));
    $variables['revision_date'] = format_date($node->changed);
	
//    $variables['submitted'] .= t(' and last modified by !revision-name on !revision-date', array(
//      '!name' => $variables['name'], '!date' => $variables['date'], '!revision-name' => $variables['revision_name'], '!revision-date' => $variables['revision_date']));

    $variables['submitted'] = t('Senest redigeret !revision-date', array('!revision-date' => $variables['revision_date']));
    $variables['created'] = t('Senest redigeret !revision-date', array('!revision-date' => $variables['revision_date']));


  }
}




// Fjerner div.panel-separator crap mellem panels  /  tho
function ishoj_panels_default_style_render_region($vars) {
  $output = '';
  $output .= implode('', $vars['panes']);
  return $output;
}

// Fjerner width- og height-attributter på image-elementer  /  tho
function ishoj_preprocess_image(&$variables) {
  $attributes = &$variables['attributes'];
  foreach (array('width', 'height') as $key) {
    unset($attributes[$key]);
    unset($variables[$key]);
  }
}

// Tilføjer klasser til image-elementer udfra image style-name  /  tho
function ishoj_preprocess_image_style(&$variables)  {
    if ($variables['style_name'] == 'ishoj_forside_selvbtj_teaserfoto') {
        $variables['attributes']['class'][] = 'teaserImg';
        $variables['attributes']['class'][] = 'round3';
    }
}

// Ren unordered list uden klasser /  tho
/*function ishoj_menu_tree($variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}
*/

function ishoj_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
/*	$form['#prefix'] = '';
    $form['#suffix'] = '';*/
    $form['search_block_form']['#title'] = t('Hvad søger du?'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    //$form['search_block_form']['#size'] = 40;  // define size of the textfield
    $form['search_block_form']['#default_value'] = t(''); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = t('Søg'); // Change the text on the submit button
    //$form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search-button.png');
	
/*	$form['name']['#prefix'] = '';
    $form['name']['#suffix'] = '';*/
// Add extra attributes to the text box
//    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
//    $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
  }
  if ($form_id == 'apachesolr_panels_search_block') {
    $form['apachesolr_panels_search_block']['#title'] = t('Hvad søger du?'); // Change the text on the label element
    $form['apachesolr_panels_search_block']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['apachesolr_panels_search_block']['#default_value'] = t(''); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = t('Søg'); // Change the text on the submit button
	$form['apachesolr_panels_search_block']['#attributes']['placeholder'] = t('Hvad søger du?');
  }
  if ($form_id == 'apachesolr_panels_search_form') {
    $form['apachesolr_panels_search_form']['#title'] = t('Hvad søger du?'); // Change the text on the label element
    $form['apachesolr_panels_search_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    //$form['apachesolr_panels_search_form']['#default_value'] = t(''); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = t('Søg'); // Change the text on the submit button
	$form['apachesolr_panels_search_form']['#attributes']['placeholder'] = t('Hvad søger du?');
  }

/*  if ($form_id == 'apachesolr-panels-search-form') {
    $form['apachesolr-panels-search-form']['#title'] = t('Hvad søger du?'); // Change the text on the label element
    $form['apachesolr-panels-search-form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['apachesolr-panels-search-form']['#default_value'] = t(''); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = t('Søg'); // Change the text on the submit button
  }*/


} 

// Menu Alternative
function ishoj_menu_tree__menu_block__7(&$variables) {
  return '<ul class="altMenu">' . $variables['tree'] . '</ul>';
}
// Menu Sitemap Erhverv
function ishoj_menu_tree__menu_block__12(&$variables) {
  return '<ul class="menu hideMe">' . $variables['tree'] . '</ul>';
}
// Menu Sitemap Politik
function ishoj_menu_tree__menu_block__13(&$variables) {
  return '<ul class="menu hideMe">' . $variables['tree'] . '</ul>';
}
// Menu Sitemap Om os
function ishoj_menu_tree__menu_block__14(&$variables) {
  return '<ul class="menu hideMe">' . $variables['tree'] . '</ul>';
}

// Mobil Menu
function ishoj_menu_tree__menu_block__8(&$variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}

// Breadcrumbs 
function ishoj_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  
  if (!empty($breadcrumb)) {
	$breadcrumb[0] = '<a href="/forside" title="Gå til forsiden af Ishøj Kommunes hjemmeside">' . t("Forside") . '</a>';
    //array_shift($breadcrumb); // Removes the Home item
    $output = '<nav class="breadcrumb gradientWhiteRev"><span>' . t("Du er her:") . ' </span>' . implode(' > ', $breadcrumb) . '</nav>';
    return $output;
  }
}


function ishoj_form_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  //$output = '<div' . drupal_attributes($attributes) . '>' . "\n";
  $output = '';
  
  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  //$output .= "</div>\n";

  return $output;
}



function ishoj_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  //element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  element_set_attributes($element, array('id', 'name', 'value'));
  _form_set_class($element, array('form-text'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}



