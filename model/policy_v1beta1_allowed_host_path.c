#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_allowed_host_path.h"



policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_create(
    char *pathPrefix,
    int readOnly
    ) {
	policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_local_var = malloc(sizeof(policy_v1beta1_allowed_host_path_t));
    if (!policy_v1beta1_allowed_host_path_local_var) {
        return NULL;
    }
	policy_v1beta1_allowed_host_path_local_var->pathPrefix = pathPrefix;
	policy_v1beta1_allowed_host_path_local_var->readOnly = readOnly;

	return policy_v1beta1_allowed_host_path_local_var;
}


void policy_v1beta1_allowed_host_path_free(policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path) {
    listEntry_t *listEntry;
    free(policy_v1beta1_allowed_host_path->pathPrefix);
	free(policy_v1beta1_allowed_host_path);
}

cJSON *policy_v1beta1_allowed_host_path_convertToJSON(policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path) {
	cJSON *item = cJSON_CreateObject();

	// policy_v1beta1_allowed_host_path->pathPrefix
    if(policy_v1beta1_allowed_host_path->pathPrefix) { 
    if(cJSON_AddStringToObject(item, "pathPrefix", policy_v1beta1_allowed_host_path->pathPrefix) == NULL) {
    goto fail; //String
    }
     } 


	// policy_v1beta1_allowed_host_path->readOnly
    if(policy_v1beta1_allowed_host_path->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", policy_v1beta1_allowed_host_path->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_parseFromJSON(cJSON *policy_v1beta1_allowed_host_pathJSON){

    policy_v1beta1_allowed_host_path_t *policy_v1beta1_allowed_host_path_local_var = NULL;

    // policy_v1beta1_allowed_host_path->pathPrefix
    cJSON *pathPrefix = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_allowed_host_pathJSON, "pathPrefix");
    if (pathPrefix) { 
    if(!cJSON_IsString(pathPrefix))
    {
    goto end; //String
    }
    }

    // policy_v1beta1_allowed_host_path->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_allowed_host_pathJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }


    policy_v1beta1_allowed_host_path_local_var = policy_v1beta1_allowed_host_path_create (
        pathPrefix ? strdup(pathPrefix->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0
        );

    return policy_v1beta1_allowed_host_path_local_var;
end:
    return NULL;

}
