<?php
/**
 * @file
 * rlc_image_carousel.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function rlc_image_carousel_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_business_card_slideshow_images';
  $strongarm->value = 0;
  $export['comment_anonymous_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_greeting_card_slideshow_images';
  $strongarm->value = 0;
  $export['comment_anonymous_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_business_card_slideshow_images';
  $strongarm->value = '1';
  $export['comment_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_business_card_slideshow_images';
  $strongarm->value = 1;
  $export['comment_default_mode_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_greeting_card_slideshow_images';
  $strongarm->value = 1;
  $export['comment_default_mode_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_business_card_slideshow_images';
  $strongarm->value = '50';
  $export['comment_default_per_page_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_greeting_card_slideshow_images';
  $strongarm->value = '50';
  $export['comment_default_per_page_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_business_card_slideshow_images';
  $strongarm->value = 1;
  $export['comment_form_location_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_greeting_card_slideshow_images';
  $strongarm->value = 1;
  $export['comment_form_location_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_greeting_card_slideshow_images';
  $strongarm->value = '2';
  $export['comment_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_business_card_slideshow_images';
  $strongarm->value = '1';
  $export['comment_preview_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_greeting_card_slideshow_images';
  $strongarm->value = '1';
  $export['comment_preview_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_business_card_slideshow_images';
  $strongarm->value = 1;
  $export['comment_subject_field_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_greeting_card_slideshow_images';
  $strongarm->value = 1;
  $export['comment_subject_field_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__business_card_slideshow_images';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__greeting_card_slideshow_images';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_business_card_slideshow_images';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_greeting_card_slideshow_images';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_business_card_slideshow_images';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_greeting_card_slideshow_images';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_business_card_slideshow_images';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_greeting_card_slideshow_images';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_business_card_slideshow_images';
  $strongarm->value = '0';
  $export['node_preview_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_greeting_card_slideshow_images';
  $strongarm->value = '1';
  $export['node_preview_greeting_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_business_card_slideshow_images';
  $strongarm->value = 0;
  $export['node_submitted_business_card_slideshow_images'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_greeting_card_slideshow_images';
  $strongarm->value = 1;
  $export['node_submitted_greeting_card_slideshow_images'] = $strongarm;

  return $export;
}
