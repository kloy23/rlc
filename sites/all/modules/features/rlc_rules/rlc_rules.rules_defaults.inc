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
        "php",
        "mimemail",
        "commerce_invoice_receipt",
        "commerce_checkout"
      ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Thank you for your order at [site:name].",
            "message" : "Thank you for your order #[commerce-order:order-number] at [site:name].\\r\\n\\r\\nIf this is your first order with us, you will receive a separate e-mail with login instructions. You can view your order history with us at any time by logging into our website at:\\r\\n\\r\\n[site:login-url]\\r\\n\\r\\nYou can find the status of your current order at:\\r\\n\\r\\n[commerce-order:customer-url]\\r\\n\\r\\nYou should receive an emailed receipt shortly.\\r\\nPlease contact us if you have any questions about your order.",
            "from" : "[site:name] \\u003C[site:mail]\\u003E",
            "language" : [ "commerce-order:state" ]
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
            "body" : "A new order#[commerce-order:order-number] has been placed at [site:name] by [commerce-order:owner].\\r\\n\\r\\nView this order here:\\r\\n[commerce-order:url]\\/print",
            "attachments" : "\\u003C?php\\r\\nforeach ($file_list as $file) {\\r\\n  $realpath = drupal_realpath($file-\\u003Euri);\\r\\n  $path = str_replace($_SERVER[\\u0027DOCUMENT_ROOT\\u0027].\\u0027\\/\\u0027,\\u0027\\u0027,$realpath);\\r\\n  echo $path . \\u0022\\\\n\\u0022;\\r\\n}\\r\\n?\\u003E",
            "language" : [ "commerce-order:state" ]
          }
        },
        { "commerce_invoice_receipt_action_mail" : {
            "commerce_order" : [ "commerce_order" ],
            "to" : "[commerce-order:owner] \\u003C[commerce-order:mail]\\u003E",
            "subject" : "[site:name]: Receipt for Order #[commerce-order:order-id]"
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
  $items['rules_calculate_shipping_based_on_products'] = entity_import('rules_config', '{ "rules_calculate_shipping_based_on_products" : {
      "LABEL" : "Calculate Shipping",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_shipping" ],
      "ON" : { "commerce_shipping_calculate_rate" : [] },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "0" },
            "PROVIDE" : { "variable_added" : { "total_quantity" : "Total Quantity" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-line-item:order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_fetch_quantity" : {
                  "USING" : { "product_line_item" : [ "list-item" ] },
                  "PROVIDE" : { "product_quantity" : { "product_quantity" : "Quantity" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "total-quantity" ],
                    "op" : "+",
                    "input_2" : [ "product-quantity" ]
                  },
                  "PROVIDE" : { "result" : { "result" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "total-quantity" ], "value" : [ "result" ] } }
            ]
          }
        },
        { "component_rules_calculate_shipping_price" : {
            "USING" : { "quantity" : [ "total-quantity" ] },
            "PROVIDE" : { "price" : { "price" : "price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce-line-item" ],
            "amount" : [ "price:amount" ],
            "component_name" : "flat_rate_flat_rate_shipping",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_shipping_price'] = entity_import('rules_config', '{ "rules_calculate_shipping_price" : {
      "LABEL" : "Calculate Shipping Price",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "quantity" : { "label" : "quantity", "type" : "integer" },
        "price" : { "label" : "price", "type" : "commerce_price", "parameter" : false }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [ { "data_is" : { "data" : [ "quantity" ], "value" : "500" } } ],
            "DO" : [ { "data_set" : { "data" : [ "price:amount" ], "value" : "700" } } ],
            "LABEL" : "Rate for 500"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003E", "value" : "999" } },
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003C", "value" : "2001" } }
            ],
            "DO" : [ { "data_set" : { "data" : [ "price:amount" ], "value" : "825" } } ],
            "LABEL" : "Rate for 1000 - 2000"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003E", "value" : "2001" } },
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003C", "value" : "4001" } }
            ],
            "DO" : [ { "data_set" : { "data" : [ "price:amount" ], "value" : "1125" } } ],
            "LABEL" : "Rate for 2500 - 4000"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003E", "value" : "4001" } },
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003C", "value" : "10001" } }
            ],
            "DO" : [ { "data_set" : { "data" : [ "price:amount" ], "value" : "1500" } } ],
            "LABEL" : "Rate for 4500 - 10000"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003E", "value" : "10001" } }
            ],
            "DO" : [
              { "drupal_message" : {
                  "message" : "We will contact you with a shipping quote on any order over 10,000!",
                  "type" : "warning"
                }
              }
            ],
            "LABEL" : "Rate over 10k"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "price" ]
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
              "value" : [ "line-item:field-print-ready-front:file" ]
            },
            "PROVIDE" : { "variable_added" : { "card_creator_front_file" : "Card Creator Front File" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "file", "value" : [ "line-item:field-print-ready-back:file" ] },
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
  $items['rules_fetch_quantity'] = entity_import('rules_config', '{ "rules_fetch_quantity" : {
      "LABEL" : "Fetch Quantity",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "product_line_item" : { "label" : "Product Line Item", "type" : "commerce_line_item" },
        "product_quantity" : { "label" : "Quantity", "type" : "integer", "parameter" : false }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "product-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : {
                "business_card" : "business_card",
                "camera_ready_business_card" : "camera_ready_business_card"
              }
            }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "product-line-item:field-quantity:name" ] },
            "PROVIDE" : { "variable_added" : { "quantity_text" : "quantity_text" } }
          }
        },
        { "data_convert" : {
            "USING" : { "type" : "integer", "value" : [ "quantity-text" ] },
            "PROVIDE" : { "conversion_result" : { "conversion_result" : "Conversion result" } }
          }
        },
        { "data_set" : { "data" : [ "product-quantity" ], "value" : [ "conversion-result" ] } }
      ],
      "PROVIDES VARIABLES" : [ "product_quantity" ]
    }
  }');
  return $items;
}
