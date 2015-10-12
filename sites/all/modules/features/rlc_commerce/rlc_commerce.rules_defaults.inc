<?php
/**
 * @file
 * rlc_commerce.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rlc_commerce_default_rules_configuration() {
  $items = array();
  $items['commerce_shipping_service_flat_rate_shipping'] = entity_import('rules_config', '{ "commerce_shipping_service_flat_rate_shipping" : {
      "LABEL" : "Rate Flat Rate Shipping",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_shipping" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "Order" } },
      "DO" : [
        { "commerce_shipping_service_rate_order" : {
            "shipping_service_name" : "flat_rate_shipping",
            "commerce_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');
  return $items;
}
