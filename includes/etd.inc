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
  $form['extension']['Facet_Information']['Level_of_Scholarship']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('level.txt');
  $form['extension']['Facet_Information']['Level_of_Scholarship']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['Level_of_Scholarship']['#empty_value'] = '';

  // Institution name.
  $form['extension']['Facet_Information']['Institution_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('campus.txt');
  $form['extension']['Facet_Information']['Institution_Name']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['Institution_Name']['#empty_value'] = '';

  // Faculty name.
  $form['extension']['Facet_Information']['Faculty_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('faculty.txt');
  $form['extension']['Facet_Information']['Faculty_Name']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['Faculty_Name']['#empty_value'] = '';

  // Department name.
  $form['extension']['Facet_Information']['Department_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('department.txt');
  $form['extension']['Facet_Information']['Department_Name']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['Department_Name']['#empty_value'] = '';

  // Discipline name.
  $form['extension']['Facet_Information']['Discipline_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('discipline.txt');
  $form['extension']['Facet_Information']['Discipline_Name']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['Discipline_Name']['#empty_value'] = '';

  // Research group name.
  $form['extension']['Facet_Information']['Group_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('centres.txt');
  $form['extension']['Facet_Information']['Group_Name']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['Group_Name']['#empty_value'] = '';

  // Degree name.
  $form['extension']['Facet_Information']['degreeName']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('degree_name.txt');
  $form['extension']['Facet_Information']['degreeName']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['degreeName']['#empty_value'] = '';

}
