<?php

/**
 * @file
 * Defines functions to modify views exposed filter data.
 */

/**
 * Alter a views exposed filter form to use dropdowns populated by solr.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 */
function _unbscholar_islandora_form_operations_alter_faculty_works_filters(&$form) {
  form_load_include($form_state, 'inc', 'unbscholar_islandora_form_operations', 'includes/solr');
  $query_string = 'RELS_EXT_hasModel_uri_ms:"info:fedora/ir:citationCModel"';
  $reset_label = t('Reset Filters');
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbInstitutionName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbFacultyName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbDepartmentName', $query_string);
  $form['submit']['#value'] = 'Filter';
  $form['reset'] = array(
    '#markup' => "<input type=\"reset\" value=\"$reset_label\" class=\"form-submit\">",
  );
}
