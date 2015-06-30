<?php
/**
 * @file
 * rlc_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rlc_rules_default_rules_configuration() {
  $items = array();
  $items['commerce_checkout_send_order_notification_e_mails_custom_'] = entity_import('rules_config', '{ "commerce_checkout_send_order_notification_e_mails_custom_" : {
      "LABEL" : "Send order notification e-mails (custom)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [
        "rules",
        "commerce_invoice_receipt",
        "php",
        "mimemail",
        "commerce_checkout"
      ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Thank you for your order at [site:name].",
            "message" : "Thank you for your order #[commerce-order:order-number] at [site:name].\\r\\n\\r\\nIf this is your first order with us, you will receive a separate e-mail with login instructions. You can view your order history with us at any time by logging into our website at:\\r\\n\\r\\n[site:login-url]\\r\\n\\r\\nYou can find the status of your current order at:\\r\\n\\r\\n[commerce-order:customer-url]\\r\\n\\r\\nYou should receive an emailed receipt shortly.\\r\\nPlease contact us if you have any questions about your order.",
            "language" : [ "commerce-order:state" ]
          }
        },
        { "commerce_invoice_receipt_action_mail" : {
            "commerce_order" : [ "commerce_order" ],
            "to" : "[commerce-order:owner] \\u003C[commerce-order:mail]\\u003E",
            "subject" : "[site:name]: Reciept for Order #[commerce-order:order-id]"
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Cfile\\u003E" },
            "PROVIDE" : { "variable_added" : { "file_list" : "File List" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_fetch_business_card_product_files" : {
                  "USING" : { "line_item" : [ "list-item" ] },
                  "PROVIDE" : {
                    "card_creator_front" : { "card_creator_front" : "Card Creator Front" },
                    "card_creator_back" : { "card_creator_back" : "Card Creator Back" }
                  }
                }
              },
              { "list_add" : { "list" : [ "file-list" ], "item" : [ "card-creator-front" ] } },
              { "list_add" : { "list" : [ "file-list" ], "item" : [ "card-creator-back" ] } },
              { "component_rules_fetch_camera_ready_product_files" : {
                  "USING" : { "line_item" : [ "list-item" ] },
                  "PROVIDE" : {
                    "camera_ready_front" : { "camera_ready_front" : "Camera Ready Front" },
                    "camera_ready_back" : { "camera_ready_back" : "Camera Ready Back" }
                  }
                }
              },
              { "list_add" : { "list" : [ "file-list" ], "item" : [ "camera-ready-front" ] } },
              { "list_add" : { "list" : [ "file-list" ], "item" : [ "camera-ready-back" ] } }
            ]
          }
        },
        { "mimemail" : {
            "key" : "Email Order to Admin",
            "to" : [ "site:mail" ],
            "subject" : "A new order #[commerce-order:order-number] has been placed at [site:name].",
            "body" : "A new order#[commerce-order:order-number] has been placed at [site:name] by [commerce-order:mail-username].\\r\\n\\r\\nView this order here:\\r\\n[commerce-order:url]\\/print",
            "attachments" : "\\u003C?php\\r\\nforeach ($file_list as $file) {\\r\\n  echo drupal_realpath($file-\\u003Euri) . \\u0022\\\\n\\u0022;\\r\\n}\\r\\n?\\u003E",
            "language" : [ "commerce-order:state" ]
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_1000'] = entity_import('rules_config', '{ "rules_calculate_price_for_1000" : {
      "LABEL" : "Calculate price for 1000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_card_stocks" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "10" } }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "commerce-line-item:field-card-stocks:field-price-1000:amount" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_10000'] = entity_import('rules_config', '{ "rules_calculate_price_for_10000" : {
      "LABEL" : "Calculate price for 10000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_card_stocks" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "15" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "9"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-1000:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_2000'] = entity_import('rules_config', '{ "rules_calculate_price_for_2000" : {
      "LABEL" : "Calculate price for 2000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_card_stocks" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "11" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-1000:amount" ],
              "op" : "+",
              "input_2" : [ "commerce-line-item:field-card-stocks:field-price-per-thousand:amount" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_3000'] = entity_import('rules_config', '{ "rules_calculate_price_for_3000" : {
      "LABEL" : "Calculate price for 3000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_card_stocks" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "12" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "2"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-1000:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_4000'] = entity_import('rules_config', '{ "rules_calculate_price_for_4000" : {
      "LABEL" : "Calculate price for 4000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_card_stocks" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "13" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "3"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-1000:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_500'] = entity_import('rules_config', '{ "rules_calculate_price_for_500" : {
      "LABEL" : "Calculate price for 500",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_card_stocks" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "9" } }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "commerce-line-item:field-card-stocks:field-price-500:amount" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_5000'] = entity_import('rules_config', '{ "rules_calculate_price_for_5000" : {
      "LABEL" : "Calculate price for 5000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_card_stocks" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "14" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "4"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-card-stocks:field-price-1000:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_two_sided_10000'] = entity_import('rules_config', '{ "rules_calculate_price_for_two_sided_10000" : {
      "LABEL" : "Calculate price for Two Sided 10000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_two_sided" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "15" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-two-sided" ], "value" : "16" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "9"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_two_sided_2000'] = entity_import('rules_config', '{ "rules_calculate_price_for_two_sided_2000" : {
      "LABEL" : "Calculate price for Two Sided 2000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_two_sided" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "11" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-two-sided" ], "value" : "16" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price:amount" ],
              "op" : "+",
              "input_2" : [ "commerce-line-item:field-two-sided:field-price-per-thousand:amount" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_two_sided_3000'] = entity_import('rules_config', '{ "rules_calculate_price_for_two_sided_3000" : {
      "LABEL" : "Calculate price for Two Sided 3000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_two_sided" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "12" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-two-sided" ], "value" : "16" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "2"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_two_sided_4000'] = entity_import('rules_config', '{ "rules_calculate_price_for_two_sided_4000" : {
      "LABEL" : "Calculate price for Two Sided 4000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_two_sided" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "13" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-two-sided" ], "value" : "16" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "3"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_two_sided_5000'] = entity_import('rules_config', '{ "rules_calculate_price_for_two_sided_5000" : {
      "LABEL" : "Calculate price for Two Sided 5000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_two_sided" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-quantity" ], "value" : "14" } },
        { "data_is" : { "data" : [ "commerce-line-item:field-two-sided" ], "value" : "16" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price-per-thousand:amount" ],
              "op" : "*",
              "input_2" : "4"
            },
            "PROVIDE" : { "result" : { "additional_cost" : "Additional Cost" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:field-two-sided:field-price:amount" ],
              "op" : "+",
              "input_2" : [ "additional-cost" ]
            },
            "PROVIDE" : { "result" : { "result" : "Calculation result" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "result" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_two_sided_500_or_1000'] = entity_import('rules_config', '{ "rules_calculate_price_for_two_sided_500_or_1000" : {
      "LABEL" : "Calculate price for Two Sided 500 or 1000",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_quantity" } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_two_sided" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:field-quantity" ],
            "op" : "IN",
            "value" : { "value" : { "9" : "9", "10" : "10" } }
          }
        },
        { "data_is" : { "data" : [ "commerce-line-item:field-two-sided" ], "value" : "16" } }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "commerce-line-item:field-two-sided:field-price:amount" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_customer_provided_artwork'] = entity_import('rules_config', '{ "rules_customer_provided_artwork" : {
      "LABEL" : "Customer Provided Artwork",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "field_camera_ready" } }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : "800",
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_fetch_business_card_product_files'] = entity_import('rules_config', '{ "rules_fetch_business_card_product_files" : {
      "LABEL" : "Fetch Business Card Product Files",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "card_creator_front" : { "label" : "Card Creator Front", "type" : "file", "parameter" : false },
        "card_creator_back" : { "label" : "Card Creator Back", "type" : "file", "parameter" : false }
      },
      "IF" : [
        { "data_is" : { "data" : [ "line-item:type" ], "value" : "business_card" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "file",
              "value" : [ "line-item:field-business-card-image:file" ]
            },
            "PROVIDE" : { "variable_added" : { "card_creator_front_file" : "Card Creator Front File" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "file",
              "value" : [ "line-item:field-business-card-image-back:file" ]
            },
            "PROVIDE" : { "variable_added" : { "card_creator_back_file" : "Card Creator Back File" } }
          }
        },
        { "data_set" : {
            "data" : [ "card-creator-front" ],
            "value" : [ "card-creator-front-file" ]
          }
        },
        { "data_set" : {
            "data" : [ "card-creator-back" ],
            "value" : [ "card-creator-back-file" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "card_creator_front", "card_creator_back" ]
    }
  }');
  $items['rules_fetch_camera_ready_product_files'] = entity_import('rules_config', '{ "rules_fetch_camera_ready_product_files" : {
      "LABEL" : "Fetch Camera Ready Product Files",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "camera_ready_front" : { "label" : "Camera Ready Front", "type" : "file", "parameter" : false },
        "camera_ready_back" : { "label" : "Camera Ready Back", "type" : "file", "parameter" : false }
      },
      "IF" : [
        { "data_is" : { "data" : [ "line-item:type" ], "value" : "camera_ready_business_card" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "file", "value" : [ "line-item:field-camera-ready:file" ] },
            "PROVIDE" : { "variable_added" : { "camera_ready_front_file" : "Camera Ready Front File" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "file",
              "value" : [ "line-item:field-camera-ready-back:file" ]
            },
            "PROVIDE" : { "variable_added" : { "camera_ready_back_file" : "Camera Ready Back File" } }
          }
        },
        { "data_set" : {
            "data" : [ "camera-ready-front" ],
            "value" : [ "camera-ready-front-file" ]
          }
        },
        { "data_set" : {
            "data" : [ "camera-ready-back" ],
            "value" : [ "camera-ready-back-file" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "camera_ready_front", "camera_ready_back" ]
    }
  }');
  return $items;
}
