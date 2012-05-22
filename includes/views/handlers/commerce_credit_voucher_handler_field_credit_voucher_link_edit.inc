<?php
/**
 * Field handler to present a link to edit a credit voucher.
 */
class commerce_credit_voucher_handler_field_credit_voucher_link_edit extends commerce_credit_voucher_handler_field_credit_voucher_link {
  function render($values) {
    // Ensure the user has access to edit credit vouchers.
    if (!user_access('edit commerce credit voucher content')) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $voucher_id = $this->get_value($values, 'voucher_id');

    return l($text, 'admin/commerce/credit-vouchers/' . $voucher_id . '/edit', array('query' => drupal_get_destination()));
  }
}
