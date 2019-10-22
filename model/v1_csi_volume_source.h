/*
 * v1_csi_volume_source.h
 *
 * Represents a source location of a volume to mount, managed by an external CSI driver
 */

#ifndef _v1_csi_volume_source_H_
#define _v1_csi_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_local_object_reference.h"



typedef struct v1_csi_volume_source_t {
    char *driver; // string
    char *fsType; // string
    v1_local_object_reference_t *nodePublishSecretRef; //model
    int readOnly; //boolean
    list_t* volumeAttributes; //map

} v1_csi_volume_source_t;

v1_csi_volume_source_t *v1_csi_volume_source_create(
    char *driver,
    char *fsType,
    v1_local_object_reference_t *nodePublishSecretRef,
    int readOnly,
    list_t* volumeAttributes
);

void v1_csi_volume_source_free(v1_csi_volume_source_t *v1_csi_volume_source);

v1_csi_volume_source_t *v1_csi_volume_source_parseFromJSON(cJSON *v1_csi_volume_sourceJSON);

cJSON *v1_csi_volume_source_convertToJSON(v1_csi_volume_source_t *v1_csi_volume_source);

#endif /* _v1_csi_volume_source_H_ */

