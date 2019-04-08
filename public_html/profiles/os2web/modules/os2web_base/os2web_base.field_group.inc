<?php
/**
 * @file
 * os2web_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_base_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_billede_tekst|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_billede_tekst';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_images';
  $field_group->data = array(
    'label' => 'Billeder',
    'weight' => '44',
    'children' => array(
      0 => 'field_os2web_base_field_image',
      1 => 'field_billedtekst',
      2 => 'field_image_flexslider',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Billeder',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_billede_tekst|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bokse|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_bokse';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Bokse',
    'weight' => '8',
    'children' => array(
      0 => 'field_entity_selvbetjening',
      1 => 'field_url',
      2 => 'field_url_2',
      3 => 'field_diverse_boks',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bokse|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bruges_ikke|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_bruges_ikke';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Bruges ikke',
    'weight' => '11',
    'children' => array(
      0 => 'field_os2web_base_field_contact',
      1 => 'field_os2web_base_field_hidlinks',
      2 => 'field_os2web_base_field_lead_img',
      3 => 'field_os2web_base_field_selfserv',
      4 => 'field_os2web_base_field_spotbox',
      5 => 'group_os2web_base_group_esdh',
      6 => 'group_os2web_base_group_extras',
      7 => 'group_os2web_base_group_hidden',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bruges_ikke|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_filer|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_filer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_images';
  $field_group->data = array(
    'label' => 'Filer',
    'weight' => '45',
    'children' => array(
      0 => 'field_os2web_base_field_media',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_filer|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kort|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_kort';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Kort',
    'weight' => '9',
    'children' => array(
      0 => 'field_kort',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_kort|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider10|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider10';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 10',
    'weight' => '36',
    'children' => array(
      0 => 'field_mikroartikler_titel10',
      1 => 'field_mikroartikler_tekst10',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 10',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider10|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider11|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider11';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 11',
    'weight' => '37',
    'children' => array(
      0 => 'field_mikroartikler_titel11',
      1 => 'field_mikroartikler_tekst11',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 11',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider11|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider12|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider12';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 12',
    'weight' => '38',
    'children' => array(
      0 => 'field_mikroartikler_titel12',
      1 => 'field_mikroartikler_tekst12',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 12',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider12|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider13|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider13';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 13',
    'weight' => '39',
    'children' => array(
      0 => 'field_mikroartikler_titel13',
      1 => 'field_mikroartikler_tekst13',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 13',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider13|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider14|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider14';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 14',
    'weight' => '40',
    'children' => array(
      0 => 'field_mikroartikler_titel14',
      1 => 'field_mikroartikler_tekst14',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 14',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider14|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider15|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider15';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 15',
    'weight' => '41',
    'children' => array(
      0 => 'field_mikroartikler_titel15',
      1 => 'field_mikroartikler_tekst15',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 15',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider15|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider16|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider16';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 16',
    'weight' => '42',
    'children' => array(
      0 => 'field_mikroartikler_titel16',
      1 => 'field_mikroartikler_tekst16',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 16',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider16|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider17|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider17';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 17',
    'weight' => '43',
    'children' => array(
      0 => 'field_mikroartikler_titel17',
      1 => 'field_mikroartikler_tekst17',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 17',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider17|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider18|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider18';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 18',
    'weight' => '44',
    'children' => array(
      0 => 'field_mikroartikler_titel18',
      1 => 'field_mikroartikler_tekst18',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 18',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider18|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider19|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider19';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 19',
    'weight' => '45',
    'children' => array(
      0 => 'field_mikroartikler_titel19',
      1 => 'field_mikroartikler_tekst19',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 19',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider19|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider1|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 1',
    'weight' => '27',
    'children' => array(
      0 => 'field_mikroartikler_titel1',
      1 => 'field_mikroartikler_tekst1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 1',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider1|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider20|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider20';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 20',
    'weight' => '46',
    'children' => array(
      0 => 'field_mikroartikler_titel20',
      1 => 'field_mikroartikler_tekst20',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 20',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider20|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider2|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 2',
    'weight' => '28',
    'children' => array(
      0 => 'field_mikroartikler_titel2',
      1 => 'field_mikroartikler_tekst2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 2',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider2|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider3|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 3',
    'weight' => '29',
    'children' => array(
      0 => 'field_mikroartikler_titel3',
      1 => 'field_mikroartikler_tekst3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 3',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider3|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider4|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 4',
    'weight' => '30',
    'children' => array(
      0 => 'field_mikroartikler_titel4',
      1 => 'field_mikroartikler_tekst4',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 4',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider4|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider5|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 5',
    'weight' => '31',
    'children' => array(
      0 => 'field_mikroartikler_titel5',
      1 => 'field_mikroartikler_tekst5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 5',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider5|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider6|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider6';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 6',
    'weight' => '32',
    'children' => array(
      0 => 'field_mikroartikler_titel6',
      1 => 'field_mikroartikler_tekst6',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 6',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider6|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider7|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider7';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 7',
    'weight' => '33',
    'children' => array(
      0 => 'field_mikroartikler_titel7',
      1 => 'field_mikroartikler_tekst7',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 7',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider7|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider8|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider8';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 8',
    'weight' => '34',
    'children' => array(
      0 => 'field_mikroartikler_titel8',
      1 => 'field_mikroartikler_tekst8',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 8',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider8|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler_divider9|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler_divider9';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_mikroartikler';
  $field_group->data = array(
    'label' => 'Mikroartikel 9',
    'weight' => '35',
    'children' => array(
      0 => 'field_mikroartikler_titel9',
      1 => 'field_mikroartikler_tekst9',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mikroartikel 9',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_mikroartikler_divider9|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mikroartikler|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_mikroartikler';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Mikroartikler',
    'weight' => '5',
    'children' => array(
      0 => 'group_mikroartikler_divider1',
      1 => 'group_mikroartikler_divider2',
      2 => 'group_mikroartikler_divider3',
      3 => 'group_mikroartikler_divider4',
      4 => 'group_mikroartikler_divider5',
      5 => 'group_mikroartikler_divider6',
      6 => 'group_mikroartikler_divider7',
      7 => 'group_mikroartikler_divider8',
      8 => 'group_mikroartikler_divider9',
      9 => 'group_mikroartikler_divider10',
      10 => 'group_mikroartikler_divider11',
      11 => 'group_mikroartikler_divider12',
      12 => 'group_mikroartikler_divider13',
      13 => 'group_mikroartikler_divider14',
      14 => 'group_mikroartikler_divider15',
      15 => 'group_mikroartikler_divider16',
      16 => 'group_mikroartikler_divider17',
      17 => 'group_mikroartikler_divider18',
      18 => 'group_mikroartikler_divider19',
      19 => 'group_mikroartikler_divider20',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_mikroartikler|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_3|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_os2web_base_group_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Indstillinger',
    'weight' => '10',
    'children' => array(
      0 => 'field_os2web_base_field_kle_ref',
      1 => 'field_indholdstype',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_3|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_content|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_os2web_base_group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Indholdsside',
    'weight' => '1',
    'children' => array(
      0 => 'group_os2web_base_group_3',
      1 => 'group_os2web_base_group_general',
      2 => 'group_os2web_base_group_images',
      3 => 'group_mikroartikler',
      4 => 'group_video',
      5 => 'group_bokse',
      6 => 'group_bruges_ikke',
      7 => 'group_kort',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_os2web_base_group_content|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_document|node|os2web_base_contentpage|default';
  $field_group->group_name = 'group_os2web_base_group_document';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hentet fra kommunens sagssystem',
    'weight' => '3',
    'children' => array(
      0 => 'field_os2web_base_field_case',
      1 => 'field_os2web_base_field_doc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Hentet fra kommunens sagssystem',
      'instance_settings' => array(
        'classes' => 'attached-documents',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_os2web_base_group_document|node|os2web_base_contentpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_esdh|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_os2web_base_group_esdh';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bruges_ikke';
  $field_group->data = array(
    'label' => 'Sager og dokumenter',
    'weight' => '47',
    'children' => array(
      0 => 'field_os2web_base_field_case',
      1 => 'field_os2web_base_field_doc',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Sager og dokumenter',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_os2web_base_group_esdh|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_extras|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_os2web_base_group_extras';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bruges_ikke';
  $field_group->data = array(
    'label' => 'Emneord',
    'weight' => '48',
    'children' => array(
      0 => 'field_os2web_base_field_edi_tags',
      1 => 'field_os2web_base_field_loca_ref',
      2 => 'field_os2web_base_field_organiz',
      3 => 'field_os2web_base_field_politics',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_extras|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_general|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_os2web_base_group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Tekst',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_os2web_base_field_summary',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Tekst',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_os2web_base_group_general|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_hidden|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_os2web_base_group_hidden';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bruges_ikke';
  $field_group->data = array(
    'label' => 'Skjult',
    'weight' => '53',
    'children' => array(
      0 => 'field_os2web_base_field_rotate',
      1 => 'field_os2web_base_field_sourceid',
      2 => 'field_os2web_base_field_struct',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_hidden|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_hidden|node|os2web_base_gallery|form';
  $field_group->group_name = 'group_os2web_base_group_hidden';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skjult',
    'weight' => '6',
    'children' => array(
      0 => 'field_os2web_base_field_inh_colm',
      1 => 'field_os2web_base_field_lead_img',
      2 => 'field_os2web_base_field_parent',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_hidden|node|os2web_base_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_hidden|node|os2web_base_news|form';
  $field_group->group_name = 'group_os2web_base_group_hidden';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_settings';
  $field_group->data = array(
    'label' => 'Skjult',
    'weight' => '48',
    'children' => array(
      0 => 'field_os2web_base_field_add_info',
      1 => 'field_os2web_base_field_related',
      2 => 'field_os2web_base_field_rel_subj',
      3 => 'field_os2web_base_field_sourceid',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_hidden|node|os2web_base_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_images|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_os2web_base_group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Billeder og filer',
    'weight' => '6',
    'children' => array(
      0 => 'group_billede_tekst',
      1 => 'group_filer',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_images|node|os2web_base_contentpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_image|node|os2web_base_news|form';
  $field_group->group_name = 'group_os2web_base_group_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Billede',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Billede',
    ),
  );
  $export['group_os2web_base_group_image|node|os2web_base_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_settings|node|os2web_base_news|form';
  $field_group->group_name = 'group_os2web_base_group_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_news_tabs';
  $field_group->data = array(
    'label' => 'Indstillinger',
    'weight' => '3',
    'children' => array(
      0 => 'field_os2web_base_field_promote',
      1 => 'field_os2web_base_field_case',
      2 => 'field_os2web_base_field_doc',
      3 => 'path',
      4 => 'group_os2web_base_group_hidden',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Indstillinger',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_os2web_base_group_settings|node|os2web_base_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_taxono|node|os2web_base_gallery|form';
  $field_group->group_name = 'group_os2web_base_group_taxono';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taksonomi',
    'weight' => '4',
    'children' => array(
      0 => 'field_os2web_base_field_kle_ref',
      1 => 'field_os2web_base_field_loca_ref',
      2 => 'field_os2web_base_field_organiz',
      3 => 'field_os2web_base_field_edi_tags',
      4 => 'field_os2web_base_field_politics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_taxono|node|os2web_base_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_taxono|node|os2web_base_iframe|form';
  $field_group->group_name = 'group_os2web_base_group_taxono';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taksonomi',
    'weight' => '8',
    'children' => array(
      0 => 'field_os2web_base_field_kle_ref',
      1 => 'field_os2web_base_field_edi_tags',
      2 => 'field_os2web_base_field_organiz',
      3 => 'field_os2web_base_field_loca_ref',
      4 => 'field_os2web_base_field_politics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_os2web_base_group_taxono|node|os2web_base_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_taxono|node|os2web_base_news|form';
  $field_group->group_name = 'group_os2web_base_group_taxono';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_news_tabs';
  $field_group->data = array(
    'label' => 'Emneord',
    'weight' => '2',
    'children' => array(
      0 => 'field_os2web_base_field_edi_tags',
      1 => 'field_os2web_base_field_organiz',
      2 => 'field_os2web_base_field_politics',
      3 => 'field_os2web_base_field_kle_ref',
      4 => 'field_os2web_base_field_loca_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Emneord',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_os2web_base_group_taxono|node|os2web_base_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_group_text|node|os2web_base_news|form';
  $field_group->group_name = 'group_os2web_base_group_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_news_tabs';
  $field_group->data = array(
    'label' => 'Tekst',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_os2web_base_field_lead_img',
      2 => 'field_os2web_base_field_summary',
      3 => 'field_os2web_base_field_struct',
      4 => 'field_os2web_base_field_media',
      5 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Tekst',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_os2web_base_group_text|node|os2web_base_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_os2web_base_news_tabs|node|os2web_base_news|form';
  $field_group->group_name = 'group_os2web_base_news_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'News',
    'weight' => '0',
    'children' => array(
      0 => 'group_os2web_base_group_settings',
      1 => 'group_os2web_base_group_taxono',
      2 => 'group_os2web_base_group_text',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_os2web_base_news_tabs|node|os2web_base_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '7',
    'children' => array(
      0 => 'field_video',
      1 => 'field_videotekst',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_video|node|os2web_base_contentpage|form'] = $field_group;

  return $export;
}
