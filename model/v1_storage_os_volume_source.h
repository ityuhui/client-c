/*
 * v1_storage_os_volume_source.h
 *
 * Represents a StorageOS persistent volume resource.
 */

#ifndef _v1_storage_os_volume_source_H_
#define _v1_storage_os_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_local_object_reference.h"



typedef struct v1_storage_os_volume_source_t {
    char *fsType; // string
    int readOnly; //boolean
    v1_local_object_reference_t *secretRef; //model
    char *volumeName; // string
    char *volumeNamespace; // string

} v1_storage_os_volume_source_t;

v1_storage_os_volume_source_t *v1_storage_os_volume_source_create(
    char *fsType,
    int readOnly,
    v1_local_object_reference_t *secretRef,
    char *volumeName,
    char *volumeNamespace
);

void v1_storage_os_volume_source_free(v1_storage_os_volume_source_t *v1_storage_os_volume_source);

v1_storage_os_volume_source_t *v1_storage_os_volume_source_parseFromJSON(cJSON *v1_storage_os_volume_sourceJSON);

cJSON *v1_storage_os_volume_source_convertToJSON(v1_storage_os_volume_source_t *v1_storage_os_volume_source);

#endif /* _v1_storage_os_volume_source_H_ */

