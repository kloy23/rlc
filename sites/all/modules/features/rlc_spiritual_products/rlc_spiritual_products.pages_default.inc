<?php
/**
 * @file
 * rlc_spiritual_products.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function rlc_spiritual_products_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'spiritual_products';
  $page->task = 'page';
  $page->admin_title = 'Spiritual Products';
  $page->admin_description = '';
  $page->path = 'spiritual-products';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_spiritual_products__panel_context_01326622-a8ce-45c9-a37e-03df506282f8';
  $handler->task = 'page';
  $handler->subtask = 'spiritual_products';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c7137c77-ac14-46bc-9781-2508ee439396';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-81091f3b-d170-481b-8eb7-5c8e3ed0c2c1';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h4 align="center" style="padding-bottom:5px">*** Call for a quote if you would like to order large quantities with your churches logo and / or information. ***</h4>
<h3 align="center">*** All Cards are Based on Quantities of 250 ***</h3>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'rlc-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '81091f3b-d170-481b-8eb7-5c8e3ed0c2c1';
    $display->content['new-81091f3b-d170-481b-8eb7-5c8e3ed0c2c1'] = $pane;
    $display->panels['center'][0] = 'new-81091f3b-d170-481b-8eb7-5c8e3ed0c2c1';
    $pane = new stdClass();
    $pane->pid = 'new-45c0a468-529b-4060-93c2-664f8f4bc637';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'order_spiritual_products';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'products_display',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '45c0a468-529b-4060-93c2-664f8f4bc637';
    $display->content['new-45c0a468-529b-4060-93c2-664f8f4bc637'] = $pane;
    $display->panels['center'][1] = 'new-45c0a468-529b-4060-93c2-664f8f4bc637';
    $pane = new stdClass();
    $pane->pid = 'new-7d07bd56-a427-4e8e-aeee-c7fa0544a74f';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'order_spiritual_products';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'products_display',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7d07bd56-a427-4e8e-aeee-c7fa0544a74f';
    $display->content['new-7d07bd56-a427-4e8e-aeee-c7fa0544a74f'] = $pane;
    $display->panels['center'][2] = 'new-7d07bd56-a427-4e8e-aeee-c7fa0544a74f';
    $pane = new stdClass();
    $pane->pid = 'new-2d223ea5-9e63-4893-9d0c-2465d05d7b9d';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'order_spiritual_products';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_3',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'products_display',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2d223ea5-9e63-4893-9d0c-2465d05d7b9d';
    $display->content['new-2d223ea5-9e63-4893-9d0c-2465d05d7b9d'] = $pane;
    $display->panels['center'][3] = 'new-2d223ea5-9e63-4893-9d0c-2465d05d7b9d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['spiritual_products'] = $page;

  return $pages;

}
