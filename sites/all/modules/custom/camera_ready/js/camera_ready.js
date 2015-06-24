(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    // Global Vars
    var $fieldUploadBack = $('#edit-line-item-fields-field-camera-ready-back');
    var $fieldTwoSided = $('#edit-line-item-fields-field-two-sided-und');
    var $addToCartButton = $('#edit-submit');
    var $colorSelection = $('#edit-line-item-fields-field-one-or-two-color-und');
    var $oneColorOptions = $('#edit-line-item-fields-field-one-color-options');
    var $twoColorOptions = $('#edit-line-item-fields-field-two-color-options');
    var $backColorOptions = $('#edit-line-item-fields-field-back-color-options');
    var $formFields = $('#edit-line-item-fields');

    // Functions
    var removeBack = function() {
      var backRemoveButton = document.getElementById('edit-line-item-fields-field-camera-ready-back-und-0-remove-button');
      // IF a file has been uploaded in this field
      if (backRemoveButton !== null) {
        // click the remove button
        $(backRemoveButton).trigger('mousedown');
        console.log('back should be removed');
      }
    }
    var toggleTwoSided = function() {
      var $backColor = $('#edit-line-item-fields-field-back-color-options-und');
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      // if this is a two sided card
      if (fieldTwoSidedVal === '16') {
        $backColorOptions.show();
        $fieldUploadBack.show();
      } else {
        // set Back Color Option to '_none'.
        $backColor.val('_none');
        // Remove uploaded file for back
        removeBack();
        $backColorOptions.hide();
        $fieldUploadBack.hide();
      }
    };

    var colorOptions = function() {
      var $oneColor = $('#edit-line-item-fields-field-one-color-options-und');
      var $twoColor = $('#edit-line-item-fields-field-two-color-options-und');
      var $colorSelectionVal = $colorSelection.val();
      // if One Color is selected
      if ($colorSelectionVal === '24') {
        // make sure two color options is hidden
        $twoColorOptions.hide();
        // set Two color Options to '_none'
        $twoColor.val('_none');
        // show one color options
        $oneColorOptions.show();
      } else if ($colorSelectionVal === '25') {// Two color is selected.
        // make sure one color options is hidden
        $oneColorOptions.hide();
        // set One Color Options to '_none'
        $oneColor.val('_none');
        // show two color options
        $twoColorOptions.show();
      }
    };

    var validateForm = function() {
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      var $colorSelectionVal = $colorSelection.val();
      var $oneColorVal = $('#edit-line-item-fields-field-one-color-options-und').val();
      var $twoColorVal = $('#edit-line-item-fields-field-two-color-options-und').val();
      var $backColorVal = $('#edit-line-item-fields-field-back-color-options-und').val();
      var $file = $('.form-item-line-item-fields-field-camera-ready-und-0').find('a');
      var $backFile = $('.form-item-line-item-fields-field-camera-ready-back-und-0').find('a');
      var errorString = '';
      // If One Color has been selected, and a color option has not,
      // or two color has been selected and a color option has not.
      if (($colorSelectionVal === '24' && $oneColorVal === '_none') || ($colorSelectionVal === '25' && $twoColorVal === '_none')) {
        errorString += 'You must select a color option in order to continue.';
      }
      // If this is a Two Sided card, and the back color option has not been selected.
      if (fieldTwoSidedVal === '16' && $backColorVal === '_none') {
        errorString += 'You must select a color option for the back in order to continue.';
      }
      // If this is a Two Sided card.
      if (fieldTwoSidedVal === '16') {
        // If Front is empty
        if ($file.length === 0) {
          errorString += 'You must upload a file for the Front in order to continue.';
        }
        // If Back is empty.
        if ($backFile.length === 0) {
          errorString += 'You must upload a file for the Back in order to continue.'
        }
      } else {
        if ($file.length === 0) {
          errorString += 'You must upload a file in order to continue.'
        }
      }

      if (errorString != '') {
        alert(errorString);
        return false;
      } else {
        return true;
      }

    };

    var loadApproval = function() {
      // IF validateForm returns true.
      if (validateForm()) {
        // Hide all form fields
        $formFields.hide();
        $('#continue').hide();
        $('#edit , #approve').show();
      }
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
      colorOptions();
      // make user order approval is not checked
      document.getElementById('edit-approve').checked = false;
      $('#edit, #approve').hide();
      $addToCartButton.hide();
    });

    // Click handlers
    $fieldTwoSided.change(toggleTwoSided);
    $colorSelection.change(colorOptions);
    $('#continue').click(loadApproval);
    $('#edit').click(editOrder);
    $('#edit-approve').change(orderApproved);

  }); // End $(document).ready()

})(jQuery); // End jQuery $ replacement


// $('#edit-line-item-fields-field-camera-ready').find('a').attr('href')
