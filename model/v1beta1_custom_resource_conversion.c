#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_conversion.h"



v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_create(
    list_t *conversionReviewVersions,
    char *strategy,
    apiextensions_v1beta1_webhook_client_config_t *webhookClientConfig
    ) {
	v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_local_var = malloc(sizeof(v1beta1_custom_resource_conversion_t));
    if (!v1beta1_custom_resource_conversion_local_var) {
        return NULL;
    }
	v1beta1_custom_resource_conversion_local_var->conversionReviewVersions = conversionReviewVersions;
	v1beta1_custom_resource_conversion_local_var->strategy = strategy;
	v1beta1_custom_resource_conversion_local_var->webhookClientConfig = webhookClientConfig;

	return v1beta1_custom_resource_conversion_local_var;
}


void v1beta1_custom_resource_conversion_free(v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_custom_resource_conversion->conversionReviewVersions) {
		free(listEntry->data);
	}
	list_free(v1beta1_custom_resource_conversion->conversionReviewVersions);
    free(v1beta1_custom_resource_conversion->strategy);
    apiextensions_v1beta1_webhook_client_config_free(v1beta1_custom_resource_conversion->webhookClientConfig);
	free(v1beta1_custom_resource_conversion);
}

cJSON *v1beta1_custom_resource_conversion_convertToJSON(v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_custom_resource_conversion->conversionReviewVersions
    if(v1beta1_custom_resource_conversion->conversionReviewVersions) { 
	cJSON *conversion_review_versions = cJSON_AddArrayToObject(item, "conversionReviewVersions");
	if(conversion_review_versions == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *conversion_review_versionsListEntry;
    list_ForEach(conversion_review_versionsListEntry, v1beta1_custom_resource_conversion->conversionReviewVersions) {
    if(cJSON_AddStringToObject(conversion_review_versions, "", (char*)conversion_review_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1beta1_custom_resource_conversion->strategy
    if (!v1beta1_custom_resource_conversion->strategy) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "strategy", v1beta1_custom_resource_conversion->strategy) == NULL) {
    goto fail; //String
    }


	// v1beta1_custom_resource_conversion->webhookClientConfig
    if(v1beta1_custom_resource_conversion->webhookClientConfig) { 
    cJSON *webhookClientConfig_local_JSON = apiextensions_v1beta1_webhook_client_config_convertToJSON(v1beta1_custom_resource_conversion->webhookClientConfig);
    if(webhookClientConfig_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webhookClientConfig", webhookClientConfig_local_JSON);
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

v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_parseFromJSON(cJSON *v1beta1_custom_resource_conversionJSON){

    v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_local_var = NULL;

    // v1beta1_custom_resource_conversion->conversionReviewVersions
    cJSON *conversionReviewVersions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_conversionJSON, "conversionReviewVersions");
    list_t *conversion_review_versionsList;
    if (conversionReviewVersions) { 
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
    }

    // v1beta1_custom_resource_conversion->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_conversionJSON, "strategy");
    if (!strategy) {
        goto end;
    }

    
    if(!cJSON_IsString(strategy))
    {
    goto end; //String
    }

    // v1beta1_custom_resource_conversion->webhookClientConfig
    cJSON *webhookClientConfig = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_conversionJSON, "webhookClientConfig");
    apiextensions_v1beta1_webhook_client_config_t *webhookClientConfig_local_nonprim = NULL;
    if (webhookClientConfig) { 
    webhookClientConfig_local_nonprim = apiextensions_v1beta1_webhook_client_config_parseFromJSON(webhookClientConfig); //nonprimitive
    }


    v1beta1_custom_resource_conversion_local_var = v1beta1_custom_resource_conversion_create (
        conversionReviewVersions ? conversion_review_versionsList : NULL,
        strdup(strategy->valuestring),
        webhookClientConfig ? webhookClientConfig_local_nonprim : NULL
        );

    return v1beta1_custom_resource_conversion_local_var;
end:
    return NULL;

}
