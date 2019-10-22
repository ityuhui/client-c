/*
 * v1_csi_persistent_volume_source.h
 *
 * Represents storage that is managed by an external CSI volume driver (Beta feature)
 */

#ifndef _v1_csi_persistent_volume_source_H_
#define _v1_csi_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_secret_reference.h"



typedef struct v1_csi_persistent_volume_source_t {
    v1_secret_reference_t *controllerExpandSecretRef; //model
    v1_secret_reference_t *controllerPublishSecretRef; //model
    char *driver; // string
    char *fsType; // string
    v1_secret_reference_t *nodePublishSecretRef; //model
    v1_secret_reference_t *nodeStageSecretRef; //model
    int readOnly; //boolean
    list_t* volumeAttributes; //map
    char *volumeHandle; // string

} v1_csi_persistent_volume_source_t;

v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_create(
    v1_secret_reference_t *controllerExpandSecretRef,
    v1_secret_reference_t *controllerPublishSecretRef,
    char *driver,
    char *fsType,
    v1_secret_reference_t *nodePublishSecretRef,
    v1_secret_reference_t *nodeStageSecretRef,
    int readOnly,
    list_t* volumeAttributes,
    char *volumeHandle
);

void v1_csi_persistent_volume_source_free(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source);

v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_parseFromJSON(cJSON *v1_csi_persistent_volume_sourceJSON);

cJSON *v1_csi_persistent_volume_source_convertToJSON(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source);

#endif /* _v1_csi_persistent_volume_source_H_ */

