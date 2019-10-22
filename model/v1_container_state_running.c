#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state_running.h"



v1_container_state_running_t *v1_container_state_running_create(
    char *startedAt
    ) {
	v1_container_state_running_t *v1_container_state_running_local_var = malloc(sizeof(v1_container_state_running_t));
    if (!v1_container_state_running_local_var) {
        return NULL;
    }
	v1_container_state_running_local_var->startedAt = startedAt;

	return v1_container_state_running_local_var;
}


void v1_container_state_running_free(v1_container_state_running_t *v1_container_state_running) {
    listEntry_t *listEntry;
    free(v1_container_state_running->startedAt);
	free(v1_container_state_running);
}

cJSON *v1_container_state_running_convertToJSON(v1_container_state_running_t *v1_container_state_running) {
	cJSON *item = cJSON_CreateObject();

	// v1_container_state_running->startedAt
    if(v1_container_state_running->startedAt) { 
    if(cJSON_AddStringToObject(item, "startedAt", v1_container_state_running->startedAt) == NULL) {
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

v1_container_state_running_t *v1_container_state_running_parseFromJSON(cJSON *v1_container_state_runningJSON){

    v1_container_state_running_t *v1_container_state_running_local_var = NULL;

    // v1_container_state_running->startedAt
    cJSON *startedAt = cJSON_GetObjectItemCaseSensitive(v1_container_state_runningJSON, "startedAt");
    if (startedAt) { 
    if(!cJSON_IsString(startedAt))
    {
    goto end; //DateTime
    }
    }


    v1_container_state_running_local_var = v1_container_state_running_create (
        startedAt ? strdup(startedAt->valuestring) : NULL
        );

    return v1_container_state_running_local_var;
end:
    return NULL;

}
