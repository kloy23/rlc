<?php
/**
 * @file
 * rlc_business_cards.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rlc_business_cards_default_rules_configuration() {
  $items = array();
  $items['rlc_rules_fetch_business_card_product_files_cloned_'] = entity_import('rules_config', '{ "rlc_rules_fetch_business_card_product_files_cloned_" : {
      "LABEL" : "Fetch Company Card Product Files",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "company_card_creator_front" : {
          "label" : "Company Card Creator Front",
          "type" : "file",
          "parameter" : false
        }
      },
      "IF" : [
        { "data_is" : { "data" : [ "line-item:type" ], "value" : "company_business_card" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "file",
              "value" : [ "line-item:field-print-ready-front:file" ]
            },
            "PROVIDE" : { "variable_added" : { "company_card_creator_front_file" : "Card Creator Front File" } }
          }
        },
        { "data_set" : {
            "data" : [ "company-card-creator-front" ],
            "value" : [ "company-card-creator-front-file" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "company_card_creator_front" ]
    }
  }');
  $items['rlc_rules_fetch_price_of_company_card'] = entity_import('rules_config', '{ "rlc_rules_fetch_price_of_company_card" : {
      "LABEL" : "Fetch Price of Company Card",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "calculated_price" : { "label" : "Calculated Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "raised_price" : { "raised_price" : "Raised Price" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-print-type" ], "value" : "35" } }
            ],
            "DO" : [
              { "component_rlc_rules_fetch_price_of_company_raised_letter" : {
                  "USING" : {
                    "line_item" : [ "line_item" ],
                    "raised_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
                  },
                  "PROVIDE" : { "raised_price" : { "raised_price" : "Raised Price" } }
                }
              },
              { "data_set" : {
                  "data" : [ "calculated-price:amount" ],
                  "value" : [ "raised-price:amount" ]
                }
              }
            ],
            "LABEL" : "Raised Letter"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "full_color_price" : { "full_color_price" : "Full Color Price" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-print-type" ], "value" : "36" } }
            ],
            "DO" : [
              { "component_rlc_rules_fetch_price_of_company_full_color" : {
                  "USING" : {
                    "line_item" : [ "line_item" ],
                    "full_color_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
                  },
                  "PROVIDE" : { "full_color_price" : { "full_color_price" : "Full Color Price" } }
                }
              },
              { "data_set" : {
                  "data" : [ "calculated-price:amount" ],
                  "value" : [ "full-color-price:amount" ]
                }
              }
            ],
            "LABEL" : "Full Color"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "magnetic_price" : { "magnetic_price" : "Magnetic Price" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-print-type" ], "value" : "37" } }
            ],
            "DO" : [
              { "component_rlc_rules_fetch_price_of_company_magnetic" : {
                  "USING" : {
                    "line_item" : [ "line_item" ],
                    "magnetic_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
                  },
                  "PROVIDE" : { "magnetic_price" : { "magnetic_price" : "Magnetic Price" } }
                }
              },
              { "data_set" : {
                  "data" : [ "calculated-price:amount" ],
                  "value" : [ "magnetic-price:amount" ]
                }
              }
            ],
            "LABEL" : "Magnetic"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "calculated_price" ]
    }
  }');
  $items['rlc_rules_fetch_price_of_company_full_color'] = entity_import('rules_config', '{ "rlc_rules_fetch_price_of_company_full_color" : {
      "LABEL" : "Fetch Price of Company Full Color",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "full_color_price" : { "label" : "Full Color Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "9" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "full-color-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-company-price-500:amount" ]
                }
              }
            ],
            "LABEL" : "500"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "10" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "full-color-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-company-price-1000:amount" ]
                }
              }
            ],
            "LABEL" : "1000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "11" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ]
                  },
                  "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-2k" ] } }
            ],
            "LABEL" : "2000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_3k" : "Additional Cost",
                "price_3k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "12" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "2"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_3k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-3k" ]
                  },
                  "PROVIDE" : { "result" : { "price_3k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-3k" ] } }
            ],
            "LABEL" : "3000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_4k" : "Additional Cost",
                "price_4k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "13" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "3"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_4k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-4k" ]
                  },
                  "PROVIDE" : { "result" : { "price_4k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-4k" ] } }
            ],
            "LABEL" : "4000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_5k" : "Calculation result",
                "price_5k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "14" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "4"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_5k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-5k" ]
                  },
                  "PROVIDE" : { "result" : { "price_5k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-5k" ] } }
            ],
            "LABEL" : "5000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_10k" : "Calculation result",
                "price_10k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "15" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "9"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_10k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-10k" ]
                  },
                  "PROVIDE" : { "result" : { "price_10k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-10k" ] } }
            ],
            "LABEL" : "10000"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "full_color_price" ]
    }
  }');
  $items['rlc_rules_fetch_price_of_company_magnetic'] = entity_import('rules_config', '{ "rlc_rules_fetch_price_of_company_magnetic" : {
      "LABEL" : "Fetch Price of Company Magnetic",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "magnetic_price" : { "label" : "Magnetic Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "9" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "magnetic-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-company-price-500:amount" ]
                }
              }
            ],
            "LABEL" : "500"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "10" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "magnetic-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-company-price-1000:amount" ]
                }
              }
            ],
            "LABEL" : "1000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "11" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ]
                  },
                  "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-2k" ] } }
            ],
            "LABEL" : "2000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_3k" : "Additional Cost",
                "price_3k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "12" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "2"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_3k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-3k" ]
                  },
                  "PROVIDE" : { "result" : { "price_3k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-3k" ] } }
            ],
            "LABEL" : "3000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_4k" : "Additional Cost",
                "price_4k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "13" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "3"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_4k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-4k" ]
                  },
                  "PROVIDE" : { "result" : { "price_4k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-4k" ] } }
            ],
            "LABEL" : "4000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_5k" : "Calculation result",
                "price_5k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "14" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "4"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_5k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-5k" ]
                  },
                  "PROVIDE" : { "result" : { "price_5k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-5k" ] } }
            ],
            "LABEL" : "5000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_10k" : "Calculation result",
                "price_10k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "15" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "9"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_10k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-10k" ]
                  },
                  "PROVIDE" : { "result" : { "price_10k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-10k" ] } }
            ],
            "LABEL" : "10000"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "magnetic_price" ]
    }
  }');
  $items['rlc_rules_fetch_price_of_company_raised_letter'] = entity_import('rules_config', '{ "rlc_rules_fetch_price_of_company_raised_letter" : {
      "LABEL" : "Fetch Price of Company Raised Letter",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "raised_price" : { "label" : "Raised Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "9" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "raised-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-company-price-500:amount" ]
                }
              }
            ],
            "LABEL" : "500"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "10" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "raised-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-company-price-1000:amount" ]
                }
              }
            ],
            "LABEL" : "1000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "11" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ]
                  },
                  "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-2k" ] } }
            ],
            "LABEL" : "2000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_3k" : "Additional Cost",
                "price_3k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "12" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "2"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_3k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-3k" ]
                  },
                  "PROVIDE" : { "result" : { "price_3k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-3k" ] } }
            ],
            "LABEL" : "3000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_4k" : "Additional Cost",
                "price_4k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "13" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "3"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_4k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-4k" ]
                  },
                  "PROVIDE" : { "result" : { "price_4k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-4k" ] } }
            ],
            "LABEL" : "4000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_5k" : "Calculation result",
                "price_5k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "14" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "4"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_5k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-5k" ]
                  },
                  "PROVIDE" : { "result" : { "price_5k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-5k" ] } }
            ],
            "LABEL" : "5000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_10k" : "Calculation result",
                "price_10k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : { "company_business_card" : "company_business_card" } }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "15" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "9"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_10k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-10k" ]
                  },
                  "PROVIDE" : { "result" : { "price_10k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-10k" ] } }
            ],
            "LABEL" : "10000"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "raised_price" ]
    }
  }');
  $items['rules_calculate_price_for_business_cards'] = entity_import('rules_config', '{ "rules_calculate_price_for_business_cards" : {
      "LABEL" : "Calculate price for Business Cards",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-line-item:type" ],
            "op" : "IN",
            "value" : { "value" : {
                "business_card" : "business_card",
                "camera_ready_business_card" : "camera_ready_business_card"
              }
            }
          }
        }
      ],
      "DO" : [
        { "component_rules_fetch_price_of_business_card" : {
            "USING" : {
              "line_item" : [ "commerce-line-item" ],
              "calculated_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
            },
            "PROVIDE" : { "calculated_price" : { "calculated_price" : "Calculated Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "calculated-price:amount" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_company_cards'] = entity_import('rules_config', '{ "rules_calculate_price_for_company_cards" : {
      "LABEL" : "Calculate price for Company Cards",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-line-item:type" ],
            "value" : "company_business_card"
          }
        }
      ],
      "DO" : [
        { "component_rlc_rules_fetch_price_of_company_card" : {
            "USING" : {
              "line_item" : [ "commerce-line-item" ],
              "calculated_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
            },
            "PROVIDE" : { "calculated_price" : { "calculated_price" : "Calculated Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "calculated-price:amount" ],
            "component_name" : "base_price",
            "round_mode" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_price_for_two_sided_business_cards'] = entity_import('rules_config', '{ "rules_calculate_price_for_two_sided_business_cards" : {
      "LABEL" : "Calculate price for Two Sided Business Cards",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : {
                "business_card" : "business_card",
                "camera_ready_business_card" : "camera_ready_business_card",
                "company_business_card" : "company_business_card"
              }
            }
          }
        },
        { "data_is" : { "data" : [ "commerce-line-item:field-two-sided" ], "value" : "16" } }
      ],
      "DO" : [
        { "component_rules_fetch_price_of_two_sided" : {
            "USING" : { "line_item" : [ "commerce-line-item" ] },
            "PROVIDE" : { "two_sided_price" : { "two_sided_price" : "Two Sided Price" } }
          }
        },
        { "commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "two-sided-price:amount" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_calculate_shipping_based_on_products'] = entity_import('rules_config', '{ "rules_calculate_shipping_based_on_products" : {
      "LABEL" : "Calculate Shipping for Custom Business Cards",
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
        { "component_rules_calculate_shipping_price" : {
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
  $items['rules_calculate_shipping_price'] = entity_import('rules_config', '{ "rules_calculate_shipping_price" : {
      "LABEL" : "Calculate Shipping Price for Custom Business Cards",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "quantity" : { "label" : "quantity", "type" : "integer" },
        "price" : { "label" : "price", "type" : "commerce_price" }
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
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "camera_ready_business_card" : "camera_ready_business_card" } }
          }
        }
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
  $items['rules_fetch_price_of_business_card'] = entity_import('rules_config', '{ "rules_fetch_price_of_business_card" : {
      "LABEL" : "Fetch Price of Business Card",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "calculated_price" : { "label" : "Calculated Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "raised_price" : { "raised_price" : "Raised Price" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-print-type" ], "value" : "35" } }
            ],
            "DO" : [
              { "component_rules_fetch_price_of_raised_letter" : {
                  "USING" : {
                    "line_item" : [ "line_item" ],
                    "raised_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
                  },
                  "PROVIDE" : { "raised_price" : { "raised_price" : "Raised Price" } }
                }
              },
              { "data_set" : {
                  "data" : [ "calculated-price:amount" ],
                  "value" : [ "raised-price:amount" ]
                }
              }
            ],
            "LABEL" : "Raised Letter"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "full_color_price" : { "full_color_price" : "Full Color Price" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-print-type" ], "value" : "36" } }
            ],
            "DO" : [
              { "component_rules_fetch_price_of_full_color" : {
                  "USING" : {
                    "line_item" : [ "line_item" ],
                    "full_color_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
                  },
                  "PROVIDE" : { "full_color_price" : { "full_color_price" : "Full Color Price" } }
                }
              },
              { "data_set" : {
                  "data" : [ "calculated-price:amount" ],
                  "value" : [ "full-color-price:amount" ]
                }
              }
            ],
            "LABEL" : "Full Color"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "magnetic_price" : { "magnetic_price" : "Magnetic Price" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-print-type" ], "value" : "37" } }
            ],
            "DO" : [
              { "component_rules_fetch_price_of_magnetic" : {
                  "USING" : {
                    "line_item" : [ "line_item" ],
                    "magnetic_price" : { "value" : { "amount" : 0, "currency_code" : "USD" } }
                  },
                  "PROVIDE" : { "magnetic_price" : { "magnetic_price" : "Magnetic Price" } }
                }
              },
              { "data_set" : {
                  "data" : [ "calculated-price:amount" ],
                  "value" : [ "magnetic-price:amount" ]
                }
              }
            ],
            "LABEL" : "Magnetic"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "calculated_price" ]
    }
  }');
  $items['rules_fetch_price_of_full_color'] = entity_import('rules_config', '{ "rules_fetch_price_of_full_color" : {
      "LABEL" : "Fetch Price of Full Color",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "full_color_price" : { "label" : "Full Color Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "9" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "full-color-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-price-500:amount" ]
                }
              }
            ],
            "LABEL" : "500"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "10" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "full-color-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-price-1000:amount" ]
                }
              }
            ],
            "LABEL" : "1000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "11" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "line-item:field-print-type:field-price-per-thousand:amount" ]
                  },
                  "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-2k" ] } }
            ],
            "LABEL" : "2000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_3k" : "Additional Cost",
                "price_3k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "12" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "2"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_3k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-3k" ]
                  },
                  "PROVIDE" : { "result" : { "price_3k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-3k" ] } }
            ],
            "LABEL" : "3000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_4k" : "Additional Cost",
                "price_4k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "13" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "3"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_4k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-4k" ]
                  },
                  "PROVIDE" : { "result" : { "price_4k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-4k" ] } }
            ],
            "LABEL" : "4000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_5k" : "Calculation result",
                "price_5k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "14" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "4"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_5k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-5k" ]
                  },
                  "PROVIDE" : { "result" : { "price_5k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-5k" ] } }
            ],
            "LABEL" : "5000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_10k" : "Calculation result",
                "price_10k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "15" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "9"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_10k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-company-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-10k" ]
                  },
                  "PROVIDE" : { "result" : { "price_10k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "full-color-price:amount" ], "value" : [ "price-10k" ] } }
            ],
            "LABEL" : "10000"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "full_color_price" ]
    }
  }');
  $items['rules_fetch_price_of_magnetic'] = entity_import('rules_config', '{ "rules_fetch_price_of_magnetic" : {
      "LABEL" : "Fetch Price of Magnetic",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "magnetic_price" : { "label" : "Magnetic Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "9" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "magnetic-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-price-500:amount" ]
                }
              }
            ],
            "LABEL" : "500"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "10" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "magnetic-price:amount" ],
                  "value" : [ "line-item:field-print-type:field-price-1000:amount" ]
                }
              }
            ],
            "LABEL" : "1000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "11" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "line-item:field-print-type:field-price-per-thousand:amount" ]
                  },
                  "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-2k" ] } }
            ],
            "LABEL" : "2000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_3k" : "Additional Cost",
                "price_3k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "12" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "2"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_3k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-3k" ]
                  },
                  "PROVIDE" : { "result" : { "price_3k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-3k" ] } }
            ],
            "LABEL" : "3000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_4k" : "Additional Cost",
                "price_4k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "13" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "3"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_4k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-4k" ]
                  },
                  "PROVIDE" : { "result" : { "price_4k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-4k" ] } }
            ],
            "LABEL" : "4000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_5k" : "Calculation result",
                "price_5k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "14" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "4"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_5k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-5k" ]
                  },
                  "PROVIDE" : { "result" : { "price_5k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-5k" ] } }
            ],
            "LABEL" : "5000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_10k" : "Calculation result",
                "price_10k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "15" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "9"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_10k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-print-type:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-10k" ]
                  },
                  "PROVIDE" : { "result" : { "price_10k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "magnetic-price:amount" ], "value" : [ "price-10k" ] } }
            ],
            "LABEL" : "10000"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "magnetic_price" ]
    }
  }');
  $items['rules_fetch_price_of_raised_letter'] = entity_import('rules_config', '{ "rules_fetch_price_of_raised_letter" : {
      "LABEL" : "Fetch Price of Raised Letter",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "raised_price" : { "label" : "Raised Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "9" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "raised-price:amount" ],
                  "value" : [ "line-item:field-card-stocks:field-price-500:amount" ]
                }
              }
            ],
            "LABEL" : "500"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "10" } }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "raised-price:amount" ],
                  "value" : [ "line-item:field-card-stocks:field-price-1000:amount" ]
                }
              }
            ],
            "LABEL" : "1000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "11" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "line-item:field-card-stocks:field-price-per-thousand:amount" ]
                  },
                  "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-2k" ] } }
            ],
            "LABEL" : "2000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_3k" : "Additional Cost",
                "price_3k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "12" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "2"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_3k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-3k" ]
                  },
                  "PROVIDE" : { "result" : { "price_3k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-3k" ] } }
            ],
            "LABEL" : "3000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_4k" : "Additional Cost",
                "price_4k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "13" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "3"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_4k" : "Additional Cost" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-4k" ]
                  },
                  "PROVIDE" : { "result" : { "price_4k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-4k" ] } }
            ],
            "LABEL" : "4000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_5k" : "Calculation result",
                "price_5k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "14" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "4"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_5k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-5k" ]
                  },
                  "PROVIDE" : { "result" : { "price_5k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-5k" ] } }
            ],
            "LABEL" : "5000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_10k" : "Calculation result",
                "price_10k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "15" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "9"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_10k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-card-stocks:field-price-1000:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-10k" ]
                  },
                  "PROVIDE" : { "result" : { "price_10k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "raised-price:amount" ], "value" : [ "price-10k" ] } }
            ],
            "LABEL" : "10000"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card"
                    }
                  }
                }
              },
              { "entity_has_field" : { "entity" : [ "line-item" ], "field" : "field_one_or_two_color" } },
              { "data_is" : { "data" : [ "line-item:field-one-or-two-color" ], "value" : "25" } }
            ],
            "DO" : [
              { "commerce_line_item_unit_price_add" : {
                  "commerce_line_item" : [ "line-item" ],
                  "amount" : [ "line-item:field-one-or-two-color:field-additional-cost:amount" ],
                  "component_name" : "base_price",
                  "round_mode" : "1"
                }
              }
            ],
            "LABEL" : "Two Color"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "raised_price" ]
    }
  }');
  $items['rules_fetch_price_of_two_sided'] = entity_import('rules_config', '{ "rules_fetch_price_of_two_sided" : {
      "LABEL" : "Fetch Price of Two Sided",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "two_sided_price" : {
          "label" : "Two Sided Price",
          "type" : "commerce_price",
          "parameter" : false
        }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card",
                      "company_business_card" : "company_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-two-sided" ], "value" : "16" } },
              { "data_is" : {
                  "data" : [ "line-item:field-quantity" ],
                  "op" : "IN",
                  "value" : { "value" : { "9" : "9", "10" : "10" } }
                }
              }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "two-sided-price:amount" ],
                  "value" : [ "line-item:field-two-sided:field-price:amount" ]
                }
              }
            ],
            "LABEL" : "500 - 1000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card",
                      "company_business_card" : "company_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-two-sided" ], "value" : "16" } },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "11" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price:amount" ],
                    "op" : "+",
                    "input_2" : [ "line-item:field-two-sided:field-price-per-thousand:amount" ]
                  },
                  "PROVIDE" : { "result" : { "price_2k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "two-sided-price:amount" ], "value" : [ "price-2k" ] } }
            ],
            "LABEL" : "2000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_3k" : "Calculation result",
                "price_3k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card",
                      "company_business_card" : "company_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-two-sided" ], "value" : "16" } },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "12" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "2"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_3k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-3k" ]
                  },
                  "PROVIDE" : { "result" : { "price_3k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "two-sided-price:amount" ], "value" : [ "price-3k" ] } }
            ],
            "LABEL" : "3000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_4k" : "Calculation result",
                "price_4k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card",
                      "company_business_card" : "company_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-two-sided" ], "value" : "16" } },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "13" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "3"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_4k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-4k" ]
                  },
                  "PROVIDE" : { "result" : { "price_4k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "two-sided-price:amount" ], "value" : [ "price-4k" ] } }
            ],
            "LABEL" : "4000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_5k" : "Calculation result",
                "price_5k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card",
                      "company_business_card" : "company_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-two-sided" ], "value" : "16" } },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "14" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "4"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_5k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-5k" ]
                  },
                  "PROVIDE" : { "result" : { "price_5k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "two-sided-price:amount" ], "value" : [ "price-5k" ] } }
            ],
            "LABEL" : "5000"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "result" : {
                "additional_cost_10k" : "Calculation result",
                "price_10k" : "Calculation result"
              }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card",
                      "company_business_card" : "company_business_card"
                    }
                  }
                }
              },
              { "data_is" : { "data" : [ "line-item:field-two-sided" ], "value" : "16" } },
              { "data_is" : { "data" : [ "line-item:field-quantity" ], "value" : "15" } }
            ],
            "DO" : [
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price-per-thousand:amount" ],
                    "op" : "*",
                    "input_2" : "9"
                  },
                  "PROVIDE" : { "result" : { "additional_cost_10k" : "Calculation result" } }
                }
              },
              { "data_calc" : {
                  "USING" : {
                    "input_1" : [ "line-item:field-two-sided:field-price:amount" ],
                    "op" : "+",
                    "input_2" : [ "additional-cost-10k" ]
                  },
                  "PROVIDE" : { "result" : { "price_10k" : "Calculation result" } }
                }
              },
              { "data_set" : { "data" : [ "two-sided-price:amount" ], "value" : [ "price-10k" ] } }
            ],
            "LABEL" : "10000"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "two_sided_price" ]
    }
  }');
  $items['rules_fetch_quantity'] = entity_import('rules_config', '{ "rules_fetch_quantity" : {
      "LABEL" : "Fetch Quantity of Custom Business Cards",
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
                "business_card" : "business_card",
                "camera_ready_business_card" : "camera_ready_business_card",
                "company_business_card" : "company_business_card"
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
  $items['rules_shipping_for_business_cards'] = entity_import('rules_config', '{ "rules_shipping_for_business_cards" : {
      "LABEL" : "Shipping for Business Cards",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "product_line_item" : { "label" : "Product Line Item", "type" : "commerce_line_item" },
        "shipping_price" : { "label" : "Shipping Price", "type" : "commerce_price" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : {
              "variable_added" : { "quantity_text" : "Quantity Text" },
              "conversion_result" : { "quantity" : "quantity" }
            },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "product-line-item" ],
                  "type" : "commerce_line_item",
                  "bundle" : { "value" : {
                      "business_card" : "business_card",
                      "camera_ready_business_card" : "camera_ready_business_card",
                      "company_business_card" : "company_business_card"
                    }
                  }
                }
              }
            ],
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "text", "value" : [ "product-line-item:field-quantity:name" ] },
                  "PROVIDE" : { "variable_added" : { "quantity_text" : "Quantity Text" } }
                }
              },
              { "data_convert" : {
                  "USING" : { "type" : "integer", "value" : [ "quantity-text" ] },
                  "PROVIDE" : { "conversion_result" : { "quantity" : "quantity" } }
                }
              }
            ],
            "LABEL" : "Fetch Quantity"
          }
        },
        { "RULE" : {
            "DO" : [ { "drupal_message" : { "message" : [ "quantity" ] } } ],
            "LABEL" : "Update Price"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "shipping_price" ]
    }
  }');
  return $items;
}
