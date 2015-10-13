(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    $(function setCardstockDisplay() {
      var el;
      var id;
      var cardStockSelection = $('select[id*="card-stock"]');
      if (cardStockSelection.length !== 0) {
        for (var i=0; i<cardStockSelection.length; i++) {
          el = cardStockSelection[i];
          (function (el) {
            $(el).change(function() {
              updateCardStockBackground(el);
            });
          })(el);
        }
        $(cardStockSelection).change();
      } else {
        cardStockSelection = $('.card-stocks');
        for (var x=0; x<cardStockSelection.length; x++) {
          el = cardStockSelection[x];
          setCardStockBackground(el);
        }
      }
    });
    // Hide Card Stocks Field if Company Card Stock is being displayed.
    $(function removeCardStocksField() {
      var products = $('tr');
      $(products).each(function() {
        var companyCardStock = $(this).find('#subOptions');
        $(companyCardStock).each(function() {
          var siblings = $(this).siblings();
          var cardStocks = siblings[0];
          $(cardStocks).hide();
        });
      });
    });
  }); // End $(document).ready()

  var fetchClassName = function(selectedCardStock) {
    var className;
    if (selectedCardStock === '1' || selectedCardStock === 'whitesmooth') {
      className = 'whiteSmooth';
    } else if (selectedCardStock === '2' || selectedCardStock === 'whitelinen') {
      className = 'whiteLinen';
    } else if (selectedCardStock === '3' || selectedCardStock === 'softwhitelinen') {
      className = 'softWhiteLinen';
    } else if (selectedCardStock === '4' || selectedCardStock === 'tanlinen') {
      className = 'tanLinen';
    } else if (selectedCardStock === '5'  || selectedCardStock === 'graylinen') {
      className = 'grayLinen';
    } else if (selectedCardStock === '6' || selectedCardStock === 'yellow') {
      className = 'yellow';
    } else if (selectedCardStock === '7' || selectedCardStock === 'kromekote') {
      className = 'kromekote';
    } else if (selectedCardStock === '8' || selectedCardStock === 'woodgrain') {
      className = 'woodgrain';
    }
    return className;
  };

  var changeImageBackground = function(el, className) {
    var images = $(el).parents('tr').find('img');
    var parent = images.parent();
    // If the parent of the image is not a span.
    // This prevents the image class from being assigned to uploaded files.
    if (!parent.is('span')) {
      if (images.attr('class') === 'undefined') {
        images.addClass(className);
      } else {
        images.removeClass();
        images.addClass(className);
      }
    }
  };

  var updateCardStockBackground = function(el) {
    var id = el.id;
    var selectedCardStock = $('#' + id + ' option:selected').val();
    var className = fetchClassName(selectedCardStock);
    changeImageBackground(el, className);
  };

  var setCardStockBackground = function(el) {
    var selectedCardStock = $(el).text().toLowerCase();
    selectedCardStock = $.trim(selectedCardStock).replace(/\s+/g, '');
    var className = fetchClassName(selectedCardStock);
    changeImageBackground(el, className);
  };

})(jQuery); // End jQuery $ replacement
