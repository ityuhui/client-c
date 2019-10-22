/*
 * v1_iscsi_persistent_volume_source.h
 *
 * ISCSIPersistentVolumeSource represents an ISCSI disk. ISCSI volumes can only be mounted as read/write once. ISCSI volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_iscsi_persistent_volume_source_H_
#define _v1_iscsi_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_secret_reference.h"



typedef struct v1_iscsi_persistent_volume_source_t {
    int chapAuthDiscovery; //boolean
    int chapAuthSession; //boolean
    char *fsType; // string
    char *initiatorName; // string
    char *iqn; // string
    char *iscsiInterface; // string
    int lun; //numeric
    list_t *portals; //primitive container
    int readOnly; //boolean
    v1_secret_reference_t *secretRef; //model
    char *targetPortal; // string

} v1_iscsi_persistent_volume_source_t;

v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_create(
    int chapAuthDiscovery,
    int chapAuthSession,
    char *fsType,
    char *initiatorName,
    char *iqn,
    char *iscsiInterface,
    int lun,
    list_t *portals,
    int readOnly,
    v1_secret_reference_t *secretRef,
    char *targetPortal
);

void v1_iscsi_persistent_volume_source_free(v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source);

v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_parseFromJSON(cJSON *v1_iscsi_persistent_volume_sourceJSON);

cJSON *v1_iscsi_persistent_volume_source_convertToJSON(v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source);

#endif /* _v1_iscsi_persistent_volume_source_H_ */

