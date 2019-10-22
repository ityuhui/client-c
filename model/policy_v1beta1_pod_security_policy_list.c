#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_pod_security_policy_list.h"



policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
	policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list_local_var = malloc(sizeof(policy_v1beta1_pod_security_policy_list_t));
    if (!policy_v1beta1_pod_security_policy_list_local_var) {
        return NULL;
    }
	policy_v1beta1_pod_security_policy_list_local_var->apiVersion = apiVersion;
	policy_v1beta1_pod_security_policy_list_local_var->items = items;
	policy_v1beta1_pod_security_policy_list_local_var->kind = kind;
	policy_v1beta1_pod_security_policy_list_local_var->metadata = metadata;

	return policy_v1beta1_pod_security_policy_list_local_var;
}


void policy_v1beta1_pod_security_policy_list_free(policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list) {
    listEntry_t *listEntry;
    free(policy_v1beta1_pod_security_policy_list->apiVersion);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_list->items) {
		policy_v1beta1_pod_security_policy_free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_list->items);
    free(policy_v1beta1_pod_security_policy_list->kind);
    v1_list_meta_free(policy_v1beta1_pod_security_policy_list->metadata);
	free(policy_v1beta1_pod_security_policy_list);
}

cJSON *policy_v1beta1_pod_security_policy_list_convertToJSON(policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list) {
	cJSON *item = cJSON_CreateObject();

	// policy_v1beta1_pod_security_policy_list->apiVersion
    if(policy_v1beta1_pod_security_policy_list->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", policy_v1beta1_pod_security_policy_list->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// policy_v1beta1_pod_security_policy_list->items
    if (!policy_v1beta1_pod_security_policy_list->items) {
        goto fail;
    }
    
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (policy_v1beta1_pod_security_policy_list->items) {
    list_ForEach(itemsListEntry, policy_v1beta1_pod_security_policy_list->items) {
    cJSON *itemLocal = policy_v1beta1_pod_security_policy_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


	// policy_v1beta1_pod_security_policy_list->kind
    if(policy_v1beta1_pod_security_policy_list->kind) { 
    if(cJSON_AddStringToObject(item, "kind", policy_v1beta1_pod_security_policy_list->kind) == NULL) {
    goto fail; //String
    }
     } 


	// policy_v1beta1_pod_security_policy_list->metadata
    if(policy_v1beta1_pod_security_policy_list->metadata) { 
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(policy_v1beta1_pod_security_policy_list->metadata);
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

policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list_parseFromJSON(cJSON *policy_v1beta1_pod_security_policy_listJSON){

    policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list_local_var = NULL;

    // policy_v1beta1_pod_security_policy_list->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_listJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // policy_v1beta1_pod_security_policy_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_listJSON, "items");
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
        policy_v1beta1_pod_security_policy_t *itemsItem = policy_v1beta1_pod_security_policy_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // policy_v1beta1_pod_security_policy_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_listJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // policy_v1beta1_pod_security_policy_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_listJSON, "metadata");
    v1_list_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    policy_v1beta1_pod_security_policy_list_local_var = policy_v1beta1_pod_security_policy_list_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        itemsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return policy_v1beta1_pod_security_policy_list_local_var;
end:
    return NULL;

}
