/*
 * v1_storage_class_list.h
 *
 * StorageClassList is a collection of storage classes.
 */

#ifndef _v1_storage_class_list_H_
#define _v1_storage_class_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_list_meta.h"
#include "v1_storage_class.h"



typedef struct v1_storage_class_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} v1_storage_class_list_t;

v1_storage_class_list_t *v1_storage_class_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_storage_class_list_free(v1_storage_class_list_t *v1_storage_class_list);

v1_storage_class_list_t *v1_storage_class_list_parseFromJSON(cJSON *v1_storage_class_listJSON);

cJSON *v1_storage_class_list_convertToJSON(v1_storage_class_list_t *v1_storage_class_list);

#endif /* _v1_storage_class_list_H_ */

