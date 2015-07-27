(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    $(function setCardstockDisplay() {
      var el;
      var id;
      var cardStockSelection = $('.card-stocks');
      setCardStockBackground(cardStockSelection);
    });
  }); // End $(document).ready()

  var fetchClassName = function(selectedCardStock) {
    var className;
    if (selectedCardStock === 'whitesmooth') {
      className = 'whiteSmooth';
    } else if (selectedCardStock === 'whitelinen') {
      className = 'whiteLinen';
    } else if (selectedCardStock === 'softwhite') {
      className = 'softWhite';
    } else if (selectedCardStock === 'tan') {
      className = 'tan';
    } else if (selectedCardStock === 'gray') {
      className = 'gray';
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
    if ($(images).attr('class') === 'undefined') {
      $(images).addClass(className);
    } else {
      $(images).removeClass();
      $(images).addClass(className);
    }
  };

  var setCardStockBackground = function(el) {
    var selectedCardStock = $(el).text().toLowerCase();
    selectedCardStock = $.trim(selectedCardStock).replace(/\s+/g, '');
    var className = fetchClassName(selectedCardStock);
    changeImageBackground(el, className);
  };

})(jQuery); // End jQuery $ replacement
