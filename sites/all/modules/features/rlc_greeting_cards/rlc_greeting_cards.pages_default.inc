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
  $page->name = 'black_tie_collection';
  $page->task = 'page';
  $page->admin_title = 'Black Tie Collection';
  $page->admin_description = 'A page that allows users to order Greeting Cards';
  $page->path = 'black-tie-collection';
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
  $handler->name = 'page_black_tie_collection__panel_context_39e6fbb6-46f3-45ad-b219-92d08b4d7370';
  $handler->task = 'page';
  $handler->subtask = 'black_tie_collection';
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
      'body' => '<h3 align="center">*** All Greeting Cards are sold in Quantities of 25 Per Pack ***</h3>
<h4 style="text-align:center; padding:5px;">All Greeting Card Packs Include Envelopes</h4>',
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
    $pane->pid = 'new-da58250d-96ee-439a-9967-1fa567572a78';
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
      'css_id' => 'silver_package',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'da58250d-96ee-439a-9967-1fa567572a78';
    $display->content['new-da58250d-96ee-439a-9967-1fa567572a78'] = $pane;
    $display->panels['center'][1] = 'new-da58250d-96ee-439a-9967-1fa567572a78';
    $pane = new stdClass();
    $pane->pid = 'new-fc5e993e-8d02-421d-bb5c-b5e51b632ba9';
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
      'css_id' => 'products-display',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'fc5e993e-8d02-421d-bb5c-b5e51b632ba9';
    $display->content['new-fc5e993e-8d02-421d-bb5c-b5e51b632ba9'] = $pane;
    $display->panels['center'][2] = 'new-fc5e993e-8d02-421d-bb5c-b5e51b632ba9';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['black_tie_collection'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'order_greeting_cards';
  $page->task = 'page';
  $page->admin_title = 'Order Greeting Cards';
  $page->admin_description = 'The site homepage';
  $page->path = 'order-greeting-cards';
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
  $handler->name = 'page_order_greeting_cards__panel_context_f9e483c1-da3a-40e4-b708-44bf6a28bc96';
  $handler->task = 'page';
  $handler->subtask = 'order_greeting_cards';
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
    $pane->pid = 'new-f7801cad-8c08-46a6-880b-6a8a95a3a88d';
    $pane->panel = 'header';
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
    $pane->uuid = 'f7801cad-8c08-46a6-880b-6a8a95a3a88d';
    $display->content['new-f7801cad-8c08-46a6-880b-6a8a95a3a88d'] = $pane;
    $display->panels['header'][0] = 'new-f7801cad-8c08-46a6-880b-6a8a95a3a88d';
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
<a href="/black-tie-collection/">Black Tie Collection</a>
</div>
<div class="buttons glossy">
<a href="/pink-ribbon-collection/">Pink Ribbon Collection</a>
</div>',
      'format' => 'full_html',
      'substitute' => TRUE,
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
    $pane->uuid = '3c231214-37ae-4c46-a20d-bcc3914fda89';
    $display->content['new-3c231214-37ae-4c46-a20d-bcc3914fda89'] = $pane;
    $display->panels['left'][0] = 'new-3c231214-37ae-4c46-a20d-bcc3914fda89';
    $pane = new stdClass();
    $pane->pid = 'new-c2a5fc87-4bf1-4a4e-beea-2222af6c315b';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
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
      'css_id' => '',
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
  $pages['order_greeting_cards'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'pink_ribbon_collection';
  $page->task = 'page';
  $page->admin_title = 'Pink Ribbon Collection';
  $page->admin_description = 'A page that allows users to order Greeting Cards';
  $page->path = 'pink-ribbon-collection';
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
  $handler->name = 'page_pink_ribbon_collection__panel_context_42532f7d-fe9d-4a1a-bb82-d690fa5d15c1';
  $handler->task = 'page';
  $handler->subtask = 'pink_ribbon_collection';
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
      'body' => '<p style="font-weight:bold;text-align:center;color:#ff69b4">It is very rare to find a family that has not been somehow affected by breast cancer. The only way we will defeat this
dreaded disease is through research and early detection. And, the only way to continue this fight is by providing the funds
needed for anyone to receive testing and researchers to keep searching for a cure. We are a printing company that
specializes in raised letter printing and provides greeting cards to businesses and individuals. Our Pink Ribbon Collection
is our way of keeping awareness at a level necessary to help the fight. Using our Pink Ribbon Collection will help this
endeavor two ways. When someone receives one of our greeting cards it will be a reminder of the challenges ahead and
our company also donates 10% of all sales proceeds of the Pink Ribbon Collection to Breast Cancer Research. </p>

<h3 style="text-align:center;color:#ff69b4">*** All Greeting Cards are sold in Quantities of 25 Per Pack ***</h3>
<h4 style="text-align:center; padding:5px;color:#ff69b4">All Greeting Card Packs Include Envelopes</h4>',
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
    $pane->pid = 'new-fda43970-101e-4ed7-8cd2-a807e75e0ad3';
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
      'display' => 'block_4',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'silver_package',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fda43970-101e-4ed7-8cd2-a807e75e0ad3';
    $display->content['new-fda43970-101e-4ed7-8cd2-a807e75e0ad3'] = $pane;
    $display->panels['center'][1] = 'new-fda43970-101e-4ed7-8cd2-a807e75e0ad3';
    $pane = new stdClass();
    $pane->pid = 'new-08e2e2e0-644f-486d-921f-b0da4adcf1bf';
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
      'css_id' => 'products-display',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '08e2e2e0-644f-486d-921f-b0da4adcf1bf';
    $display->content['new-08e2e2e0-644f-486d-921f-b0da4adcf1bf'] = $pane;
    $display->panels['center'][2] = 'new-08e2e2e0-644f-486d-921f-b0da4adcf1bf';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['pink_ribbon_collection'] = $page;

  return $pages;

}
