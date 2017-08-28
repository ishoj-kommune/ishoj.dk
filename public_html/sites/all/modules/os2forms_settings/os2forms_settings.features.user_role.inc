<?php
/**
 * @file
 * os2forms_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function os2forms_settings_user_default_roles() {
  $roles = array();

  // Exported role: os2forms.
  $roles['os2forms'] = array(
    'name' => 'os2forms',
    'weight' => 4,
  );

  return $roles;
}
