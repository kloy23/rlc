<?php
/**
 * @file
 * rlc_commerce.features.inc
 */

/**
 * Implements hook_commerce_flat_rate_default_services().
 */
function rlc_commerce_commerce_flat_rate_default_services() {
  $items = array(
    'flat_rate_shipping' => array(
      'name' => 'flat_rate_shipping',
      'base' => 'flat_rate_shipping',
      'display_title' => 'Flat Rate Shipping',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_flat_rate_shipping',
      'weight' => 0,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'flat_rate_shipping_details_form',
        'details_form_validate' => 'flat_rate_shipping_details_form_validate',
        'details_form_submit' => 'flat_rate_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Flat Rate Shipping',
      'base_rate' => array(
        'amount' => 0,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
      'is_features' => TRUE,
    ),
  );
  return $items;
}

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
    'company_business_card' => array(
      'name' => 'Company Business Card',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
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
    'company_business_card' => array(
      'type' => 'company_business_card',
      'name' => 'Company Business Card',
      'description' => 'A company specific business card.',
      'help' => '',
      'revision' => 0,
    ),
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
    'custom_artwork_product_display' => array(
      'name' => t('Custom Artwork Product Display'),
      'base' => 'node_content',
      'description' => t('The product display for Camera Ready Business Cards.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_display' => array(
      'name' => t('Product display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'spiritual_card_product_display' => array(
      'name' => t('Spiritual Card Product Display'),
      'base' => 'node_content',
      'description' => t('The Product Display for Spiritual Cards'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
