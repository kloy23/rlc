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
      'body' => 'Please use the form below to contact us.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
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
    $pane->css = array();
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
        'width' => '54.454033278857636',
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
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '17ff964f-db7a-4b2c-985f-77621a780fed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ff003493-b20e-435b-9047-6365a7c4cf9f';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '1000 High Quality Raised Letter Business Cards for just $16.95!
Why Pay More?
<p id="disclaimer">*Price is based on White Smooth card stock.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-home-header',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ff003493-b20e-435b-9047-6365a7c4cf9f';
    $display->content['new-ff003493-b20e-435b-9047-6365a7c4cf9f'] = $pane;
    $display->panels['header'][0] = 'new-ff003493-b20e-435b-9047-6365a7c4cf9f';
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
      'title' => 'Get Started',
      'body' => '<a class="buttons" href="/card-creator/">Create a New Design</a>
<a class="buttons" href="/upload-artwork">Upload Custom Artwork</a>',
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
          1 => 1,
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
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_',
          1 => 'left',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => 75,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 25,
        'width_type' => '%',
        'parent' => '1',
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
      'body' => '<a class="buttons" href="/card-creator/">Create a New Design</a>',
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
    $pane->pid = 'new-9e4ab5fa-9bbd-409f-94ca-0e50401083ab';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<a class="buttons" href="/upload-artwork">Upload Custom Artwork</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-order-now-top-button2',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9e4ab5fa-9bbd-409f-94ca-0e50401083ab';
    $display->content['new-9e4ab5fa-9bbd-409f-94ca-0e50401083ab'] = $pane;
    $display->panels['center'][1] = 'new-9e4ab5fa-9bbd-409f-94ca-0e50401083ab';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c744c164-8046-45bc-905f-342ef4166c77';
    $display->content['new-c744c164-8046-45bc-905f-342ef4166c77'] = $pane;
    $display->panels['center'][2] = 'new-c744c164-8046-45bc-905f-342ef4166c77';
    $pane = new stdClass();
    $pane->pid = 'new-739a7c28-912f-4f56-9370-9b3f7217e48c';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'Lowest Price and Highest Quality in the Business!',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-order-now-right-top',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '739a7c28-912f-4f56-9370-9b3f7217e48c';
    $display->content['new-739a7c28-912f-4f56-9370-9b3f7217e48c'] = $pane;
    $display->panels['left'][0] = 'new-739a7c28-912f-4f56-9370-9b3f7217e48c';
    $pane = new stdClass();
    $pane->pid = 'new-902c7ab5-1f81-499e-b928-7858ca476afe';
    $pane->panel = 'left_';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<img src="/sites/default/files/images/lowest_price.jpg"></img>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'panel-order-now-left-top',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '902c7ab5-1f81-499e-b928-7858ca476afe';
    $display->content['new-902c7ab5-1f81-499e-b928-7858ca476afe'] = $pane;
    $display->panels['left_'][0] = 'new-902c7ab5-1f81-499e-b928-7858ca476afe';
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
      'body' => 'This is where our pricing information will go',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
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
We accept the following file formats: .TIF, .TIFF, .EPS, .PSD, .PNG, & .PDF.
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
    $pane->css = array();
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
