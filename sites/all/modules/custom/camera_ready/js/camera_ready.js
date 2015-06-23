(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    // Global Vars
    var $fieldUploadBack = $('.field-name-field-camera-ready-back');
    var $fieldTwoSided = $('.field-name-field-two-sided');

    // Functions
    var toggleTwoSided = function() {
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      // if this is a two sided card
      if (fieldTwoSidedVal === '16') {
        $fieldUploadBack.show();
      } else {
        $fieldUploadBack.hide();
      }
    };

    var createContinueButton = function() {
      var $addToCartButton = $('#edit-submit');
      // hide add to cart button
      $addToCartButton.hide();
      var continueButton = document.createElement('button');
      $(continueButton).attr({
        'id' : 'continue',
        'type' : 'button'
      }).text('Continue').click(function() {
        loadProof();
      });
      $addToCartButton.before(continueButton);
    }

    var loadProof = function() {

    }

    // On page load, set defaults
    $(function setDefaults() {
      toggleTwoSided();
      createContinueButton();
    });

    // Click handlers
    $fieldTwoSided.change(toggleTwoSided);

  }); // End $(document).ready()

})(jQuery); // End jQuery $ replacement


// $('#edit-line-item-fields-field-camera-ready').find('a').attr('href')
