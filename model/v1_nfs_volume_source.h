/*
 * v1_nfs_volume_source.h
 *
 * Represents an NFS mount that lasts the lifetime of a pod. NFS volumes do not_ support ownership management or SELinux relabeling.
 */

#ifndef _v1_nfs_volume_source_H_
#define _v1_nfs_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_nfs_volume_source_t {
    char *path; // string
    int readOnly; //boolean
    char *server; // string

} v1_nfs_volume_source_t;

v1_nfs_volume_source_t *v1_nfs_volume_source_create(
    char *path,
    int readOnly,
    char *server
);

void v1_nfs_volume_source_free(v1_nfs_volume_source_t *v1_nfs_volume_source);

v1_nfs_volume_source_t *v1_nfs_volume_source_parseFromJSON(cJSON *v1_nfs_volume_sourceJSON);

cJSON *v1_nfs_volume_source_convertToJSON(v1_nfs_volume_source_t *v1_nfs_volume_source);

#endif /* _v1_nfs_volume_source_H_ */

