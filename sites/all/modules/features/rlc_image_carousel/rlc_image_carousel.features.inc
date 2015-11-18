<?php
/**
 * @file
 * rlc_image_carousel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rlc_image_carousel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "slick" && $api == "slick_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rlc_image_carousel_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rlc_image_carousel_node_info() {
  $items = array(
    'slideshow_images' => array(
      'name' => t('Slideshow Images'),
      'base' => 'node_content',
      'description' => t('Images used for homepage slideshow.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
