<?php
/**
 * @file
 * card_creator_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function card_creator_rules_default_rules_configuration() {
  $items = array();
  $items['rules_add_new_business_card_product_to_cart'] = entity_import('rules_config', '{ "rules_add_new_business_card_product_to_cart" : {
      "LABEL" : "Add new business card product to cart",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart", "rules", "entity" ],
      "ON" : { "commerce_product_insert" : [] },
      "DO" : [
        { "commerce_cart_product_add_by_sku" : {
            "USING" : {
              "user" : [ "site:current-user" ],
              "sku" : [ "commerce-product:sku" ],
              "quantity" : "1",
              "combine" : "0"
            },
            "PROVIDE" : { "product_add_line_item" : { "product_add_line_item" : "Added product line item" } }
          }
        },
        { "redirect" : { "url" : "\\/cart" } }
      ]
    }
  }');
  return $items;
}
