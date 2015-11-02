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

    var applyClasses = function($button, $selectList, $selectListParent) {
      if ($selectList.is(':visible')) {
        $button.addClass('company_selection_left selected');
        $selectListParent.addClass('company_selection_right');
      } else {
        $button.removeClass('company_selection_left selected');
        $selectListParent.removeClass('company_selection_right');
      }
    };

    var setCategoryDisplay = function() {
      var $categories = $allCategories.children();
      var $buttons = $categories.children();
      var $buttonSelected = $buttons.hasClass('selected');
      if ($buttonSelected) {
        for (var i=0; i<$categories.length; i++) {
          var category = $categories[i];
          var $button = $(category).children([0]);
          var hasClassSelected = $button.hasClass('selected');
          if (hasClassSelected === true) {
            $(category).show();
          } else {
            $(category).hide();
          }
        }
      } else {
        $categories.show();
      }
    };

    $('#franchise_companies').click(function() {
      $allCategories.toggle();
    });

    $categoryButton.click(function() {
      var $button = $(this).parent();
      var $selectList = $button.parent().find('select');
      var $selectListParent = $selectList.parent();
      $selectList.toggle();
      applyClasses($button, $selectList, $selectListParent);
      setCategoryDisplay();
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
