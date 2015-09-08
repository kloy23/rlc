(function ($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  var companyName;
  $(document).ready(function() { // Begin $(document).ready()

    var $inputFields = $('#cardInfoFront :input[type="text"]');

    // Hide selected divs on pageload
    $('#proof').hide();

    // *** FUNCTIONS ***

    var fetchCompanyName = function() {
      var companyName = document.location.search.substring(1);
      var companyName = companyName.split('&');
      var companyName = companyName[0].split('=');
      var companyName = companyName[1];
      return companyName;
    };
    var fetchCardStock = function() {
      var cardStock = document.location.search.substring(1);
      var cardStock = cardStock.split('&');
      var cardStock = cardStock[1].split('=');
      var cardStock = cardStock[1];
      return cardStock;
    };
    var setCardStock = function() {
      var cardStock = fetchCardStock();
      $('#previewFront, #proofImageFront').attr('class', cardStock);
    };
    var setFields = function() {
      var templateFields = Snap('#previewFront').selectAll('text');
      console.log(templateFields.length);
    };
    var highlightTemplate = function(el) {
      var background = el.node.firstElementChild;
      if ($(background).attr('class') !== 'selected') {
        $(background).attr('fill', '#E0FFFF');
      }
    };
    var unHighlightTemplate = function(el) {
      var background = el.node.firstElementChild;
      if ($(background).attr('class') !== 'selected') {
        $(background).attr('fill', '#FFF');
      }
    };
    var highlightSelectedTemplateFront = function(el) {
      var background = el.node.firstElementChild;
      var svgElement = Snap.select('#templatesFront');
      var svgNodes = svgElement.selectAll('g');
      for (var i=0; i<svgNodes.length; i++) {
        el = svgNodes[i];
        var node = el.node.firstElementChild;
        if ($(node).attr('class') == 'selected') {
          $(node).attr({
            class: '',
            fill: '#FFF',
            stroke: '#000',
            'stroke-width': '1px'
          });
        }
      }
      $(background).attr({
        class: 'selected',
        stroke: '#F00',
        'stroke-width': '2px'
      });
    };
    var highlightSelectedTemplateBack = function(el) {
      var background = el.node.firstElementChild;
      var svgElement = Snap.select('#templatesBack');
      var svgNodes = svgElement.selectAll('g');
      for (var i=0; i<svgNodes.length; i++) {
        el = svgNodes[i];
        var node = el.node.firstElementChild;
        if ($(node).attr('class') == 'selected') {
          $(node).attr({
            class: '',
            fill: '#FFF',
            stroke: '#000',
            'stroke-width': '1px'
          });
        }
      }
      $(background).attr({
        class: 'selected',
        stroke: '#F00',
        'stroke-width': '2px'
      });
    };
    // when called, changes the appropriate svg text field to match the value of corresponding html input field
    var changeTextFront = function(e) {
      var id = '#' + e.target.id;
      var newText = e.target.value;
      $(previewFront.select(id).node).text(newText);
    };
    // Load the template that is selected for Front
    var changeTemplateFront = function(el) {
      var svgNode;
      var companyName = fetchCompanyName();
      var templateId = el.node.id;
      var svgLogo = Snap('#previewFront');
      previewFront.clear(); // removes display of old template
      var fileName = '../sites/all/modules/custom/company_card_creator/svgTemplates/' + companyName + '/' + templateId + '.svg'; // dynamicly creates url to template
      Snap.load(fileName, function(f) {
        previewFront.append(f);
        // target the loaded svg document
        svgNode = Snap.select('#previewFront');
        // find all text fields within the svg document
        var svgElement = svgNode.selectAll('text');
        // for each svg text field
        for (var i = 0; i < svgElement.length; i++) {
          // target the correct input field for the current svg text field
          var field = $inputFields[i];
          // get the field value (text content)
          var fieldVal = field.value;
          // retrive the fields id and add a # to the begining in order to be used in an id selector
          var fieldId = '#' + field.id;
          // if the current text field is not empty
          if (fieldVal.length !== 0) {
            // target the appropriate svg field, and replace its text with the value of the current text field
            $(previewFront.select(fieldId).node).text(fieldVal);
          }
        }
      });
    };
    var calculateCost = function(quantity, price500, price1000, pricePerThousand) {
      var price;
      // If the quantity is 500
      if (quantity === '9') {
        price = price500;
        return price;
      } else if (quantity === '10') {
        price = price1000;
        return price;
      } else {
        var multiple = quantity - 10;
        price = price1000 + (pricePerThousand * multiple);
        return price;
      }
    };
    var updatePrice = function(quantity) {
      var price,
          price500,
          price1000,
          pricePerThousand;
      var $currentPrice = $('#currentPrice');
      var quantity = $('#edit-select-quantity').val();
      var cardStock = fetchCardStock();
      // If the cardStock is White Smooth
      if (cardStock === 'whiteSmooth') {
        price500 = 14.95;
        price1000 = 16.95;
        pricePerThousand = 14.95;
        price = calculateCost(quantity, price500, price1000, pricePerThousand);
      } else if (cardStock === 'whiteLinen') { // White Linen
        price500 = 23.95;
        price1000 = 26.95;
        pricePerThousand = 22.50;
        price = calculateCost(quantity, price500, price1000, pricePerThousand);
      } else if (cardStock === 'softWhiteLinen' || cardStock === 'tanLinen' || cardStock === 'grayLinen') { // Linens => Soft White, Tan, and Gray
        price500 = 24.95;
        price1000 = 28.95;
        pricePerThousand = 23.50;
        price = calculateCost(quantity, price500, price1000, pricePerThousand);
      } else if (cardStock === 'yellow' || cardStock === 'kromekote') { // Yellow and Kromekote
        price500 = 32.95;
        price1000 = 36.95;
        pricePerThousand = 31.50;
        price = calculateCost(quantity, price500, price1000, pricePerThousand);
      } else if (cardStock === 'Woodgrain') { // Woodgrain
        price500 = 47.50;
        price1000 = 53.50;
        pricePerThousand = 46.00;
        price = calculateCost(quantity, price500, price1000, pricePerThousand);
      }
      var convertedTotal = price.toFixed(2);
      // display price to customer
      $currentPrice.text("Price = $" + convertedTotal);
    };
    var startLoading = function() {
      var box = $('<div></div>').attr('id', 'loading');
      $('body').prepend(box);
    };
    var endloading = function() {
      $('#loading').remove();
    }
    // Allows users to view the card before adding it to their cart
    var loadProof = function(filepathFront, filepathBack) {
      filepathFront = '../' + filepathFront + '?' + Math.floor(Math.random() * 500000);
      filepathBack = '../' + filepathBack + '?' + Math.floor(Math.random() * 500000);
      // Hide all divs within container
      $('#leftColumn, #midColumn, #rightColumn, #bottomColumn').hide();
      // Show Proof Div
      $('#proof').show();
      $('#proofImageFront').attr('src', filepathFront);
      $('#proofImageBack').hide();
    };
    var removeEmptyFields = function() {
      var el;
      // target the loaded svg document
      var svgFrontNode = Snap.select('#previewFront');
      // loop through front imput fields and find all empty fields
      for (var i=0; i < $inputFields.length; i++) {
        el = $inputFields[i];
        if (!$(el).val()) {
          var id = '#' + el.id;
          var svgTextField = svgFrontNode.select(id);
          $(svgTextField.node).text('');
        }
      }
    };
    // SAVE THE ARTWORK
    var saveCard = function() {
      var filepathFront;
      var filepathBack;
      var companyName = fetchCompanyName();
      var name = $('#line1').val();
      var svgFront = document.getElementById("previewFront");
      // Show loading gif when ajax starts
      $(document).ajaxStart(function() {
        startLoading();
      }).ajaxStop(function() {
        loadProof(filepathFront, filepathBack);
        // Remove loading gif when ajax stops
        endloading();
      });
      svgFront.toDataURL("image/svg+xml", {
        callback: function(data) {
          $.ajax({
            type: 'POST',
            url: '/card-creator-ajax-front',
            data: {
              img: data,
              company_name: companyName,
              name: name,
            },
            success:function(filepath) {
              filepathFront = filepath;
            }
          });
        }
      });
    };

    // *** LOAD SVG DOCUMENTS ***

    // Use Snap.svg to load the 'previewFront' svg document
    // Add the classes primaryColor and secondaryColor to text fields within the SVG
    var previewFront = Snap('#previewFront');
    var companyName = fetchCompanyName();
    var templatePath = '../sites/all/modules/custom/company_card_creator/svgTemplates/' + companyName + '/template1.svg';
    Snap.load(templatePath, function(f) {
      previewFront.append(f);
      previewFront.attr({
        'width' : '315px',
        'height' : '180px',
      });
    });
    // Use Snap.svg to load the 'templatesFront' svg document
    var templatesFront = Snap('#templatesFront');
    var templateSelection = '../sites/all/modules/custom/company_card_creator/svgTemplates/' + companyName + '/' + companyName + '.svg';
    Snap.load(templateSelection, function(f) {
      templatesFront.append(f);
      // get all rect within loaded svg.  Each template has a rect that has an id to identify it.
      var svgElements = templatesFront.selectAll('g');
      // target the first template
      var firstTemplate = svgElements[0];
      var firstTemplateBackground = firstTemplate.node.firstElementChild;
      // Style the template, since it is selected when page loads
      $(firstTemplateBackground).attr({
        class: 'selected',
        fill: '#E0FFFF',
        stroke: '#F00',
        'stroke-width': '2px'
      });
      changeTemplateFront(firstTemplate);
      // click handeler for when a group in #templatesFront is clicked
      // must insert the click handeler here in order to add it to svg document
      for (var i=0; i<svgElements.length; i++) {
        var el = svgElements[i];
        (function(el) {
          el.mouseover(function() {
              highlightTemplate(el);
          });
          el.mouseout(function() {
              unHighlightTemplate(el);
          });
          el.click(function(e) {
              highlightSelectedTemplateFront(el);
              changeTemplateFront(el);
          });
        })(el);
      }
    });

    // *** SET DEFAULTS ***
    $(function setDefaults() {
      setFields();
      setCardStock();
      updatePrice();
    });

    // *** CLICK HANDLERS ***

    // When cardInfoFront is changed, update svg
    $('#cardInfoFront').on('input focus', 'input', function(e) {
      changeTextFront(e);
    });
    // When a quantity is selected, change the price
    $('#edit-select-quantity').on('change', function() {
      updatePrice();
    });
    // Take the user through the proofing process
    $('#continue_button').click(function(e) {
      e.preventDefault();
      removeEmptyFields();
      saveCard();
    });
    // Allow user to edit their card if needed
    $('#edit').click(function(e) {
      // unset src for proof Images
      $('#proofImageFront').attr('src', '');
      e.preventDefault();
      // Hide proof display
      $('#proof').hide();
      // Show card creation divs
      $('#leftColumn, #midColumn, #rightColumn, #bottomColumn').show();
    });
    $('#addToCart').click(function(e) {
      var approval = $('#edit-approve-proof:checked').val();
      // If proof is not approved
      if (approval === undefined) {
        // prevent form submittion
        e.preventDefault();
        // Notify the user
        alert("You must approve this proof before adding this product to your cart.");
      }
    });

  }); // End $(document).ready()

})(jQuery); // End jQuery $ replacement
