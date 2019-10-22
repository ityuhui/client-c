/*
 * v1_managed_fields_entry.h
 *
 * ManagedFieldsEntry is a workflow-id, a FieldSet and the group version of the resource that the fieldset applies to.
 */

#ifndef _v1_managed_fields_entry_H_
#define _v1_managed_fields_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct v1_managed_fields_entry_t {
    char *apiVersion; // string
    char *fieldsType; // string
    object_t *fieldsV1; //object
    char *manager; // string
    char *operation; // string
    char *time; //date time

} v1_managed_fields_entry_t;

v1_managed_fields_entry_t *v1_managed_fields_entry_create(
    char *apiVersion,
    char *fieldsType,
    object_t *fieldsV1,
    char *manager,
    char *operation,
    char *time
);

void v1_managed_fields_entry_free(v1_managed_fields_entry_t *v1_managed_fields_entry);

v1_managed_fields_entry_t *v1_managed_fields_entry_parseFromJSON(cJSON *v1_managed_fields_entryJSON);

cJSON *v1_managed_fields_entry_convertToJSON(v1_managed_fields_entry_t *v1_managed_fields_entry);

#endif /* _v1_managed_fields_entry_H_ */

