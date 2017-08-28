<?php
/**
 * @file
 * os2forms_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os2forms_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Sektionsredaktør' => 'Sektionsredaktør',
      'Site-redaktør' => 'Site-redaktør',
      'Webmaster' => 'Webmaster',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Site-redaktør' => 'Site-redaktør',
      'Webmaster' => 'Webmaster',
      'os2forms' => 'os2forms',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Sektionsredaktør' => 'Sektionsredaktør',
      'Site-redaktør' => 'Site-redaktør',
      'Webmaster' => 'Webmaster',
      'os2forms' => 'os2forms',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'Sektionsredaktør' => 'Sektionsredaktør',
      'Site-redaktør' => 'Site-redaktør',
      'Webmaster' => 'Webmaster',
      'os2forms' => 'os2forms',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Sektionsredaktør' => 'Sektionsredaktør',
      'Site-redaktør' => 'Site-redaktør',
      'Webmaster' => 'Webmaster',
      'os2forms' => 'os2forms',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'Sektionsredaktør' => 'Sektionsredaktør',
      'Site-redaktør' => 'Site-redaktør',
      'Webmaster' => 'Webmaster',
      'os2forms' => 'os2forms',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'Sektionsredaktør' => 'Sektionsredaktør',
      'Site-redaktør' => 'Site-redaktør',
      'Webmaster' => 'Webmaster',
      'os2forms' => 'os2forms',
    ),
    'module' => 'webform',
  );

  return $permissions;
}
