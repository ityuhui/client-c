#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_resource_list.h"



v1_api_resource_list_t *v1_api_resource_list_create(
    char *apiVersion,
    char *groupVersion,
    char *kind,
    list_t *resources
    ) {
	v1_api_resource_list_t *v1_api_resource_list_local_var = malloc(sizeof(v1_api_resource_list_t));
    if (!v1_api_resource_list_local_var) {
        return NULL;
    }
	v1_api_resource_list_local_var->apiVersion = apiVersion;
	v1_api_resource_list_local_var->groupVersion = groupVersion;
	v1_api_resource_list_local_var->kind = kind;
	v1_api_resource_list_local_var->resources = resources;

	return v1_api_resource_list_local_var;
}


void v1_api_resource_list_free(v1_api_resource_list_t *v1_api_resource_list) {
    listEntry_t *listEntry;
    free(v1_api_resource_list->apiVersion);
    free(v1_api_resource_list->groupVersion);
    free(v1_api_resource_list->kind);
	list_ForEach(listEntry, v1_api_resource_list->resources) {
		v1_api_resource_free(listEntry->data);
	}
	list_free(v1_api_resource_list->resources);
	free(v1_api_resource_list);
}

cJSON *v1_api_resource_list_convertToJSON(v1_api_resource_list_t *v1_api_resource_list) {
	cJSON *item = cJSON_CreateObject();

	// v1_api_resource_list->apiVersion
    if(v1_api_resource_list->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_resource_list->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_resource_list->groupVersion
    if (!v1_api_resource_list->groupVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "groupVersion", v1_api_resource_list->groupVersion) == NULL) {
    goto fail; //String
    }


	// v1_api_resource_list->kind
    if(v1_api_resource_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_api_resource_list->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_resource_list->resources
    if (!v1_api_resource_list->resources) {
        goto fail;
    }
    
    cJSON *resources = cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resourcesListEntry;
    if (v1_api_resource_list->resources) {
    list_ForEach(resourcesListEntry, v1_api_resource_list->resources) {
    cJSON *itemLocal = v1_api_resource_convertToJSON(resourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resources, itemLocal);
    }
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_api_resource_list_t *v1_api_resource_list_parseFromJSON(cJSON *v1_api_resource_listJSON){

    v1_api_resource_list_t *v1_api_resource_list_local_var = NULL;

    // v1_api_resource_list->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_api_resource_list->groupVersion
    cJSON *groupVersion = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "groupVersion");
    if (!groupVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(groupVersion))
    {
    goto end; //String
    }

    // v1_api_resource_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_api_resource_list->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_api_resource_listJSON, "resources");
    if (!resources) {
        goto end;
    }

    list_t *resourcesList;
    
    cJSON *resources_local_nonprimitive;
    if(!cJSON_IsArray(resources)){
        goto end; //nonprimitive container
    }

    resourcesList = list_create();

    cJSON_ArrayForEach(resources_local_nonprimitive,resources )
    {
        if(!cJSON_IsObject(resources_local_nonprimitive)){
            goto end;
        }
        v1_api_resource_t *resourcesItem = v1_api_resource_parseFromJSON(resources_local_nonprimitive);

        list_addElement(resourcesList, resourcesItem);
    }


    v1_api_resource_list_local_var = v1_api_resource_list_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        strdup(groupVersion->valuestring),
        kind ? strdup(kind->valuestring) : NULL,
        resourcesList
        );

    return v1_api_resource_list_local_var;
end:
    return NULL;

}
