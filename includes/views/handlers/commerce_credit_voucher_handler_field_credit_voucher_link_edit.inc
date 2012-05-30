<?php
/**
 * @file
 * Field handler to present a link to a credit voucher.
 */
class commerce_credit_voucher_handler_field_credit_voucher_link_edit extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['voucher_id'] = 'voucher_id';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Ensure the user has access to edit credit vouchers.
    if (!commerce_credit_voucher_access('update')) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $voucher_id = $this->get_value($values, 'voucher_id');

    return l($text, 'admin/commerce/credit-vouchers/' . $voucher_id, array('query' => drupal_get_destination()));
  }
}
