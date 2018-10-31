<?php

/**
 * @file
 * Defines alterations for the exam type Islandora metadata form.
 */

/**
 * Callback: Alter the Islandora exam type form elements.
 */

function _unbscholar_islandora_form_operations_exam_form_alter(&$form, &$form_state) {
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
}

