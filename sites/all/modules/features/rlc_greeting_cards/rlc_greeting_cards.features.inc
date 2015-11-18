<?php
/**
 * @file
 * rlc_greeting_cards.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function rlc_greeting_cards_commerce_line_item_default_types() {
  $items = array(
    'greeting_card' => array(
      'name' => 'Greeting Card',
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
function rlc_greeting_cards_commerce_product_default_types() {
  $items = array(
    'greeting_card' => array(
      'type' => 'greeting_card',
      'name' => 'Greeting Card',
      'description' => 'Uncustomizable greeting cards.',
      'help' => '',
      'revision' => 0,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function rlc_greeting_cards_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rlc_greeting_cards_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
