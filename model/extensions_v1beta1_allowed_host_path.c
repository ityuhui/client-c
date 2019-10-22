#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_allowed_host_path.h"



extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_create(
    char *pathPrefix,
    int readOnly
    ) {
	extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_local_var = malloc(sizeof(extensions_v1beta1_allowed_host_path_t));
    if (!extensions_v1beta1_allowed_host_path_local_var) {
        return NULL;
    }
	extensions_v1beta1_allowed_host_path_local_var->pathPrefix = pathPrefix;
	extensions_v1beta1_allowed_host_path_local_var->readOnly = readOnly;

	return extensions_v1beta1_allowed_host_path_local_var;
}


void extensions_v1beta1_allowed_host_path_free(extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path) {
    listEntry_t *listEntry;
    free(extensions_v1beta1_allowed_host_path->pathPrefix);
	free(extensions_v1beta1_allowed_host_path);
}

cJSON *extensions_v1beta1_allowed_host_path_convertToJSON(extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_allowed_host_path->pathPrefix
    if(extensions_v1beta1_allowed_host_path->pathPrefix) { 
    if(cJSON_AddStringToObject(item, "pathPrefix", extensions_v1beta1_allowed_host_path->pathPrefix) == NULL) {
    goto fail; //String
    }
     } 


	// extensions_v1beta1_allowed_host_path->readOnly
    if(extensions_v1beta1_allowed_host_path->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", extensions_v1beta1_allowed_host_path->readOnly) == NULL) {
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

extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_parseFromJSON(cJSON *extensions_v1beta1_allowed_host_pathJSON){

    extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_local_var = NULL;

    // extensions_v1beta1_allowed_host_path->pathPrefix
    cJSON *pathPrefix = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_allowed_host_pathJSON, "pathPrefix");
    if (pathPrefix) { 
    if(!cJSON_IsString(pathPrefix))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_allowed_host_path->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_allowed_host_pathJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }


    extensions_v1beta1_allowed_host_path_local_var = extensions_v1beta1_allowed_host_path_create (
        pathPrefix ? strdup(pathPrefix->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0
        );

    return extensions_v1beta1_allowed_host_path_local_var;
end:
    return NULL;

}
