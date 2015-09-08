(function ($) {
  'use strict';
  $(document).ready(function() {

    var fetchArgument = function() {
      var selectListVal = $('#edit-company-select-list').val();
      return selectListVal;
    };

    var goToCreator = function(argument) {
      var url = '/company-card-creator' + argument;
      window.location.href = url;
    };

    $('#submit').on('click', function(e) {
      e.preventDefault();
      var argument = fetchArgument();
      goToCreator(argument);
    });

  });

})(jQuery);
