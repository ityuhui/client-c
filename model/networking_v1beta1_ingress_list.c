#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_list.h"



networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
	networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list_local_var = malloc(sizeof(networking_v1beta1_ingress_list_t));
    if (!networking_v1beta1_ingress_list_local_var) {
        return NULL;
    }
	networking_v1beta1_ingress_list_local_var->apiVersion = apiVersion;
	networking_v1beta1_ingress_list_local_var->items = items;
	networking_v1beta1_ingress_list_local_var->kind = kind;
	networking_v1beta1_ingress_list_local_var->metadata = metadata;

	return networking_v1beta1_ingress_list_local_var;
}


void networking_v1beta1_ingress_list_free(networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list) {
    listEntry_t *listEntry;
    free(networking_v1beta1_ingress_list->apiVersion);
	list_ForEach(listEntry, networking_v1beta1_ingress_list->items) {
		networking_v1beta1_ingress_free(listEntry->data);
	}
	list_free(networking_v1beta1_ingress_list->items);
    free(networking_v1beta1_ingress_list->kind);
    v1_list_meta_free(networking_v1beta1_ingress_list->metadata);
	free(networking_v1beta1_ingress_list);
}

cJSON *networking_v1beta1_ingress_list_convertToJSON(networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list) {
	cJSON *item = cJSON_CreateObject();

	// networking_v1beta1_ingress_list->apiVersion
    if(networking_v1beta1_ingress_list->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", networking_v1beta1_ingress_list->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// networking_v1beta1_ingress_list->items
    if (!networking_v1beta1_ingress_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (networking_v1beta1_ingress_list->items) {
    list_ForEach(itemsListEntry, networking_v1beta1_ingress_list->items) {
    cJSON *itemLocal = networking_v1beta1_ingress_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


	// networking_v1beta1_ingress_list->kind
    if(networking_v1beta1_ingress_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", networking_v1beta1_ingress_list->kind) == NULL) {
    goto fail; //String
    }
     } 


	// networking_v1beta1_ingress_list->metadata
    if(networking_v1beta1_ingress_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(networking_v1beta1_ingress_list->metadata);
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

networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list_parseFromJSON(cJSON *networking_v1beta1_ingress_listJSON){

    networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list_local_var = NULL;

    // networking_v1beta1_ingress_list->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_listJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // networking_v1beta1_ingress_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_listJSON, "items");
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
        networking_v1beta1_ingress_t *itemsItem = networking_v1beta1_ingress_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // networking_v1beta1_ingress_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // networking_v1beta1_ingress_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    networking_v1beta1_ingress_list_local_var = networking_v1beta1_ingress_list_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return networking_v1beta1_ingress_list_local_var;
end:
    return NULL;

}
