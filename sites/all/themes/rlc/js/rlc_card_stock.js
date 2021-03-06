(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    $(function setCardstockDisplay() {
      var el;
      var printType = $('select[id*="print-type"]');
      var cardStockDropdown = $('select[id*="card-stock"]');
      var cardStockSelection = $('.card-stocks');
      if (printType.length === 0) {
        printType = $('.print-type');
      }
      for (var i=0; i<printType.length; i++) {
        // if the print type is Raised Letter
        if (printType[i].value === '35' || $(printType[i]).text().replace(/\s+/g, '') === 'RaisedLetter') {
          if (cardStockDropdown.length !== 0) {
            for (var x=0; x<cardStockDropdown.length; x++) {
              el = cardStockDropdown[x];
              (function (el) {
                $(el).change(function() {
                  updateCardStockBackground(el);
                });
              })(el);
              $(cardStockDropdown[x]).change();
            }          
          }
          if (cardStockSelection.length !== 0) {
            for (var y=0; y<cardStockSelection.length; y++) {
              el = cardStockSelection[y];
              setCardStockBackground(el);
            }              
          }
        } else {
          el = printType[i];
          setWhiteBackground(el);
        }
      }
    });
  }); // End $(document).ready()

  var fetchClassName = function(selectedCardStock) {
    var className;
    if (selectedCardStock === '1' || selectedCardStock === 'whitesmooth' || selectedCardStock === 'White Smooth') {
      className = 'whiteSmooth';
    } else if (selectedCardStock === '2' || selectedCardStock === 'whitelinen' || selectedCardStock === 'White Linen') {
      className = 'whiteLinen';
    } else if (selectedCardStock === '3' || selectedCardStock === 'softwhitelinen' || selectedCardStock === 'Soft White Linen') {
      className = 'softWhiteLinen';
    } else if (selectedCardStock === '4' || selectedCardStock === 'tanlinen' || selectedCardStock === 'Tan Linen') {
      className = 'tanLinen';
    } else if (selectedCardStock === '5'  || selectedCardStock === 'graylinen' || selectedCardStock === 'Gray Linen') {
      className = 'grayLinen';
    } else if (selectedCardStock === '6' || selectedCardStock === 'yellow' || selectedCardStock === 'Yellow') {
      className = 'yellow';
    } else if (selectedCardStock === '7' || selectedCardStock === 'kromekote' || selectedCardStock === 'Kromekote') {
      className = 'kromekote';
    } else if (selectedCardStock === '8' || selectedCardStock === 'woodgrain' || selectedCardStock === 'Woodgrain') {
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

  var setWhiteBackground = function(el) {
    var className = 'whiteSmooth';
    changeImageBackground(el, className);
  };

})(jQuery); // End jQuery $ replacement
