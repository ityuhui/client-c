/*
 * v1_config_map.h
 *
 * ConfigMap holds configuration data for pods to consume.
 */

#ifndef _v1_config_map_H_
#define _v1_config_map_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"



typedef struct v1_config_map_t {
    char *apiVersion; // string
    list_t* binaryData; //map
    list_t* data; //map
    char *kind; // string
    v1_object_meta_t *metadata; //model

} v1_config_map_t;

v1_config_map_t *v1_config_map_create(
    char *apiVersion,
    list_t* binaryData,
    list_t* data,
    char *kind,
    v1_object_meta_t *metadata
);

void v1_config_map_free(v1_config_map_t *v1_config_map);

v1_config_map_t *v1_config_map_parseFromJSON(cJSON *v1_config_mapJSON);

cJSON *v1_config_map_convertToJSON(v1_config_map_t *v1_config_map);

#endif /* _v1_config_map_H_ */

