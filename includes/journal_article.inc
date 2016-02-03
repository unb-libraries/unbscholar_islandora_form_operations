<?php

/**
 * @file
 * Defines alterations for the journal_article type Islandora metadata form.
 */

/**
 * Callback: Alter the Islandora journal_article type form elements.
 */
function _unbscholar_islandora_form_operations_journal_article_form_alter(&$form, &$form_state) {

  // Article is published?
  $form['host']['#states'] = array(
    'visible' => array(
      ':input[name="ArticleIsPublished"]' => array('checked' => TRUE),
    ),
  );

  // Collection.
  $form['extensionTop']['facetInformationTop']['collectionName']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('collection.txt');
  $form['extensionTop']['facetInformationTop']['collectionName']['#validated'] = TRUE;

  // Level of scholarship.
  $form['principalAuthorInformation']['UNBFacetInfo']['Level_of_Scholarship']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('level.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Level_of_Scholarship']['#validated'] = TRUE;

  // Institution name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('campus.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']['#validated'] = TRUE;

  // Faculty name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('faculty.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#validated'] = TRUE;

  // Department name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('department.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#validated'] = TRUE;

  // Discipline name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Discipline_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('discipline.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Discipline_Name']['#validated'] = TRUE;

  // Research group name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('centres.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#validated'] = TRUE;

  // Hide some fields from all but administrators.
  if (
    !user_has_role(user_role_load_by_name('METADATA_RECORDS_EDITOR')->rid) &&
    !user_has_role(user_role_load_by_name('ADMINISTRATOR')->rid)
  ) {
    hide($form['extensionTop']['facetInformationTop']['collectionName']);
    hide($form['titleInfoAlt']['titleAlt']);
    hide($form['identifiers']['uri']);
    hide($form['identifiers']['pmcid']);
    hide($form['identifiers']['oclc']);
  }
}

/**
 * AJAX form callback : Get 'principalAuthorInformation' form element.
 */
function _unbscholar_islandora_form_operations_principal_author_information_callback($form, $form_state) {
  return $form['principalAuthorInformation'];
}
