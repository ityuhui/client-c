#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_windows_security_context_options.h"



v1_windows_security_context_options_t *v1_windows_security_context_options_create(
    char *gmsaCredentialSpec,
    char *gmsaCredentialSpecName,
    char *runAsUserName
    ) {
	v1_windows_security_context_options_t *v1_windows_security_context_options_local_var = malloc(sizeof(v1_windows_security_context_options_t));
    if (!v1_windows_security_context_options_local_var) {
        return NULL;
    }
	v1_windows_security_context_options_local_var->gmsaCredentialSpec = gmsaCredentialSpec;
	v1_windows_security_context_options_local_var->gmsaCredentialSpecName = gmsaCredentialSpecName;
	v1_windows_security_context_options_local_var->runAsUserName = runAsUserName;

	return v1_windows_security_context_options_local_var;
}


void v1_windows_security_context_options_free(v1_windows_security_context_options_t *v1_windows_security_context_options) {
    listEntry_t *listEntry;
    free(v1_windows_security_context_options->gmsaCredentialSpec);
    free(v1_windows_security_context_options->gmsaCredentialSpecName);
    free(v1_windows_security_context_options->runAsUserName);
	free(v1_windows_security_context_options);
}

cJSON *v1_windows_security_context_options_convertToJSON(v1_windows_security_context_options_t *v1_windows_security_context_options) {
	cJSON *item = cJSON_CreateObject();

	// v1_windows_security_context_options->gmsaCredentialSpec
    if(v1_windows_security_context_options->gmsaCredentialSpec) { 
    if(cJSON_AddStringToObject(item, "gmsaCredentialSpec", v1_windows_security_context_options->gmsaCredentialSpec) == NULL) {
    goto fail; //String
    }
     } 


	// v1_windows_security_context_options->gmsaCredentialSpecName
    if(v1_windows_security_context_options->gmsaCredentialSpecName) { 
    if(cJSON_AddStringToObject(item, "gmsaCredentialSpecName", v1_windows_security_context_options->gmsaCredentialSpecName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_windows_security_context_options->runAsUserName
    if(v1_windows_security_context_options->runAsUserName) { 
    if(cJSON_AddStringToObject(item, "runAsUserName", v1_windows_security_context_options->runAsUserName) == NULL) {
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

v1_windows_security_context_options_t *v1_windows_security_context_options_parseFromJSON(cJSON *v1_windows_security_context_optionsJSON){

    v1_windows_security_context_options_t *v1_windows_security_context_options_local_var = NULL;

    // v1_windows_security_context_options->gmsaCredentialSpec
    cJSON *gmsaCredentialSpec = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "gmsaCredentialSpec");
    if (gmsaCredentialSpec) { 
    if(!cJSON_IsString(gmsaCredentialSpec))
    {
    goto end; //String
    }
    }

    // v1_windows_security_context_options->gmsaCredentialSpecName
    cJSON *gmsaCredentialSpecName = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "gmsaCredentialSpecName");
    if (gmsaCredentialSpecName) { 
    if(!cJSON_IsString(gmsaCredentialSpecName))
    {
    goto end; //String
    }
    }

    // v1_windows_security_context_options->runAsUserName
    cJSON *runAsUserName = cJSON_GetObjectItemCaseSensitive(v1_windows_security_context_optionsJSON, "runAsUserName");
    if (runAsUserName) { 
    if(!cJSON_IsString(runAsUserName))
    {
    goto end; //String
    }
    }


    v1_windows_security_context_options_local_var = v1_windows_security_context_options_create (
        gmsaCredentialSpec ? strdup(gmsaCredentialSpec->valuestring) : NULL,
        gmsaCredentialSpecName ? strdup(gmsaCredentialSpecName->valuestring) : NULL,
        runAsUserName ? strdup(runAsUserName->valuestring) : NULL
        );

    return v1_windows_security_context_options_local_var;
end:
    return NULL;

}
