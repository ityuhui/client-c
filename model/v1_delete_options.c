#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_delete_options.h"



v1_delete_options_t *v1_delete_options_create(
    char *apiVersion,
    list_t *dryRun,
    long gracePeriodSeconds,
    char *kind,
    int orphanDependents,
    v1_preconditions_t *preconditions,
    char *propagationPolicy
    ) {
	v1_delete_options_t *v1_delete_options_local_var = malloc(sizeof(v1_delete_options_t));
    if (!v1_delete_options_local_var) {
        return NULL;
    }
	v1_delete_options_local_var->apiVersion = apiVersion;
	v1_delete_options_local_var->dryRun = dryRun;
	v1_delete_options_local_var->gracePeriodSeconds = gracePeriodSeconds;
	v1_delete_options_local_var->kind = kind;
	v1_delete_options_local_var->orphanDependents = orphanDependents;
	v1_delete_options_local_var->preconditions = preconditions;
	v1_delete_options_local_var->propagationPolicy = propagationPolicy;

	return v1_delete_options_local_var;
}


void v1_delete_options_free(v1_delete_options_t *v1_delete_options) {
    listEntry_t *listEntry;
    free(v1_delete_options->apiVersion);
	list_ForEach(listEntry, v1_delete_options->dryRun) {
		free(listEntry->data);
	}
	list_free(v1_delete_options->dryRun);
    free(v1_delete_options->kind);
    v1_preconditions_free(v1_delete_options->preconditions);
    free(v1_delete_options->propagationPolicy);
	free(v1_delete_options);
}

cJSON *v1_delete_options_convertToJSON(v1_delete_options_t *v1_delete_options) {
	cJSON *item = cJSON_CreateObject();

	// v1_delete_options->apiVersion
    if(v1_delete_options->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_delete_options->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_delete_options->dryRun
    if(v1_delete_options->dryRun) { 
	cJSON *dry_run = cJSON_AddArrayToObject(item, "dryRun");
	if(dry_run == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *dry_runListEntry;
    list_ForEach(dry_runListEntry, v1_delete_options->dryRun) {
    if(cJSON_AddStringToObject(dry_run, "", (char*)dry_runListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_delete_options->gracePeriodSeconds
    if(v1_delete_options->gracePeriodSeconds) { 
    if(cJSON_AddNumberToObject(item, "gracePeriodSeconds", v1_delete_options->gracePeriodSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_delete_options->kind
    if(v1_delete_options->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_delete_options->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_delete_options->orphanDependents
    if(v1_delete_options->orphanDependents) { 
    if(cJSON_AddBoolToObject(item, "orphanDependents", v1_delete_options->orphanDependents) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_delete_options->preconditions
    if(v1_delete_options->preconditions) { 
    cJSON *preconditions_local_JSON = v1_preconditions_convertToJSON(v1_delete_options->preconditions);
    if(preconditions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preconditions", preconditions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_delete_options->propagationPolicy
    if(v1_delete_options->propagationPolicy) { 
    if(cJSON_AddStringToObject(item, "propagationPolicy", v1_delete_options->propagationPolicy) == NULL) {
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

v1_delete_options_t *v1_delete_options_parseFromJSON(cJSON *v1_delete_optionsJSON){

    v1_delete_options_t *v1_delete_options_local_var = NULL;

    // v1_delete_options->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_delete_options->dryRun
    cJSON *dryRun = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "dryRun");
    list_t *dry_runList;
    if (dryRun) { 
    cJSON *dry_run_local;
    if(!cJSON_IsArray(dryRun)) {
        goto end;//primitive container
    }
    dry_runList = list_create();

    cJSON_ArrayForEach(dry_run_local, dryRun)
    {
        if(!cJSON_IsString(dry_run_local))
        {
            goto end;
        }
        list_addElement(dry_runList , strdup(dry_run_local->valuestring));
    }
    }

    // v1_delete_options->gracePeriodSeconds
    cJSON *gracePeriodSeconds = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "gracePeriodSeconds");
    if (gracePeriodSeconds) { 
    if(!cJSON_IsNumber(gracePeriodSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_delete_options->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_delete_options->orphanDependents
    cJSON *orphanDependents = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "orphanDependents");
    if (orphanDependents) { 
    if(!cJSON_IsBool(orphanDependents))
    {
    goto end; //Bool
    }
    }

    // v1_delete_options->preconditions
    cJSON *preconditions = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "preconditions");
    v1_preconditions_t *preconditions_local_nonprim = NULL;
    if (preconditions) { 
    preconditions_local_nonprim = v1_preconditions_parseFromJSON(preconditions); //nonprimitive
    }

    // v1_delete_options->propagationPolicy
    cJSON *propagationPolicy = cJSON_GetObjectItemCaseSensitive(v1_delete_optionsJSON, "propagationPolicy");
    if (propagationPolicy) { 
    if(!cJSON_IsString(propagationPolicy))
    {
    goto end; //String
    }
    }


    v1_delete_options_local_var = v1_delete_options_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        dryRun ? dry_runList : NULL,
        gracePeriodSeconds ? gracePeriodSeconds->valuedouble : 0,
        kind ? strdup(kind->valuestring) : NULL,
        orphanDependents ? orphanDependents->valueint : 0,
        preconditions ? preconditions_local_nonprim : NULL,
        propagationPolicy ? strdup(propagationPolicy->valuestring) : NULL
        );

    return v1_delete_options_local_var;
end:
    return NULL;

}
