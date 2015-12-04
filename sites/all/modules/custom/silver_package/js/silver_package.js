(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()

    var $productSelect = $('.silver_package_product_select input');
    var $quantitySelect = $('.silver_package_product_quantity select');
    // Change the default quantity based on whether or not a product is selected.
    var defaultQuantity = function(e) {
      var checkbox = e.target;
      var $quantity = $(e.target).parent().parent().parent().children().find('select');
      if (checkbox.checked) {
        $quantity.val('1');
      } else {
        $quantity.val('0');
      }
    }

    // When a product is selected, or unselected
    $productSelect.click(function(e) {
      // Change the products default value
      defaultQuantity(e);
    });

  }); // End $(document).ready()
})(jQuery); // End jQuery $ replacement
