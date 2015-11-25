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
    'black_tie_collection_sp' => array(
      'name' => 'Black Tie Collection - SP',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'greeting_card' => array(
      'name' => 'Greeting Card',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'pink_ribbon_collection_sp' => array(
      'name' => 'Pink Ribbon Collection - SP',
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
    'black_tie_collection' => array(
      'type' => 'black_tie_collection',
      'name' => 'Black Tie Collection',
      'description' => 'Greeting Cards that belong to the Black Tie Collection.',
      'help' => '',
      'revision' => 0,
    ),
    'pink_ribbon_collection' => array(
      'type' => 'pink_ribbon_collection',
      'name' => 'Pink Ribbon Collection',
      'description' => 'Greeting Cards that belong to the Pink Ribbon Collection.',
      'help' => '',
      'revision' => 0,
    ),
    'silver_package' => array(
      'type' => 'silver_package',
      'name' => 'Silver Package',
      'description' => 'Allows users to select a total of 10 packs to order at a discounted price.',
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
