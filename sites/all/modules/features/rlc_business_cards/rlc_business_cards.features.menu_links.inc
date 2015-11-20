<?php
/**
 * @file
 * rlc_business_cards.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function rlc_business_cards_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_pricing--card-stock-options:pricing.
  $menu_links['main-menu_pricing--card-stock-options:pricing'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'pricing',
    'router_path' => 'pricing',
    'link_title' => 'Pricing & Card Stock Options',
    'options' => array(
      'identifier' => 'main-menu_pricing--card-stock-options:pricing',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Pricing & Card Stock Options');

  return $menu_links;
}
