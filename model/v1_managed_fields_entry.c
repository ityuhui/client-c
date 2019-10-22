#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_managed_fields_entry.h"



v1_managed_fields_entry_t *v1_managed_fields_entry_create(
    char *apiVersion,
    char *fieldsType,
    object_t *fieldsV1,
    char *manager,
    char *operation,
    char *time
    ) {
	v1_managed_fields_entry_t *v1_managed_fields_entry_local_var = malloc(sizeof(v1_managed_fields_entry_t));
    if (!v1_managed_fields_entry_local_var) {
        return NULL;
    }
	v1_managed_fields_entry_local_var->apiVersion = apiVersion;
	v1_managed_fields_entry_local_var->fieldsType = fieldsType;
	v1_managed_fields_entry_local_var->fieldsV1 = fieldsV1;
	v1_managed_fields_entry_local_var->manager = manager;
	v1_managed_fields_entry_local_var->operation = operation;
	v1_managed_fields_entry_local_var->time = time;

	return v1_managed_fields_entry_local_var;
}


void v1_managed_fields_entry_free(v1_managed_fields_entry_t *v1_managed_fields_entry) {
    listEntry_t *listEntry;
    free(v1_managed_fields_entry->apiVersion);
    free(v1_managed_fields_entry->fieldsType);
    object_free(v1_managed_fields_entry->fieldsV1);
    free(v1_managed_fields_entry->manager);
    free(v1_managed_fields_entry->operation);
    free(v1_managed_fields_entry->time);
	free(v1_managed_fields_entry);
}

cJSON *v1_managed_fields_entry_convertToJSON(v1_managed_fields_entry_t *v1_managed_fields_entry) {
	cJSON *item = cJSON_CreateObject();

	// v1_managed_fields_entry->apiVersion
    if(v1_managed_fields_entry->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_managed_fields_entry->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_managed_fields_entry->fieldsType
    if(v1_managed_fields_entry->fieldsType) { 
    if(cJSON_AddStringToObject(item, "fieldsType", v1_managed_fields_entry->fieldsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_managed_fields_entry->fieldsV1
    if(v1_managed_fields_entry->fieldsV1) { 
    cJSON *fieldsV1_object = object_convertToJSON(v1_managed_fields_entry->fieldsV1);
    if(fieldsV1_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fieldsV1", fieldsV1_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_managed_fields_entry->manager
    if(v1_managed_fields_entry->manager) { 
    if(cJSON_AddStringToObject(item, "manager", v1_managed_fields_entry->manager) == NULL) {
    goto fail; //String
    }
     } 


	// v1_managed_fields_entry->operation
    if(v1_managed_fields_entry->operation) { 
    if(cJSON_AddStringToObject(item, "operation", v1_managed_fields_entry->operation) == NULL) {
    goto fail; //String
    }
     } 


	// v1_managed_fields_entry->time
    if(v1_managed_fields_entry->time) { 
    if(cJSON_AddStringToObject(item, "time", v1_managed_fields_entry->time) == NULL) {
    goto fail; //Date-Time
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_managed_fields_entry_t *v1_managed_fields_entry_parseFromJSON(cJSON *v1_managed_fields_entryJSON){

    v1_managed_fields_entry_t *v1_managed_fields_entry_local_var = NULL;

    // v1_managed_fields_entry->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->fieldsType
    cJSON *fieldsType = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "fieldsType");
    if (fieldsType) { 
    if(!cJSON_IsString(fieldsType))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->fieldsV1
    cJSON *fieldsV1 = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "fieldsV1");
    object_t *fieldsV1_local_object = NULL;
    if (fieldsV1) { 
    fieldsV1_local_object = object_parseFromJSON(fieldsV1); //object
    }

    // v1_managed_fields_entry->manager
    cJSON *manager = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "manager");
    if (manager) { 
    if(!cJSON_IsString(manager))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->operation
    cJSON *operation = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "operation");
    if (operation) { 
    if(!cJSON_IsString(operation))
    {
    goto end; //String
    }
    }

    // v1_managed_fields_entry->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(v1_managed_fields_entryJSON, "time");
    if (time) { 
    if(!cJSON_IsString(time))
    {
    goto end; //DateTime
    }
    }


    v1_managed_fields_entry_local_var = v1_managed_fields_entry_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        fieldsType ? strdup(fieldsType->valuestring) : NULL,
        fieldsV1 ? fieldsV1_local_object : NULL,
        manager ? strdup(manager->valuestring) : NULL,
        operation ? strdup(operation->valuestring) : NULL,
        time ? strdup(time->valuestring) : NULL
        );

    return v1_managed_fields_entry_local_var;
end:
    return NULL;

}
