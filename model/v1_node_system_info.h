/*
 * v1_node_system_info.h
 *
 * NodeSystemInfo is a set of ids/uuids to uniquely identify the node.
 */

#ifndef _v1_node_system_info_H_
#define _v1_node_system_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_node_system_info_t {
    char *architecture; // string
    char *bootID; // string
    char *containerRuntimeVersion; // string
    char *kernelVersion; // string
    char *kubeProxyVersion; // string
    char *kubeletVersion; // string
    char *machineID; // string
    char *operatingSystem; // string
    char *osImage; // string
    char *systemUUID; // string

} v1_node_system_info_t;

v1_node_system_info_t *v1_node_system_info_create(
    char *architecture,
    char *bootID,
    char *containerRuntimeVersion,
    char *kernelVersion,
    char *kubeProxyVersion,
    char *kubeletVersion,
    char *machineID,
    char *operatingSystem,
    char *osImage,
    char *systemUUID
);

void v1_node_system_info_free(v1_node_system_info_t *v1_node_system_info);

v1_node_system_info_t *v1_node_system_info_parseFromJSON(cJSON *v1_node_system_infoJSON);

cJSON *v1_node_system_info_convertToJSON(v1_node_system_info_t *v1_node_system_info);

#endif /* _v1_node_system_info_H_ */

