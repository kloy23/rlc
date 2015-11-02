(function ($) {
  'use strict';
  $(document).ready(function() {

    var $allCategories = $('#categories');
    var $allSelectList = $('#categories select');
    var $categoryButton = $('.category').children().find('a');


    $(function(){
      $allCategories.hide();
      $allSelectList.hide();
    });

    var fetchArgument = function(e) {
      var selectListVal = e.target.value;
      return selectListVal;
    };

    var goToCreator = function(argument) {
      var url = '/company-card-creator' + argument;
      window.location.href = url;
    };

    $('#franchise_companies').click(function() {
      $allCategories.toggle();
    });

    $categoryButton.click(function() {
      var $button = $(this).parent();
      var $selectList = $button.parent().find('select');
      var $selectListParent = $selectList.parent();
      $selectList.toggle();
      if ($selectList.is(':visible')) {
        $button.addClass('company_selection_left');
        $selectListParent.addClass('company_selection_right');
      } else {
        $button.removeClass('company_selection_left');
        $selectListParent.removeClass('company_selection_right');
      }
    });

    $allSelectList.change(function(e) {
      var argument = fetchArgument(e);
      if (argument !== '0') {
        goToCreator(argument);
      } else {
        // Do Nothing;
      }
    });

  });

})(jQuery);
