#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_config_source.h"



v1_node_config_source_t *v1_node_config_source_create(
    v1_config_map_node_config_source_t *configMap
    ) {
	v1_node_config_source_t *v1_node_config_source_local_var = malloc(sizeof(v1_node_config_source_t));
    if (!v1_node_config_source_local_var) {
        return NULL;
    }
	v1_node_config_source_local_var->configMap = configMap;

	return v1_node_config_source_local_var;
}


void v1_node_config_source_free(v1_node_config_source_t *v1_node_config_source) {
    listEntry_t *listEntry;
    v1_config_map_node_config_source_free(v1_node_config_source->configMap);
	free(v1_node_config_source);
}

cJSON *v1_node_config_source_convertToJSON(v1_node_config_source_t *v1_node_config_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_config_source->configMap
    if(v1_node_config_source->configMap) { 
    cJSON *configMap_local_JSON = v1_config_map_node_config_source_convertToJSON(v1_node_config_source->configMap);
    if(configMap_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMap", configMap_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_node_config_source_t *v1_node_config_source_parseFromJSON(cJSON *v1_node_config_sourceJSON){

    v1_node_config_source_t *v1_node_config_source_local_var = NULL;

    // v1_node_config_source->configMap
    cJSON *configMap = cJSON_GetObjectItemCaseSensitive(v1_node_config_sourceJSON, "configMap");
    v1_config_map_node_config_source_t *configMap_local_nonprim = NULL;
    if (configMap) { 
    configMap_local_nonprim = v1_config_map_node_config_source_parseFromJSON(configMap); //nonprimitive
    }


    v1_node_config_source_local_var = v1_node_config_source_create (
        configMap ? configMap_local_nonprim : NULL
        );

    return v1_node_config_source_local_var;
end:
    return NULL;

}
