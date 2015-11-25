<?php

/**
 * @file
 * Defines common functions for form element operations.
 */


/**
 * Callback : Get select option values from from a data file.
 *
 * @param string $filename
 *   The filename of the data file to be read from this module's data directory.
 *
 * @return array
 *   A drupal_map_assoc() mapped associative array of lines from the file, or
 *   an empty array if the file is not readable.
 */
function _unbscholar_islandora_form_operations_get_options_from_file($filename) {
  $file_to_read = UNBSCHOLAR_ISLANDORA_FORM_OPERATIONS_DATA_PATH . "/$filename";
  if (!is_readable($file_to_read)) {
    return array();
  }

  return drupal_map_assoc(
    explode(PHP_EOL,trim(file_get_contents($file_to_read)))
  );
}
