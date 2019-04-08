<?php
/**
 * @file
 * os2web_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function os2web_base_user_default_roles() {
  $roles = array();

  // Exported role: Administrator.
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => 9,
  );

  // Exported role: Kommunikation.
  $roles['Kommunikation'] = array(
    'name' => 'Kommunikation',
    'weight' => 4,
  );

  // Exported role: Student.
  $roles['Student'] = array(
    'name' => 'Student',
    'weight' => 2,
  );

  // Exported role: Webmaster.
  $roles['Webmaster'] = array(
    'name' => 'Webmaster',
    'weight' => 8,
  );

  return $roles;
}
