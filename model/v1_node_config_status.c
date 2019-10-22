#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_config_status.h"



v1_node_config_status_t *v1_node_config_status_create(
    v1_node_config_source_t *active,
    v1_node_config_source_t *assigned,
    char *error,
    v1_node_config_source_t *lastKnownGood
    ) {
	v1_node_config_status_t *v1_node_config_status_local_var = malloc(sizeof(v1_node_config_status_t));
    if (!v1_node_config_status_local_var) {
        return NULL;
    }
	v1_node_config_status_local_var->active = active;
	v1_node_config_status_local_var->assigned = assigned;
	v1_node_config_status_local_var->error = error;
	v1_node_config_status_local_var->lastKnownGood = lastKnownGood;

	return v1_node_config_status_local_var;
}


void v1_node_config_status_free(v1_node_config_status_t *v1_node_config_status) {
    listEntry_t *listEntry;
    v1_node_config_source_free(v1_node_config_status->active);
    v1_node_config_source_free(v1_node_config_status->assigned);
    free(v1_node_config_status->error);
    v1_node_config_source_free(v1_node_config_status->lastKnownGood);
	free(v1_node_config_status);
}

cJSON *v1_node_config_status_convertToJSON(v1_node_config_status_t *v1_node_config_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_config_status->active
    if(v1_node_config_status->active) { 
    cJSON *active_local_JSON = v1_node_config_source_convertToJSON(v1_node_config_status->active);
    if(active_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "active", active_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_node_config_status->assigned
    if(v1_node_config_status->assigned) { 
    cJSON *assigned_local_JSON = v1_node_config_source_convertToJSON(v1_node_config_status->assigned);
    if(assigned_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "assigned", assigned_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_node_config_status->error
    if(v1_node_config_status->error) { 
    if(cJSON_AddStringToObject(item, "error", v1_node_config_status->error) == NULL) {
    goto fail; //String
    }
     } 


	// v1_node_config_status->lastKnownGood
    if(v1_node_config_status->lastKnownGood) { 
    cJSON *lastKnownGood_local_JSON = v1_node_config_source_convertToJSON(v1_node_config_status->lastKnownGood);
    if(lastKnownGood_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lastKnownGood", lastKnownGood_local_JSON);
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

v1_node_config_status_t *v1_node_config_status_parseFromJSON(cJSON *v1_node_config_statusJSON){

    v1_node_config_status_t *v1_node_config_status_local_var = NULL;

    // v1_node_config_status->active
    cJSON *active = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "active");
    v1_node_config_source_t *active_local_nonprim = NULL;
    if (active) { 
    active_local_nonprim = v1_node_config_source_parseFromJSON(active); //nonprimitive
    }

    // v1_node_config_status->assigned
    cJSON *assigned = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "assigned");
    v1_node_config_source_t *assigned_local_nonprim = NULL;
    if (assigned) { 
    assigned_local_nonprim = v1_node_config_source_parseFromJSON(assigned); //nonprimitive
    }

    // v1_node_config_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "error");
    if (error) { 
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }
    }

    // v1_node_config_status->lastKnownGood
    cJSON *lastKnownGood = cJSON_GetObjectItemCaseSensitive(v1_node_config_statusJSON, "lastKnownGood");
    v1_node_config_source_t *lastKnownGood_local_nonprim = NULL;
    if (lastKnownGood) { 
    lastKnownGood_local_nonprim = v1_node_config_source_parseFromJSON(lastKnownGood); //nonprimitive
    }


    v1_node_config_status_local_var = v1_node_config_status_create (
        active ? active_local_nonprim : NULL,
        assigned ? assigned_local_nonprim : NULL,
        error ? strdup(error->valuestring) : NULL,
        lastKnownGood ? lastKnownGood_local_nonprim : NULL
        );

    return v1_node_config_status_local_var;
end:
    return NULL;

}
