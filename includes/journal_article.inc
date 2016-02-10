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
      ':input[name="ArticleIsPublished"]' => array('value' => 'Yes'),
    ),
  );

  // Collection.
  $form['extension']['Facet_Information']['collectionName']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('collection.txt');
  $form['extension']['Facet_Information']['collectionName']['#validated'] = TRUE;
  $form['extension']['Facet_Information']['collectionName']['#empty_value'] = '';

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

  // Hide some fields from all but administrators.
  if (
    !user_has_role(user_role_load_by_name('METADATA_RECORDS_EDITOR')->rid) &&
    !user_has_role(user_role_load_by_name('ADMINISTRATOR')->rid)
  ) {
    hide($form['extension']['Facet_Information']['collectionName']);
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
