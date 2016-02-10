<?php

/**
 * @file
 * Defines alterations for the etd type Islandora metadata form.
 */

/**
 * Callback: Alter the Islandora etd type form elements.
 */
function _unbscholar_islandora_form_operations_etd_form_alter(&$form, &$form_state) {

  // Article is published?
  $form['host']['#states'] = array(
    'visible' => array(
      ':input[name="ArticleIsPublished"]' => array('value' => 'Yes'),
    ),
  );

  // Collection.
  $form['extensionTop']['facetInformationTop']['collectionName']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('collection.txt');
  $form['extensionTop']['facetInformationTop']['collectionName']['#validated'] = TRUE;
  $form['extensionTop']['facetInformationTop']['collectionName']['#empty_value'] = '';

  // Level of scholarship.
  $form['principalAuthorInformation']['UNBFacetInfo']['Level_of_Scholarship']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('level.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Level_of_Scholarship']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Level_of_Scholarship']['#empty_value'] = '';

  // Institution name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('campus.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']['#empty_value'] = '';

  // Faculty name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('faculty.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#empty_value'] = '';

  // Department name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('department.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#empty_value'] = '';

  // Discipline name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Discipline_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('discipline.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Discipline_Name']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Discipline_Name']['#empty_value'] = '';

  // Research group name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('centres.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#empty_value'] = '';

}
