<?php
/**
 * @file
 * rlc_greeting_cards.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rlc_greeting_cards_default_rules_configuration() {
  $items = array();
  $items['rlc_rules_calculate_shipping_for_greeting_cards'] = entity_import('rules_config', '{ "rlc_rules_calculate_shipping_for_greeting_cards" : {
      "LABEL" : "Calculate Shipping for Greeting Cards",
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
              { "component_rlc_rules_fetch_quantity_of_greeting_cards" : {
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
        { "component_rlc_rules_calculate_shipping_price_for_greeting_cards" : {
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
  $items['rlc_rules_calculate_shipping_price_for_greeting_cards'] = entity_import('rules_config', '{ "rlc_rules_calculate_shipping_price_for_greeting_cards" : {
      "LABEL" : "Calculate Shipping Price for Greeting Cards",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "quantity" : { "label" : "quantity", "type" : "integer" },
        "price" : { "label" : "price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [ { "data_is" : { "data" : [ "quantity" ], "value" : "1" } } ],
            "DO" : [ { "data_set" : { "data" : [ "price:amount" ], "value" : "700" } } ],
            "LABEL" : "One Pack"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "multiple" : "Calculation result",
                "additional_cost" : "Calculation result",
                "shipping_cost" : "Calculation result"
              }
            },
            "IF" : [
              { "data_is" : { "data" : [ "quantity" ], "op" : "\\u003E", "value" : "1" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : { "input_1" : [ "quantity" ], "op" : "-", "input_2" : "1" },
                  "PROVIDE" : { "result" : { "multiple" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : { "input_1" : [ "multiple" ], "op" : "*", "input_2" : "250" },
                  "PROVIDE" : { "result" : { "additional_cost" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : { "input_1" : [ "additional-cost" ], "op" : "+", "input_2" : "700" },
                  "PROVIDE" : { "result" : { "shipping_cost" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "price:amount" ], "value" : [ "shipping-cost" ] } }
            ],
            "LABEL" : "More Than One"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "price" ]
    }
  }');
  $items['rlc_rules_fetch_quantity_of_greeting_cards'] = entity_import('rules_config', '{ "rlc_rules_fetch_quantity_of_greeting_cards" : {
      "LABEL" : "Fetch Quantity of Greeting Cards",
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
            "bundle" : { "value" : { "greeting_card" : "greeting_card" } }
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
  $items['rules_calculate_shipping_for_silver_package'] = entity_import('rules_config', '{ "rules_calculate_shipping_for_silver_package" : {
      "LABEL" : "Calculate Shipping for Silver Package",
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
              { "component_rules_fetch_quantity_of_silver_packages" : {
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
        { "component_rules_calculate_shipping_price_for_silver_packages" : {
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
  $items['rules_calculate_shipping_price_for_silver_packages'] = entity_import('rules_config', '{ "rules_calculate_shipping_price_for_silver_packages" : {
      "LABEL" : "Calculate Shipping Price for Silver Packages",
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
                  "USING" : { "input_1" : [ "quantity" ], "op" : "*", "input_2" : "1500" },
                  "PROVIDE" : { "result" : { "result" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "price:amount" ], "value" : [ "result" ] } }
            ],
            "LABEL" : "Rate for Silver Packages"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "price" ]
    }
  }');
  $items['rules_fetch_quantity_of_silver_packages'] = entity_import('rules_config', '{ "rules_fetch_quantity_of_silver_packages" : {
      "LABEL" : "Fetch Quantity of Silver Packages",
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
            "bundle" : { "value" : {
                "black_tie_collection_sp" : "black_tie_collection_sp",
                "pink_ribbon_collection_sp" : "pink_ribbon_collection_sp"
              }
            }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "product-line-item:quantity" ] },
            "PROVIDE" : { "variable_added" : { "quantity_text" : "Quantity Text" } }
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
