<?php
/**
 * @file
 * Views for the default Credit Voucher UI.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_credit_voucher_ui_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'commerce_credit_voucher';
  $view->description = 'Display a list of credit vouchers for the store admin.';
  $view->tag = 'default';
  $view->base_table = 'commerce_credit_voucher';
  $view->human_name = 'Credit Voucher';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Credit vouchers';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'voucher_id' => 'voucher_id',
    'code' => 'code',
    'created' => 'created',
    'view_credit_voucher' => 'view_credit_voucher',
    'edit_credit_voucher' => 'view_credit_voucher',
    'delete_credit_voucher' => 'view_credit_voucher',
  );
  $handler->display->display_options['style_options']['default'] = 'voucher_id';
  $handler->display->display_options['style_options']['info'] = array(
    'voucher_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_credit_voucher' => array(
      'align' => '',
      'separator' => ' &nbsp; ',
      'empty_column' => 0,
    ),
    'edit_credit_voucher' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_credit_voucher' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Commerce Credit Voucher: Credit Voucher ID */
  $handler->display->display_options['fields']['voucher_id']['id'] = 'voucher_id';
  $handler->display->display_options['fields']['voucher_id']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['fields']['voucher_id']['field'] = 'voucher_id';
  $handler->display->display_options['fields']['voucher_id']['label'] = 'ID';
  $handler->display->display_options['fields']['voucher_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['voucher_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['voucher_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['voucher_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['voucher_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['voucher_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['voucher_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['voucher_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['voucher_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['voucher_id']['format_plural'] = 0;
  /* Field: Commerce Credit Voucher: Code */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  $handler->display->display_options['fields']['code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['code']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['code']['hide_alter_empty'] = 1;
  /* Field: Commerce Credit Voucher: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Commerce Credit Voucher: Link */
  $handler->display->display_options['fields']['view_credit_voucher']['id'] = 'view_credit_voucher';
  $handler->display->display_options['fields']['view_credit_voucher']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['fields']['view_credit_voucher']['field'] = 'view_credit_voucher';
  $handler->display->display_options['fields']['view_credit_voucher']['label'] = 'Operations';
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_credit_voucher']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_credit_voucher']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_credit_voucher']['hide_alter_empty'] = 1;
  /* Field: Commerce Credit Voucher: Edit link */
  $handler->display->display_options['fields']['edit_credit_voucher']['id'] = 'edit_credit_voucher';
  $handler->display->display_options['fields']['edit_credit_voucher']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['fields']['edit_credit_voucher']['field'] = 'edit_credit_voucher';
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_credit_voucher']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_credit_voucher']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_credit_voucher']['hide_alter_empty'] = 1;
  /* Field: Commerce Credit Voucher: Delete link */
  $handler->display->display_options['fields']['delete_credit_voucher']['id'] = 'delete_credit_voucher';
  $handler->display->display_options['fields']['delete_credit_voucher']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['fields']['delete_credit_voucher']['field'] = 'delete_credit_voucher';
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_credit_voucher']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_credit_voucher']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_credit_voucher']['hide_alter_empty'] = 1;
  /* Filter criterion: Commerce Credit Voucher: Code */
  $handler->display->display_options['filters']['code']['id'] = 'code';
  $handler->display->display_options['filters']['code']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['filters']['code']['field'] = 'code';
  $handler->display->display_options['filters']['code']['group'] = 1;
  $handler->display->display_options['filters']['code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['code']['expose']['operator_id'] = 'code_op';
  $handler->display->display_options['filters']['code']['expose']['label'] = 'Code';
  $handler->display->display_options['filters']['code']['expose']['operator'] = 'code_op';
  $handler->display->display_options['filters']['code']['expose']['identifier'] = 'code';
  $handler->display->display_options['filters']['code']['expose']['required'] = 0;
  $handler->display->display_options['filters']['code']['expose']['multiple'] = FALSE;
  /* Filter criterion: Commerce Credit Voucher: SKU */
  $handler->display->display_options['filters']['sku']['id'] = 'sku';
  $handler->display->display_options['filters']['sku']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['filters']['sku']['field'] = 'sku';
  $handler->display->display_options['filters']['sku']['group'] = 1;
  $handler->display->display_options['filters']['sku']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['label'] = 'SKU';
  $handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
  $handler->display->display_options['filters']['sku']['expose']['required'] = 0;
  $handler->display->display_options['filters']['sku']['expose']['multiple'] = FALSE;
  /* Filter criterion: Commerce Credit Voucher: Status */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'commerce_credit_voucher';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = 'All';
  $handler->display->display_options['filters']['is_active']['group'] = 1;
  $handler->display->display_options['filters']['is_active']['exposed'] = TRUE;
  $handler->display->display_options['filters']['is_active']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['is_active']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['is_active']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['is_active']['expose']['operator'] = 'is_active_op';
  $handler->display->display_options['filters']['is_active']['expose']['identifier'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/credit-vouchers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Credit vouchers';
  $handler->display->display_options['menu']['description'] = 'Display a list of credit vouchers for the store admin.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Credit vouchers';
  $handler->display->display_options['tab_options']['description'] = 'Display a list of credit vouchers for the store admin.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  $views[$view->name] = $view;

  return $views;
}
