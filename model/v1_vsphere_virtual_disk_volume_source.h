/*
 * v1_vsphere_virtual_disk_volume_source.h
 *
 * Represents a vSphere volume resource.
 */

#ifndef _v1_vsphere_virtual_disk_volume_source_H_
#define _v1_vsphere_virtual_disk_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_vsphere_virtual_disk_volume_source_t {
    char *fsType; // string
    char *storagePolicyID; // string
    char *storagePolicyName; // string
    char *volumePath; // string

} v1_vsphere_virtual_disk_volume_source_t;

v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_create(
    char *fsType,
    char *storagePolicyID,
    char *storagePolicyName,
    char *volumePath
);

void v1_vsphere_virtual_disk_volume_source_free(v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source);

v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_parseFromJSON(cJSON *v1_vsphere_virtual_disk_volume_sourceJSON);

cJSON *v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source);

#endif /* _v1_vsphere_virtual_disk_volume_source_H_ */

