<?php
/**
 * @file
 * rlc_commerce.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rlc_commerce_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'configure store'.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce',
  );

  return $permissions;
}
