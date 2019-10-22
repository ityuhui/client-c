#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_list_meta.h"



v1_list_meta_t *v1_list_meta_create(
    char *continue,
    long remainingItemCount,
    char *resourceVersion,
    char *selfLink
    ) {
	v1_list_meta_t *v1_list_meta_local_var = malloc(sizeof(v1_list_meta_t));
    if (!v1_list_meta_local_var) {
        return NULL;
    }
	v1_list_meta_local_var->continue = continue;
	v1_list_meta_local_var->remainingItemCount = remainingItemCount;
	v1_list_meta_local_var->resourceVersion = resourceVersion;
	v1_list_meta_local_var->selfLink = selfLink;

	return v1_list_meta_local_var;
}


void v1_list_meta_free(v1_list_meta_t *v1_list_meta) {
    listEntry_t *listEntry;
    free(v1_list_meta->continue);
    free(v1_list_meta->resourceVersion);
    free(v1_list_meta->selfLink);
	free(v1_list_meta);
}

cJSON *v1_list_meta_convertToJSON(v1_list_meta_t *v1_list_meta) {
	cJSON *item = cJSON_CreateObject();

	// v1_list_meta->continue
    if(v1_list_meta->continue) { 
    if(cJSON_AddStringToObject(item, "continue", v1_list_meta->continue) == NULL) {
    goto fail; //String
    }
     } 


	// v1_list_meta->remainingItemCount
    if(v1_list_meta->remainingItemCount) { 
    if(cJSON_AddNumberToObject(item, "remainingItemCount", v1_list_meta->remainingItemCount) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_list_meta->resourceVersion
    if(v1_list_meta->resourceVersion) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_list_meta->resourceVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_list_meta->selfLink
    if(v1_list_meta->selfLink) { 
    if(cJSON_AddStringToObject(item, "selfLink", v1_list_meta->selfLink) == NULL) {
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

v1_list_meta_t *v1_list_meta_parseFromJSON(cJSON *v1_list_metaJSON){

    v1_list_meta_t *v1_list_meta_local_var = NULL;

    // v1_list_meta->continue
    cJSON *continue = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "continue");
    if (continue) { 
    if(!cJSON_IsString(continue))
    {
    goto end; //String
    }
    }

    // v1_list_meta->remainingItemCount
    cJSON *remainingItemCount = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "remainingItemCount");
    if (remainingItemCount) { 
    if(!cJSON_IsNumber(remainingItemCount))
    {
    goto end; //Numeric
    }
    }

    // v1_list_meta->resourceVersion
    cJSON *resourceVersion = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "resourceVersion");
    if (resourceVersion) { 
    if(!cJSON_IsString(resourceVersion))
    {
    goto end; //String
    }
    }

    // v1_list_meta->selfLink
    cJSON *selfLink = cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "selfLink");
    if (selfLink) { 
    if(!cJSON_IsString(selfLink))
    {
    goto end; //String
    }
    }


    v1_list_meta_local_var = v1_list_meta_create (
        continue ? strdup(continue->valuestring) : NULL,
        remainingItemCount ? remainingItemCount->valuedouble : 0,
        resourceVersion ? strdup(resourceVersion->valuestring) : NULL,
        selfLink ? strdup(selfLink->valuestring) : NULL
        );

    return v1_list_meta_local_var;
end:
    return NULL;

}
