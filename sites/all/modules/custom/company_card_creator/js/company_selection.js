(function ($) {
  'use strict';
  $(document).ready(function() {

    $(function(){
      $('#company_selection').hide();
    });

    var fetchArgument = function() {
      var selectListVal = $('#company_selection').val();
      return selectListVal;
    };

    var goToCreator = function(argument) {
      var url = '/company-card-creator' + argument;
      window.location.href = url;
    };

    $('#company_selection').change(function() {
      var argument = fetchArgument();
      goToCreator(argument);
    });

    $('#franchise_companies').click(function() {
      $('#company_selection').toggle();
    });

  });

})(jQuery);
