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
  $page->name = 'order_business_cards';
  $page->task = 'page';
  $page->admin_title = 'Order Business Cards';
  $page->admin_description = 'The site homepage';
  $page->path = 'order-business-cards';
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
  $handler->name = 'page_order_business_cards__panel_context_bcde5b2b-393d-43ef-a981-5b915a7750fe';
  $handler->task = 'page';
  $handler->subtask = 'order_business_cards';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
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
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 1,
          2 => 3,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '25.261498335372718',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 54.454033278857636,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'header' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'header' => NULL,
      'top_left' => NULL,
      'log_in' => NULL,
      'company_selection' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '17ff964f-db7a-4b2c-985f-77621a780fed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ff003493-b20e-435b-9047-6365a7c4cf9f';
    $pane->panel = 'footer';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '500 One Color Raised Letter Business Cards for just $14.95!
<p id="disclaimer">*Price is based on a One Color Card printed on White Smooth card stock, and the use of our Custom Business Card Creator.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-business-cards-header',
      'css_class' => 'rlc-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ff003493-b20e-435b-9047-6365a7c4cf9f';
    $display->content['new-ff003493-b20e-435b-9047-6365a7c4cf9f'] = $pane;
    $display->panels['footer'][0] = 'new-ff003493-b20e-435b-9047-6365a7c4cf9f';
    $pane = new stdClass();
    $pane->pid = 'new-9e625c09-b499-40bc-87e8-59c1d1416bcf';
    $pane->panel = 'header';
    $pane->type = 'views';
    $pane->subtype = 'business_card_image_carousel';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9e625c09-b499-40bc-87e8-59c1d1416bcf';
    $display->content['new-9e625c09-b499-40bc-87e8-59c1d1416bcf'] = $pane;
    $display->panels['header'][0] = 'new-9e625c09-b499-40bc-87e8-59c1d1416bcf';
    $pane = new stdClass();
    $pane->pid = 'new-3c231214-37ae-4c46-a20d-bcc3914fda89';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'admin_title' => 'Get Started',
      'title' => '',
      'body' => '<div class="buttons glossy">
<a href="/card-creator/">Create Your Card</a>
</div>
<div class="buttons glossy">
<a  href="/upload-artwork">Upload Custom Artwork</a>
</div>
<div class="buttons glossy">
<a  href="/spiritual-products">Spiritual Products</a>
</div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-business-cards-left',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3c231214-37ae-4c46-a20d-bcc3914fda89';
    $display->content['new-3c231214-37ae-4c46-a20d-bcc3914fda89'] = $pane;
    $display->panels['left'][0] = 'new-3c231214-37ae-4c46-a20d-bcc3914fda89';
    $pane = new stdClass();
    $pane->pid = 'new-a7dc9ea6-09d2-48a3-b45a-0e2a7ab1f5fd';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'company_card_creator-company_selection';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a7dc9ea6-09d2-48a3-b45a-0e2a7ab1f5fd';
    $display->content['new-a7dc9ea6-09d2-48a3-b45a-0e2a7ab1f5fd'] = $pane;
    $display->panels['left'][1] = 'new-a7dc9ea6-09d2-48a3-b45a-0e2a7ab1f5fd';
    $pane = new stdClass();
    $pane->pid = 'new-c2a5fc87-4bf1-4a4e-beea-2222af6c315b';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<ul>
  <li>One or Two Color Thermography, Full Color, and Magnetics available.</li>
  <li>Choose from several proven business card templates.</li>
  <li>Multiple high quality card stocks available.</li>
  <li>Printed and Shipped within 3 - 5 Business Days.</li>
  <li>Satisfaction guaranteed!</li>
</ul>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-business-cards-right',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c2a5fc87-4bf1-4a4e-beea-2222af6c315b';
    $display->content['new-c2a5fc87-4bf1-4a4e-beea-2222af6c315b'] = $pane;
    $display->panels['right'][0] = 'new-c2a5fc87-4bf1-4a4e-beea-2222af6c315b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['order_business_cards'] = $page;

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
