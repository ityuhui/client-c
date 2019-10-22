#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_component_status.h"



v1_component_status_t *v1_component_status_create(
    char *apiVersion,
    list_t *conditions,
    char *kind,
    v1_object_meta_t *metadata
    ) {
	v1_component_status_t *v1_component_status_local_var = malloc(sizeof(v1_component_status_t));
    if (!v1_component_status_local_var) {
        return NULL;
    }
	v1_component_status_local_var->apiVersion = apiVersion;
	v1_component_status_local_var->conditions = conditions;
	v1_component_status_local_var->kind = kind;
	v1_component_status_local_var->metadata = metadata;

	return v1_component_status_local_var;
}


void v1_component_status_free(v1_component_status_t *v1_component_status) {
    listEntry_t *listEntry;
    free(v1_component_status->apiVersion);
	list_ForEach(listEntry, v1_component_status->conditions) {
		v1_component_condition_free(listEntry->data);
	}
	list_free(v1_component_status->conditions);
    free(v1_component_status->kind);
    v1_object_meta_free(v1_component_status->metadata);
	free(v1_component_status);
}

cJSON *v1_component_status_convertToJSON(v1_component_status_t *v1_component_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_component_status->apiVersion
    if(v1_component_status->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_component_status->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_component_status->conditions
    if(v1_component_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_component_status->conditions) {
    list_ForEach(conditionsListEntry, v1_component_status->conditions) {
    cJSON *itemLocal = v1_component_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1_component_status->kind
    if(v1_component_status->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_component_status->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_component_status->metadata
    if(v1_component_status->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_component_status->metadata);
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

v1_component_status_t *v1_component_status_parseFromJSON(cJSON *v1_component_statusJSON){

    v1_component_status_t *v1_component_status_local_var = NULL;

    // v1_component_status->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_component_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_component_condition_t *conditionsItem = v1_component_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_component_status->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_component_status->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_component_status_local_var = v1_component_status_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        conditions ? conditionsList : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_component_status_local_var;
end:
    return NULL;

}
