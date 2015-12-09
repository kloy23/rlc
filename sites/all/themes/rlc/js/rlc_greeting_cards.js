(function($) { // Begin jQuery Replacement
  'use strict';
  $(document).ready(function() { // Begin Doc Ready

  // Fetch quantity field
  var $quantityFields = $('.form-item-quantity');

  // Create paragraph to hold total number of cards
  var numOfCards = document.createElement('p');
  // Create text node that contains number of cards
  $(numOfCards).attr('class', 'num_of_cards').text('25 Cards');
  // Append fields
  $($quantityFields).append(numOfCards);

  var updateTotalCards = function(e) {
    var quantity = e.target.value;
    var $paragraph = $(e.target).parent().children();
    var $price = $(e.target).closest('.inside').children().eq(0).children().eq(1);
    var pricePerProduct = 9.75;
    var totalCards = quantity * 25;
    var totalPrice = quantity * pricePerProduct;

    $($price).text('$' + totalPrice.toFixed(2));
    $($paragraph[2]).text(totalCards + ' Cards');
  };

  var updateTotals = function() {
    for (var i=0; i<$quantityFields.length; i++) {
      var $quantity = $($quantityFields[i]).children('input').val();
      var $paragraph = $($quantityFields[i]).parent().children().find('p');
      var $price = $($quantityFields[i]).closest('.inside').children().eq(0).children().eq(1);
      var pricePerProduct = 9.75;
      var totalCards = $quantity * 25;
      var totalPrice = $quantity * pricePerProduct;

      $($price).text('$' + totalPrice.toFixed(2));
      $($paragraph).text(totalCards + ' Cards');
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
