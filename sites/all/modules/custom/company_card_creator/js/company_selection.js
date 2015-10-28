(function ($) {
  'use strict';
  $(document).ready(function() {


    // $(function(){
    //   $allCategories.hide();
    //   $allSelectList.hide();
    // });

    var fetchArgument = function(e) {
      var selectListVal = e.target.value;
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

    $franchiseCompanies.click(function() {
      $allCategories.toggle();
    });

    $allCategories.click(function() {
      $(this).find('select').toggle();
    });

    $allSelectList.change(function(e) {
      var argument = fetchArgument(e);
      goToCreator(argument);
    });

  });

})(jQuery);
