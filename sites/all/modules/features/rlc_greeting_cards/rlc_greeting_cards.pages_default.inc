<?php
/**
 * @file
 * rlc_greeting_cards.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function rlc_greeting_cards_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'greeting_cards';
  $page->task = 'page';
  $page->admin_title = 'Greeting Cards';
  $page->admin_description = 'A page that allows users to order Greeting Cards';
  $page->path = 'greeting-cards';
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
  $handler->name = 'page_greeting_cards__panel_context_e4abf242-f127-42d1-b029-39e1658ef567';
  $handler->task = 'page';
  $handler->subtask = 'greeting_cards';
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
  $display->uuid = '9669b8cc-ba39-4119-9064-25b009565021';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6602a20e-907d-4588-9cd9-b5689cfa925f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h3 align="center">*** All Greeting Cards are sold in Quantities of 25 Per Pack ***</h3>',
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
    $pane->uuid = '6602a20e-907d-4588-9cd9-b5689cfa925f';
    $display->content['new-6602a20e-907d-4588-9cd9-b5689cfa925f'] = $pane;
    $display->panels['center'][0] = 'new-6602a20e-907d-4588-9cd9-b5689cfa925f';
    $pane = new stdClass();
    $pane->pid = 'new-f17d43e2-1436-40ec-bf2b-4a01c6d8b0e3';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'order_greeting_cards';
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
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'products-display',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f17d43e2-1436-40ec-bf2b-4a01c6d8b0e3';
    $display->content['new-f17d43e2-1436-40ec-bf2b-4a01c6d8b0e3'] = $pane;
    $display->panels['center'][1] = 'new-f17d43e2-1436-40ec-bf2b-4a01c6d8b0e3';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-f17d43e2-1436-40ec-bf2b-4a01c6d8b0e3';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['greeting_cards'] = $page;

  return $pages;

}
