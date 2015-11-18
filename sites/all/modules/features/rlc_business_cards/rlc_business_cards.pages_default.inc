<?php
/**
 * @file
 * rlc_business_cards.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function rlc_business_cards_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'upload_artwork';
  $page->task = 'page';
  $page->admin_title = 'Upload Artwork';
  $page->admin_description = 'Allow users to upload print ready artwork.';
  $page->path = 'upload-artwork';
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
  $handler->name = 'page_upload_artwork__panel_context_51925729-06e3-4cb5-87fb-256f916d0ab3';
  $handler->task = 'page';
  $handler->subtask = 'upload_artwork';
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
  $display->uuid = '16744a8a-7819-4a40-acbb-24ea489e4046';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bc1f913f-4598-4251-b711-cc3b93427e52';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Requirements',
      'title' => '',
      'body' => '<h3>File Requirements:</h3>
We accept the following file formats: .TIF, .TIFF, .JPG, .JPEG, .PNG, & .PDF
<h3>Resolution</h3>
All file formats must have a minimum of 300 dpi (dot per inch) resolution.
Images designed for the web typically cannot be used for printing as they have a low resolution of 72dpi.  If images are not created at a minimum of 300dpi there will be a substantial drop in the print quality.
<h3>Bleeds</h3>
Any uploaded artwork that requires bleeds will be printed in full color.
',
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
    $pane->uuid = 'bc1f913f-4598-4251-b711-cc3b93427e52';
    $display->content['new-bc1f913f-4598-4251-b711-cc3b93427e52'] = $pane;
    $display->panels['center'][0] = 'new-bc1f913f-4598-4251-b711-cc3b93427e52';
    $pane = new stdClass();
    $pane->pid = 'new-7f5077ed-3b1d-4c04-8712-495c83d69e13';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'order_camera_ready';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
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
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-upload-artwork-form',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7f5077ed-3b1d-4c04-8712-495c83d69e13';
    $display->content['new-7f5077ed-3b1d-4c04-8712-495c83d69e13'] = $pane;
    $display->panels['center'][1] = 'new-7f5077ed-3b1d-4c04-8712-495c83d69e13';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['upload_artwork'] = $page;

  return $pages;

}
