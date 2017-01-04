<?php

/**
 * @file
 * Defines functions to modify views exposed filter data.
 */

/**
 * Alter electronic_theses view filters to use dropdowns populated by solr.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 */
function _unbscholar_islandora_form_operations_alter_electronic_theses_filters(&$form) {
  form_load_include($form_state, 'inc', 'unbscholar_islandora_form_operations', 'includes/solr');
  $query_string = 'RELS_EXT_hasModel_uri_ms:"info:fedora/ir:thesisCModel" AND mods_genre_s:"Thesis / Dissertation"';

  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbInstitutionName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbFacultyName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbDepartmentName', $query_string);
  _unbscholar_islandora_form_operations_alter_filters_add_reset($form);
}

/**
 * Alter faculty_works view filters to use dropdowns populated by solr.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 */
function _unbscholar_islandora_form_operations_alter_faculty_works_filters(&$form) {
  form_load_include($form_state, 'inc', 'unbscholar_islandora_form_operations', 'includes/solr');
  $query_string = 'RELS_EXT_hasModel_uri_ms:"info:fedora/ir:citationCModel"';

  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbInstitutionName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbFacultyName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbDepartmentName', $query_string);
  _unbscholar_islandora_form_operations_alter_filters_add_reset($form);
}

/**
 * Alter senior_reports view filters to use dropdowns populated by solr.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 */
function _unbscholar_islandora_form_operations_alter_senior_reports_filters(&$form) {
  form_load_include($form_state, 'inc', 'unbscholar_islandora_form_operations', 'includes/solr');
  $query_string = 'mods_genre_s:"Senior Report"';

  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbFacultyName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbDepartmentName', $query_string);
  _unbscholar_islandora_form_operations_alter_filters_add_reset($form);
}

/**
 * Alter CRI view filters to use dropdowns populated by solr.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 */
function _unbscholar_islandora_form_operations_alter_cri_filters(&$form) {
  form_load_include($form_state, 'inc', 'unbscholar_islandora_form_operations', 'includes/solr');
  $query_string = 'mods_extension_unbfacetInfo_unbGroupName_t:"Canadian Rivers Institute (CRI)"';

  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_genre', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbCollectionName', $query_string);
  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_extension_unbfacetInfo_unbDisciplineName', $query_string);
  _unbscholar_islandora_form_operations_alter_filters_add_reset($form);
}

/**
 * Alter L2RIC view filters to use dropdowns populated by solr.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 */
function _unbscholar_islandora_form_operations_alter_l2ric_filters(&$form) {
  form_load_include($form_state, 'inc', 'unbscholar_islandora_form_operations', 'includes/solr');
  $query_string = 'mods_extension_unbfacetInfo_unbGroupName_t:"Second Language Research Institute of Canada"';

  _unbscholar_islandora_form_operations_replace_field_with_unique_solr_results($form, 'mods_genre', $query_string);
  _unbscholar_islandora_form_operations_alter_filters_add_reset($form);
}

/**
 * Alter view filters form to add a reset button.
 *
 * @param object $form
 *      The form that will have the controls added to iterator_apply.
 */
function _unbscholar_islandora_form_operations_alter_filters_add_reset(&$form) {
  $reset_label = t('Reset Filters');
  $cur_url = strtok($_SERVER["REQUEST_URI"],'?');
  $form['submit']['#value'] = 'Filter';
  $form['reset'] = array(
    '#markup' => "<a class=\"form-submit\" href=\"$cur_url\">$reset_label</a>",
  );
}
