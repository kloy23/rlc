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

  // Exported permission: 'create commerce_product entities of bundle greeting_card'.
  $permissions['create commerce_product entities of bundle greeting_card'] = array(
    'name' => 'create commerce_product entities of bundle greeting_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle greeting_card'.
  $permissions['edit any commerce_product entity of bundle greeting_card'] = array(
    'name' => 'edit any commerce_product entity of bundle greeting_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle greeting_card'.
  $permissions['edit own commerce_product entities of bundle greeting_card'] = array(
    'name' => 'edit own commerce_product entities of bundle greeting_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle greeting_card'.
  $permissions['view any commerce_product entity of bundle greeting_card'] = array(
    'name' => 'view any commerce_product entity of bundle greeting_card',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle greeting_card'.
  $permissions['view own commerce_product entities of bundle greeting_card'] = array(
    'name' => 'view own commerce_product entities of bundle greeting_card',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  return $permissions;
}
