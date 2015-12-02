(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()

    var $productSelect = $('.silver_package_product_select input');
    var $productQuantity = $('.silver_package_product_quantity');
    var $quantitySelect = $('.silver_package_product_quantity select');

    var toggleQuantity = function(e) {
      var $productDiv = $(e.target).parents().eq(2);
      var $quantity = $productDiv.children().eq(1);
      $quantity.toggle();
    };
    var clearProducts = function() {
      for (var i = 0; i < $productSelect.length; i++) {
        var $product = $productSelect[i];
        $product.checked = false;
      };
    };
    var clearQuantity = function() {
      for (var i = 0; i < $quantitySelect.length; i++) {
        var $quantity = $quantitySelect[i];
        $quantity.value = 0;
      };
    };

    $('#addToCart').click(function(e) {
      // e.preventDefault();
    });

    $productSelect.click(function(e) {
      toggleQuantity(e);
    });

    $(function setDefaults() {
      clearProducts();
      clearQuantity();
    });
  }); // End $(document).ready()
})(jQuery); // End jQuery $ replacement
