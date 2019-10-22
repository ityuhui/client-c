/*
 * v1_config_map_node_config_source.h
 *
 * ConfigMapNodeConfigSource contains the information to reference a ConfigMap as a config source for the Node.
 */

#ifndef _v1_config_map_node_config_source_H_
#define _v1_config_map_node_config_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_config_map_node_config_source_t {
    char *kubeletConfigKey; // string
    char *name; // string
    char *namespace; // string
    char *resourceVersion; // string
    char *uid; // string

} v1_config_map_node_config_source_t;

v1_config_map_node_config_source_t *v1_config_map_node_config_source_create(
    char *kubeletConfigKey,
    char *name,
    char *namespace,
    char *resourceVersion,
    char *uid
);

void v1_config_map_node_config_source_free(v1_config_map_node_config_source_t *v1_config_map_node_config_source);

v1_config_map_node_config_source_t *v1_config_map_node_config_source_parseFromJSON(cJSON *v1_config_map_node_config_sourceJSON);

cJSON *v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_t *v1_config_map_node_config_source);

#endif /* _v1_config_map_node_config_source_H_ */

