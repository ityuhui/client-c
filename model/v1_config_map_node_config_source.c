#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map_node_config_source.h"



v1_config_map_node_config_source_t *v1_config_map_node_config_source_create(
    char *kubeletConfigKey,
    char *name,
    char *namespace,
    char *resourceVersion,
    char *uid
    ) {
	v1_config_map_node_config_source_t *v1_config_map_node_config_source_local_var = malloc(sizeof(v1_config_map_node_config_source_t));
    if (!v1_config_map_node_config_source_local_var) {
        return NULL;
    }
	v1_config_map_node_config_source_local_var->kubeletConfigKey = kubeletConfigKey;
	v1_config_map_node_config_source_local_var->name = name;
	v1_config_map_node_config_source_local_var->namespace = namespace;
	v1_config_map_node_config_source_local_var->resourceVersion = resourceVersion;
	v1_config_map_node_config_source_local_var->uid = uid;

	return v1_config_map_node_config_source_local_var;
}


void v1_config_map_node_config_source_free(v1_config_map_node_config_source_t *v1_config_map_node_config_source) {
    listEntry_t *listEntry;
    free(v1_config_map_node_config_source->kubeletConfigKey);
    free(v1_config_map_node_config_source->name);
    free(v1_config_map_node_config_source->namespace);
    free(v1_config_map_node_config_source->resourceVersion);
    free(v1_config_map_node_config_source->uid);
	free(v1_config_map_node_config_source);
}

cJSON *v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_t *v1_config_map_node_config_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_config_map_node_config_source->kubeletConfigKey
    if (!v1_config_map_node_config_source->kubeletConfigKey) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kubeletConfigKey", v1_config_map_node_config_source->kubeletConfigKey) == NULL) {
    goto fail; //String
    }


	// v1_config_map_node_config_source->name
    if (!v1_config_map_node_config_source->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_config_map_node_config_source->name) == NULL) {
    goto fail; //String
    }


	// v1_config_map_node_config_source->namespace
    if (!v1_config_map_node_config_source->namespace) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "namespace", v1_config_map_node_config_source->namespace) == NULL) {
    goto fail; //String
    }


	// v1_config_map_node_config_source->resourceVersion
    if(v1_config_map_node_config_source->resourceVersion) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_config_map_node_config_source->resourceVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_config_map_node_config_source->uid
    if(v1_config_map_node_config_source->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_config_map_node_config_source->uid) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_config_map_node_config_source_t *v1_config_map_node_config_source_parseFromJSON(cJSON *v1_config_map_node_config_sourceJSON){

    v1_config_map_node_config_source_t *v1_config_map_node_config_source_local_var = NULL;

    // v1_config_map_node_config_source->kubeletConfigKey
    cJSON *kubeletConfigKey = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "kubeletConfigKey");
    if (!kubeletConfigKey) {
        goto end;
    }

    
    if(!cJSON_IsString(kubeletConfigKey))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "namespace");
    if (!namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->resourceVersion
    cJSON *resourceVersion = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "resourceVersion");
    if (resourceVersion) { 
    if(!cJSON_IsString(resourceVersion))
    {
    goto end; //String
    }
    }

    // v1_config_map_node_config_source->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_config_map_node_config_source_local_var = v1_config_map_node_config_source_create (
        strdup(kubeletConfigKey->valuestring),
        strdup(name->valuestring),
        strdup(namespace->valuestring),
        resourceVersion ? strdup(resourceVersion->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_config_map_node_config_source_local_var;
end:
    return NULL;

}
