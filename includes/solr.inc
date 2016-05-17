<?php

/**
 * @file
 * Defines functions to modify forms based on solr data.
 */

/**
 * Callback: Alter a views exposed filter to use dropdowns populated by solr.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 * @param string $field_name
 *    The field name, minus the type extension.
 * @param string $query
 *      An optional solr query used to contextualize the results.
 */
function _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results(&$form, $field_name, $query = "*:*") {
  $element_key = strtolower("{$field_name}_t");
  $form[$element_key]['#type'] = 'select';
  $form[$element_key]['#options'] = _unbscholar_islandora_form_operations_get_field_associative_array_options_solr($field_name, $query);
  $form[$element_key]['#empty_option'] = "All";
  $form[$element_key]['#validated'] = TRUE;
}

/**
 * Callback: Return an array of unique values in a solr field.
 *
 * @param string $field_name
 *    The field name, minus the type extension.
 * @param string $query
 *      An optional solr query used to contextualize the results.
 *
 * @return array
 *    An associative array of results mapped using drupal_map_assoc().
 */
function _unbscholar_islandora_form_operations_get_field_associative_array_options_solr($field_name, $query) {
  module_load_include('inc', 'islandora_solr', 'includes/db');
  global $_islandora_solr_queryclass;
  $qp = new IslandoraSolrQueryProcessor();
  $_islandora_solr_queryclass = $qp;
  $qp->buildQuery($query);
  $qp->solrParams['facet'] = 'true';
  $qp->solrParams['facet.limit'] = '-1';
  $qp->solrParams['facet.field'] = "{$field_name}_s";
  $qp->executeQuery();
  if (!empty($qp->islandoraSolrResult['facet_counts']['facet_fields']["{$field_name}_s"])) {
    return (drupal_map_assoc(array_keys($qp->islandoraSolrResult['facet_counts']['facet_fields']["{$field_name}_s"])));
  }
  return array();
}
