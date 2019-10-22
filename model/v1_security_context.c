#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_security_context.h"



v1_security_context_t *v1_security_context_create(
    int allowPrivilegeEscalation,
    v1_capabilities_t *capabilities,
    int privileged,
    char *procMount,
    int readOnlyRootFilesystem,
    long runAsGroup,
    int runAsNonRoot,
    long runAsUser,
    v1_se_linux_options_t *seLinuxOptions,
    v1_windows_security_context_options_t *windowsOptions
    ) {
	v1_security_context_t *v1_security_context_local_var = malloc(sizeof(v1_security_context_t));
    if (!v1_security_context_local_var) {
        return NULL;
    }
	v1_security_context_local_var->allowPrivilegeEscalation = allowPrivilegeEscalation;
	v1_security_context_local_var->capabilities = capabilities;
	v1_security_context_local_var->privileged = privileged;
	v1_security_context_local_var->procMount = procMount;
	v1_security_context_local_var->readOnlyRootFilesystem = readOnlyRootFilesystem;
	v1_security_context_local_var->runAsGroup = runAsGroup;
	v1_security_context_local_var->runAsNonRoot = runAsNonRoot;
	v1_security_context_local_var->runAsUser = runAsUser;
	v1_security_context_local_var->seLinuxOptions = seLinuxOptions;
	v1_security_context_local_var->windowsOptions = windowsOptions;

	return v1_security_context_local_var;
}


void v1_security_context_free(v1_security_context_t *v1_security_context) {
    listEntry_t *listEntry;
    v1_capabilities_free(v1_security_context->capabilities);
    free(v1_security_context->procMount);
    v1_se_linux_options_free(v1_security_context->seLinuxOptions);
    v1_windows_security_context_options_free(v1_security_context->windowsOptions);
	free(v1_security_context);
}

cJSON *v1_security_context_convertToJSON(v1_security_context_t *v1_security_context) {
	cJSON *item = cJSON_CreateObject();

	// v1_security_context->allowPrivilegeEscalation
    if(v1_security_context->allowPrivilegeEscalation) { 
    if(cJSON_AddBoolToObject(item, "allowPrivilegeEscalation", v1_security_context->allowPrivilegeEscalation) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_security_context->capabilities
    if(v1_security_context->capabilities) { 
    cJSON *capabilities_local_JSON = v1_capabilities_convertToJSON(v1_security_context->capabilities);
    if(capabilities_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "capabilities", capabilities_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_security_context->privileged
    if(v1_security_context->privileged) { 
    if(cJSON_AddBoolToObject(item, "privileged", v1_security_context->privileged) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_security_context->procMount
    if(v1_security_context->procMount) { 
    if(cJSON_AddStringToObject(item, "procMount", v1_security_context->procMount) == NULL) {
    goto fail; //String
    }
     } 


	// v1_security_context->readOnlyRootFilesystem
    if(v1_security_context->readOnlyRootFilesystem) { 
    if(cJSON_AddBoolToObject(item, "readOnlyRootFilesystem", v1_security_context->readOnlyRootFilesystem) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_security_context->runAsGroup
    if(v1_security_context->runAsGroup) { 
    if(cJSON_AddNumberToObject(item, "runAsGroup", v1_security_context->runAsGroup) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_security_context->runAsNonRoot
    if(v1_security_context->runAsNonRoot) { 
    if(cJSON_AddBoolToObject(item, "runAsNonRoot", v1_security_context->runAsNonRoot) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_security_context->runAsUser
    if(v1_security_context->runAsUser) { 
    if(cJSON_AddNumberToObject(item, "runAsUser", v1_security_context->runAsUser) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_security_context->seLinuxOptions
    if(v1_security_context->seLinuxOptions) { 
    cJSON *seLinuxOptions_local_JSON = v1_se_linux_options_convertToJSON(v1_security_context->seLinuxOptions);
    if(seLinuxOptions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinuxOptions", seLinuxOptions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_security_context->windowsOptions
    if(v1_security_context->windowsOptions) { 
    cJSON *windowsOptions_local_JSON = v1_windows_security_context_options_convertToJSON(v1_security_context->windowsOptions);
    if(windowsOptions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "windowsOptions", windowsOptions_local_JSON);
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

v1_security_context_t *v1_security_context_parseFromJSON(cJSON *v1_security_contextJSON){

    v1_security_context_t *v1_security_context_local_var = NULL;

    // v1_security_context->allowPrivilegeEscalation
    cJSON *allowPrivilegeEscalation = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "allowPrivilegeEscalation");
    if (allowPrivilegeEscalation) { 
    if(!cJSON_IsBool(allowPrivilegeEscalation))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->capabilities
    cJSON *capabilities = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "capabilities");
    v1_capabilities_t *capabilities_local_nonprim = NULL;
    if (capabilities) { 
    capabilities_local_nonprim = v1_capabilities_parseFromJSON(capabilities); //nonprimitive
    }

    // v1_security_context->privileged
    cJSON *privileged = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "privileged");
    if (privileged) { 
    if(!cJSON_IsBool(privileged))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->procMount
    cJSON *procMount = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "procMount");
    if (procMount) { 
    if(!cJSON_IsString(procMount))
    {
    goto end; //String
    }
    }

    // v1_security_context->readOnlyRootFilesystem
    cJSON *readOnlyRootFilesystem = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "readOnlyRootFilesystem");
    if (readOnlyRootFilesystem) { 
    if(!cJSON_IsBool(readOnlyRootFilesystem))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->runAsGroup
    cJSON *runAsGroup = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "runAsGroup");
    if (runAsGroup) { 
    if(!cJSON_IsNumber(runAsGroup))
    {
    goto end; //Numeric
    }
    }

    // v1_security_context->runAsNonRoot
    cJSON *runAsNonRoot = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "runAsNonRoot");
    if (runAsNonRoot) { 
    if(!cJSON_IsBool(runAsNonRoot))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->runAsUser
    cJSON *runAsUser = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "runAsUser");
    if (runAsUser) { 
    if(!cJSON_IsNumber(runAsUser))
    {
    goto end; //Numeric
    }
    }

    // v1_security_context->seLinuxOptions
    cJSON *seLinuxOptions = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "seLinuxOptions");
    v1_se_linux_options_t *seLinuxOptions_local_nonprim = NULL;
    if (seLinuxOptions) { 
    seLinuxOptions_local_nonprim = v1_se_linux_options_parseFromJSON(seLinuxOptions); //nonprimitive
    }

    // v1_security_context->windowsOptions
    cJSON *windowsOptions = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "windowsOptions");
    v1_windows_security_context_options_t *windowsOptions_local_nonprim = NULL;
    if (windowsOptions) { 
    windowsOptions_local_nonprim = v1_windows_security_context_options_parseFromJSON(windowsOptions); //nonprimitive
    }


    v1_security_context_local_var = v1_security_context_create (
        allowPrivilegeEscalation ? allowPrivilegeEscalation->valueint : 0,
        capabilities ? capabilities_local_nonprim : NULL,
        privileged ? privileged->valueint : 0,
        procMount ? strdup(procMount->valuestring) : NULL,
        readOnlyRootFilesystem ? readOnlyRootFilesystem->valueint : 0,
        runAsGroup ? runAsGroup->valuedouble : 0,
        runAsNonRoot ? runAsNonRoot->valueint : 0,
        runAsUser ? runAsUser->valuedouble : 0,
        seLinuxOptions ? seLinuxOptions_local_nonprim : NULL,
        windowsOptions ? windowsOptions_local_nonprim : NULL
        );

    return v1_security_context_local_var;
end:
    return NULL;

}
