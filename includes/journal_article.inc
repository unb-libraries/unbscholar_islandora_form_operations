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
  $form['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']['#ajax'] = array(
    'wrapper' => 'author-details-wrapper',
    'callback' => '_unbscholar_islandora_form_operations_principalAuthorInformation_callback',
    'method' => 'replace',
  );

  // Faculty name.
  $campus = isset($form_state['values']['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']) ? trim($form_state['values']['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']) : $form['principalAuthorInformation']['UNBFacetInfo']['Institution_Name']['#default_value'];
  switch ($campus) {
    case 'University of New Brunswick (Fredericton)':
      $campus_slug = 'fredericton';
      break;

    case 'University of New Brunswick (Saint John)':
      $campus_slug = 'saint_john';
      break;
  }
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file("$campus_slug/faculty.txt");
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#empty_value'] = '';
  $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#ajax'] = array(
    'wrapper' => 'author-details-wrapper',
    'callback' => '_unbscholar_islandora_form_operations_principalAuthorInformation_callback',
    'method' => 'replace',
  );

  // Department name.
  $faculty = isset($form_state['values']['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']) ? trim($form_state['values']['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']) : $form['principalAuthorInformation']['UNBFacetInfo']['Faculty_Name']['#default_value'];
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#empty_value'] = '';
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#validated'] = TRUE;
  if (!in_array(
    $faculty,
    array(
      'Arts',
      'Engineering',
      'Science',
      'Science, Applied Science & Engineering',
    )
  )) {
    $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#type'] = 'hidden';
    $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#value'] = '';
  }
  switch ($faculty) {
    case 'Arts':
      $department_file = 'arts';
      break;

    case 'Engineering':
      $department_file = 'engineering';
      break;

    case 'Science':
    case 'Science, Applied Science & Engineering':
      $department_file = 'science';
      break;

  }
  $form['principalAuthorInformation']['UNBFacetInfo']['Department_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file("$campus_slug/$department_file.txt");

  // Research group name.
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#options'] = _unbscholar_islandora_form_operations_get_options_from_file('centres.txt');
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#validated'] = TRUE;
  $form['principalAuthorInformation']['UNBFacetInfo']['Group_Name']['#empty_value'] = '';
}

/**
 * AJAX form callback : Get 'principalAuthorInformation' form element.
 */
function _unbscholar_islandora_form_operations_principalAuthorInformation_callback($form, $form_state) {
  return $form['principalAuthorInformation'];
}
