<?php
/**
 * @file
 * rlc_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rlc_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any commerce_product entity of bundle spiritual_book'.
  $permissions['view any commerce_product entity of bundle spiritual_book'] = array(
    'name' => 'view any commerce_product entity of bundle spiritual_book',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle spiritual_card'.
  $permissions['view any commerce_product entity of bundle spiritual_card'] = array(
    'name' => 'view any commerce_product entity of bundle spiritual_card',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  return $permissions;
}
