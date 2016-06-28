<?php

/**
 * @file
 * Defines access control components.
 */

/**
 * Implements hook_CMODEL_islandora_view_object().
 */
function unbscholar_islandora_form_operations_ir_thesisCModel_islandora_view_object(AbstractObject $object) {
  if (_unbscholar_islandora_form_operations_datastream_exists_user_unauth($object, 'PDF')) {
    drupal_set_message(
      t(
        'Full text resources related to this item are available for members of the UNB community. <a href="@login_url">Login</a> to view.',
        array(
          '@login_url' => '/user/login?destination=' . current_path(),
        )
      ),
      'warning'
    );
  }
}

/**
 * Determine if a tuque AbstractObject has a datastream the user cannot access.
 *
 * @param AbstractObject $object
 *   The tuque AbstractObject object to view.
 * @param string $datastream_label
 *   The datastream label to check.
 *
 * @return bool
 *   Returns TRUE if the AbstractObject has a datastream with $datastream_label
 *   that the current user cannot access. FALSE otherwise.
 */
function _unbscholar_islandora_form_operations_datastream_exists_user_unauth(AbstractObject $object, $datastream_label) {
  $pdf_datastream_exists = isset($object[$datastream_label]);
  $user_datastream_access = islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $object[$datastream_label]);
  if ($pdf_datastream_exists && $user_datastream_access == FALSE) {
    return TRUE;
  }
  return FALSE;
}
