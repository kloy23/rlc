<?php
/**
 * @file
 * rlc_greeting_cards.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function rlc_greeting_cards_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-commerce_display_path'.
  $field_instances['commerce_line_item-black_tie_collection_sp-commerce_display_path'] = array(
    'bundle' => 'black_tie_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_display_path',
    'label' => 'Display path',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-commerce_product'.
  $field_instances['commerce_line_item-black_tie_collection_sp-commerce_product'] = array(
    'bundle' => 'black_tie_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 2,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_product',
    'label' => 'Product',
    'required' => TRUE,
    'settings' => array(
      'field_injection' => TRUE,
      'referenceable_types' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_product_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'commerce_product/autocomplete',
        'size' => 60,
      ),
      'type' => 'commerce_product_reference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-commerce_total'.
  $field_instances['commerce_line_item-black_tie_collection_sp-commerce_total'] = array(
    'bundle' => 'black_tie_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_total',
    'label' => 'Total',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-commerce_unit_price'.
  $field_instances['commerce_line_item-black_tie_collection_sp-commerce_unit_price'] = array(
    'bundle' => 'black_tie_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_unit_price',
    'label' => 'Unit price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_1'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_1'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_1',
    'label' => 'Product 1',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_10'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_10'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_10',
    'label' => 'Product 10',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_10_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_10_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_10_quantity',
    'label' => 'Product 10 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_1_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_1_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_1_quantity',
    'label' => 'Product 1 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_2'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_2'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_2',
    'label' => 'Product 2',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_2_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_2_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_2_quantity',
    'label' => 'Product 2 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_3'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_3'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_3',
    'label' => 'Product 3',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_3_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_3_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_3_quantity',
    'label' => 'Product 3 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_4'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_4'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_4',
    'label' => 'Product 4',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_4_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_4_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_4_quantity',
    'label' => 'Product 4 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_5'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_5'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_5',
    'label' => 'Product 5',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_5_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_5_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_5_quantity',
    'label' => 'Product 5 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_6'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_6'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_6',
    'label' => 'Product 6',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_6_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_6_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_6_quantity',
    'label' => 'Product 6 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_7'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_7'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_7',
    'label' => 'Product 7',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_7_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_7_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_7_quantity',
    'label' => 'Product 7 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_8'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_8'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_8',
    'label' => 'Product 8',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_8_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_8_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_8_quantity',
    'label' => 'Product 8 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_9'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_9'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_9',
    'label' => 'Product 9',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 'black_tie_collection',
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 0,
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-black_tie_collection_sp-field_product_9_quantity'.
  $field_instances['commerce_line_item-black_tie_collection_sp-field_product_9_quantity'] = array(
    'bundle' => 'black_tie_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_9_quantity',
    'label' => 'Product 9 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-greeting_card-commerce_display_path'.
  $field_instances['commerce_line_item-greeting_card-commerce_display_path'] = array(
    'bundle' => 'greeting_card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_display_path',
    'label' => 'Display path',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-greeting_card-commerce_product'.
  $field_instances['commerce_line_item-greeting_card-commerce_product'] = array(
    'bundle' => 'greeting_card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => 0,
          'default_quantity' => 1,
          'line_item_type' => 'greeting_card',
          'show_quantity' => 0,
          'show_single_product_attributes' => 0,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 2,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_product',
    'label' => 'Product',
    'required' => TRUE,
    'settings' => array(
      'field_injection' => TRUE,
      'referenceable_types' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_product_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'commerce_product/autocomplete',
        'size' => 60,
      ),
      'type' => 'commerce_product_reference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'commerce_line_item-greeting_card-commerce_total'.
  $field_instances['commerce_line_item-greeting_card-commerce_total'] = array(
    'bundle' => 'greeting_card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_total',
    'label' => 'Total',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-greeting_card-commerce_unit_price'.
  $field_instances['commerce_line_item-greeting_card-commerce_unit_price'] = array(
    'bundle' => 'greeting_card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_unit_price',
    'label' => 'Unit price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-commerce_display_path'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-commerce_display_path'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_display_path',
    'label' => 'Display path',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-commerce_product'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-commerce_product'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 2,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_product',
    'label' => 'Product',
    'required' => TRUE,
    'settings' => array(
      'field_injection' => TRUE,
      'referenceable_types' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_product_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'commerce_product/autocomplete',
        'size' => 60,
      ),
      'type' => 'commerce_product_reference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-commerce_total'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-commerce_total'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_total',
    'label' => 'Total',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-commerce_unit_price'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-commerce_unit_price'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'commerce_unit_price',
    'label' => 'Unit price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_1'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_1'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_1',
    'label' => 'Product 1',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_10'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_10'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_10',
    'label' => 'Product 10',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 24,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_10_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_10_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_10_quantity',
    'label' => 'Product 10 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 25,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_1_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_1_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_1_quantity',
    'label' => 'Product 1 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_2'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_2'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_2',
    'label' => 'Product 2',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_2_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_2_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_2_quantity',
    'label' => 'Product 2 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_3'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_3'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_3',
    'label' => 'Product 3',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_3_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_3_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_3_quantity',
    'label' => 'Product 3 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_4'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_4'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_4',
    'label' => 'Product 4',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_4_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_4_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_4_quantity',
    'label' => 'Product 4 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_5'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_5'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_5',
    'label' => 'Product 5',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_5_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_5_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_5_quantity',
    'label' => 'Product 5 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_6'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_6'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_6',
    'label' => 'Product 6',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_6_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_6_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_6_quantity',
    'label' => 'Product 6 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_7'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_7'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_7',
    'label' => 'Product 7',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_7_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_7_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_7_quantity',
    'label' => 'Product 7 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_8'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_8'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_8',
    'label' => 'Product 8',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_8_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_8_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_8_quantity',
    'label' => 'Product 8 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_9'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_9'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_9',
    'label' => 'Product 9',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'black_tie_collection' => 0,
        'business_card' => 0,
        'camera_ready_business_card' => 0,
        'company_business_card' => 0,
        'pink_ribbon_collection' => 'pink_ribbon_collection',
        'product' => 0,
        'silver_package' => 0,
        'spiritual_book' => 0,
        'spiritual_card' => 0,
        'two_sided_business_card' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 22,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-pink_ribbon_collection_sp-field_product_9_quantity'.
  $field_instances['commerce_line_item-pink_ribbon_collection_sp-field_product_9_quantity'] = array(
    'bundle' => 'pink_ribbon_collection_sp',
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_product_9_quantity',
    'label' => 'Product 9 Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 23,
    ),
  );

  // Exported field_instance:
  // 'commerce_product-black_tie_collection-commerce_price'.
  $field_instances['commerce_product-black_tie_collection-commerce_price'] = array(
    'bundle' => 'black_tie_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'commerce_line_item_display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'commerce_line_item_token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_rss' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_index' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_result' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'commerce_price',
    'label' => 'Price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'commerce_product-black_tie_collection-field_product_image'.
  $field_instances['commerce_product-black_tie_collection-field_product_image'] = array(
    'bundle' => 'black_tie_collection',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_product_image',
    'label' => 'Product Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'product_images/greeting_cards/black_tie_collection',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 37,
    ),
  );

  // Exported field_instance:
  // 'commerce_product-pink_ribbon_collection-commerce_price'.
  $field_instances['commerce_product-pink_ribbon_collection-commerce_price'] = array(
    'bundle' => 'pink_ribbon_collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'commerce_line_item_display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'commerce_line_item_token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_rss' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_index' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_result' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'commerce_price',
    'label' => 'Price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'commerce_product-pink_ribbon_collection-field_product_image'.
  $field_instances['commerce_product-pink_ribbon_collection-field_product_image'] = array(
    'bundle' => 'pink_ribbon_collection',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_product_image',
    'label' => 'Product Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'product_images/greeting_cards/pink_ribbon_collection',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'commerce_product-silver_package-commerce_price'.
  $field_instances['commerce_product-silver_package-commerce_price'] = array(
    'bundle' => 'silver_package',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'commerce_line_item_display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'commerce_line_item_token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_rss' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_index' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_result' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'commerce_price',
    'label' => 'Price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'commerce_product-silver_package-field_product_image'.
  $field_instances['commerce_product-silver_package-field_product_image'] = array(
    'bundle' => 'silver_package',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_product_image',
    'label' => 'Product Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'product_images/greeting_cards/silver_package',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 37,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Display path');
  t('Price');
  t('Product');
  t('Product 1');
  t('Product 1 Quantity');
  t('Product 10');
  t('Product 10 Quantity');
  t('Product 2');
  t('Product 2 Quantity');
  t('Product 3');
  t('Product 3 Quantity');
  t('Product 4');
  t('Product 4 Quantity');
  t('Product 5');
  t('Product 5 Quantity');
  t('Product 6');
  t('Product 6 Quantity');
  t('Product 7');
  t('Product 7 Quantity');
  t('Product 8');
  t('Product 8 Quantity');
  t('Product 9');
  t('Product 9 Quantity');
  t('Product Image');
  t('Total');
  t('Unit price');

  return $field_instances;
}
