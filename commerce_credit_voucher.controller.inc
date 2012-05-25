<?php
/**
 * @file
 * The controller for the commerce credit voucher entity containing the CRUD operations.
 */

/**
 * Entity controller for commerce credit voucher entity objects.
 */
class CommerceCreditVoucherEntityController extends DrupalCommerceEntityController {

  /**
   * Create a default credit voucher.
   *
   * @param array $values
   *   An array of values to set, keyed by property name.
   *
   * @return
   *   A commerce credit voucher object with all default fields initialized.
   */
  public function create(array $values = array()) {
    $values += array(
      'voucher_id' => NULL,
      'code' => '',
      'amount' => NULL,
      'sku' => '',
      'number_of_uses' => 1,
      'is_active' => 1,
      'start_date' => strtotime('now'),
      'end_date' => strtotime('now'),
      'created' => '',
      'changed' => '',
    );

    return parent::create($values);
  }

}
