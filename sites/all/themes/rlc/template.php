<?php

/**
 * @file
 * IMPORTANT WARNING: DO NOT MODIFY THIS FILE OR ANY OF THE INCLUDED FILES.
 * Including files from the /inc folder
 */

$dgp = drupal_get_path('theme', 'rlc');

include_once $dgp . '/inc/template.helpers.inc';
// include_once $dgp . '/inc/template.theme.inc';
include_once $dgp . '/inc/template.process.inc';
// include_once $dgp . '/inc/template.forms.inc';

/*
  Implements hook_preprocess_view()
 */
function rlc_preprocess_views_view(&$vars) {
  $name = $vars['name'];
  $id = $vars['display_id'];
  // If the view is order-greeting-cards
  if ($name === 'order_greeting_cards') {
    // If the view is black tie or pink ribbon
    if ($id === 'block_1' || $id === 'block_2') {
      // add rlc_greeting_cards js file
      drupal_add_js(drupal_get_path('theme', 'rlc') . '/js/rlc_greeting_cards.js', 'file');
    }
  }
}

