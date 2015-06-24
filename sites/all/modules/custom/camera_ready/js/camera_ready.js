(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()
    // Global Vars
    var $fileUploadField = $('.form-item-line-item-fields-field-camera-ready-und-0');
    var $fileUploadBackField = $('#edit-line-item-fields-field-camera-ready-back-und-0-upload');
    var $fileUploadDiv = $('#edit-line-item-fields-field-camera-ready');
    var $fileUploadBackDiv = $('#edit-line-item-fields-field-camera-ready-back');
    var $fieldTwoSided = $('#edit-line-item-fields-field-two-sided-und');
    var $addToCartButton = $('#edit-submit');
    var $colorSelection = $('#edit-line-item-fields-field-one-or-two-color-und');
    var $oneColorSelection = $('#edit-line-item-fields-field-one-color-options-und');
    var $twoColorSelection = $('#edit-line-item-fields-field-two-color-options-und');
    var $backColorSelection = $('#edit-line-item-fields-field-back-color-options-und');
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
    };
    var toggleTwoSided = function() {
      var $backColor = $('#edit-line-item-fields-field-back-color-options-und');
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      // if this is a two sided card
      if (fieldTwoSidedVal === '16') {
        $backColorOptions.show();
        $fileUploadBackDiv.show();
      } else {
        // set Back Color Option to '_none'.
        $backColor.val('_none');
        // Remove uploaded file for back
        removeBack();
        $backColorOptions.hide();
        $fileUploadBackDiv.hide();
      }
    };
    var colorOptions = function() {
      var $colorSelectionVal = $colorSelection.val();
      // if One Color is selected
      if ($colorSelectionVal === '24') {
        // make sure two color options is hidden
        $twoColorOptions.hide();
        // set Two color Options to '_none'
        $twoColorSelection.val('_none');
        // show one color options
        $oneColorOptions.show();
      } else if ($colorSelectionVal === '25') {// Two color is selected.
        // make sure one color options is hidden
        $oneColorOptions.hide();
        // set One Color Options to '_none'
        $oneColorSelection.val('_none');
        // show two color options
        $twoColorOptions.show();
      }
    };
    var formError = function(el) {
      el.addClass('form-error');
    };
    var removeFormError = function(el) {
      el.removeClass('form-error');
    };
    var validateForm = function() {
      var fieldTwoSidedVal = document.getElementById('edit-line-item-fields-field-two-sided-und').value;
      var $colorSelectionVal = $colorSelection.val();
      var $oneColorVal = $oneColorSelection.val();
      var $twoColorVal = $twoColorSelection.val();
      var $backColorVal = $backColorSelection.val();
      var $file = $fileUploadDiv.find('a');
      var $backFile = $fileUploadBackDiv.find('a');
      var errorString = '';
      // If One Color has been selected, and a color option has not,
      // or two color has been selected and a color option has not.
      if ($colorSelectionVal === '24' && $oneColorVal === '_none') {
        errorString += 'You must select a color option in order to continue.\n';
        formError($oneColorOptions);
      }
      //
      if ($colorSelectionVal === '25' && $twoColorVal === '_none') {
        errorString += 'You must select a color option in order to continue.\n';
        formError($twoColorOptions);
      }
      // If this is a Two Sided card, and the back color option has not been selected.
      if (fieldTwoSidedVal === '16' && $backColorVal === '_none') {
        errorString += 'You must select a color option for the back in order to continue.\n';
        formError($backColorOptions);
      }
      // If this is a Two Sided card.
      if (fieldTwoSidedVal === '16') {
        // If Front is empty
        if ($file.length === 0) {
          errorString += 'You must upload a file for the Front in order to continue.\n';
          formError($fileUploadDiv);
        }
        // If Back is empty.
        if ($backFile.length === 0) {
          errorString += 'You must upload a file for the Back in order to continue.\n';
          formError($fileUploadBackDiv);
        }
      } else {
        if ($file.length === 0) {
          errorString += 'You must upload a file in order to continue.\n';
          formError($fileUploadDiv);
        }
      }
      if (errorString !== '') {
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
    $oneColorSelection.change(function() {
      removeFormError($oneColorOptions);
    });
    $twoColorSelection.change(function() {
      removeFormError($twoColorOptions);
    });
    $backColorSelection.change(function() {
      removeFormError($backColorOptions);
    });
    $fileUploadField.on('change', function() {
      removeFormError($fileUploadDiv);
    });
    $fileUploadBackField.change(function() {
      removeFormError($fileUploadBackDiv);
    });
    $('#continue').click(loadApproval);
    $('#edit').click(editOrder);
    $('#edit-approve').change(orderApproved);
  }); // End $(document).ready()
})(jQuery); // End jQuery $ replacement
