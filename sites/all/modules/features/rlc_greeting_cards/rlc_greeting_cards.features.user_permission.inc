<?php
/**
 * @file
 * rlc_greeting_cards.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rlc_greeting_cards_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create commerce_product entities of bundle black_tie_collection'.
  $permissions['create commerce_product entities of bundle black_tie_collection'] = array(
    'name' => 'create commerce_product entities of bundle black_tie_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle pink_ribbon_collection'.
  $permissions['create commerce_product entities of bundle pink_ribbon_collection'] = array(
    'name' => 'create commerce_product entities of bundle pink_ribbon_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle silver_package'.
  $permissions['create commerce_product entities of bundle silver_package'] = array(
    'name' => 'create commerce_product entities of bundle silver_package',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle black_tie_collection'.
  $permissions['edit any commerce_product entity of bundle black_tie_collection'] = array(
    'name' => 'edit any commerce_product entity of bundle black_tie_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle pink_ribbon_collection'.
  $permissions['edit any commerce_product entity of bundle pink_ribbon_collection'] = array(
    'name' => 'edit any commerce_product entity of bundle pink_ribbon_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle silver_package'.
  $permissions['edit any commerce_product entity of bundle silver_package'] = array(
    'name' => 'edit any commerce_product entity of bundle silver_package',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle black_tie_collection'.
  $permissions['edit own commerce_product entities of bundle black_tie_collection'] = array(
    'name' => 'edit own commerce_product entities of bundle black_tie_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle pink_ribbon_collection'.
  $permissions['edit own commerce_product entities of bundle pink_ribbon_collection'] = array(
    'name' => 'edit own commerce_product entities of bundle pink_ribbon_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle silver_package'.
  $permissions['edit own commerce_product entities of bundle silver_package'] = array(
    'name' => 'edit own commerce_product entities of bundle silver_package',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle black_tie_collection'.
  $permissions['view any commerce_product entity of bundle black_tie_collection'] = array(
    'name' => 'view any commerce_product entity of bundle black_tie_collection',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle pink_ribbon_collection'.
  $permissions['view any commerce_product entity of bundle pink_ribbon_collection'] = array(
    'name' => 'view any commerce_product entity of bundle pink_ribbon_collection',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle silver_package'.
  $permissions['view any commerce_product entity of bundle silver_package'] = array(
    'name' => 'view any commerce_product entity of bundle silver_package',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle black_tie_collection'.
  $permissions['view own commerce_product entities of bundle black_tie_collection'] = array(
    'name' => 'view own commerce_product entities of bundle black_tie_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle pink_ribbon_collection'.
  $permissions['view own commerce_product entities of bundle pink_ribbon_collection'] = array(
    'name' => 'view own commerce_product entities of bundle pink_ribbon_collection',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle silver_package'.
  $permissions['view own commerce_product entities of bundle silver_package'] = array(
    'name' => 'view own commerce_product entities of bundle silver_package',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  return $permissions;
}
