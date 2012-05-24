<?php
/**
 * @file
 * User page callbacks for the Commerce Credit Voucher module.
 */

/**
 * Form callback wrapper: create or edit a commerce credit voucher.
 *
 * @param $commerce_credit_voucher
 *   The commerce credit voucher object to edit through the form.
 *
 * @see commerce_credit_voucher_ui_form()
 */
function commerce_credit_voucher_ui_form_wrapper($commerce_credit_voucher) {
  if ($commerce_credit_voucher->voucher_id) {
    drupal_set_title(t('<em>Edit Credit voucher</em> @voucher_id', array('@voucher_id' => check_plain($commerce_credit_voucher->voucher_id))), PASS_THROUGH);
  }
  return drupal_get_form('commerce_credit_voucher_ui_form', $commerce_credit_voucher);
}


/**
 * Form callback: create or edit a commerce credit voucher.
 *
 * @param $commerce_credit_voucher
 *   The commerce credit voucher object to edit through the form.
 */
function commerce_credit_voucher_ui_form($form, &$form_state, $commerce_credit_voucher) {

  // Set the id to identify this as an cost centre edit form.
  $form['#id'] = 'commerce-credit-voucher-form';

  // Save the commerce credit voucher for later, in case we need it.
  $form_state['commerce_credit_voucher'] = $commerce_credit_voucher;

  // Common fields.
  $form['code'] = array(
    '#type' => 'textfield',
    '#title' => t('Code'),
    '#default_value' => check_plain($commerce_credit_voucher->code),
    '#required' => TRUE,
  );

  $form['amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount'),
    '#default_value' => number_format(check_plain($commerce_credit_voucher->amount) / 100, 2),
    '#required' => TRUE,
  );

  $form['sku'] = array(
    '#type' => 'textfield',
    '#title' => t('SKU'),
    '#default_value' => check_plain($commerce_credit_voucher->sku),
    '#autocomplete_path' => 'commerce_product/autocomplete/commerce_product/line_item_product_selector/product',
  );

  $form['is_active'] = array(
    '#type' => 'radios',
    '#title' => t('Active'),
    '#default_value' => check_plain($commerce_credit_voucher->is_active),
    '#options' => array('1' => t('Yes'), '0' => t('No')),
  );

  $form['start_date'] = array(
    '#type' => 'date',
    '#title' => t('Start Date'),
    '#after_build' => array('commerce_credit_voucher_ui_custom_date_element'),
    '#start_year' => date('Y'),
    '#default_value' => array(
      'year' => date('Y', check_plain($commerce_credit_voucher->start_date)),
      'month' => date('m', check_plain($commerce_credit_voucher->start_date)),
      'day' => date('d', check_plain($commerce_credit_voucher->start_date)),
    ),
  );

  $form['end_date'] = array(
    '#type' => 'date',
    '#title' => t('End Date'),
    '#after_build' => array('commerce_credit_voucher_ui_custom_date_element'),
    '#start_year' => date('Y'),
    '#default_value' => array(
      'year' => date('Y', check_plain($commerce_credit_voucher->end_date)),
      'month' => date('m', check_plain($commerce_credit_voucher->end_date)),
      'day' => date('d', check_plain($commerce_credit_voucher->end_date)),
    ),
  );

  // Add the buttons.
  $form['buttons'] = array();
  $form['buttons']['#weight'] = 100;
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save credit voucher'),
    '#weight' => 5,
    '#submit' => array('commerce_credit_voucher_ui_form_submit'),
  );

  return $form;
}


/**
 * Submit callback for commerce_credit_voucher_ui_form().
 */
function commerce_credit_voucher_ui_form_submit($form, &$form_state) {
  $commerce_credit_voucher = &$form_state['commerce_credit_voucher'];

  $commerce_credit_voucher->code = $form_state['values']['code'];
  $commerce_credit_voucher->amount = $form_state['values']['amount'] * 100;
  $commerce_credit_voucher->sku = $form_state['values']['sku'];
  $commerce_credit_voucher->is_active = $form_state['values']['is_active'];
  $commerce_credit_voucher->start_date = strtotime($form_state['values']['start_date']['year'] . '-'. $form_state['values']['start_date']['month'] . '-' . $form_state['values']['start_date']['day'] . ' 00:00');
  $commerce_credit_voucher->end_date = strtotime($form_state['values']['end_date']['year'] . '-'. $form_state['values']['end_date']['month'] . '-' . $form_state['values']['end_date']['day'] . ' 23:59:59');
  $commerce_credit_voucher->changed = strtotime('now');

  if ($commerce_credit_voucher->is_new) {
    $commerce_credit_voucher->created = strtotime('now');
  }

  // Save the cost centre.
  commerce_credit_voucher_save($commerce_credit_voucher);

  // Notify the user.
  if ($commerce_credit_voucher->voucher_id) {
    drupal_set_message(t('Credit Voucher saved.'));
    watchdog('commerce_credit_voucher', 'Created credit voucher @voucher_id.', array('@voucher_id' => $commerce_credit_voucher->voucher_id), WATCHDOG_NOTICE);
    $form_state['redirect'] = 'admin/commerce/credit-vouchers/' . $commerce_credit_voucher->voucher_id;
  }
  else {
    drupal_set_message(t('Credit voucher could not be created.'), 'error');
  }

}


/**
 * Form callback wrapper: confirmation form for deleting a commerce credit voucher.
 *
 * @param $commerce_credit_voucher
 *   The commerce credit voucher object to delete through the form.
 *
 * @see commerce_credit_voucher_ui_credit_voucher_delete_form()
 */
function commerce_credit_voucher_ui_credit_voucher_delete_form_wrapper($commerce_credit_voucher) {
  drupal_set_title(t('<em>Delete Credit voucher</em> @voucher_id', array('@voucher_id' => check_plain($commerce_credit_voucher->voucher_id))), PASS_THROUGH);
  return drupal_get_form('commerce_credit_voucher_ui_credit_voucher_delete_form', $commerce_credit_voucher);
}


/**
 * Form callback: confirmation form for deleting a commerce credit voucher.
 *
 * @param $commerce_credit_voucher
 *   The commerce credit voucher object to delete through the form.
 *
 * @return
 *   The form array to add or edit a commerce credit voucher.
 *
 * @see confirm_form()
 */
function commerce_credit_voucher_ui_credit_voucher_delete_form($form, &$form_state, $commerce_credit_voucher) {
  $form_state['commerce_credit_voucher'] = $commerce_credit_voucher;

  $form['#submit'][] = 'commerce_credit_voucher_ui_credit_voucher_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete credit voucher @voucher_id?', array('@voucher_id' => $commerce_credit_voucher->voucher_id)),
    '',
    '<p>' . t('Deleting this credit voucher cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}


/**
 * Submit callback for commerce_credit_voucher_ui_credit_voucher_delete_form().
 */
function commerce_credit_voucher_ui_credit_voucher_delete_form_submit($form, &$form_state) {
  $commerce_credit_voucher = $form_state['commerce_credit_voucher'];

  // Notify the user.
  if (commerce_credit_voucher_delete($commerce_credit_voucher->voucher_id)) {
    drupal_set_message(t('Credit voucher @voucher_id has been deleted.', array('@voucher_id' => $commerce_credit_voucher->voucher_id)));
    watchdog('commerce_credit_voucher', 'Deleted credit voucher @voucher_id.', array('@voucher_id' => $commerce_credit_voucher->voucher_id), WATCHDOG_NOTICE);
  }
  else {
    drupal_set_message(t('Credit voucher @voucher_id could not be deleted.', array('@voucher_id' => $commerce_credit_voucher->voucher_id)), 'error');
  }
}


/**
 * Menu callback: display an overview of available types.
 */
function commerce_credit_voucher_ui_credit_voucher_types_overview() {
  $header = array(
    t('Name'),
    t('Operations'),
  );

  $rows = array();

  // Loop through all defined commerce credit voucher types.
  foreach (commerce_credit_voucher_types() as $type => $info) {
    // Build the operation links for the current commerce credit voucher type.
    $links = menu_contextual_links('commerce-credit-voucher-type', 'admin/commerce/credit-vouchers/types', array(strtr($type, array('_' => '-'))));

    // Add the commerce credit voucher type's row to the table's rows array.
    $rows[] = array(
      theme('commerce_credit_voucher_type_admin_overview', array('credit_voucher_type' => $info)),
      theme('links', array('links' => $links, 'attributes' => array('class' => 'links inline operations'))),
    );
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}
