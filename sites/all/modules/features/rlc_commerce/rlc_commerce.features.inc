<?php
/**
 * @file
 * rlc_commerce.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function rlc_commerce_commerce_line_item_default_types() {
  $items = array(
    'business_card' => array(
      'name' => 'Business Card',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'camera_ready_business_card' => array(
      'name' => 'Camera Ready Business Card',
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
function rlc_commerce_commerce_product_default_types() {
  $items = array(
    'business_card' => array(
      'type' => 'business_card',
      'name' => 'Business Card',
      'description' => 'A customized One Sided business card.',
      'help' => '',
      'revision' => 1,
    ),
    'camera_ready_business_card' => array(
      'type' => 'camera_ready_business_card',
      'name' => 'Camera Ready Business Card',
      'description' => 'Business cards printed from customer provided artwork.',
      'help' => '',
      'revision' => 0,
    ),
    'two_sided_business_card' => array(
      'type' => 'two_sided_business_card',
      'name' => 'Two Sided Business Card',
      'description' => 'A customized Two Sided business card.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function rlc_commerce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rlc_commerce_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rlc_commerce_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Product display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
