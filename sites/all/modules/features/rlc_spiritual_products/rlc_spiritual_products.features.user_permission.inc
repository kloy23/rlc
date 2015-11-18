<?php
/**
 * @file
 * rlc_spiritual_products.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rlc_spiritual_products_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create commerce_product entities of bundle spiritual_book'.
  $permissions['create commerce_product entities of bundle spiritual_book'] = array(
    'name' => 'create commerce_product entities of bundle spiritual_book',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle spiritual_card'.
  $permissions['create commerce_product entities of bundle spiritual_card'] = array(
    'name' => 'create commerce_product entities of bundle spiritual_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle spiritual_book'.
  $permissions['edit any commerce_product entity of bundle spiritual_book'] = array(
    'name' => 'edit any commerce_product entity of bundle spiritual_book',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle spiritual_card'.
  $permissions['edit any commerce_product entity of bundle spiritual_card'] = array(
    'name' => 'edit any commerce_product entity of bundle spiritual_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle spiritual_book'.
  $permissions['edit own commerce_product entities of bundle spiritual_book'] = array(
    'name' => 'edit own commerce_product entities of bundle spiritual_book',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle spiritual_card'.
  $permissions['edit own commerce_product entities of bundle spiritual_card'] = array(
    'name' => 'edit own commerce_product entities of bundle spiritual_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

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

  // Exported permission: 'view own commerce_product entities of bundle spiritual_book'.
  $permissions['view own commerce_product entities of bundle spiritual_book'] = array(
    'name' => 'view own commerce_product entities of bundle spiritual_book',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle spiritual_card'.
  $permissions['view own commerce_product entities of bundle spiritual_card'] = array(
    'name' => 'view own commerce_product entities of bundle spiritual_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  return $permissions;
}
