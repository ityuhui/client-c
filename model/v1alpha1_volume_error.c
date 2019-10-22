#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_volume_error.h"



v1alpha1_volume_error_t *v1alpha1_volume_error_create(
    char *message,
    char *time
    ) {
	v1alpha1_volume_error_t *v1alpha1_volume_error_local_var = malloc(sizeof(v1alpha1_volume_error_t));
    if (!v1alpha1_volume_error_local_var) {
        return NULL;
    }
	v1alpha1_volume_error_local_var->message = message;
	v1alpha1_volume_error_local_var->time = time;

	return v1alpha1_volume_error_local_var;
}


void v1alpha1_volume_error_free(v1alpha1_volume_error_t *v1alpha1_volume_error) {
    listEntry_t *listEntry;
    free(v1alpha1_volume_error->message);
    free(v1alpha1_volume_error->time);
	free(v1alpha1_volume_error);
}

cJSON *v1alpha1_volume_error_convertToJSON(v1alpha1_volume_error_t *v1alpha1_volume_error) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_volume_error->message
    if(v1alpha1_volume_error->message) { 
    if(cJSON_AddStringToObject(item, "message", v1alpha1_volume_error->message) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_volume_error->time
    if(v1alpha1_volume_error->time) { 
    if(cJSON_AddStringToObject(item, "time", v1alpha1_volume_error->time) == NULL) {
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

v1alpha1_volume_error_t *v1alpha1_volume_error_parseFromJSON(cJSON *v1alpha1_volume_errorJSON){

    v1alpha1_volume_error_t *v1alpha1_volume_error_local_var = NULL;

    // v1alpha1_volume_error->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_errorJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1alpha1_volume_error->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_errorJSON, "time");
    if (time) { 
    if(!cJSON_IsString(time))
    {
    goto end; //DateTime
    }
    }


    v1alpha1_volume_error_local_var = v1alpha1_volume_error_create (
        message ? strdup(message->valuestring) : NULL,
        time ? strdup(time->valuestring) : NULL
        );

    return v1alpha1_volume_error_local_var;
end:
    return NULL;

}
