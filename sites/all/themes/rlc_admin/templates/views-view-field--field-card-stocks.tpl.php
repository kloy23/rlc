<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

  $product_type = $row->_field_data['commerce_product_field_data_commerce_product_product_id']['entity']->type;
  
  if ($view->name === 'commerce_line_item_table') {
    $print_type = $row->_field_data['line_item_id']['entity']->field_print_type['und'][0]['tid'];
  } else {
    if (!empty($row->_field_data['commerce_line_item_field_data_commerce_line_items_line_item_']['entity']->field_print_type['und'][0]['tid'])) {
      $print_type = $row->_field_data['commerce_line_item_field_data_commerce_line_items_line_item_']['entity']->field_print_type['und'][0]['tid'];
    }
  }

  // If the Product Type is Company Business Card
  if ($product_type === 'business_card' || $product_type === 'two_sided_business_card' ||$product_type === 'camera_ready_business_card' || $product_type === 'company_business_card') {
    // If  the print type is Raised Letter
    if ($print_type === '35') {
      print $field->last_render;
    }
  }

?>


