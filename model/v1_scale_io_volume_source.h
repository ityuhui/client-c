/*
 * v1_scale_io_volume_source.h
 *
 * ScaleIOVolumeSource represents a persistent ScaleIO volume
 */

#ifndef _v1_scale_io_volume_source_H_
#define _v1_scale_io_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_local_object_reference.h"



typedef struct v1_scale_io_volume_source_t {
    char *fsType; // string
    char *gateway; // string
    char *protectionDomain; // string
    int readOnly; //boolean
    v1_local_object_reference_t *secretRef; //model
    int sslEnabled; //boolean
    char *storageMode; // string
    char *storagePool; // string
    char *system; // string
    char *volumeName; // string

} v1_scale_io_volume_source_t;

v1_scale_io_volume_source_t *v1_scale_io_volume_source_create(
    char *fsType,
    char *gateway,
    char *protectionDomain,
    int readOnly,
    v1_local_object_reference_t *secretRef,
    int sslEnabled,
    char *storageMode,
    char *storagePool,
    char *system,
    char *volumeName
);

void v1_scale_io_volume_source_free(v1_scale_io_volume_source_t *v1_scale_io_volume_source);

v1_scale_io_volume_source_t *v1_scale_io_volume_source_parseFromJSON(cJSON *v1_scale_io_volume_sourceJSON);

cJSON *v1_scale_io_volume_source_convertToJSON(v1_scale_io_volume_source_t *v1_scale_io_volume_source);

#endif /* _v1_scale_io_volume_source_H_ */

