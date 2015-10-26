<?php
/**
 * @file
 * rlc_commerce.slick_default_preset.inc
 */

/**
 * Implements hook_slick_default_presets().
 */
function rlc_commerce_slick_default_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'hompage_carousel';
  $preset->label = 'Hompage Carousel';
  $preset->breakpoints = 2;
  $preset->skin = '';
  $preset->options = array(
    'general' => array(
      'normal' => 'medium',
      'thumbnail' => 'thumbnail',
      'template_class' => 'rlc-header',
      'goodies' => array(
        'random' => 'random',
        'arrow-down' => 0,
        'pattern' => 0,
      ),
      'arrow_down_target' => '',
      'arrow_down_offset' => '',
    ),
    'settings' => array(
      'mobileFirst' => TRUE,
      'asNavFor' => '',
      'accessibility' => TRUE,
      'adaptiveHeight' => FALSE,
      'autoplay' => TRUE,
      'autoplaySpeed' => 1000,
      'pauseOnHover' => TRUE,
      'pauseOnDotsHover' => FALSE,
      'arrows' => TRUE,
      'prevArrow' => '<button type="button" data-role="none" class="slick-prev" aria-label="previous">Previous</button>',
      'nextArrow' => '<button type="button" data-role="none" class="slick-next" aria-label="next">Next</button>',
      'centerMode' => TRUE,
      'centerPadding' => '50px',
      'dots' => FALSE,
      'dotsClass' => 'slick-dots',
      'appendDots' => '$(element)',
      'draggable' => TRUE,
      'fade' => FALSE,
      'focusOnSelect' => TRUE,
      'infinite' => TRUE,
      'initialSlide' => 0,
      'lazyLoad' => 'ondemand',
      'respondTo' => 'window',
      'rtl' => FALSE,
      'rows' => 1,
      'slidesPerRow' => 1,
      'slide' => '',
      'slidesToShow' => 5,
      'slidesToScroll' => 20,
      'speed' => 500,
      'swipe' => TRUE,
      'swipeToSlide' => TRUE,
      'edgeFriction' => 0.34999999999999998,
      'touchMove' => TRUE,
      'touchThreshold' => 5,
      'useCSS' => TRUE,
      'cssEase' => 'ease',
      'cssEaseBezier' => '',
      'cssEaseOverride' => '',
      'easing' => 'linear',
      'variableWidth' => FALSE,
      'vertical' => FALSE,
      'verticalSwiping' => FALSE,
      'waitForAnimate' => TRUE,
    ),
    'responsives' => array(
      'responsive' => array(
        0 => array(
          'breakpoint' => 310,
          'unslick' => FALSE,
          'settings' => array(
            'accessibility' => FALSE,
            'adaptiveHeight' => FALSE,
            'autoplay' => TRUE,
            'autoplaySpeed' => 3000,
            'pauseOnHover' => FALSE,
            'pauseOnDotsHover' => FALSE,
            'arrows' => TRUE,
            'centerMode' => FALSE,
            'centerPadding' => '50px',
            'dots' => FALSE,
            'draggable' => FALSE,
            'fade' => FALSE,
            'focusOnSelect' => FALSE,
            'infinite' => TRUE,
            'initialSlide' => 0,
            'rows' => 1,
            'slidesPerRow' => 1,
            'slidesToShow' => 2,
            'slidesToScroll' => 1,
            'speed' => 500,
            'swipe' => FALSE,
            'swipeToSlide' => FALSE,
            'edgeFriction' => 0.34999999999999998,
            'touchMove' => FALSE,
            'touchThreshold' => 5,
            'useCSS' => FALSE,
            'cssEase' => 'ease',
            'cssEaseBezier' => '',
            'cssEaseOverride' => '',
            'easing' => 'linear',
            'variableWidth' => FALSE,
            'vertical' => FALSE,
            'verticalSwiping' => FALSE,
            'waitForAnimate' => FALSE,
          ),
        ),
        1 => array(
          'breakpoint' => 760,
          'unslick' => FALSE,
          'settings' => array(
            'accessibility' => FALSE,
            'adaptiveHeight' => FALSE,
            'autoplay' => TRUE,
            'autoplaySpeed' => 3000,
            'pauseOnHover' => FALSE,
            'pauseOnDotsHover' => FALSE,
            'arrows' => TRUE,
            'centerMode' => TRUE,
            'centerPadding' => '50px',
            'dots' => FALSE,
            'draggable' => FALSE,
            'fade' => FALSE,
            'focusOnSelect' => FALSE,
            'infinite' => TRUE,
            'initialSlide' => 0,
            'rows' => 1,
            'slidesPerRow' => 1,
            'slidesToShow' => 5,
            'slidesToScroll' => 1,
            'speed' => 500,
            'swipe' => FALSE,
            'swipeToSlide' => FALSE,
            'edgeFriction' => 0.34999999999999998,
            'touchMove' => FALSE,
            'touchThreshold' => 5,
            'useCSS' => FALSE,
            'cssEase' => 'ease',
            'cssEaseBezier' => '',
            'cssEaseOverride' => '',
            'easing' => 'linear',
            'variableWidth' => FALSE,
            'vertical' => FALSE,
            'verticalSwiping' => FALSE,
            'waitForAnimate' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['hompage_carousel'] = $preset;

  return $export;
}
