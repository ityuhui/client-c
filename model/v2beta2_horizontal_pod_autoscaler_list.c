#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_horizontal_pod_autoscaler_list.h"



v2beta2_horizontal_pod_autoscaler_list_t *v2beta2_horizontal_pod_autoscaler_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
	v2beta2_horizontal_pod_autoscaler_list_t *v2beta2_horizontal_pod_autoscaler_list_local_var = malloc(sizeof(v2beta2_horizontal_pod_autoscaler_list_t));
    if (!v2beta2_horizontal_pod_autoscaler_list_local_var) {
        return NULL;
    }
	v2beta2_horizontal_pod_autoscaler_list_local_var->apiVersion = apiVersion;
	v2beta2_horizontal_pod_autoscaler_list_local_var->items = items;
	v2beta2_horizontal_pod_autoscaler_list_local_var->kind = kind;
	v2beta2_horizontal_pod_autoscaler_list_local_var->metadata = metadata;

	return v2beta2_horizontal_pod_autoscaler_list_local_var;
}


void v2beta2_horizontal_pod_autoscaler_list_free(v2beta2_horizontal_pod_autoscaler_list_t *v2beta2_horizontal_pod_autoscaler_list) {
    listEntry_t *listEntry;
    free(v2beta2_horizontal_pod_autoscaler_list->apiVersion);
	list_ForEach(listEntry, v2beta2_horizontal_pod_autoscaler_list->items) {
		v2beta2_horizontal_pod_autoscaler_free(listEntry->data);
	}
	list_free(v2beta2_horizontal_pod_autoscaler_list->items);
    free(v2beta2_horizontal_pod_autoscaler_list->kind);
    v1_list_meta_free(v2beta2_horizontal_pod_autoscaler_list->metadata);
	free(v2beta2_horizontal_pod_autoscaler_list);
}

cJSON *v2beta2_horizontal_pod_autoscaler_list_convertToJSON(v2beta2_horizontal_pod_autoscaler_list_t *v2beta2_horizontal_pod_autoscaler_list) {
	cJSON *item = cJSON_CreateObject();

	// v2beta2_horizontal_pod_autoscaler_list->apiVersion
    if(v2beta2_horizontal_pod_autoscaler_list->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v2beta2_horizontal_pod_autoscaler_list->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_list->items
    if (!v2beta2_horizontal_pod_autoscaler_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v2beta2_horizontal_pod_autoscaler_list->items) {
    list_ForEach(itemsListEntry, v2beta2_horizontal_pod_autoscaler_list->items) {
    cJSON *itemLocal = v2beta2_horizontal_pod_autoscaler_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


	// v2beta2_horizontal_pod_autoscaler_list->kind
    if(v2beta2_horizontal_pod_autoscaler_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v2beta2_horizontal_pod_autoscaler_list->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_list->metadata
    if(v2beta2_horizontal_pod_autoscaler_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v2beta2_horizontal_pod_autoscaler_list->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

v2beta2_horizontal_pod_autoscaler_list_t *v2beta2_horizontal_pod_autoscaler_list_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_listJSON){

    v2beta2_horizontal_pod_autoscaler_list_t *v2beta2_horizontal_pod_autoscaler_list_local_var = NULL;

    // v2beta2_horizontal_pod_autoscaler_list->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_listJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v2beta2_horizontal_pod_autoscaler_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_listJSON, "items");
    if (!items) {
        goto end;
    }

    list_t *itemsList;
    
    cJSON *items_local_nonprimitive;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_create();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v2beta2_horizontal_pod_autoscaler_t *itemsItem = v2beta2_horizontal_pod_autoscaler_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v2beta2_horizontal_pod_autoscaler_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v2beta2_horizontal_pod_autoscaler_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v2beta2_horizontal_pod_autoscaler_list_local_var = v2beta2_horizontal_pod_autoscaler_list_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v2beta2_horizontal_pod_autoscaler_list_local_var;
end:
    return NULL;

}
