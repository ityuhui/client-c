/*
 * v1_glusterfs_volume_source.h
 *
 * Represents a Glusterfs mount that lasts the lifetime of a pod. Glusterfs volumes do not_ support ownership management or SELinux relabeling.
 */

#ifndef _v1_glusterfs_volume_source_H_
#define _v1_glusterfs_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_glusterfs_volume_source_t {
    char *endpoints; // string
    char *path; // string
    int readOnly; //boolean

} v1_glusterfs_volume_source_t;

v1_glusterfs_volume_source_t *v1_glusterfs_volume_source_create(
    char *endpoints,
    char *path,
    int readOnly
);

void v1_glusterfs_volume_source_free(v1_glusterfs_volume_source_t *v1_glusterfs_volume_source);

v1_glusterfs_volume_source_t *v1_glusterfs_volume_source_parseFromJSON(cJSON *v1_glusterfs_volume_sourceJSON);

cJSON *v1_glusterfs_volume_source_convertToJSON(v1_glusterfs_volume_source_t *v1_glusterfs_volume_source);

#endif /* _v1_glusterfs_volume_source_H_ */

