/*
 * v1_object_meta.h
 *
 * ObjectMeta is metadata that all persisted resources must have, which includes all objects users must create.
 */

#ifndef _v1_object_meta_H_
#define _v1_object_meta_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_managed_fields_entry.h"
#include "v1_owner_reference.h"



typedef struct v1_object_meta_t {
    list_t* annotations; //map
    char *clusterName; // string
    char *creationTimestamp; //date time
    long deletionGracePeriodSeconds; //numeric
    char *deletionTimestamp; //date time
    list_t *finalizers; //primitive container
    char *generateName; // string
    long generation; //numeric
    list_t* labels; //map
    list_t *managedFields; //nonprimitive container
    char *name; // string
    char *namespace; // string
    list_t *ownerReferences; //nonprimitive container
    char *resourceVersion; // string
    char *selfLink; // string
    char *uid; // string

} v1_object_meta_t;

v1_object_meta_t *v1_object_meta_create(
    list_t* annotations,
    char *clusterName,
    char *creationTimestamp,
    long deletionGracePeriodSeconds,
    char *deletionTimestamp,
    list_t *finalizers,
    char *generateName,
    long generation,
    list_t* labels,
    list_t *managedFields,
    char *name,
    char *namespace,
    list_t *ownerReferences,
    char *resourceVersion,
    char *selfLink,
    char *uid
);

void v1_object_meta_free(v1_object_meta_t *v1_object_meta);

v1_object_meta_t *v1_object_meta_parseFromJSON(cJSON *v1_object_metaJSON);

cJSON *v1_object_meta_convertToJSON(v1_object_meta_t *v1_object_meta);

#endif /* _v1_object_meta_H_ */

