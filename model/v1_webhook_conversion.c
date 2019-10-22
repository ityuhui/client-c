#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_webhook_conversion.h"



v1_webhook_conversion_t *v1_webhook_conversion_create(
    apiextensions_v1_webhook_client_config_t *clientConfig,
    list_t *conversionReviewVersions
    ) {
	v1_webhook_conversion_t *v1_webhook_conversion_local_var = malloc(sizeof(v1_webhook_conversion_t));
    if (!v1_webhook_conversion_local_var) {
        return NULL;
    }
	v1_webhook_conversion_local_var->clientConfig = clientConfig;
	v1_webhook_conversion_local_var->conversionReviewVersions = conversionReviewVersions;

	return v1_webhook_conversion_local_var;
}


void v1_webhook_conversion_free(v1_webhook_conversion_t *v1_webhook_conversion) {
    listEntry_t *listEntry;
    apiextensions_v1_webhook_client_config_free(v1_webhook_conversion->clientConfig);
	list_ForEach(listEntry, v1_webhook_conversion->conversionReviewVersions) {
		free(listEntry->data);
	}
	list_free(v1_webhook_conversion->conversionReviewVersions);
	free(v1_webhook_conversion);
}

cJSON *v1_webhook_conversion_convertToJSON(v1_webhook_conversion_t *v1_webhook_conversion) {
	cJSON *item = cJSON_CreateObject();

	// v1_webhook_conversion->clientConfig
    if(v1_webhook_conversion->clientConfig) { 
    cJSON *clientConfig_local_JSON = apiextensions_v1_webhook_client_config_convertToJSON(v1_webhook_conversion->clientConfig);
    if(clientConfig_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientConfig", clientConfig_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_webhook_conversion->conversionReviewVersions
    if (!v1_webhook_conversion->conversionReviewVersions) {
        goto fail;
    }
    
	cJSON *conversion_review_versions = cJSON_AddArrayToObject(item, "conversionReviewVersions");
	if(conversion_review_versions == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *conversion_review_versionsListEntry;
    list_ForEach(conversion_review_versionsListEntry, v1_webhook_conversion->conversionReviewVersions) {
    if(cJSON_AddStringToObject(conversion_review_versions, "", (char*)conversion_review_versionsListEntry->data) == NULL)
    {
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

v1_webhook_conversion_t *v1_webhook_conversion_parseFromJSON(cJSON *v1_webhook_conversionJSON){

    v1_webhook_conversion_t *v1_webhook_conversion_local_var = NULL;

    // v1_webhook_conversion->clientConfig
    cJSON *clientConfig = cJSON_GetObjectItemCaseSensitive(v1_webhook_conversionJSON, "clientConfig");
    apiextensions_v1_webhook_client_config_t *clientConfig_local_nonprim = NULL;
    if (clientConfig) { 
    clientConfig_local_nonprim = apiextensions_v1_webhook_client_config_parseFromJSON(clientConfig); //nonprimitive
    }

    // v1_webhook_conversion->conversionReviewVersions
    cJSON *conversionReviewVersions = cJSON_GetObjectItemCaseSensitive(v1_webhook_conversionJSON, "conversionReviewVersions");
    if (!conversionReviewVersions) {
        goto end;
    }

    list_t *conversion_review_versionsList;
    
    cJSON *conversion_review_versions_local;
    if(!cJSON_IsArray(conversionReviewVersions)) {
        goto end;//primitive container
    }
    conversion_review_versionsList = list_create();

    cJSON_ArrayForEach(conversion_review_versions_local, conversionReviewVersions)
    {
        if(!cJSON_IsString(conversion_review_versions_local))
        {
            goto end;
        }
        list_addElement(conversion_review_versionsList , strdup(conversion_review_versions_local->valuestring));
    }


    v1_webhook_conversion_local_var = v1_webhook_conversion_create (
        clientConfig ? clientConfig_local_nonprim : NULL,
        conversion_review_versionsList
        );

    return v1_webhook_conversion_local_var;
end:
    return NULL;

}
