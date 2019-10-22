/*
 * v1_persistent_volume.h
 *
 * PersistentVolume (PV) is a storage resource provisioned by an administrator. It is analogous to a node. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes
 */

#ifndef _v1_persistent_volume_H_
#define _v1_persistent_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1_persistent_volume_spec.h"
#include "v1_persistent_volume_status.h"



typedef struct v1_persistent_volume_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_persistent_volume_spec_t *spec; //model
    v1_persistent_volume_status_t *status; //model

} v1_persistent_volume_t;

v1_persistent_volume_t *v1_persistent_volume_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_persistent_volume_spec_t *spec,
    v1_persistent_volume_status_t *status
);

void v1_persistent_volume_free(v1_persistent_volume_t *v1_persistent_volume);

v1_persistent_volume_t *v1_persistent_volume_parseFromJSON(cJSON *v1_persistent_volumeJSON);

cJSON *v1_persistent_volume_convertToJSON(v1_persistent_volume_t *v1_persistent_volume);

#endif /* _v1_persistent_volume_H_ */

