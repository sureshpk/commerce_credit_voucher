<?php
/**
 * @file
 * Export Commerce Credit Voucher to Views.
 */

/**
 * Implements hook_views_data()
 */
function commerce_credit_voucher_ui_views_data() {
  $data = array();

  $data['commerce_credit_voucher']['table']['group']  = t('Commerce Credit Voucher');

  $data['commerce_credit_voucher']['table']['base'] = array(
    'field' => 'voucher_id',
    'title' => t('Commerce Credit Voucher'),
    'help' => t('Credit Voucher created for the store.'),
    'access query tag' => 'commerce_credit_voucher_access',
  );

  $data['commerce_credit_voucher']['table']['entity type'] = 'commerce_credit_voucher';

  $data['commerce_credit_voucher']['voucher_id'] = array(
    'title' => t('Credit Voucher ID'),
    'help' => t('The unique ID of the credit voucher.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['commerce_credit_voucher']['code'] = array(
    'title' => t('Code'),
    'help' => t('The credit voucher code.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_credit_voucher']['amount'] = array(
    'title' => t('Amount'),
    'help' => t('How much the voucher is worth.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['commerce_credit_voucher']['sku'] = array(
    'title' => t('SKU'),
    'help' => t('The SKU code the credit voucher is associated with.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_credit_voucher']['is_active'] = array(
    'title' => t('Status'),
    'help' => t('Whether the credit voucher is active or not.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_credit_voucher']['start_date'] = array(
    'title' => t('Start date'),
    'help' => t('The date the credit voucher is going to start being accepted.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_credit_voucher']['end_date'] = array(
    'title' => t('End date'),
    'help' => t('The date the credit voucher expires.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_credit_voucher']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the credit voucher was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_credit_voucher']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the credit voucher was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_credit_voucher']['edit_credit_voucher'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the credit voucher.'),
      'handler' => 'commerce_credit_voucher_handler_field_credit_voucher_link_edit',
    ),
  );

  $data['commerce_credit_voucher']['delete_credit_voucher'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the credit voucher.'),
      'handler' => 'commerce_credit_voucher_handler_field_credit_voucher_link_delete',
    ),
  );

  return $data;
}
