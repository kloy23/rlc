<?php
/**
 * @file
 * rlc_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function rlc_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact_us';
  $page->task = 'page';
  $page->admin_title = 'Contact Us';
  $page->admin_description = 'Site Contact Page';
  $page->path = 'contact';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Contact Us',
    'name' => 'main-menu',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contact_us__panel_context_daa3bccd-1f22-442b-9f20-f6d9f5b18de6';
  $handler->task = 'page';
  $handler->subtask = 'contact_us';
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
  $display->uuid = '90a1a70c-4ae2-44b3-ad03-de8a7a0fbc5a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bb03d1e7-77a3-43a0-ac6c-25925774a6de';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p align="center" style="font-size:18px; font-weight:bold;">Please use the form below to contact us.',
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
    $pane->uuid = 'bb03d1e7-77a3-43a0-ac6c-25925774a6de';
    $display->content['new-bb03d1e7-77a3-43a0-ac6c-25925774a6de'] = $pane;
    $display->panels['center'][0] = 'new-bb03d1e7-77a3-43a0-ac6c-25925774a6de';
    $pane = new stdClass();
    $pane->pid = 'new-7a79f561-a47e-4ff3-bea0-31ce9d817b22';
    $pane->panel = 'center';
    $pane->type = 'contact';
    $pane->subtype = 'contact';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7a79f561-a47e-4ff3-bea0-31ce9d817b22';
    $display->content['new-7a79f561-a47e-4ff3-bea0-31ce9d817b22'] = $pane;
    $display->panels['center'][1] = 'new-7a79f561-a47e-4ff3-bea0-31ce9d817b22';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contact_us'] = $page;

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
  $handler->name = 'page_greeting_cards__panel';
  $handler->task = 'page';
  $handler->subtask = 'greeting_cards';
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
    'name' => 'panel',
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

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = 'The site homepage';
  $page->path = 'home';
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
  $handler->name = 'page_home__panel_context_9143f179-b100-4741-8b7f-55c20de89eeb';
  $handler->task = 'page';
  $handler->subtask = 'home';
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
      'body' => '1000 High Quality Raised Letter Business Cards for just $16.95!
<p id="disclaimer">*Price is based on White Smooth card stock, and the use of our Custom Business Card Creator.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-home-header',
      'css_class' => 'rlc-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ff003493-b20e-435b-9047-6365a7c4cf9f';
    $display->content['new-ff003493-b20e-435b-9047-6365a7c4cf9f'] = $pane;
    $display->panels['footer'][0] = 'new-ff003493-b20e-435b-9047-6365a7c4cf9f';
    $pane = new stdClass();
    $pane->pid = 'new-00b44c6d-5197-4a37-9b9c-cc33cb94b398';
    $pane->panel = 'header';
    $pane->type = 'views';
    $pane->subtype = 'image_carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '00b44c6d-5197-4a37-9b9c-cc33cb94b398';
    $display->content['new-00b44c6d-5197-4a37-9b9c-cc33cb94b398'] = $pane;
    $display->panels['header'][0] = 'new-00b44c6d-5197-4a37-9b9c-cc33cb94b398';
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
<a  href="/greeting-cards">Greeting Cards</a>
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
      'css_id' => 'panel-home-left',
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
  <li>One or Two color printing available.</li>
  <li>Choose from several proven business card templates.</li>
  <li>Multiple high quality card stocks available.</li>
  <li>Printed and Shipped within 48 hours.</li>
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
      'css_id' => 'panel-home-right',
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
  $pages['home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'order_now';
  $page->task = 'page';
  $page->admin_title = 'Order Now';
  $page->admin_description = 'Order Page';
  $page->path = 'order-now';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Order Now',
    'name' => 'main-menu',
    'weight' => '1',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_order_now__panel_context_ce2d090b-7155-4fe6-a16b-a7ca65ded68f';
  $handler->task = 'page';
  $handler->subtask = 'order_now';
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
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'top',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
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
      'left_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f6bfcae5-9c21-416d-be82-f7eed8fe3393';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9ef70d4f-dc9a-4aad-93bb-1158f8a67e7d';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<a class="buttons" href="/card-creator/">Create Your Card</a>
<a class="buttons" href="/upload-artwork">Upload Custom Artwork</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-order-now-top',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9ef70d4f-dc9a-4aad-93bb-1158f8a67e7d';
    $display->content['new-9ef70d4f-dc9a-4aad-93bb-1158f8a67e7d'] = $pane;
    $display->panels['center'][0] = 'new-9ef70d4f-dc9a-4aad-93bb-1158f8a67e7d';
    $pane = new stdClass();
    $pane->pid = 'new-c744c164-8046-45bc-905f-342ef4166c77';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Printed and Shipped within 48 hours.</p>
<p>Satisfaction guaranteed!</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-order-now-top-shipped',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c744c164-8046-45bc-905f-342ef4166c77';
    $display->content['new-c744c164-8046-45bc-905f-342ef4166c77'] = $pane;
    $display->panels['center'][1] = 'new-c744c164-8046-45bc-905f-342ef4166c77';
    $pane = new stdClass();
    $pane->pid = 'new-14c9db09-a2d8-494f-8b65-6b0aedb1ed03';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<img src="../sites/all/themes/rlc/css/images/satisfaction_guaranteed.svg"></img>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-order-now-guarantee',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '14c9db09-a2d8-494f-8b65-6b0aedb1ed03';
    $display->content['new-14c9db09-a2d8-494f-8b65-6b0aedb1ed03'] = $pane;
    $display->panels['center'][2] = 'new-14c9db09-a2d8-494f-8b65-6b0aedb1ed03';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['order_now'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'pricing';
  $page->task = 'page';
  $page->admin_title = 'Pricing & Card Stock Options';
  $page->admin_description = 'Pricing and Card Stock information.';
  $page->path = 'pricing';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Pricing & Card Stock Options',
    'name' => 'main-menu',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_pricing__panel_context_92474ada-51ce-4eb4-8370-7865721953d6';
  $handler->task = 'page';
  $handler->subtask = 'pricing';
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
  $display->uuid = 'a5e9a390-bf5f-40d7-aa5a-f366ffb76e22';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c6dd4fce-8a87-45fb-be1c-a9979df219a8';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<!-- Head -->
<div id="pricingHeader" class="rlc-header">
  <h3>Pricing is based on the use of our Custom Business Card Creator</h3>
  <h3>There is no additional cost for the use of a second color</h3>
  <h3>Uploaded Artwork will have an additional fee of $8.00</h3>
</div>
<!-- Card Stock Pricing Info -->
<table>
  <tr class="rlc-header">
    <th>Card Stock</th>
    <th>Sample</th>
    <th>500</th>
    <th>1000</th>
    <th>Per Additional 1000</th>
  </tr>
  <tr>
    <td>White Smooth</td>
    <td><div class="whiteSmoothSample"></div></td>
    <td>$14.95</td>
    <td>$16.95</td>
    <td>$14.95</td>
  </tr>
  <tr>
    <td>White Linen</td>
    <td><div class="whiteLinenSample"></div></td>
    <td>$23.95</td>
    <td>$26.95</td>
    <td>$22.50</td>
  </tr>
  <tr>
    <td>Soft White Linen</td>
    <td><div class="softWhiteLinenSample"></div></td>
    <td>$24.95</td>
    <td>$28.95</td>
    <td>$23.50</td>
  </tr>
  <tr>
    <td>Tan Linen</td>
    <td><div class="tanLinenSample"></div></td>
    <td>$24.95</td>
    <td>$28.95</td>
    <td>$23.50</td>
  </tr>
  <tr>
    <td>Gray Linen</td>
    <td><div class="grayLinenSample"></div></td>
    <td>$24.95</td>
    <td>$28.95</td>
    <td>$23.50</td>
  </tr>
  <tr>
    <td>Yellow</td>
    <td><div class="yellowSample"></div></td>
    <td>$32.95</td>
    <td>$36.95</td>
    <td>$31.50</td>
  </tr>
  <tr>
    <td>KromeKote</td>
    <td><div class="kromekoteSample"></div></td>
    <td>$32.95</td>
    <td>$36.95</td>
    <td>$31.50</td>
  </tr>
  <tr>
    <td>Woodgrain</td>
    <td><div class="woodgrainSample"></div></td>
    <td>$47.50</td>
    <td>$53.50</td>
    <td>$46.00</td>
  </tr>
</table>

<!-- Backside Pricing Info -->
<div id="pricingBacks" class="rlc-header">
<h3>** All Backs Are Printed "Flat", Meaning The Ink Is NOT Raised. **</h3>
</div>
<table>
  <tr class="rlc-header">
    <th>1 Color Back</th>
    <th>500 - 1000</th>
    <th>Per Additional 1000</th>
  </tr>
  <tr>
    <td>Any Card Stock</td>
    <td>$14.00</td>
    <td>$10.00</td>
  </tr>
</table>

<!-- Shipping pricing Info -->
<table>
  <tr class="rlc-header">
    <th>Shipping</th>
    <th>All orders are shipped at a flat rate based on the orders total quantity</th>
  </tr>
  <tr>
    <td>Quantity | 500</td>
    <td>$7.00</td>
  </tr>
  <tr>
    <td>Quantity | 1,000 - 2,000</td>
    <td>$8.25</td>
  </tr>
  <tr>
    <td>Quantity | 2,500 - 4,000</td>
    <td>$11.25</td>
  </tr>
  <tr>
    <td>Quantity | 4,500 - 10,000</td>
    <td>$15.00</td>
  </tr>
</table>
<div id="pricingFooter" class="rlc-header">
  <h3>Please Contact Us for a shipping quote for orders totaling over 10,000</h3>
</div>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'pricing',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c6dd4fce-8a87-45fb-be1c-a9979df219a8';
    $display->content['new-c6dd4fce-8a87-45fb-be1c-a9979df219a8'] = $pane;
    $display->panels['center'][0] = 'new-c6dd4fce-8a87-45fb-be1c-a9979df219a8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-c6dd4fce-8a87-45fb-be1c-a9979df219a8';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['pricing'] = $page;

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
  $handler->name = 'page_spiritual_products__panel';
  $handler->task = 'page';
  $handler->subtask = 'spiritual_products';
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
    'name' => 'panel',
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
      'body' => '<h3 align="center">*** All Cards are Based on Quantities of 250 ***</h3>',
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
    $pane->pid = 'new-d27a1026-991f-4960-b953-6cca93f4ae51';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'order_spiritual_cards';
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
      'css_id' => 'products-display',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd27a1026-991f-4960-b953-6cca93f4ae51';
    $display->content['new-d27a1026-991f-4960-b953-6cca93f4ae51'] = $pane;
    $display->panels['center'][1] = 'new-d27a1026-991f-4960-b953-6cca93f4ae51';
    $pane = new stdClass();
    $pane->pid = 'new-647246aa-5bf9-4ceb-bdeb-25ec3d45fa06';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'order_spiritual_books';
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
      'override_title' => 0,
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '647246aa-5bf9-4ceb-bdeb-25ec3d45fa06';
    $display->content['new-647246aa-5bf9-4ceb-bdeb-25ec3d45fa06'] = $pane;
    $display->panels['center'][2] = 'new-647246aa-5bf9-4ceb-bdeb-25ec3d45fa06';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['spiritual_products'] = $page;

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
  $handler->name = 'page_upload_artwork__panel_context_f50eb4ac-ddc6-4990-9cb7-7daada78f901';
  $handler->task = 'page';
  $handler->subtask = 'upload_artwork';
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
