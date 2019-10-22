#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_api_service_spec.h"



v1beta1_api_service_spec_t *v1beta1_api_service_spec_create(
    char caBundle,
    char *group,
    int groupPriorityMinimum,
    int insecureSkipTLSVerify,
    apiregistration_v1beta1_service_reference_t *service,
    char *version,
    int versionPriority
    ) {
	v1beta1_api_service_spec_t *v1beta1_api_service_spec_local_var = malloc(sizeof(v1beta1_api_service_spec_t));
    if (!v1beta1_api_service_spec_local_var) {
        return NULL;
    }
	v1beta1_api_service_spec_local_var->caBundle = caBundle;
	v1beta1_api_service_spec_local_var->group = group;
	v1beta1_api_service_spec_local_var->groupPriorityMinimum = groupPriorityMinimum;
	v1beta1_api_service_spec_local_var->insecureSkipTLSVerify = insecureSkipTLSVerify;
	v1beta1_api_service_spec_local_var->service = service;
	v1beta1_api_service_spec_local_var->version = version;
	v1beta1_api_service_spec_local_var->versionPriority = versionPriority;

	return v1beta1_api_service_spec_local_var;
}


void v1beta1_api_service_spec_free(v1beta1_api_service_spec_t *v1beta1_api_service_spec) {
    listEntry_t *listEntry;
    free(v1beta1_api_service_spec->group);
    apiregistration_v1beta1_service_reference_free(v1beta1_api_service_spec->service);
    free(v1beta1_api_service_spec->version);
	free(v1beta1_api_service_spec);
}

cJSON *v1beta1_api_service_spec_convertToJSON(v1beta1_api_service_spec_t *v1beta1_api_service_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_api_service_spec->caBundle
    if(v1beta1_api_service_spec->caBundle) { 
    if(cJSON_AddNumberToObject(item, "caBundle", v1beta1_api_service_spec->caBundle) == NULL) {
    goto fail; //Byte
    }
     } 


	// v1beta1_api_service_spec->group
    if(v1beta1_api_service_spec->group) { 
    if(cJSON_AddStringToObject(item, "group", v1beta1_api_service_spec->group) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_api_service_spec->groupPriorityMinimum
    if (!v1beta1_api_service_spec->groupPriorityMinimum) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "groupPriorityMinimum", v1beta1_api_service_spec->groupPriorityMinimum) == NULL) {
    goto fail; //Numeric
    }


	// v1beta1_api_service_spec->insecureSkipTLSVerify
    if(v1beta1_api_service_spec->insecureSkipTLSVerify) { 
    if(cJSON_AddBoolToObject(item, "insecureSkipTLSVerify", v1beta1_api_service_spec->insecureSkipTLSVerify) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1beta1_api_service_spec->service
    if (!v1beta1_api_service_spec->service) {
        goto fail;
    }
    
    cJSON *service_local_JSON = apiregistration_v1beta1_service_reference_convertToJSON(v1beta1_api_service_spec->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta1_api_service_spec->version
    if(v1beta1_api_service_spec->version) { 
    if(cJSON_AddStringToObject(item, "version", v1beta1_api_service_spec->version) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_api_service_spec->versionPriority
    if (!v1beta1_api_service_spec->versionPriority) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "versionPriority", v1beta1_api_service_spec->versionPriority) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_api_service_spec_t *v1beta1_api_service_spec_parseFromJSON(cJSON *v1beta1_api_service_specJSON){

    v1beta1_api_service_spec_t *v1beta1_api_service_spec_local_var = NULL;

    // v1beta1_api_service_spec->caBundle
    cJSON *caBundle = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "caBundle");
    if (caBundle) { 
    if(!cJSON_IsNumber(caBundle))
    {
    goto end; //Byte
    }
    }

    // v1beta1_api_service_spec->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }
    }

    // v1beta1_api_service_spec->groupPriorityMinimum
    cJSON *groupPriorityMinimum = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "groupPriorityMinimum");
    if (!groupPriorityMinimum) {
        goto end;
    }

    
    if(!cJSON_IsNumber(groupPriorityMinimum))
    {
    goto end; //Numeric
    }

    // v1beta1_api_service_spec->insecureSkipTLSVerify
    cJSON *insecureSkipTLSVerify = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "insecureSkipTLSVerify");
    if (insecureSkipTLSVerify) { 
    if(!cJSON_IsBool(insecureSkipTLSVerify))
    {
    goto end; //Bool
    }
    }

    // v1beta1_api_service_spec->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "service");
    if (!service) {
        goto end;
    }

    apiregistration_v1beta1_service_reference_t *service_local_nonprim = NULL;
    
    service_local_nonprim = apiregistration_v1beta1_service_reference_parseFromJSON(service); //nonprimitive

    // v1beta1_api_service_spec->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }

    // v1beta1_api_service_spec->versionPriority
    cJSON *versionPriority = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_specJSON, "versionPriority");
    if (!versionPriority) {
        goto end;
    }

    
    if(!cJSON_IsNumber(versionPriority))
    {
    goto end; //Numeric
    }


    v1beta1_api_service_spec_local_var = v1beta1_api_service_spec_create (
        caBundle ? caBundle->valueint : 0,
        group ? strdup(group->valuestring) : NULL,
        groupPriorityMinimum->valuedouble,
        insecureSkipTLSVerify ? insecureSkipTLSVerify->valueint : 0,
        service_local_nonprim,
        version ? strdup(version->valuestring) : NULL,
        versionPriority->valuedouble
        );

    return v1beta1_api_service_spec_local_var;
end:
    return NULL;

}
