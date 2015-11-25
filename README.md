# UNB Scholar Islandora Metadata Form Operations
Local changes and a rudimentary framework used to alter [islandora_xml_forms builder forms](https://github.com/Islandora/islandora_xml_forms) metadata forms to populate select elements with controlled vocabularies, and change default behaviors via Form API.

Approaching the problem with this model eases the burden of maintaining a controlled vocabulary across several forms, arranging value dependencies between form values, or referencing external data sources to serve as a controlled vocabulary.

## Looking to Re-Use this?
This module isn't generalized. Implementing it in your unique situation would involve:

* Adding an 'formDataType' element (hidden, with a unique ID as the #value) to the form you wish to alter.
* Creating a UNIQUE_ID.inc file inside the includes directory, which must include a `_unbscholar_islandora_form_operations_UNIQUE_ID_form_alter()` form hook function.

## License
- UNB Libraries Controlled Vocabularies for Islandora Forms is licensed under the MIT License:
  - http://opensource.org/licenses/mit-license.html
- Attribution is not required, but much appreciated:
  - `UNB Libraries Controlled Vocabularies for Islandora Forms by UNB Libraries`
