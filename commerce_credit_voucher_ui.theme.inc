<?php
/**
 * @file
 * Theme functions for the Commerce Credit Voucher module.
 */

/**
 * Returns HTML for a list of available commerce credit voucher types.
 *
 * @param $variables
 *   An associative array containing:
 *   - credit_voucher_type: An array of info about a particular commerce
 *     credit voucher type.
 *
 * @ingroup themeable
 */
function theme_commerce_credit_voucher_type_add_page($variables) {
  $credit_voucher_types = $variables['credit_voucher_types'];
  $output = '';

  if (!empty($credit_voucher_types)) {
    $items = array();

    foreach ($credit_voucher_types as $type => $info) {
      $items[] = array(
        'title' => $info->name,
        'description' => $info->description,
        'href' => 'admin/commerce/credit-vouchers/add/' . strtr($type, '_', '-'),
        'localized_options' => array(),
      );
    }

    $output = theme('admin_block_content', array('content' => $items));
  }

  return $output;
}


/**
 * Builds an overview of a commerce credit voucher type for display to an administrator.
 *
 * @param $variables
 *   An array of variables used to generate the display; by default includes the
 *   type key with a value of the commerce credit voucher type object.
 *
 * @ingroup themeable
 */
function theme_commerce_credit_voucher_type_admin_overview($variables) {
  $credit_voucher_type = $variables['credit_voucher_type'];

  $output = check_plain($credit_voucher_type->name);
  $output .= ' <small>' . t('(Machine name: @type)', array('@type' => $credit_voucher_type->type)) . '</small>';
  $output .= '<div class="description">' . filter_xss_admin($credit_voucher_type->description) . '</div>';

  return $output;
}
