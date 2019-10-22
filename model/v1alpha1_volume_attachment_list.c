#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_volume_attachment_list.h"



v1alpha1_volume_attachment_list_t *v1alpha1_volume_attachment_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
	v1alpha1_volume_attachment_list_t *v1alpha1_volume_attachment_list_local_var = malloc(sizeof(v1alpha1_volume_attachment_list_t));
    if (!v1alpha1_volume_attachment_list_local_var) {
        return NULL;
    }
	v1alpha1_volume_attachment_list_local_var->apiVersion = apiVersion;
	v1alpha1_volume_attachment_list_local_var->items = items;
	v1alpha1_volume_attachment_list_local_var->kind = kind;
	v1alpha1_volume_attachment_list_local_var->metadata = metadata;

	return v1alpha1_volume_attachment_list_local_var;
}


void v1alpha1_volume_attachment_list_free(v1alpha1_volume_attachment_list_t *v1alpha1_volume_attachment_list) {
    listEntry_t *listEntry;
    free(v1alpha1_volume_attachment_list->apiVersion);
	list_ForEach(listEntry, v1alpha1_volume_attachment_list->items) {
		v1alpha1_volume_attachment_free(listEntry->data);
	}
	list_free(v1alpha1_volume_attachment_list->items);
    free(v1alpha1_volume_attachment_list->kind);
    v1_list_meta_free(v1alpha1_volume_attachment_list->metadata);
	free(v1alpha1_volume_attachment_list);
}

cJSON *v1alpha1_volume_attachment_list_convertToJSON(v1alpha1_volume_attachment_list_t *v1alpha1_volume_attachment_list) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_volume_attachment_list->apiVersion
    if(v1alpha1_volume_attachment_list->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_volume_attachment_list->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_volume_attachment_list->items
    if (!v1alpha1_volume_attachment_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1alpha1_volume_attachment_list->items) {
    list_ForEach(itemsListEntry, v1alpha1_volume_attachment_list->items) {
    cJSON *itemLocal = v1alpha1_volume_attachment_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


	// v1alpha1_volume_attachment_list->kind
    if(v1alpha1_volume_attachment_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_volume_attachment_list->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_volume_attachment_list->metadata
    if(v1alpha1_volume_attachment_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v1alpha1_volume_attachment_list->metadata);
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

v1alpha1_volume_attachment_list_t *v1alpha1_volume_attachment_list_parseFromJSON(cJSON *v1alpha1_volume_attachment_listJSON){

    v1alpha1_volume_attachment_list_t *v1alpha1_volume_attachment_list_local_var = NULL;

    // v1alpha1_volume_attachment_list->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_listJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1alpha1_volume_attachment_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_listJSON, "items");
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
        v1alpha1_volume_attachment_t *itemsItem = v1alpha1_volume_attachment_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v1alpha1_volume_attachment_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_volume_attachment_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1alpha1_volume_attachment_list_local_var = v1alpha1_volume_attachment_list_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1alpha1_volume_attachment_list_local_var;
end:
    return NULL;

}
