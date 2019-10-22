/*
 * v1_ceph_fs_persistent_volume_source.h
 *
 * Represents a Ceph Filesystem mount that lasts the lifetime of a pod Cephfs volumes do not support ownership management or SELinux relabeling.
 */

#ifndef _v1_ceph_fs_persistent_volume_source_H_
#define _v1_ceph_fs_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_secret_reference.h"



typedef struct v1_ceph_fs_persistent_volume_source_t {
    list_t *monitors; //primitive container
    char *path; // string
    int readOnly; //boolean
    char *secretFile; // string
    v1_secret_reference_t *secretRef; //model
    char *user; // string

} v1_ceph_fs_persistent_volume_source_t;

v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source_create(
    list_t *monitors,
    char *path,
    int readOnly,
    char *secretFile,
    v1_secret_reference_t *secretRef,
    char *user
);

void v1_ceph_fs_persistent_volume_source_free(v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source);

v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source_parseFromJSON(cJSON *v1_ceph_fs_persistent_volume_sourceJSON);

cJSON *v1_ceph_fs_persistent_volume_source_convertToJSON(v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source);

#endif /* _v1_ceph_fs_persistent_volume_source_H_ */

