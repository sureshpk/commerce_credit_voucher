<?php
/**
 * @file
 * User page callbacks for the Commerce Credit Voucher module.
 */

/**
 * Menu callback to create a cost centre
 */
function cost_centre_add() {
  global $user;

  $cost_centre = entity_get_controller('cost_centre')->create();
  drupal_set_title(t('Create Cost Centre'), PASS_THROUGH);

  return drupal_get_form('cost_centre_form', $cost_centre);
}


/**
 * Create Cost Centre form.
 */
function cost_centre_form($form, &$form_state, $cost_centre) {
  // Set the id to identify this as an cost centre edit form.
  $form['#id'] = 'cost-centre-form';

  // Save the cost centre for later, in case we need it.
  $form['#cost_centre'] = $cost_centre;
  $form_state['cost_centre'] = $cost_centre;

  // Common fields. We don't have many.
  $form['cost_centre_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Cost Centre Code'),
    '#default_value' => $cost_centre->cost_centre_code,
    '#weight' => -5,
    '#required' => TRUE,
  );
  $form['cost_centre_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Cost Centre Decription'),
    '#default_value' => $cost_centre->cost_centre_desc,
    '#weight' => -4,
    '#required' => TRUE,
  );

  // Add the buttons.
  $form['buttons'] = array();
  $form['buttons']['#weight'] = 100;
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 5,
    '#submit' => array('cost_centre_form_submit'),
  );

  if (!empty($cost_centre->cost_centre_id_pk)) {
    $form['buttons']['delete'] = array(
      '#access' => user_access('delete cost_centre'),
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#weight' => 15,
      '#submit' => array('cost_centre_form_delete_submit'),
    );
  }

  $form['#validate'][] = 'cost_centre_form_validate';
  field_attach_form('cost_centre', $cost_centre, $form, $form_state);

  return $form;
}


/**
 * cost centre form valdation callback
 *
 * Tell the Field system to do its own validation.
 */
function cost_centre_form_validate($form, &$form_state) {
  $cost_centre = $form_state['cost_centre'];

  $result = db_query('SELECT * FROM {cost_centre} WHERE cost_centre_code = :code AND cost_centre_id_pk <> :curid', array(
    ':code' => $form_state['values']['cost_centre_code'],
    ':curid' => $form_state['build_info']['args'][0]->cost_centre_id_pk
  ));

  if(($result->rowCount()) > 0){
    form_set_error('cost_centre_code', 'A Cost Centre with this code already exists.');
  }

  // Field validation.
  field_attach_form_validate('cost_centre', $cost_centre, $form, $form_state);
}


/**
 * Cost Centre form submit callback
 */
function cost_centre_form_submit($form, &$form_state) {
  global $user;
  $cost_centre = &$form_state['cost_centre'];
  // Set the cost centre's uid if it's being created at this time.
  if (empty($cost_centre->uid)) {
    $cost_centre->uid = $user->uid;
  }
  $cost_centre->cost_centre_code = $form_state['values']['cost_centre_code'];
  $cost_centre->cost_centre_desc = $form_state['values']['cost_centre_desc'];
  // Notify field widgets.
  field_attach_submit('cost_centre', $cost_centre, $form, $form_state);
  // Save the cost centre.
  cost_centre_save($cost_centre);
  // Notify the user.
  if($cost_centre->cost_centre_id_pk){
    drupal_set_message(t('Cost Centre saved.'));
    $form_state['redirect'] = 'cost-centre/' . $cost_centre->cost_centre_id_pk;
  }

}


/**
 * Let the controller class do the hard work and
 * save the cost centre.
 */
function cost_centre_save($cost_centre) {
  return entity_get_controller('cost_centre')->save($cost_centre);
}


/**
 * Basically display a Cost Centre.
 */
function cost_centre_page_view($cost_centre, $view_mode = 'full') {

  // Remove previously built content, if exists.
  $cost_centre->content = array();

  if ($view_mode == 'teaser') {
    $cost_centre->content['title'] = array(
      '#markup' => filter_xss($cost_centre->title),
      '#weight' => -5,
    );
  }
  // Build fields content.
  field_attach_prepare_view('cost_centre', array($cost_centre->cost_centre_id_pk => $cost_centre), $view_mode);
  entity_prepare_view('cost_centre', array($cost_centre->cost_centre_id_pk => $cost_centre));
  $cost_centre->content += field_attach_view('cost_centre', $cost_centre, $view_mode);

  return $cost_centre->content;
}


/**
 * Cost centre edit page callback.
 */
function cost_centre_page_edit($cost_centre) {
  drupal_set_title(t('Edit @title', array('@title' => $cost_centre->cost_centre_desc)), PASS_THROUGH);
  return drupal_get_form('cost_centre_form', $cost_centre);
}


/**
 * Form function to confirm deletion.
 *
 * Rather than build a complete form, we will simply
 * pass data on to a utility function of the Form API
 * called confirm_form().
 */
function cost_centre_delete_confirm($form, &$form_state, $cost_centre) {
  $form['#cost_centre'] = $cost_centre;

  // Always provide entity id in the same form key as in the entity edit form.
  $form['cost_centre_id_pk'] = array(
    '#type' => 'value',
    '#value' => $cost_centre->cost_centre_id_pk
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete %title?', array('%title' => $cost_centre->title)),
    'cost-centre/' . $cost_centre->cost_centre_id_pk,
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}


/**
 * Delete submit for Cost Centres
 */
function cost_centre_form_delete_submit($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $cost_centre = $form['#cost_centre'];
  $form_state['redirect'] = array('cost-centre/' . $cost_centre->cost_centre_id_pk . '/delete', array('query' => $destination));
}


/**
 * Confirmation
 *  The submit callback handles deleting the cost centre.
 */
function cost_centre_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $cost_centre = cost_centre_load($form_state['values']['cost_centre_id_pk']);
    cost_centre_delete($form_state['values']['cost_centre_id_pk']);
    watchdog('cost_centre', 'deleted %title.', array('%title' => $cost_centre->title));
  }

  drupal_set_message(t('%title has been deleted.', array('%title' => $cost_centre->title)));

  $form_state['redirect'] = '<front>';
}


/**
 * The summary page for cost centres.
 */
function cost_centre_information() {
  return 'Information';
}
