<?php
/**
 * @file
 * rlc_business_cards.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rlc_business_cards_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create commerce_product entities of bundle business_card'.
  $permissions['create commerce_product entities of bundle business_card'] = array(
    'name' => 'create commerce_product entities of bundle business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle camera_ready_business_card'.
  $permissions['create commerce_product entities of bundle camera_ready_business_card'] = array(
    'name' => 'create commerce_product entities of bundle camera_ready_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle company_business_card'.
  $permissions['create commerce_product entities of bundle company_business_card'] = array(
    'name' => 'create commerce_product entities of bundle company_business_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle two_sided_business_card'.
  $permissions['create commerce_product entities of bundle two_sided_business_card'] = array(
    'name' => 'create commerce_product entities of bundle two_sided_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle business_card'.
  $permissions['edit any commerce_product entity of bundle business_card'] = array(
    'name' => 'edit any commerce_product entity of bundle business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle camera_ready_business_card'.
  $permissions['edit any commerce_product entity of bundle camera_ready_business_card'] = array(
    'name' => 'edit any commerce_product entity of bundle camera_ready_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle company_business_card'.
  $permissions['edit any commerce_product entity of bundle company_business_card'] = array(
    'name' => 'edit any commerce_product entity of bundle company_business_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle two_sided_business_card'.
  $permissions['edit any commerce_product entity of bundle two_sided_business_card'] = array(
    'name' => 'edit any commerce_product entity of bundle two_sided_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle business_card'.
  $permissions['edit own commerce_product entities of bundle business_card'] = array(
    'name' => 'edit own commerce_product entities of bundle business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle camera_ready_business_card'.
  $permissions['edit own commerce_product entities of bundle camera_ready_business_card'] = array(
    'name' => 'edit own commerce_product entities of bundle camera_ready_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle company_business_card'.
  $permissions['edit own commerce_product entities of bundle company_business_card'] = array(
    'name' => 'edit own commerce_product entities of bundle company_business_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle two_sided_business_card'.
  $permissions['edit own commerce_product entities of bundle two_sided_business_card'] = array(
    'name' => 'edit own commerce_product entities of bundle two_sided_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle business_card'.
  $permissions['view any commerce_product entity of bundle business_card'] = array(
    'name' => 'view any commerce_product entity of bundle business_card',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle camera_ready_business_card'.
  $permissions['view any commerce_product entity of bundle camera_ready_business_card'] = array(
    'name' => 'view any commerce_product entity of bundle camera_ready_business_card',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle company_business_card'.
  $permissions['view any commerce_product entity of bundle company_business_card'] = array(
    'name' => 'view any commerce_product entity of bundle company_business_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle two_sided_business_card'.
  $permissions['view any commerce_product entity of bundle two_sided_business_card'] = array(
    'name' => 'view any commerce_product entity of bundle two_sided_business_card',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle business_card'.
  $permissions['view own commerce_product entities of bundle business_card'] = array(
    'name' => 'view own commerce_product entities of bundle business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle camera_ready_business_card'.
  $permissions['view own commerce_product entities of bundle camera_ready_business_card'] = array(
    'name' => 'view own commerce_product entities of bundle camera_ready_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle company_business_card'.
  $permissions['view own commerce_product entities of bundle company_business_card'] = array(
    'name' => 'view own commerce_product entities of bundle company_business_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle two_sided_business_card'.
  $permissions['view own commerce_product entities of bundle two_sided_business_card'] = array(
    'name' => 'view own commerce_product entities of bundle two_sided_business_card',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  return $permissions;
}
