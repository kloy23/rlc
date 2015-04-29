<?php

/**
 * Implements hook_rules_event_info().
 */
function card_creator_rules_event_info() {
  return array(
    'card_creator_card_created' => array(
      'label' => t('After a business card has been created'),
      'module' => 'card_creator',
      'group' => 'Card Creator',
    ),
  );
}
