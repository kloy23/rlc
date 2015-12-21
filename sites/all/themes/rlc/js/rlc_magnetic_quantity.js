(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    var quantity500;
    var printType = $('select[id*="print-type"]');

    var changeQuantityOptions = function(e) {
      var quantity = $(e.target).parents().eq(2).children().find('[id*="field-quantity"]');
      var option500 = quantity.children().eq(0);
      var selectedPrintType = e.currentTarget.value;
      if (selectedPrintType === '37') {
        quantity500 = $(option500).detach();
        quantity.change();
      } else {
        $(quantity).prepend(quantity500);
        quantity.change();
      }
    };

    for (var i=0; i<printType.length; i++) {
      var el = printType[i];
      (function(el) {
        $(el).change(function(e) {
          changeQuantityOptions(e);
        });
      })(el);
        
    }

  }); // End $(document).ready()
})(jQuery); // End jQuery $ replacement
