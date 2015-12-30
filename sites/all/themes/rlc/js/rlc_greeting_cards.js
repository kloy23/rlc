(function($) { // Begin jQuery Replacement
  'use strict';
  $(document).ready(function() { // Begin Doc Ready

  // Fetch quantity field
  var $quantityFields = $('.form-item-quantity');

  var updateTotalCards = function(e) {
    var $productTitle = $(e.target).parents().eq(7).find('.views-field-title').text();
    var quantity = e.target.value;
    var $paragraph = $(e.target).parents().eq(5).find('p');
    var $price = $(e.target).closest('.inside').children().eq(0).children().eq(1);
    var pricePerProduct = 9.75;
    var totalCards = quantity * 25;
    var totalPrice = quantity * pricePerProduct;
    // Update total if product is NOT a variety pack
    if ($productTitle.indexOf('Pack') === -1) {
      $($price).text('$' + totalPrice.toFixed(2));
      $($paragraph).text(totalCards + ' Cards');
    }    
  };

  var updateTotals = function() {
    for (var i=0; i<$quantityFields.length; i++) {
      var $productTitle = $($quantityFields[i]).parents().eq(6).find('.views-field-title').text();
      // Update total if product is NOT a variety pack
      if ($productTitle.indexOf('Pack') === -1) {
        var $quantity = $($quantityFields[i]).children('input').val();
        var $paragraph = $($quantityFields[i]).parents().eq(4).find('p');
        var $price = $($quantityFields[i]).closest('.inside').children().eq(0).children().eq(1);
        var pricePerProduct = 9.75;
        var totalCards = $quantity * 25;
        var totalPrice = $quantity * pricePerProduct;

        $($price).text('$' + totalPrice.toFixed(2));
        $($paragraph).text(totalCards + ' Cards');
      }        
    }
  };

  $(function setDefaults() {
    updateTotals();
  });

  $quantityFields.on('input focus', 'input', function(e) {
    updateTotalCards(e);
  });

  }); // End Doc Ready

})(jQuery); // End jQuery Replacement
