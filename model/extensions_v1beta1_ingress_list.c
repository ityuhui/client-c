#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_list.h"



extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
	extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list_local_var = malloc(sizeof(extensions_v1beta1_ingress_list_t));
    if (!extensions_v1beta1_ingress_list_local_var) {
        return NULL;
    }
	extensions_v1beta1_ingress_list_local_var->apiVersion = apiVersion;
	extensions_v1beta1_ingress_list_local_var->items = items;
	extensions_v1beta1_ingress_list_local_var->kind = kind;
	extensions_v1beta1_ingress_list_local_var->metadata = metadata;

	return extensions_v1beta1_ingress_list_local_var;
}


void extensions_v1beta1_ingress_list_free(extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list) {
    listEntry_t *listEntry;
    free(extensions_v1beta1_ingress_list->apiVersion);
	list_ForEach(listEntry, extensions_v1beta1_ingress_list->items) {
		extensions_v1beta1_ingress_free(listEntry->data);
	}
	list_free(extensions_v1beta1_ingress_list->items);
    free(extensions_v1beta1_ingress_list->kind);
    v1_list_meta_free(extensions_v1beta1_ingress_list->metadata);
	free(extensions_v1beta1_ingress_list);
}

cJSON *extensions_v1beta1_ingress_list_convertToJSON(extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_ingress_list->apiVersion
    if(extensions_v1beta1_ingress_list->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", extensions_v1beta1_ingress_list->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// extensions_v1beta1_ingress_list->items
    if (!extensions_v1beta1_ingress_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (extensions_v1beta1_ingress_list->items) {
    list_ForEach(itemsListEntry, extensions_v1beta1_ingress_list->items) {
    cJSON *itemLocal = extensions_v1beta1_ingress_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


	// extensions_v1beta1_ingress_list->kind
    if(extensions_v1beta1_ingress_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", extensions_v1beta1_ingress_list->kind) == NULL) {
    goto fail; //String
    }
     } 


	// extensions_v1beta1_ingress_list->metadata
    if(extensions_v1beta1_ingress_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(extensions_v1beta1_ingress_list->metadata);
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

extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list_parseFromJSON(cJSON *extensions_v1beta1_ingress_listJSON){

    extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list_local_var = NULL;

    // extensions_v1beta1_ingress_list->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_listJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_ingress_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_listJSON, "items");
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
        extensions_v1beta1_ingress_t *itemsItem = extensions_v1beta1_ingress_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // extensions_v1beta1_ingress_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_ingress_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    extensions_v1beta1_ingress_list_local_var = extensions_v1beta1_ingress_list_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return extensions_v1beta1_ingress_list_local_var;
end:
    return NULL;

}
