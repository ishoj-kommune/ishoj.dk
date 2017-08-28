<?php
/**
 * @file
 * os2forms_frontend_app.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os2forms_frontend_app_user_default_permissions() {
  $permissions = array();

  // Exported permission: access print.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'print',
  );

  return $permissions;
}
