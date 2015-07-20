(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()

    $(function () {
      var el;
      var id;
      var cardStockSelection = $('select[id*="card-stocks"]');
      if (cardStockSelection.length !== 0) {
        for (var i=0; i<cardStockSelection.length; i++) {
          el = cardStockSelection[i];
          (function (el) {
            $(el).change(function() {
              updateCardStockBackground(el);
            })
          })(el);
        }
        $(cardStockSelection).change();
      } else {
        cardStockSelection = $('.card-stocks');
        for (i=0; i<cardStockSelection.length; i++) {
          el = cardStockSelection[i];
          setCardStockBackground(el);
        }
      }
    });

    var fetchClassName = function(selectedCardStock) {
      var className;
      if (selectedCardStock === '1' || selectedCardStock === 'whitesmooth') {
        className = 'whiteSmooth';
      } else if (selectedCardStock === '2' || selectedCardStock === 'whitelinen') {
        className = 'whiteLinen';
      } else if (selectedCardStock === '3' || selectedCardStock === 'softwhite') {
        className = 'softWhite';
      } else if (selectedCardStock === '4' || selectedCardStock === 'tan') {
        className = 'tan';
      } else if (selectedCardStock === '5'  || selectedCardStock === 'gray') {
        className = 'gray';
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
      if ($(images).attr('class') === 'undefined') {
        $(images).addClass(className);
      } else {
        $(images).removeClass();
        $(images).addClass(className);
      }
    }

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
    }

  }); // End $(document).ready()

})(jQuery); // End jQuery $ replacement
