#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_status.h"



v1_container_status_t *v1_container_status_create(
    char *containerID,
    char *image,
    char *imageID,
    v1_container_state_t *lastState,
    char *name,
    int ready,
    int restartCount,
    int started,
    v1_container_state_t *state
    ) {
	v1_container_status_t *v1_container_status_local_var = malloc(sizeof(v1_container_status_t));
    if (!v1_container_status_local_var) {
        return NULL;
    }
	v1_container_status_local_var->containerID = containerID;
	v1_container_status_local_var->image = image;
	v1_container_status_local_var->imageID = imageID;
	v1_container_status_local_var->lastState = lastState;
	v1_container_status_local_var->name = name;
	v1_container_status_local_var->ready = ready;
	v1_container_status_local_var->restartCount = restartCount;
	v1_container_status_local_var->started = started;
	v1_container_status_local_var->state = state;

	return v1_container_status_local_var;
}


void v1_container_status_free(v1_container_status_t *v1_container_status) {
    listEntry_t *listEntry;
    free(v1_container_status->containerID);
    free(v1_container_status->image);
    free(v1_container_status->imageID);
    v1_container_state_free(v1_container_status->lastState);
    free(v1_container_status->name);
    v1_container_state_free(v1_container_status->state);
	free(v1_container_status);
}

cJSON *v1_container_status_convertToJSON(v1_container_status_t *v1_container_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_container_status->containerID
    if(v1_container_status->containerID) { 
    if(cJSON_AddStringToObject(item, "containerID", v1_container_status->containerID) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container_status->image
    if (!v1_container_status->image) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "image", v1_container_status->image) == NULL) {
    goto fail; //String
    }


	// v1_container_status->imageID
    if (!v1_container_status->imageID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "imageID", v1_container_status->imageID) == NULL) {
    goto fail; //String
    }


	// v1_container_status->lastState
    if(v1_container_status->lastState) { 
    cJSON *lastState_local_JSON = v1_container_state_convertToJSON(v1_container_status->lastState);
    if(lastState_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lastState", lastState_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_container_status->name
    if (!v1_container_status->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_container_status->name) == NULL) {
    goto fail; //String
    }


	// v1_container_status->ready
    if (!v1_container_status->ready) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "ready", v1_container_status->ready) == NULL) {
    goto fail; //Bool
    }


	// v1_container_status->restartCount
    if (!v1_container_status->restartCount) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "restartCount", v1_container_status->restartCount) == NULL) {
    goto fail; //Numeric
    }


	// v1_container_status->started
    if(v1_container_status->started) { 
    if(cJSON_AddBoolToObject(item, "started", v1_container_status->started) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_container_status->state
    if(v1_container_status->state) { 
    cJSON *state_local_JSON = v1_container_state_convertToJSON(v1_container_status->state);
    if(state_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "state", state_local_JSON);
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

v1_container_status_t *v1_container_status_parseFromJSON(cJSON *v1_container_statusJSON){

    v1_container_status_t *v1_container_status_local_var = NULL;

    // v1_container_status->containerID
    cJSON *containerID = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "containerID");
    if (containerID) { 
    if(!cJSON_IsString(containerID))
    {
    goto end; //String
    }
    }

    // v1_container_status->image
    cJSON *image = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "image");
    if (!image) {
        goto end;
    }

    
    if(!cJSON_IsString(image))
    {
    goto end; //String
    }

    // v1_container_status->imageID
    cJSON *imageID = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "imageID");
    if (!imageID) {
        goto end;
    }

    
    if(!cJSON_IsString(imageID))
    {
    goto end; //String
    }

    // v1_container_status->lastState
    cJSON *lastState = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "lastState");
    v1_container_state_t *lastState_local_nonprim = NULL;
    if (lastState) { 
    lastState_local_nonprim = v1_container_state_parseFromJSON(lastState); //nonprimitive
    }

    // v1_container_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_container_status->ready
    cJSON *ready = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "ready");
    if (!ready) {
        goto end;
    }

    
    if(!cJSON_IsBool(ready))
    {
    goto end; //Bool
    }

    // v1_container_status->restartCount
    cJSON *restartCount = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "restartCount");
    if (!restartCount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(restartCount))
    {
    goto end; //Numeric
    }

    // v1_container_status->started
    cJSON *started = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "started");
    if (started) { 
    if(!cJSON_IsBool(started))
    {
    goto end; //Bool
    }
    }

    // v1_container_status->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(v1_container_statusJSON, "state");
    v1_container_state_t *state_local_nonprim = NULL;
    if (state) { 
    state_local_nonprim = v1_container_state_parseFromJSON(state); //nonprimitive
    }


    v1_container_status_local_var = v1_container_status_create (
        containerID ? strdup(containerID->valuestring) : NULL,
        strdup(image->valuestring),
        strdup(imageID->valuestring),
        lastState ? lastState_local_nonprim : NULL,
        strdup(name->valuestring),
        ready->valueint,
        restartCount->valuedouble,
        started ? started->valueint : 0,
        state ? state_local_nonprim : NULL
        );

    return v1_container_status_local_var;
end:
    return NULL;

}
