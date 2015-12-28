<?php
/**
 * @file
 * rlc_spiritual_products.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rlc_spiritual_products_default_rules_configuration() {
  $items = array();
  $items['rlc_rules_calculate_shipping_for_spiritual_books'] = entity_import('rules_config', '{ "rlc_rules_calculate_shipping_for_spiritual_books" : {
      "LABEL" : "Calculate Shipping for Spiritual Books",
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
              { "component_rlc_rules_fetch_quantity_of_spiritual_books" : {
                  "USING" : { "product_line_item" : [ "list-item" ], "product_quantity" : "0" },
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
        { "component_rlc_rules_calculate_shipping_price_for_spiritual_books" : {
            "USING" : {
              "quantity" : [ "total-quantity" ],
              "price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
            },
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
  $items['rlc_rules_calculate_shipping_for_spiritual_cards'] = entity_import('rules_config', '{ "rlc_rules_calculate_shipping_for_spiritual_cards" : {
      "LABEL" : "Calculate Shipping for Spiritual Cards",
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
              { "component_rlc_rules_fetch_quantity_of_spiritual_cards" : {
                  "USING" : { "product_line_item" : [ "list-item" ], "product_quantity" : "0" },
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
        { "component_rlc_rules_calculate_shipping_price_for_spiritual_cards" : {
            "USING" : {
              "quantity" : [ "total-quantity" ],
              "price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
            },
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
  $items['rlc_rules_calculate_shipping_price_for_spiritual_books'] = entity_import('rules_config', '{ "rlc_rules_calculate_shipping_price_for_spiritual_books" : {
      "LABEL" : "Calculate Shipping Price for Spiritual Books",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "quantity" : { "label" : "quantity", "type" : "integer" },
        "price" : { "label" : "price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "result" : { "result" : "Calculation result" } },
            "DO" : [
              { "data_calc" : {
                  "USING" : { "input_1" : [ "quantity" ], "op" : "*", "input_2" : "550" },
                  "PROVIDE" : { "result" : { "result" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "price:amount" ], "value" : [ "result" ] } }
            ],
            "LABEL" : "Rate for Spiritual Books"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "price" ]
    }
  }');
  $items['rlc_rules_calculate_shipping_price_for_spiritual_cards'] = entity_import('rules_config', '{ "rlc_rules_calculate_shipping_price_for_spiritual_cards" : {
      "LABEL" : "Calculate Shipping Price for Spiritual Cards",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "quantity" : { "label" : "quantity", "type" : "integer" },
        "price" : { "label" : "price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003E", "value" : "0" } }
            ],
            "DO" : [ { "data_set" : { "data" : [ "price:amount" ], "value" : "550" } } ],
            "LABEL" : "Rate for Spiritual Cards"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "price" ]
    }
  }');
  $items['rlc_rules_fetch_quantity_of_spiritual_books'] = entity_import('rules_config', '{ "rlc_rules_fetch_quantity_of_spiritual_books" : {
      "LABEL" : "Fetch Quantity of Spiritual Books",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "product_line_item" : { "label" : "Product Line Item", "type" : "commerce_line_item" },
        "product_quantity" : { "label" : "Quantity", "type" : "integer" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "product-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "spiritual_book" : "spiritual_book" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "product-line-item:quantity" ] },
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
  $items['rlc_rules_fetch_quantity_of_spiritual_cards'] = entity_import('rules_config', '{ "rlc_rules_fetch_quantity_of_spiritual_cards" : {
      "LABEL" : "Fetch Quantity of Spiritual Cards",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "product_line_item" : { "label" : "Product Line Item", "type" : "commerce_line_item" },
        "product_quantity" : { "label" : "Quantity", "type" : "integer" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "product-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "spiritual_card" : "spiritual_card" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "product-line-item:quantity" ] },
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
  $items['rules_calculate_shipping_for_spiritual_notepads'] = entity_import('rules_config', '{ "rules_calculate_shipping_for_spiritual_notepads" : {
      "LABEL" : "Calculate Shipping for Spiritual Notepads",
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
              { "component_rules_fetch_quantity_of_spiritual_notepads" : {
                  "USING" : { "product_line_item" : [ "list-item" ], "product_quantity" : "0" },
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
        { "component_rules_calculate_shipping_price_for_spiritual_notepads" : {
            "USING" : {
              "quantity" : [ "total-quantity" ],
              "price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
            },
            "PROVIDE" : { "price" : { "price" : "price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "price:amount" ],
            "component_name" : "flat_rate_flat_rate_shipping",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_shipping_price_for_spiritual_notepads'] = entity_import('rules_config', '{ "rules_calculate_shipping_price_for_spiritual_notepads" : {
      "LABEL" : "Calculate Shipping Price for Spiritual Notepads",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "quantity" : { "label" : "quantity", "type" : "integer" },
        "price" : { "label" : "price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "result" : { "result" : "Calculation result" } },
            "IF" : [
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003E", "value" : "0" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : { "input_1" : [ "quantity" ], "op" : "*", "input_2" : "800" },
                  "PROVIDE" : { "result" : { "result" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "price:amount" ], "value" : [ "result" ] } }
            ],
            "LABEL" : "Rate for Spiritual Notepads"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "price" ]
    }
  }');
  $items['rules_fetch_quantity_of_spiritual_notepads'] = entity_import('rules_config', '{ "rules_fetch_quantity_of_spiritual_notepads" : {
      "LABEL" : "Fetch Quantity of Spiritual Notepads",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "product_line_item" : { "label" : "Product Line Item", "type" : "commerce_line_item" },
        "product_quantity" : { "label" : "Quantity", "type" : "integer" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "product-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "spiritual_notepad" : "spiritual_notepad" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "product-line-item:quantity" ] },
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
