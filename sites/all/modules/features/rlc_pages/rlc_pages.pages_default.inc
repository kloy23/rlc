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
  $handler->name = 'page_contact_us__panel_context_e4d12c6b-afdc-4962-91ad-d2b7693a030c';
  $handler->task = 'page';
  $handler->subtask = 'contact_us';
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
  $handler->name = 'page_home__panel_context_13c25c93-fb02-491e-b68e-2e6df6ec317c';
  $handler->task = 'page';
  $handler->subtask = 'home';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'front',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
          0 => 5,
          1 => 4,
          2 => 3,
        ),
        'parent' => 'canvas',
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
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top_left',
          1 => 'top_right',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'top_right' => array(
        'type' => 'region',
        'title' => 'top-right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'rlc-header',
        'hide_empty' => 0,
      ),
      'top_left' => array(
        'type' => 'region',
        'title' => 'top-left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'rlc-header',
        'hide_empty' => 0,
      ),
      5 => array(
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
        'parent' => '5',
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
      'top_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '17ff964f-db7a-4b2c-985f-77621a780fed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0d21f58b-051f-47c7-ac7a-db54063e7ef6';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div id="siteSlogan" class="rlc-header">
We are one of the very few companies in the U.S. that has the capability to provide you with the Elegance and Professionalism of Raised Letter Printing.
</div>',
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
    $pane->uuid = '0d21f58b-051f-47c7-ac7a-db54063e7ef6';
    $display->content['new-0d21f58b-051f-47c7-ac7a-db54063e7ef6'] = $pane;
    $display->panels['header'][0] = 'new-0d21f58b-051f-47c7-ac7a-db54063e7ef6';
    $pane = new stdClass();
    $pane->pid = 'new-610088fd-a152-482d-955b-5ff128759d2c';
    $pane->panel = 'top_left';
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
      'display' => 'block',
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
    $pane->uuid = '610088fd-a152-482d-955b-5ff128759d2c';
    $display->content['new-610088fd-a152-482d-955b-5ff128759d2c'] = $pane;
    $display->panels['top_left'][0] = 'new-610088fd-a152-482d-955b-5ff128759d2c';
    $pane = new stdClass();
    $pane->pid = 'new-68421b42-3972-44e3-9375-0a709190ebe9';
    $pane->panel = 'top_right';
    $pane->type = 'views';
    $pane->subtype = 'greeting_card_image_carousel';
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
      'display' => 'block',
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
    $pane->uuid = '68421b42-3972-44e3-9375-0a709190ebe9';
    $display->content['new-68421b42-3972-44e3-9375-0a709190ebe9'] = $pane;
    $display->panels['top_right'][0] = 'new-68421b42-3972-44e3-9375-0a709190ebe9';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

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
  $handler->name = 'page_pricing__panel_context_846b47b7-701f-41d9-b013-88f58b78dc65';
  $handler->task = 'page';
  $handler->subtask = 'pricing';
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

  return $pages;

}
