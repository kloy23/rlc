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
      var $selectedColorTypeVal = $selectColorType.val();
      // if One Color is selected
      if ($selectedColorTypeVal === '24') {
        // make sure two color options is hidden
        $twoColorOptions.hide();
        // show one color options
        $oneColorOptions.show();
      } else if ($selectedColorTypeVal === '25') {// Two color is selected.
        // make sure one color options is hidden
        $oneColorOptions.hide();
        // show two color options
        $twoColorOptions.show();
      }
    };

    var validateForm = function() {
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      var $selectedColorTypeVal = $selectColorType.val();
      var $selectedOneColorVal = $('#edit-line-item-fields-field-one-color-options-und').val();
      var $selectedTwoColorVal = $('#edit-line-item-fields-field-two-color-options-und').val();
      var $selectedBackColorVal = $('#edit-line-item-fields-field-back-color-options-und').val();
      var $cameraReadyFile = $('.form-item-line-item-fields-field-camera-ready-und-0').find('a');
      var $cameraReadyBackFile = $('.form-item-line-item-fields-field-camera-ready-back-und-0').find('a');
      // If this is a two sided card
      if (fieldTwoSidedVal === '16') {
        if ($cameraReadyFile.length === 0 || $cameraReadyBackFile.length === 0) {
          alert('You must upload a file for the front AND back in order to continue.');
        } else if ($selectedColorTypeVal === '24') { // If One Color has been selected
          if ($selectedOneColorVal === '_none') { // A color option has not been selected
            alert('You must select a color option in order to continue.');
          }
        } else if ($selectedOneColorVal === '25') { // If Two Color has been selected
          if ($selectedTwoColorVal === '_none') { // A color option has not been selected
            alert('You must select a color option in order to continue.');
          }
        } else if ($selectedBackColorVal === '_none') { // A back color option has not been selected
          alert('You must select a Back color option in order to continue.');
        }
      } else if (fieldTwoSidedVal !== '16') { // If this is NOT a two sided card
        if ($cameraReadyFile.length === 0) {
          alert('You must upload a file in order to continue.');
        } else if ($selectedColorTypeVal === '24') { // If One Color has been selected
          if ($selectedOneColorVal === '_none') { // A color option has not been selected
            alert('You must select a color option in order to continue.');
          }
        } else if ($selectedOneColorVal === '25') { // If Two Color has been selected
          if ($selectedTwoColorVal === '_none') { // A color option has not been selected
            alert('You must select a color option in order to continue.');
          }
        }
      }
    };

    var loadApproval = function() {
      // Hide all form fields
      $formFields.hide();
      $('#continue').hide();
      $('#edit , #approve').show();
    };

    var orderApproved = function() {
      var orderIsApproved = document.getElementById('edit-approve').checked;
      // If the order is approved
      if (orderIsApproved === true) {
        $addToCartButton.show();
        $('#edit').hide();
      } else if (orderIsApproved === false) {
        $addToCartButton.hide();
        $('#edit').show();
      }
    };

    var editOrder = function() {
      $('#edit, #approve').hide();
      $formFields.show();
      $('#continue').show();
    };

    // On page load, set defaults
    $(function setDefaults() {
      toggleTwoSided();
      showColorOptions();
      // make user order approval is not checked
      document.getElementById('edit-approve').checked = false;
      $('#edit, #approve').hide();
      $addToCartButton.hide();
    });

    // Click handlers
    $fieldTwoSided.change(toggleTwoSided);
    $selectColorType.change(showColorOptions);
    $('#continue').click(validateForm);
    $('#edit').click(editOrder);
    $('#edit-approve').change(orderApproved);

  }); // End $(document).ready()

})(jQuery); // End jQuery $ replacement


// $('#edit-line-item-fields-field-camera-ready').find('a').attr('href')
