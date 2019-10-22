/*
 * v1_volume_mount.h
 *
 * VolumeMount describes a mounting of a Volume within a container.
 */

#ifndef _v1_volume_mount_H_
#define _v1_volume_mount_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_volume_mount_t {
    char *mountPath; // string
    char *mountPropagation; // string
    char *name; // string
    int readOnly; //boolean
    char *subPath; // string
    char *subPathExpr; // string

} v1_volume_mount_t;

v1_volume_mount_t *v1_volume_mount_create(
    char *mountPath,
    char *mountPropagation,
    char *name,
    int readOnly,
    char *subPath,
    char *subPathExpr
);

void v1_volume_mount_free(v1_volume_mount_t *v1_volume_mount);

v1_volume_mount_t *v1_volume_mount_parseFromJSON(cJSON *v1_volume_mountJSON);

cJSON *v1_volume_mount_convertToJSON(v1_volume_mount_t *v1_volume_mount);

#endif /* _v1_volume_mount_H_ */

