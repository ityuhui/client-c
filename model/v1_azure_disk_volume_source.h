/*
 * v1_azure_disk_volume_source.h
 *
 * AzureDisk represents an Azure Data Disk mount on the host and bind mount to the pod.
 */

#ifndef _v1_azure_disk_volume_source_H_
#define _v1_azure_disk_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_azure_disk_volume_source_t {
    char *cachingMode; // string
    char *diskName; // string
    char *diskURI; // string
    char *fsType; // string
    char *kind; // string
    int readOnly; //boolean

} v1_azure_disk_volume_source_t;

v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_create(
    char *cachingMode,
    char *diskName,
    char *diskURI,
    char *fsType,
    char *kind,
    int readOnly
);

void v1_azure_disk_volume_source_free(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source);

v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_parseFromJSON(cJSON *v1_azure_disk_volume_sourceJSON);

cJSON *v1_azure_disk_volume_source_convertToJSON(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source);

#endif /* _v1_azure_disk_volume_source_H_ */

