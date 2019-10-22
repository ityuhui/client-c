#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_preconditions.h"



v1_preconditions_t *v1_preconditions_create(
    char *resourceVersion,
    char *uid
    ) {
	v1_preconditions_t *v1_preconditions_local_var = malloc(sizeof(v1_preconditions_t));
    if (!v1_preconditions_local_var) {
        return NULL;
    }
	v1_preconditions_local_var->resourceVersion = resourceVersion;
	v1_preconditions_local_var->uid = uid;

	return v1_preconditions_local_var;
}


void v1_preconditions_free(v1_preconditions_t *v1_preconditions) {
    listEntry_t *listEntry;
    free(v1_preconditions->resourceVersion);
    free(v1_preconditions->uid);
	free(v1_preconditions);
}

cJSON *v1_preconditions_convertToJSON(v1_preconditions_t *v1_preconditions) {
	cJSON *item = cJSON_CreateObject();

	// v1_preconditions->resourceVersion
    if(v1_preconditions->resourceVersion) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_preconditions->resourceVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_preconditions->uid
    if(v1_preconditions->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_preconditions->uid) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_preconditions_t *v1_preconditions_parseFromJSON(cJSON *v1_preconditionsJSON){

    v1_preconditions_t *v1_preconditions_local_var = NULL;

    // v1_preconditions->resourceVersion
    cJSON *resourceVersion = cJSON_GetObjectItemCaseSensitive(v1_preconditionsJSON, "resourceVersion");
    if (resourceVersion) { 
    if(!cJSON_IsString(resourceVersion))
    {
    goto end; //String
    }
    }

    // v1_preconditions->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_preconditionsJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_preconditions_local_var = v1_preconditions_create (
        resourceVersion ? strdup(resourceVersion->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_preconditions_local_var;
end:
    return NULL;

}
