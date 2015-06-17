(function($) { // Throughout the document, replace "$" with "jQuery"
  'use strict';
  $(document).ready(function() { // Begin $(document).ready()

    var $inputFields = $('#cardInfoFront :input[type="text"], #cardInfoBack :input[type="text"]');
    var selectedLogo;

    // Hide selected divs on pageload
    $('#clipartColor, #selectTwoColor, #selectTwoSided, #price, #proof, #removeBack, #frontBack, #cardInfoBack, #previewBack, #templatesBackDisplay').hide();

    // *** SET DEFAULTS ***
    $(function setDefaults() {
      var selectTwoColor = document.getElementById('edit-two-color');
      var selectTwoSided = document.getElementById('edit-two-sided');
      // uncheck two_color form field
      selectTwoColor.checked = false;
      selectTwoColor.value = 0;
      // uncheck two_sided form field
      selectTwoSided.checked = false;
      selectTwoSided.value = 0;
      // update price on page refresh
      updatePrice();
    });

    // *** CREATE COLOR OPTIONS ***

    // Recreate 'Ink Color' options, dynamically add color boxes, add classes for css
    $(function colorOptions() {
      var el;
      // One Color
      var oneColorOptions = $('#oneColor').children();
      // loop through each color altering the color of the text and add colorboxes
      // i = 1 in order to skip the first field, which is not a color
      for (var i = 0; i < oneColorOptions.length; i++) {
        el = oneColorOptions[i];
        var text = $(el).text();
        var color = text.toLowerCase();
        // create new button element.  This is used as the 'colorBox'
        var colorBox = document.createElement('button');
        // set the class of the new button to 'colorBox'
        $(colorBox).attr('class', 'colorBox');
        // set the class of text
        $(el).addClass('oneColorText selectOneColor');
        // add the colorBox before current element
        $(el).prepend(colorBox);
        // sets the color of colorbox
        $(colorBox).css({
            'background-color': color
        });
      }
      // Add .selected to the first color in #oneColor ('Black')
      var styledOptions = $('#oneColor').children();
      var firstStyledColor = styledOptions[0];
      $(firstStyledColor).addClass('selected');
      // Two Colors
      var $twoColors = $('#twoColors').children();
      // loop through each color altering the color of the text and add colorboxes
      // i = 1 in order to skip the first field, which is not a color
      for (i = 0; i < $twoColors.length; i++) {
        el = $twoColors[i];
        var words = $(el).text().split('/');
        var text1 = words[0];
        var text2 = words[1];
        var color1 = text1.toLowerCase();
        var color2 = text2.toLowerCase();
        // create new button element to act as first colorBox
        var colorBox1 = document.createElement('button');
        // create new button element to act as second colorBox
        var colorBox2 = document.createElement('button');
        // set the class of colorBox1 and colorBox2 to colorBox
        $(colorBox1).attr('class', 'colorBox');
        $(colorBox2).attr('class', 'colorBox');
        // set the class of text
        $(el).addClass('twoColorText selectTwoColor');
        // add colorBox2 and colorBox2 before the current element
        $(el).prepend(colorBox1, colorBox2);
         // set the color of colorBox1 to match the first color
        $(colorBox1).css({
          'background-color': color1
        });
        // set the color of colorBox2 to match the second color
        $(colorBox2).css({
          'background-color': color2
        });
      }
    });

    // ** CREATE FONT OPTIONS

    // create changeFontOptions (button that opens font family)
    $(function fontStyleOptions() {
      for (var i=0; i<$inputFields.length; i++) {
        var el = $inputFields[i];
        // create wrapper to wrap input field and changeFontOptions
        var wrapper = document.createElement('div');
        // create button
        var fontOptionsButton = document.createElement('button');
        // set button id to 'changeFontOptions', set type to 'button', and give the button a text value
        // create fontOptions div to wrap font options
        var fontOptions = document.createElement('div');
        // create fontFamily select
        var fontFamily = document.createElement('select');
        // create bold button
        var bold = document.createElement('button');
        // create italic button
        var italic = document.createElement('button');
        // create options
        var o1 = new Option('Helvetica', 'helvetica');
        var o2 = new Option('Futura', 'futura');
        var o3 = new Option('Garamond', 'garamond');
        var o4 = new Option('Frutiger', 'frutiger');
        // add all options to an array
        var options = [o1, o2, o3, o4];
        // give the button a type of 'button'.  Default type is submit, and we dont want that.
        $(fontOptionsButton).attr({
          class: 'button',
          type: 'button',
          title: 'Change Font Options for this Field'
        }).text('A');
        $(bold).attr({
          class: 'button',
          type: 'button',
          title: 'Toggle Bold for this field'
        }).text('B');
        $(italic).attr({
          class: 'button',
          type: 'button',
          title: 'Toggle Italic for this field'
        }).text('I');
        // wrap the input field and button in a div (for themeing)
        $(el).before().wrap(wrapper);
        // add the button before input field, within the wrapper
        $(el).before(fontOptionsButton);
        // add options to select list
        $(fontFamily).append(options);
        // add select list to fontOptions
        $(fontOptions).append(fontFamily);
        // add bold button to fontOptions
        $(fontOptions).append(bold);
        // add italic button to fontOptions
        $(fontOptions).append(italic);
        // add font options div after wrapper input field
        $(el).after(fontOptions);
        $(fontOptions).hide();
        // add click handlers to buttons, and pass parameters
        (function(currentField, fontOptions, fontFamilySelect, fontOptionsButton, bold, italic) {
          $(fontFamily).change(function() {
            changeFieldFont(currentField, fontFamilySelect);
          });
          $(fontOptionsButton).click(function() {
            loadFontOptions(fontOptions, fontOptionsButton);
          });
          $(bold).click(function() {
            boldFont(currentField, bold);
          });
          $(italic).click(function() {
            italicFont(currentField, italic);
          });
        })(el, fontOptions, fontFamily, fontOptionsButton, bold, italic);
      }
    });

    // *** FUNCTIONS ***

    var highlightTemplate = function(el) {
      var rect = el.node;
      if ($(rect).attr('class') !== 'selected') {
        $(rect).attr('fill', '#E0FFFF');
      }
    };
    var unHighlightTemplate = function(el) {
      var rect = el.node;
      if ($(rect).attr('class') !== 'selected') {
        $(rect).attr('fill', '#FFF');
      }
    };
    var highlightSelectedTemplate = function(el) {
      var rect = el.node;
      var svgElement = Snap.select('#templatesFront');
      var svgNodes = svgElement.selectAll('rect');
      for (var i=0; i<svgNodes.length; i++) {
        el = svgNodes[i];
        var node = el.node;
        if ($(node).attr('class') == 'selected') {
          $(node).attr({
            class: '',
            fill: '#FFF',
            stroke: '#000',
            'stroke-width': '1px'
          });
        }
      }
      $(rect).attr({
        class: 'selected',
        stroke: '#F00',
        'stroke-width': '2px'
      });
    };
    var highlightClipart = function(el) {
      var rect = el.getElementsByTagName('rect')[0];
      if ($(rect).attr('class') !== 'selected') {
        $(rect).attr({
          fill: '#E0FFFF',
          opacity: '1'
        });
      }
    };
    var unHighlightClipart = function(el) {
      var rect = el.getElementsByTagName('rect')[0];
      if ($(rect).attr('class') !== 'selected') {
        $(rect).attr({
          fill: '#FFF',
          opacity: '0'
        });
      }
    };
    var highlightSelectedClipart = function(el) {
      var rect = el.getElementsByTagName('rect')[0];
      var logos = clipart.select('#layer1');
      var svgElements = logos.node.children;
      for (var i=0; i<svgElements.length; i++) {
        el = svgElements[i];
        var thisRect = el.getElementsByTagName('rect')[0];
        if ($(thisRect).attr('class') == 'selected') {
          $(thisRect).attr({
            class: '',
            opacity: '0'
          });
        }
      }
      $(rect).attr({
        class: 'selected',
        stroke: '#F00',
        'stroke-width': '2px'
      });
    };
    // fetch the color that is currently selected, and return the value
    var fetchSelectedColor = function() {
      var el;
      var color;
      var colorOptions = $('#oneColor').children();
      var clipartColorOptions = $('#clipartColor').siblings();
      for (var i=0; i<colorOptions.length; i++) {
        el = colorOptions[i];
        if ($(el).hasClass('selected')) {
          color = $(el).text().toLowerCase();
          return color;
        }
      }
      for (i=0; i<clipartColorOptions.length; i++) {
        el = clipartColorOptions[i];
        if ($(el).hasClass('selected')) {
          color = $(el).css('background-color');
          return color;
        }
      }
    };
    // when called, change the color of current logo
    var changeLogoColor = function() {
      var color = fetchSelectedColor();
      var svgNode = Snap.select('#previewFront');
       // find the logo within the svg document, if one exist
      var node = svgNode.selectAll('svg');
      // if node.length is greater than 1, then a logo has already been selected
      if (node.length > 1) {
        // find the existing logo
        var currentLogo = node[1];
        // select all elements within the logo
        var elements = currentLogo.selectAll('*');
        // loop through each element
        for (var i=0; i<elements.length; i++) {
          // get current element
          var currentEl = elements[i];
          // if the elements fill is not white, and it is not none
          if (currentEl.attr('fill') != 'rgb(255, 255, 255)' && currentEl.attr('fill') != 'none') {
            // set the fill color to match the selected color
            currentEl.attr('fill', color);
          }
          // if the elements stroke is not white, and it is not none
          if (currentEl.attr('stroke') != 'rgb(255, 255, 255)' && currentEl.attr('stroke') != 'none') {
            // set the stroke color to match the selected color
            currentEl.attr('stroke', color);
          }
        }
      }
    };
    // when a logo is clicked, add that logo to the previewFront
    var addLogo = function(category, el) {
      // target the loaded svg document
      var svgNode = Snap('#previewFront');
      // get the logo placeHolder from previewFront
      var placeHolder = svgNode.select('#logo');
      // get the x and y values from the placeholder
      var x = $(placeHolder.node).attr('x');
      var y = $(placeHolder.node).attr('y');
      // dynamicly create the file name based on the id of selected logo
      var fileName = '../sites/all/modules/custom/card_creator/logos/' + category + '/' + el.id + '.svg';
      // load the logo that was selected, and give it the x and y values of placeholder
      Snap.load(fileName, function(f) {
        var el = f.select('svg');
        el.attr({
          'x': x,
          'y': y
        });
        previewFront.append(f);
        // set the logo's color to match selection
        changeLogoColor();
      });
      selectedLogo = fileName;
    };
    // when a logo is already on the previewFront, and a different logo has been selected
    var removeLogo = function() {
      // load the previewFront
      var svgNode = Snap('#previewFront');
      // target the node of previewFront
      var node = svgNode.selectAll('svg');
      // if node.length is greater than 3, then a logo has already been selected
      if (node.length > 1) {
        // find the existing logo
        var currentLogo = node[1];
        // remove the existing logo
        currentLogo.remove();
      }
    };
    var addClipartFunctionality = function(category) {
      // target the layer that holds the logos
      var logos = clipart.select('#layer1');
      // find all logos that exist in the document
      var svgElements = logos.node.children;
      // add click handlers to each logo
      for (var i=0; i<svgElements.length; i++) {
        var el = svgElements[i];
        (function(el) {
          $(el).click(function() {
            // removes any logo that exist, if there is one, before adding new logo.
            removeLogo();
            // adds the logo that has been selected
            addLogo(category, el);
            highlightSelectedClipart(el);
          });
          $(el).hover(function() {
            highlightClipart(el);
          }, function() {
            unHighlightClipart(el);
          });
        })(el);
      }
    };
    // when a clipart category is selected, load that clipart svg doc
    var loadClipartCategory = function() {
      var category = $('#clipartCategory').val();
      clipart.clear();
      var fileName = '../sites/all/modules/custom/card_creator/logos/' + category + '/' + category + '.svg';
      Snap.load(fileName, function(f){
        clipart.append(f);
        if (category == 'vehicles') {
          $('#clipart').css({
            'background-color': 'white',
            'height': '680px',
            'width': '100%'
          });
        } else if (category == 'manufacturer') {
          $('#clipart').css({
            'background-color': 'white',
            'height': '950px',
            'width': '100%'
          });
        } else if (category == 'animals') {
          $('#clipart').css({
            'background-color': 'white',
            'height': '100%',
            'width': '100%'
          });
        }
        addClipartFunctionality(category);
      });
    };
    // when called, changes the appropriate svg text field to match the value of corresponding html input field
    var changeTextFront = function(e) {
      var id = '#' + e.target.id;
      var newText = e.target.value;
      $(previewFront.select(id).node).text(newText);
    };
    var changeTextBack = function(e) {
      var id = '#' + e.target.id;
      var newText = e.target.value;
      $(previewBack.select(id).node).text(newText);
    };
    // When font-family is changed, update previewFront.svg
    var changeAllFonts = function() {
      var $newFontFamily = $('#docFontFamily').val();
      var svgNode = Snap.select('#previewFront');
      var svgElement = svgNode.selectAll('text');
      for (var i=0; i < svgElement.length; i++) {
        var el = svgElement[i].node;
        var id = '#' + el.id;
        var textField = svgNode.select(id);
        textField.attr({
          'font-family': $newFontFamily
        });
      }
    };
    // When a font is changed for an individual field
    var changeFieldFont = function(currentField, fontFamilySelect) {
      var newFontFamily = $(fontFamilySelect).val();
      var id = '#' + $(currentField).attr('id');
      var svgNode = Snap.select('#previewFront');
      var svgText = svgNode.select(id);
      svgText.attr({
        'font-family': newFontFamily
      });
    };
    // when FontOptions button is clicked for a field
    var loadFontOptions = function(fontOptions, fontOptionsButton) {
      var display = $(fontOptions).css('display');
      if (display == 'none') {
        $(fontOptions).show();
        $(fontOptionsButton).addClass('selected');
      } else {
        $(fontOptions).hide();
        $(fontOptionsButton).removeClass('selected');
      }
    };
    // when bold is selected for current field
    var boldFont = function(currentField, bold) {
      var svgNode = Snap.select('#previewFront');
      var id = '#' + currentField.id;
      var svgElement = svgNode.select(id);
      if ($(bold).hasClass('selected')) {
        $(bold).removeClass('selected');
        svgElement.attr('font-weight', 'normal');
      } else {
        $(bold).addClass('selected');
        svgElement.attr('font-weight', 'bold');
      }
    };
    // when italic is selected for current field
    var italicFont = function(currentField, italic) {
      var svgNode = Snap.select('#previewFront');
      var id = '#' + currentField.id;
      var svgElement = svgNode.select(id);
      if ($(italic).hasClass('selected')) {
        $(italic).removeClass('selected');
        svgElement.attr('font-style', 'normal');
      } else {
        $(italic).addClass('selected');
        svgElement.attr('font-style', 'italic');
      }
    };
    // Load the template that is selected for Front
    var changeTemplateFront = function(e) {
      var svgNode;
      var templateId = e.target.id;
      var svgLogo = Snap('#previewFront');
      var getLogo = svgLogo.selectAll('svg');
      // fetch the color that is selected
      var color = fetchSelectedColor();
      previewFront.clear(); // removes display of old template
      var fileName = '../sites/all/modules/custom/card_creator/svgTemplates/front/' + templateId + '.svg'; // dynamicly creates url to template
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
          // find current color options
          var colorOptions = $(field).siblings();
          var primaryColor = $(colorOptions[1]).css('background-color');
          var secondaryColor = $(colorOptions[2]).css('background-color');
          var el = svgElement[i];
          var id = el.attr('id');
          if (id == 'companyName' || id == 'name') {
            el.attr('class', 'primaryColor');
          } else {
              el.attr('class', 'secondaryColor');
          }
          // if the appropriate text field is not empty
          if (fieldVal.length !== 0) {
            // target the appropriate svg field, and replace its text with the value of the appropriate text field
            $(previewFront.select(fieldId).node).text(fieldVal);
          }
          if (el.hasClass('primaryColor') && colorOptions.length > 2) {
              el.attr('fill', primaryColor);
              if ($(colorOptions[2]).hasClass('selected')) {
                $(colorOptions[2]).removeClass('selected');
                $(colorOptions[1]).addClass('selected');
              }
          } else if (el.hasClass('secondaryColor') && colorOptions.length > 2) {
              el.attr('fill', secondaryColor);
              if ($(colorOptions[1]).hasClass('selected')) {
                $(colorOptions[1]).removeClass('selected');
                $(colorOptions[2]).addClass('selected');
              }
          } else {
              el.attr('fill', color);
          }
        }
        // If a logo is selected before a new template is selected, give the new template the existing logo.
        if (getLogo.length == 2) {
          // target the loaded svg document
          svgNode = Snap('#previewFront');
          // get the logo placeHolder from previewFront
          var placeHolder = svgNode.select('#logo');
          // get the x and y values from the placeholder
          var x = $(placeHolder.node).attr('x');
          var y = $(placeHolder.node).attr('y');
          // load the logo that was previously selected
          Snap.load(selectedLogo, function(f) {
            var el = f.select('svg');
            el.attr({
              'x': x,
              'y': y
            });
            previewFront.append(f);
            // set the logo color to match selection
            changeLogoColor();
          });
        }
      });
    };
    // Load the template that is selected for Back
    var changeTemplateBack = function(e) {
      var templateId = e.target.id;
      // fetch the color that is selected
      var color = fetchSelectedColor();
      previewBack.clear(); // removes display of old template
      var fileName = '../sites/all/modules/custom/card_creator/svgTemplates/back/' + templateId + '.svg'; // dynamicly creates url to template
      Snap.load(fileName, function(f) {
        previewBack.append(f);
        // target the loaded svg document
        var svgNode = Snap.select('#previewBack');
        // find all text fields within the svg document
        var svgElement = svgNode.selectAll('text');
        // for each svg text field
        for (var i = 0; i < svgElement.length; i++) {
          // target the correct input field for the current svg text field
          var fields = $('#cardInfoBack :input[type="text"]');
          var field = fields[i];
          // get the field value (text content)
          var fieldVal = field.value;
          // retrive the fields id and add a # to the begining in order to be used in an id selector
          var fieldId = '#' + field.id;
          // find current color options
          var colorOptions = $(field).siblings();
          var primaryColor = $(colorOptions[1]).css('background-color');
          var secondaryColor = $(colorOptions[2]).css('background-color');
          var el = svgElement[i];
          var id = el.attr('id');
          if (id == 'backLine1' || id == 'backLine2') {
            el.attr('class', 'primaryColor');
          } else {
              el.attr('class', 'secondaryColor');
          }
          // if the appropriate text field is not empty
          if (fieldVal.length !== 0) {
            // target the appropriate svg field, and replace its text with the value of the appropriate text field
            $(previewBack.select(fieldId).node).text(fieldVal);
          }
          if (el.hasClass('primaryColor') && colorOptions.length > 2) {
              el.attr('fill', primaryColor);
              if ($(colorOptions[2]).hasClass('selected')) {
                $(colorOptions[2]).removeClass('selected');
                $(colorOptions[1]).addClass('selected');
              }
          } else if (el.hasClass('secondaryColor') && colorOptions.length > 2) {
              el.attr('fill', secondaryColor);
              if ($(colorOptions[1]).hasClass('selected')) {
                $(colorOptions[1]).removeClass('selected');
                $(colorOptions[2]).addClass('selected');
              }
          } else {
              el.attr('fill', color);
          }
        }
      });
    };
    // clear any two color options from fields if they exist
    var clearTwoColorOptions = function() {
      var colorBox1;
      var colorBox2;
      // for each input field
      for (var i = 0; i < $inputFields.length; i++) {
        // target current field
        var el = $inputFields[i];
        // find siblings of current field
        var siblings = $(el).siblings();
        // if the siblings.length is greater than 2, a two color option has been selected
        if (siblings.length > 2) {
            // remove siblings (colorBoxes) of the current field
          colorBox1 = siblings[1];
          colorBox2 = siblings[2];
          $(colorBox1).remove();
          $(colorBox2).remove();
        }
      }
      var clipartColor = $('#clipartColor').siblings();
      colorBox1 = clipartColor[0];
      colorBox2 = clipartColor[1];
      $(colorBox1).remove();
      $(colorBox2).remove();
      $('#clipartColor').hide();
    };
    // update previewFront when a two color option is selected
    var updateFillColor = function() {
      // target the loaded svg documents
      var svgFrontNode = Snap.select('#previewFront');
      var svgBackNode = Snap.select('#previewBack');
      // find all text fields within the svg documents
      var frontElements = svgFrontNode.selectAll('text');
      var backElements = svgBackNode.selectAll('text');
      // combine svg text fields
      var svgElements = $(frontElements).add(backElements);
      // for each svg text field
      for (var i = 0; i < svgElements.length; i++) {
        // target the correct input field for the current svg text field
        var field = $inputFields[i];
        // find current color options are
        var colorOptions = $(field).siblings();
        var colorBox1 = colorOptions[1];
        var colorBox2 = colorOptions[2];
        var primaryColor = $(colorBox1).css('background-color');
        var secondaryColor = $(colorBox2).css('background-color');
        var el = svgElements[i];
        if (el.hasClass('primaryColor') && colorOptions.length > 2) {
          el.attr('fill', primaryColor);
          $(colorBox1).addClass('selected');
        } else if (el.hasClass('secondaryColor') && colorOptions.length > 2) {
          el.attr('fill', secondaryColor);
          $(colorBox2).addClass('selected');
        }
      }
    };
    // remove .selected from all color options
    var clearColorSelection = function() {
      var el;
      var oneColor = $('#oneColor').children();
      for (var i=0; i<oneColor.length; i++) {
        el = oneColor[i];
        if ($(el).hasClass('selected')) {
          $(el).removeClass('selected');
        }
      }
      var twoColors = $('#twoColors').children();
      for (i=0; i<twoColors.length; i++) {
        el = twoColors[i];
        if ($(el).hasClass('selected')) {
          $(el).removeClass('selected');
        }
      }
    };
    // when called, create color boxes for input fields and add functionality
    var createColorBoxes = function(tar, el) {
      var colors = $(tar).text().split('/');
      var color1 = colors[0].toLowerCase();
      var color2 = colors[1].toLowerCase();
      // create new paragraph element to act as first colorBox
      var colorBox1 = document.createElement('button');
      // create new paragraph element to act as second colorBox
      var colorBox2 = document.createElement('button');
      // set the class of colorBox1 and colorBox2 to colorBox
      // give colorboxes an id
      $(colorBox1).attr({
        type: 'button',
        class: 'colorBox',
        id: 'primaryColor'
      });
      $(colorBox2).attr({
        type: 'button',
        class: 'colorBox',
        id: 'secondaryColor'
      });
      // set the color of colorBox1 to match the first color
      $(colorBox1).css({
        'background-color': color1,
        'position': 'relative',
        'top': '17px',
        'width': '12px',
        'height': '12px',
        'margin-right': '2px'
      });
      // set the color of colorBox2 to match the second color
      $(colorBox2).css({
        'background-color': color2,
        'margin-right': '2px',
        'position': 'relative',
        'top': '17px',
        'width': '12px',
        'height': '12px'
      });
      // add click handlers to colorBox1 and colorBox2 for each inputField
      // When primary color is clicked, call changeFillColor
      $(colorBox1).click(changeFillColor);
      // When secondary color is clicked, call changeFillColor
      $(colorBox2).click(changeFillColor);
      var siblings = $(el).siblings();
      // if the parent of the input field is #cardInfoFront, then it means that a color option has not been selected yet.
      // if a color options has not been selected, the input field will have 2 siblings
      if (siblings.length == 2) {
        // add colorBox1 and colorBox2 before the current element
        $(el).after(colorBox1, colorBox2);
      } else { // a color option has been selected
        // get the first sibling
        var primaryColorBox = $(siblings[1]);
        // get the second sibling
        var secondaryColorBox = $(siblings[2]);
        // replace existing colorBoxes to match the new selection
        $(primaryColorBox).replaceWith(colorBox1);
        $(secondaryColorBox).replaceWith(colorBox2);
      }
    };
    // when called, create color boxes for Clipart and add functionality
    var createClipartColorBoxes = function(tar, el) {
      var colors = $(tar).text().split('/');
      var color1 = colors[0].toLowerCase();
      var color2 = colors[1].toLowerCase();
      // create new button to act as first colorBox
      var colorBox1 = document.createElement('button');
      // create new button to act as second colorBox
      var colorBox2 = document.createElement('button');
      // set the class of colorBox1 and colorBox2 to colorBox
      // give colorboxes an id
      $(colorBox1).attr({
        type: 'button',
        class: 'colorBox selected',
        id: 'primaryColor'
      });
      $(colorBox2).attr({
        type: 'button',
        class: 'colorBox',
        id: 'secondaryColor'
      });
      // set the color of colorBox1 to match the first color
      $(colorBox1).css({
        'background-color': color1,
        'position': 'relative',
        'top': '5px',
        'width': '12px',
        'height': '12px',
        'margin-right': '2px'
      });
      // set the color of colorBox2 to match the second color
      $(colorBox2).css({
        'background-color': color2,
        'margin-right': '2px',
        'position': 'relative',
        'top': '5px',
        'width': '12px',
        'height': '12px'
      });
      // add click handlers to colorBox1 and colorBox2 for each inputField
      // When primary color is clicked, call changeFillColor
      $(colorBox1).click(selectLogoColor);
      // When secondary color is clicked, call changeFillColor
      $(colorBox2).click(selectLogoColor);
      var siblings = $(el).siblings();
      // if the parent of the input field is #cardInfoFront, then it means that a color option has not been selected yet.
      // if a color options has not been selected, the input field will have 2 siblings
      if (siblings.length === 0) {
        // add colorBox1 and colorBox2 before the current element
        $(el).before(colorBox1, colorBox2);
      } else { // a color option has been selected
        // get the first sibling
        var primaryColorBox = $(siblings[0]);
        // get the second sibling
        var secondaryColorBox = $(siblings[1]);
        // replace existing colorBoxes to match the new selection
        $(primaryColorBox).replaceWith(colorBox1);
        $(secondaryColorBox).replaceWith(colorBox2);
      }
    };
    // when a one color option is selected
    var loadOneColor = function() {
      var selectTwoColor = document.getElementById('edit-two-color');
      var color = $(this).text().toLowerCase();
      // target the loaded svg document
      var svgNode = Snap.select('#previewFront');
      // find all text fields within the svg document
      var svgElement = svgNode.selectAll('text');
      // for each svg text field, set fill color to match selection
      for (var i = 0; i < svgElement.length; i++) {
        // target current svg text field
        var el = svgElement[i];
        // change the current fields fill value to match the color selected
        el.attr('fill', color);
      }
      // Uncheck form field two_color
      selectTwoColor.checked = false;
      // set value of two color to 0
      selectTwoColor.value = 0;
      updatePrice();
      clearColorSelection();
      $(this).addClass('selected');
      changeLogoColor();
      clearTwoColorOptions();
    };
    // when a two color option is selected, create the color options for each field
    var loadTwoColors = function() {
      var selectTwoColor = document.getElementById('edit-two-color');
      var $clipartColor = $('#clipartColor');
      for (var i = 0; i < $inputFields.length; i++) {
        var el = $inputFields[i];
        createColorBoxes(this, el);
      }
      // Check hidden form field two_color
      selectTwoColor.checked = true;
      // set value of hidden form field two_color to 1
      selectTwoColor.value = 1;
      updatePrice();
      $clipartColor.show();
      createClipartColorBoxes(this, $clipartColor);
      clearColorSelection();
      $(this).addClass('selected');
      changeLogoColor();
      updateFillColor();
    };
    // change the color of a field when one of the two color options are selected, when using a two color option
    var changeFillColor = function() {
      // target the current svg file
      var svgNode;
      var color = $(this).css('background-color');
      // find the id of the input field that is a sibling of colorBox
      // add '#' in order to use the id within Snap
      var id = '#' + $(this).siblings('input').attr('id');
      // Load all parent divs
      var parrentDiv = $(this).siblings('input').parents();
      // Find out if input field is for front or back, and act accordingly
      if (parrentDiv[2].id == 'cardInfoFront') {
        svgNode = Snap.select('#previewFront');
      } else if (parrentDiv[2].id == 'cardInfoBack') {
        svgNode = Snap.select('#previewBack');
      }
      // find coresponding svg text field using the created id
      var svgElement = svgNode.select(id);
      // retrieve the id of the colorbox that was clicked
      var colorBoxId = $(this).attr('id');
      // set the fill color to match the color selected
      // change the class of the svg text field to the id of selected colorBox
      // changing class temporarily saves the cards color scheme, allowing the user to switch color options without losing their modifications
      svgElement.attr({
        fill: color,
        class: colorBoxId
      });
      var siblings = $(this).siblings();
      for (var i=0; i<siblings.length; i++) {
        var el = siblings[i];
        if ($(el).hasClass('selected')) {
          $(el).removeClass('selected');
        }
      }
      $(this).addClass('selected');
    };
    var selectLogoColor = function() {
      var siblings = $(this).siblings();
      for (var i=0; i<siblings.length; i++) {
        var el = siblings[i];
        if ($(el).hasClass('selected')) {
          $(el).removeClass('selected');
        }
      }
      $(this).addClass('selected');
      changeLogoColor();
    };
    // Switch to two sided
    var twoSided = function() {
      var selectTwoSided = document.getElementById('edit-two-sided');
      // Check form field two_sided
      selectTwoSided.checked = true;
      // set value of form field two_sided to 1
      selectTwoSided.value = 1;
      $('#addBack').hide();
      $('#removeBack').show();
      $('#frontBack').show();
    };
    // Switch to one sided
    var oneSided = function() {
      var selectTwoSided = document.getElementById('edit-two-sided');
      // Uncheck form field two_sided
      selectTwoSided.checked = false;
      // set value of form field two_sided to 0
      selectTwoSided.value = 0;
      $('#addBack').show();
      $('#removeBack').hide();
      $('#frontBack').hide();
    };
    // Switch to Back
    var switchToBack = function() {
      $('#cardInfoFront').hide();
      $('#previewFront').hide();
      $('#templatesFrontDisplay').hide();
      $('#cardInfoBack').show();
      $('#previewBack').show();
      $('#templatesBackDisplay').show();
    };
    // Switch to Front
    var switchToFront = function() {
      $('#cardInfoFront').show();
      $('#previewFront').show();
      $('#templatesFrontDisplay').show();
      $('#cardInfoBack').hide();
      $('#previewBack').hide();
      $('#templatesBackDisplay').hide();
    };
    var calculateCost = function(isTwoSided, quantity, price500, price1000, pricePerThousand) {
      // Store two sided price
      var twoSidedPrice = 0;
      var price;
      // If this is a Two Sided card
      if (isTwoSided == 1) {
        if (quantity[0].checked === true || quantity[1].checked === true) {
          twoSidedPrice = 14.00;
        } else {
          twoSidedPrice = 10.00;
        }
      }
      // If the quantity is 500
      if (quantity[0].checked === true) {
        price = price500 + twoSidedPrice;
        return price;
      } else if (quantity[1].checked === true) {
        price = price1000 + twoSidedPrice;
        return price;
      } else {
        // Loop through quantities
        for (var i=0; i<quantity.length; i++) {
          // Find the selected quantity
          var el = quantity[i];
          if (el.checked === true) {
            var multiple = i;
            multiple -= 1;
            price = price1000 + (pricePerThousand * multiple) + (twoSidedPrice * (multiple + 1));
            return price;
          }
        }
      }
    };
    var updatePrice = function() {
      var price,
          price500,
          price1000,
          pricePerThousand;
      var $currentPrice = $('#currentPrice');
      var isTwoSided = $('#edit-two-sided').val();
      var cardStock = $('#edit-card-stock-options').children().children('input');
      var quantity = $('#edit-select-quantity').children().children('input');
      // If the cardStock is White Smooth
      if (cardStock[0].checked === true) {
        price500 = 14.95;
        price1000 = 16.95;
        pricePerThousand = 14.95;
        price = calculateCost(isTwoSided, quantity, price500, price1000, pricePerThousand);
      } else if (cardStock[1].checked === true) { // White Linen
        price500 = 23.95;
        price1000 = 26.95;
        pricePerThousand = 22.50;
        price = calculateCost(isTwoSided, quantity, price500, price1000, pricePerThousand);
      } else if (cardStock[2].checked === true || cardStock[3].checked === true || cardStock[4].checked === true) { // Linens => Soft White, Tan, and Gray
        price500 = 24.95;
        price1000 = 28.95;
        pricePerThousand = 23.50;
        price = calculateCost(isTwoSided, quantity, price500, price1000, pricePerThousand);
      } else if (cardStock[5].checked === true || cardStock[6].checked === true) { // Yellow and Kromekote
        price500 = 32.95;
        price1000 = 36.95;
        pricePerThousand = 31.50;
        price = calculateCost(isTwoSided, quantity, price500, price1000, pricePerThousand);
      } else if (cardStock[7].checked === true) { // Woodgrain
        price500 = 47.50;
        price1000 = 53.50;
        pricePerThousand = 46.00;
        price = calculateCost(isTwoSided, quantity, price500, price1000, pricePerThousand);
      }
      var convertedTotal = price.toFixed(2);
      // display price to customer
      $currentPrice.text("Price = $" + convertedTotal);
    };
    // Allows users to view the card before adding it to their cart
    var loadProof = function() {
      var companyName;
      var name;
      var fileDirFront;
      var fileDirBack;
      // Hide all divs within container
      $('#leftColumn').hide();
      $('#midColumn').hide();
      $('#rightColumn').hide();
      $('#bottom').hide();
      // Show Proof Div
      $('#proof').show();
      var isTwoSided = $('#edit-two-sided').val();
      // if card is two sided
      if (isTwoSided == 1) {
        // Generate the filename
        // Replace spaces and special characters for companyName and name fields
        companyName = $('#companyName').val().replace(/[^a-z0-9\s]/gi, '').replace(/[_\s]/g, '');
        name = $('#name').val().replace(/[^a-z0-9\s]/gi, '').replace(/[_\s]/g, '');
        // Replicate the file name given during the ajax callback
        fileDirFront = '../sites/default/files/tmp/' + companyName + '-' + name + '.svg#' + new Date().getTime();
        fileDirBack = '../sites/default/files/tmp/' + companyName + '-' + name + '-back' + '.svg#' + new Date().getTime();
        // Make sure back is visible
        $('#proofImageBack').show();
        // Set the image src to show the user the file that was created
        $('#proofImageFront').attr('src', fileDirFront);
        $('#proofImageBack').attr('src', fileDirBack);
      } else if (isTwoSided == 0) { // card is not two sided
        // Generate the filename
        // Replace spaces and special characters for companyName and name fields
        companyName = $('#companyName').val().replace(/[^a-z0-9\s]/gi, '').replace(/[_\s]/g, '');
        name = $('#name').val().replace(/[^a-z0-9\s]/gi, '').replace(/[_\s]/g, '');
        // Replicate the file name given during the ajax callback
        fileDirFront = '../sites/default/files/tmp/' + companyName + '-' + name + '.svg#' + new Date().getTime();
        // Set the image src to show the user the file that was created
        $('#proofImageFront').attr('src', fileDirFront);
        $('#proofImageBack').hide();
      }
    };
    // SAVE THE ARTWORK
    var saveCard = function() {
      var companyName = $('#companyName').val();
      var name = $('#name').val();
      var svgFront = document.getElementById("previewFront");
      var svgBack = document.getElementById("previewBack");
      var isTwoSided = $('#edit-two-sided').val();
      // if card is two sided
      if (isTwoSided == 1) {
        // Temporarily show front and back in order for img to save correctly
        $('#previewFront').show();
        $('#previewBack').show();
        svgBack.toDataURL("image/svg+xml", {
          callback: function(data) {
            $.ajax({
              type: 'POST',
              url: '/rlcdev/card-creator-ajax-back',
              data: {
                img: data,
                company_name: companyName,
                name: name,
              },
            });
          }
        });
        svgFront.toDataURL("image/svg+xml", {
          callback: function(data) {
            $.ajax({
              type: 'POST',
              url: '/rlcdev/card-creator-ajax-front',
              data: {
                img: data,
                company_name: companyName,
                name: name,
              },
            });
          }
        });
      } else if (isTwoSided == 0) { // card is not two sided
        svgFront.toDataURL("image/svg+xml", {
          callback: function(data) {
            $.ajax({
              type: 'POST',
              url: '/rlcdev/card-creator-ajax-front',
              data: {
                img: data,
                company_name: companyName,
                name: name,
              },
            });
          }
        });
      }
      // Load Proof after ajax is finished
      $(document).ajaxStop(function() {
        loadProof();
      });
    };

    // *** LOAD SVG DOCUMENTS ***

    // Use Snap.svg to load the 'previewFront' svg document
    // Add the classes primaryColor and secondaryColor to text fields within the SVG
    var previewFront = Snap('#previewFront');
    Snap.load('../sites/all/modules/custom/card_creator/svgTemplates/front/template1.svg', function(f) {
      previewFront.append(f);
      previewFront.attr({
        'width' : '315px',
        'height' : '180px',
      });
      // this allows the color options loaded by loadTwoColors to take effect automagically.
      // select all text fields in the svg element
      var svgElement = previewFront.selectAll('text');
      // for every svg text field
      for (var i=0; i<svgElement.length; i++) {
        // target the current svg text field
        var el = svgElement[i];
        // get it's id
        var id = el.attr('id');
        // if the id is equal to 'companyName', or 'name'
        if (id == 'companyName' || id == 'name') {
          // give it the class of 'primaryColor'
          el.attr('class', 'primaryColor');
        } else { // if the id is not 'companyName', or 'name'
          // give it the class of 'secondaryColor'
          el.attr('class', 'secondaryColor');
        }
      }
    });
    // Use Snap.svg to load the 'previewBack' svg document
    // Add the classes primaryColor and secondaryColor to text fields within the SVG
    var previewBack = Snap('#previewBack');
    Snap.load('../sites/all/modules/custom/card_creator/svgTemplates/back/template1.svg', function(f) {
      previewBack.append(f);
      previewBack.attr({
        'width' : '315px',
        'height' : '180px',
      });
      // this allows the color options loaded by loadTwoColors to take effect automagically.
      // select all text fields in the svg element
      var svgElement = previewBack.selectAll('text');
      // for every svg text field
      for (var i=0; i<svgElement.length; i++) {
        // target the current svg text field
        var el = svgElement[i];
        // get it's id
        var id = el.attr('id');
        // if the id is equal to 'companyName', or 'name'
        if (id == 'backLine1' || id == 'backLine2') {
          // give it the class of 'primaryColor'
          el.attr('class', 'primaryColor');
        } else { // if the id is not 'companyName', or 'name'
          // give it the class of 'secondaryColor'
          el.attr('class', 'secondaryColor');
        }
      }
    });
    // Use Snap.svg to load the 'templatesFront' svg document
    var templatesFront = Snap('#templatesFront');
    Snap.load('../sites/all/modules/custom/card_creator/svgTemplates/front/selectTemplateFront.svg', function(f) {
      templatesFront.append(f);
      // get all rect within loaded svg.  Each template has a rect that has an id to identify it.
      var svgElements = templatesFront.selectAll('rect');
      // target the first template
      var firstTemplate = svgElements[0].node;
      // Style the template, since it is selected when page loads
      $(firstTemplate).attr({
        class: 'selected',
        fill: '#E0FFFF',
        stroke: '#F00',
        'stroke-width': '2px'
      });
      // click handeler for when a rect within #templatesFront is clicked
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
              highlightSelectedTemplate(el);
              changeTemplateFront(e);
          });
        })(el);
      }
    });
    // Use Snap.svg to load the 'templatesBack' svg document
    var templatesBack = Snap('#templatesBack');
    Snap.load('../sites/all/modules/custom/card_creator/svgTemplates/back/selectTemplateBack.svg', function(f) {
      templatesBack.append(f);
      // get all rect within loaded svg.  Each template has a rect that has an id to identify it.
      var svgElements = templatesBack.selectAll('rect');
      // target the first template
      var firstTemplate = svgElements[0].node;
      // Style the template, since it is selected when page loads
      $(firstTemplate).attr({
        class: 'selected',
        fill: '#E0FFFF',
        stroke: '#F00',
        'stroke-width': '2px'
      });
      // click handeler for when a rect within #templatesFront is clicked
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
              highlightSelectedTemplate(el);
              changeTemplateBack(e);
          });
        })(el);
      }
    });
    // use Snap.svg to load logos in the 'clipart' svg
    var clipart = Snap('#clipart');
    // load the svg document that acts as a selection for logos
    Snap.load('../sites/all/modules/custom/card_creator/logos/vehicles/vehicles.svg', function(f) {
      clipart.append(f);
      var category = 'vehicles';
      $('#clipart').css({
        'background-color': 'white',
        'height': '680px',
        'width': '100%'
      });
      addClipartFunctionality(category);
    });

    // *** CLICK HANDLERS ***

    // When addBack is clicked, execute twoSided and switch to back
    $('#addBack').click(function() {
      twoSided();
      updatePrice();
      switchToBack();
    });
    // When removeBack is clicked, execute oneSided and switch to front
    $('#removeBack').click(function() {
      oneSided();
      updatePrice();
      switchToFront();
    });
    // When "back" is clicked, switch to back
    $('#back').click(switchToBack);
    // When "front" is clicked, switch to front
    $('#front').click(switchToFront);
    // When cardInfoFront is changed, update svg
    $('#cardInfoFront').on('input focus', 'input', function(e) {
      changeTextFront(e);
    });
    // When cardInfoBack is changed, update svg
    $('#cardInfoBack').on('input focus', 'input', function(e) {
      changeTextBack(e);
    });
    // When a new font is selected for the entire doc, change text.
    $('#docFontFamily').change(changeAllFonts);
    // When a one color option is clicked, call loadOneColor
    $(function() {
      $('.selectOneColor').click(loadOneColor);
    });
    // When a two color option is clicked, call loadTwoColors
    $(function() {
      $('.selectTwoColor').click(loadTwoColors);
    });
    // When a clipart category is clicked, load the svg
    $('#clipartCategory').change(loadClipartCategory);
    // When a quantity is selected, change the price
    $('#edit-select-quantity').on('change', 'input', function() {
      updatePrice();
    });
    $('#edit-card-stock-options').on('change', 'input', function() {
      updatePrice();
    });
    // Take the user through the proofing process
    $('#continue_button').click(function(e) {
      e.preventDefault();
      saveCard();
    });
    // Allow user to edit their card if needed
    $('#edit').click(function(e) {
      e.preventDefault();
      // Hide proof display
      $('#proof').hide();

      // Show card creation divs
      $('#leftColumn').show();
      $('#midColumn').show();
      $('#rightColumn').show();
      $('#bottom').show();
      switchToFront();
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
