/*
 * v1_cinder_persistent_volume_source.h
 *
 * Represents a cinder volume resource in Openstack. A Cinder volume must exist before mounting to a container. The volume must also be in the same region as the kubelet. Cinder volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_cinder_persistent_volume_source_H_
#define _v1_cinder_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_secret_reference.h"



typedef struct v1_cinder_persistent_volume_source_t {
    char *fsType; // string
    int readOnly; //boolean
    v1_secret_reference_t *secretRef; //model
    char *volumeID; // string

} v1_cinder_persistent_volume_source_t;

v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source_create(
    char *fsType,
    int readOnly,
    v1_secret_reference_t *secretRef,
    char *volumeID
);

void v1_cinder_persistent_volume_source_free(v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source);

v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source_parseFromJSON(cJSON *v1_cinder_persistent_volume_sourceJSON);

cJSON *v1_cinder_persistent_volume_source_convertToJSON(v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source);

#endif /* _v1_cinder_persistent_volume_source_H_ */

