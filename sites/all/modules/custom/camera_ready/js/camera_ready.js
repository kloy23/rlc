(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    // Global Vars
    var $fieldUploadBack = $('#edit-line-item-fields-field-camera-ready-back');
    var $fieldTwoSided = $('#edit-line-item-fields-field-two-sided-und');
    var $addToCartButton = $('#edit-submit');
    var $selectColorType = $('#edit-line-item-fields-field-one-or-two-color-und');
    var $oneColorOptions = $('#edit-line-item-fields-field-one-color-options');
    var $twoColorOptions = $('#edit-line-item-fields-field-two-color-options');
    var $backColorOptions = $('#edit-line-item-fields-field-back-color-options');
    var $formFields = $('#edit-line-item-fields');

    // Functions
    var toggleTwoSided = function() {
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      // if this is a two sided card
      if (fieldTwoSidedVal === '16') {
        $backColorOptions.show();
        $fieldUploadBack.show();
      } else {
        $backColorOptions.hide();
        $fieldUploadBack.hide();
      }
    };

    var showColorOptions = function() {
      var $selectedColorVal = $selectColorType.val();
      // if One Color is selected
      if ($selectedColorVal === '24') {
        // make sure two color options is hidden
        $twoColorOptions.hide();
        // show one color options
        $oneColorOptions.show();
      } else if ($selectedColorVal === '25') {// Two color is selected.
        // make sure one color options is hidden
        $oneColorOptions.hide();
        // show two color options
        $twoColorOptions.show();
      }
    }

    var validateForm = function() {
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      var $cameraReadyFile = $('.form-item-line-item-fields-field-camera-ready-und-0').find('a');
      var $cameraReadyBackFile = $('.form-item-line-item-fields-field-camera-ready-back-und-0').find('a');
      // If this is a two sided card
      if (fieldTwoSidedVal === '16') {
        if ($cameraReadyFile.length === 0 || $cameraReadyBackFile.length === 0) {
          alert('You must upload a file for the front AND back in order to continue.');
        } else {
          loadProof();
        }
      } else {
        if ($cameraReadyFile.length === 0) {
          alert('You must upload a file in order to continue.');
        } else {
          loadProof();
        }
      }
    };

    var loadApproval = function() {
      // Hide all form fields
      $formFields.hide();
      $('#continue').hide();
      $('#edit , #approve').show();
    };

    var editOrder = function() {
      $('#edit, #approve').hide();
      $formFields.show();
      $('#continue').show();
    }

    // On page load, set defaults
    $(function setDefaults() {
      toggleTwoSided();
      showColorOptions();
      $('#edit, #approve').hide();
      $addToCartButton.hide();
    });

    // Click handlers
    $fieldTwoSided.change(toggleTwoSided);
    $selectColorType.change(showColorOptions);
    $('#continue').click(loadApproval);
    $('#edit').click(editOrder);

  }); // End $(document).ready()

})(jQuery); // End jQuery $ replacement


// $('#edit-line-item-fields-field-camera-ready').find('a').attr('href')
