#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_security_context.h"



v1_pod_security_context_t *v1_pod_security_context_create(
    long fsGroup,
    long runAsGroup,
    int runAsNonRoot,
    long runAsUser,
    v1_se_linux_options_t *seLinuxOptions,
    list_t *supplementalGroups,
    list_t *sysctls,
    v1_windows_security_context_options_t *windowsOptions
    ) {
	v1_pod_security_context_t *v1_pod_security_context_local_var = malloc(sizeof(v1_pod_security_context_t));
    if (!v1_pod_security_context_local_var) {
        return NULL;
    }
	v1_pod_security_context_local_var->fsGroup = fsGroup;
	v1_pod_security_context_local_var->runAsGroup = runAsGroup;
	v1_pod_security_context_local_var->runAsNonRoot = runAsNonRoot;
	v1_pod_security_context_local_var->runAsUser = runAsUser;
	v1_pod_security_context_local_var->seLinuxOptions = seLinuxOptions;
	v1_pod_security_context_local_var->supplementalGroups = supplementalGroups;
	v1_pod_security_context_local_var->sysctls = sysctls;
	v1_pod_security_context_local_var->windowsOptions = windowsOptions;

	return v1_pod_security_context_local_var;
}


void v1_pod_security_context_free(v1_pod_security_context_t *v1_pod_security_context) {
    listEntry_t *listEntry;
    v1_se_linux_options_free(v1_pod_security_context->seLinuxOptions);
	list_ForEach(listEntry, v1_pod_security_context->supplementalGroups) {
		free(listEntry->data);
	}
	list_free(v1_pod_security_context->supplementalGroups);
	list_ForEach(listEntry, v1_pod_security_context->sysctls) {
		v1_sysctl_free(listEntry->data);
	}
	list_free(v1_pod_security_context->sysctls);
    v1_windows_security_context_options_free(v1_pod_security_context->windowsOptions);
	free(v1_pod_security_context);
}

cJSON *v1_pod_security_context_convertToJSON(v1_pod_security_context_t *v1_pod_security_context) {
	cJSON *item = cJSON_CreateObject();

	// v1_pod_security_context->fsGroup
    if(v1_pod_security_context->fsGroup) { 
    if(cJSON_AddNumberToObject(item, "fsGroup", v1_pod_security_context->fsGroup) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_pod_security_context->runAsGroup
    if(v1_pod_security_context->runAsGroup) { 
    if(cJSON_AddNumberToObject(item, "runAsGroup", v1_pod_security_context->runAsGroup) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_pod_security_context->runAsNonRoot
    if(v1_pod_security_context->runAsNonRoot) { 
    if(cJSON_AddBoolToObject(item, "runAsNonRoot", v1_pod_security_context->runAsNonRoot) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_pod_security_context->runAsUser
    if(v1_pod_security_context->runAsUser) { 
    if(cJSON_AddNumberToObject(item, "runAsUser", v1_pod_security_context->runAsUser) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_pod_security_context->seLinuxOptions
    if(v1_pod_security_context->seLinuxOptions) { 
    cJSON *seLinuxOptions_local_JSON = v1_se_linux_options_convertToJSON(v1_pod_security_context->seLinuxOptions);
    if(seLinuxOptions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinuxOptions", seLinuxOptions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_pod_security_context->supplementalGroups
    if(v1_pod_security_context->supplementalGroups) { 
	cJSON *supplemental_groups = cJSON_AddArrayToObject(item, "supplementalGroups");
	if(supplemental_groups == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *supplemental_groupsListEntry;
    list_ForEach(supplemental_groupsListEntry, v1_pod_security_context->supplementalGroups) {
    if(cJSON_AddNumberToObject(supplemental_groups, "", *(double *)supplemental_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_pod_security_context->sysctls
    if(v1_pod_security_context->sysctls) { 
    cJSON *sysctls = cJSON_AddArrayToObject(item, "sysctls");
    if(sysctls == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sysctlsListEntry;
    if (v1_pod_security_context->sysctls) {
    list_ForEach(sysctlsListEntry, v1_pod_security_context->sysctls) {
    cJSON *itemLocal = v1_sysctl_convertToJSON(sysctlsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sysctls, itemLocal);
    }
    }
     } 


	// v1_pod_security_context->windowsOptions
    if(v1_pod_security_context->windowsOptions) { 
    cJSON *windowsOptions_local_JSON = v1_windows_security_context_options_convertToJSON(v1_pod_security_context->windowsOptions);
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

v1_pod_security_context_t *v1_pod_security_context_parseFromJSON(cJSON *v1_pod_security_contextJSON){

    v1_pod_security_context_t *v1_pod_security_context_local_var = NULL;

    // v1_pod_security_context->fsGroup
    cJSON *fsGroup = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "fsGroup");
    if (fsGroup) { 
    if(!cJSON_IsNumber(fsGroup))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_security_context->runAsGroup
    cJSON *runAsGroup = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "runAsGroup");
    if (runAsGroup) { 
    if(!cJSON_IsNumber(runAsGroup))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_security_context->runAsNonRoot
    cJSON *runAsNonRoot = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "runAsNonRoot");
    if (runAsNonRoot) { 
    if(!cJSON_IsBool(runAsNonRoot))
    {
    goto end; //Bool
    }
    }

    // v1_pod_security_context->runAsUser
    cJSON *runAsUser = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "runAsUser");
    if (runAsUser) { 
    if(!cJSON_IsNumber(runAsUser))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_security_context->seLinuxOptions
    cJSON *seLinuxOptions = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "seLinuxOptions");
    v1_se_linux_options_t *seLinuxOptions_local_nonprim = NULL;
    if (seLinuxOptions) { 
    seLinuxOptions_local_nonprim = v1_se_linux_options_parseFromJSON(seLinuxOptions); //nonprimitive
    }

    // v1_pod_security_context->supplementalGroups
    cJSON *supplementalGroups = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "supplementalGroups");
    list_t *supplemental_groupsList;
    if (supplementalGroups) { 
    cJSON *supplemental_groups_local;
    if(!cJSON_IsArray(supplementalGroups)) {
        goto end;//primitive container
    }
    supplemental_groupsList = list_create();

    cJSON_ArrayForEach(supplemental_groups_local, supplementalGroups)
    {
        if(!cJSON_IsNumber(supplemental_groups_local))
        {
            goto end;
        }
        list_addElement(supplemental_groupsList , &supplemental_groups_local->valuedouble);
    }
    }

    // v1_pod_security_context->sysctls
    cJSON *sysctls = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "sysctls");
    list_t *sysctlsList;
    if (sysctls) { 
    cJSON *sysctls_local_nonprimitive;
    if(!cJSON_IsArray(sysctls)){
        goto end; //nonprimitive container
    }

    sysctlsList = list_create();

    cJSON_ArrayForEach(sysctls_local_nonprimitive,sysctls )
    {
        if(!cJSON_IsObject(sysctls_local_nonprimitive)){
            goto end;
        }
        v1_sysctl_t *sysctlsItem = v1_sysctl_parseFromJSON(sysctls_local_nonprimitive);

        list_addElement(sysctlsList, sysctlsItem);
    }
    }

    // v1_pod_security_context->windowsOptions
    cJSON *windowsOptions = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "windowsOptions");
    v1_windows_security_context_options_t *windowsOptions_local_nonprim = NULL;
    if (windowsOptions) { 
    windowsOptions_local_nonprim = v1_windows_security_context_options_parseFromJSON(windowsOptions); //nonprimitive
    }


    v1_pod_security_context_local_var = v1_pod_security_context_create (
        fsGroup ? fsGroup->valuedouble : 0,
        runAsGroup ? runAsGroup->valuedouble : 0,
        runAsNonRoot ? runAsNonRoot->valueint : 0,
        runAsUser ? runAsUser->valuedouble : 0,
        seLinuxOptions ? seLinuxOptions_local_nonprim : NULL,
        supplementalGroups ? supplemental_groupsList : NULL,
        sysctls ? sysctlsList : NULL,
        windowsOptions ? windowsOptions_local_nonprim : NULL
        );

    return v1_pod_security_context_local_var;
end:
    return NULL;

}
