<?php
/**
 * @file
 * rlc_spiritual_products.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function rlc_spiritual_products_commerce_line_item_default_types() {
  $items = array(
    'spiritual_book' => array(
      'name' => 'Spiritual Book',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'spiritual_card' => array(
      'name' => 'Spiritual Card',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function rlc_spiritual_products_commerce_product_default_types() {
  $items = array(
    'spiritual_book' => array(
      'type' => 'spiritual_book',
      'name' => 'Spiritual Book',
      'description' => 'Uncustomizable spiritual books.',
      'help' => '',
      'revision' => 1,
    ),
    'spiritual_card' => array(
      'type' => 'spiritual_card',
      'name' => 'Spiritual Card',
      'description' => 'Uncustomizable spiritual business cards.',
      'help' => '',
      'revision' => 0,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function rlc_spiritual_products_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rlc_spiritual_products_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
