/*
 * v1_persistent_volume_list.h
 *
 * PersistentVolumeList is a list of PersistentVolume items.
 */

#ifndef _v1_persistent_volume_list_H_
#define _v1_persistent_volume_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_list_meta.h"
#include "v1_persistent_volume.h"



typedef struct v1_persistent_volume_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} v1_persistent_volume_list_t;

v1_persistent_volume_list_t *v1_persistent_volume_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_persistent_volume_list_free(v1_persistent_volume_list_t *v1_persistent_volume_list);

v1_persistent_volume_list_t *v1_persistent_volume_list_parseFromJSON(cJSON *v1_persistent_volume_listJSON);

cJSON *v1_persistent_volume_list_convertToJSON(v1_persistent_volume_list_t *v1_persistent_volume_list);

#endif /* _v1_persistent_volume_list_H_ */

