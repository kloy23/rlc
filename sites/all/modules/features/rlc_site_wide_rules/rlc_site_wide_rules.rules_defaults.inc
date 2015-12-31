<?php
/**
 * @file
 * rlc_site_wide_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rlc_site_wide_rules_default_rules_configuration() {
  $items = array();
  $items['rules_update_order_status'] = entity_import('rules_config', '{ "rules_update_order_status" : {
      "LABEL" : "Update Order Status",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_order", "rules_scheduler", "entity" ],
      "ON" : { "commerce_order_view" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "4" : "4" } }
          }
        },
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "pending" } }
      ],
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "processing" } },
        { "schedule" : {
            "component" : "rules_update_order_status_to_completed",
            "date" : "now",
            "identifier" : "Change order status from processing to completed.",
            "param_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');
  $items['rules_update_order_status_to_completed'] = entity_import('rules_config', '{ "rules_update_order_status_to_completed" : {
      "LABEL" : "Update Order Status to Completed",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order" ],
      "USES VARIABLES" : { "order" : { "label" : "order", "type" : "commerce_order" } },
      "ACTION SET" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "order" ], "order_status" : "completed" } }
      ]
    }
  }');
  return $items;
}
