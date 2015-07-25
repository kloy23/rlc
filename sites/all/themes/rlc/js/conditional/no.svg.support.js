(function($) {

  var wrapper = document.createElement('div');
  var notification = document.createElement('p');
  var chromeWrapper = document.createElement('div');
  var firefoxWrapper = document.createElement('div');
  var chromeDl = document.createElement('a');
  var firefoxDl = document.createElement('a');

  $(chromeDl).addClass('chromeDl').attr('href', 'https://www.google.com/chrome/browser/desktop/');
  $(firefoxDl).addClass('firefoxDl').attr('href', 'https://www.mozilla.org/en-US/firefox/new/');

  $(chromeWrapper).addClass('dlWrapper').append(chromeDl);
  $(firefoxWrapper).addClass('dlWrapper').append(firefoxDl);

  $(notification).text('Your browser is not supported. Please install the newest version of one of these browsers.')
    .addClass('error')
    .attr('id', 'notification')
    .append(chromeWrapper, firefoxWrapper)
    .css('text-align', 'center');


  $(wrapper).attr('id', 'unsupportedBrowser').append(notification);
  $('#main-content').before(wrapper);




})(jQuery);
