<?php
/**
 * @file
 * FeedsCommerceCreditVoucherProcessor class.
 */

/**
 * Feeds processor plugin. Create commerce credit vouchers from feed items.
 */
class FeedsCommerceCreditVoucherProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'commerce_credit_voucher';
  }


  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Credit Vouchers');
    return $info;
  }


  /**
   * Creates a new commerce credit voucher in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $commerce_credit_voucher = new stdClass();
    $commerce_credit_voucher->created = strtotime('now');
    $commerce_credit_voucher->changed = strtotime('now');

    return $commerce_credit_voucher;
  }


  /**
   * Loads an existing commerce credit voucher.
   */
  protected function entityLoad(FeedsSource $source, $voucher_id) {
    return commerce_credit_voucher_load($voucher_id);
  }


  /**
   * Validates a commerce credit voucher.
   */
  protected function entityValidate($commerce_credit_voucher) {
    if (empty($commerce_credit_voucher->code)) {
      throw new FeedsValidationException(t('Credit voucher code missing.'));
    }
    if (empty($commerce_credit_voucher->amount) || !is_numeric($commerce_credit_voucher->amount)) {
      throw new FeedsValidationException(t('Credit voucher amount missing or not valid.'));
    }
  }


  /**
   * Saves a commerce commerce credit voucher.
   */
  protected function entitySave($commerce_credit_voucher) {
    commerce_credit_voucher_save($commerce_credit_voucher);
  }


  /**
   * Delete multiple commerce credit vouchers.
   */
  protected function entityDeleteMultiple($voucher_ids) {
    commerce_credit_voucher_delete_multiple($voucher_ids);
  }


  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets += array(
      'type' => array(
        'name' => t('Type'),
        'description' => t('The credit voucher type.'),
      ),
      'code' => array(
        'name' => t('Code'),
        'description' => t('The credit voucher code.'),
        'optional_unique' => TRUE,
      ),
      'amount' => array(
        'name' => t('Amount'),
        'description' => t('How much the voucher is worth.'),
      ),
      'sku' => array(
        'name' => t('SKU'),
        'description' => t('The SKU code the credit voucher is associated with.'),
      ),
      'is_active' => array(
        'name' => t('Status'),
        'description' => t('Whether the credit voucher is active or not.'),
      ),
      'start_date' => array(
        'name' => t('Start date'),
        'description' => t('The date the credit voucher is going to start being accepted.'),
      ),
      'end_date' => array(
        'name' => t('End date'),
        'description' => t('The date the credit voucher expires.'),
      ),
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'commerce_credit_voucher', 'commerce_credit_voucher');

    return $targets;
  }


  /**
   * Get id of an existing feed item term if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($voucher_id = parent::existingEntityId($source, $result)) {
      return $voucher_id;
    }

    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'code':
          $commerce_credit_voucher = commerce_credit_voucher_load_by_code($value, FALSE, FALSE);

          if (!$commerce_credit_voucher) {
            return NULL;
          }
          else {
            return $commerce_credit_voucher->voucher_id;
          }

          break;
      }
    }

    return 0;
  }

}
