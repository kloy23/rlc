(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    $(function setCardstockDisplay() {
      var el;
      var cardStockSelection = $('.card-stocks');
      var printType = $('.print-type');
      for (var i=0; i<printType.length; i++) {
        if ($(printType[i]).text().replace(/\s+/g, '') === 'RaisedLetter') {
          if (cardStockSelection.length !== 0) {
            for (var x=0; x<cardStockSelection.length; x++) {
              el = cardStockSelection[x];
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
    if (selectedCardStock === 'whitesmooth') {
      className = 'whiteSmooth';
    } else if (selectedCardStock === 'whitelinen') {
      className = 'whiteLinen';
    } else if (selectedCardStock === 'softwhitelinen') {
      className = 'softWhiteLinen';
    } else if (selectedCardStock === 'tanlinen') {
      className = 'tanLinen';
    } else if (selectedCardStock === 'graylinen') {
      className = 'grayLinen';
    } else if (selectedCardStock === 'yellow') {
      className = 'yellow';
    } else if (selectedCardStock === 'kromekote') {
      className = 'kromekote';
    } else if (selectedCardStock === 'woodgrain') {
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
