#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject_rules_review_status.h"



v1_subject_rules_review_status_t *v1_subject_rules_review_status_create(
    char *evaluationError,
    int incomplete,
    list_t *nonResourceRules,
    list_t *resourceRules
    ) {
	v1_subject_rules_review_status_t *v1_subject_rules_review_status_local_var = malloc(sizeof(v1_subject_rules_review_status_t));
    if (!v1_subject_rules_review_status_local_var) {
        return NULL;
    }
	v1_subject_rules_review_status_local_var->evaluationError = evaluationError;
	v1_subject_rules_review_status_local_var->incomplete = incomplete;
	v1_subject_rules_review_status_local_var->nonResourceRules = nonResourceRules;
	v1_subject_rules_review_status_local_var->resourceRules = resourceRules;

	return v1_subject_rules_review_status_local_var;
}


void v1_subject_rules_review_status_free(v1_subject_rules_review_status_t *v1_subject_rules_review_status) {
    listEntry_t *listEntry;
    free(v1_subject_rules_review_status->evaluationError);
	list_ForEach(listEntry, v1_subject_rules_review_status->nonResourceRules) {
		v1_non_resource_rule_free(listEntry->data);
	}
	list_free(v1_subject_rules_review_status->nonResourceRules);
	list_ForEach(listEntry, v1_subject_rules_review_status->resourceRules) {
		v1_resource_rule_free(listEntry->data);
	}
	list_free(v1_subject_rules_review_status->resourceRules);
	free(v1_subject_rules_review_status);
}

cJSON *v1_subject_rules_review_status_convertToJSON(v1_subject_rules_review_status_t *v1_subject_rules_review_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_subject_rules_review_status->evaluationError
    if(v1_subject_rules_review_status->evaluationError) { 
    if(cJSON_AddStringToObject(item, "evaluationError", v1_subject_rules_review_status->evaluationError) == NULL) {
    goto fail; //String
    }
     } 


	// v1_subject_rules_review_status->incomplete
    if (!v1_subject_rules_review_status->incomplete) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "incomplete", v1_subject_rules_review_status->incomplete) == NULL) {
    goto fail; //Bool
    }


	// v1_subject_rules_review_status->nonResourceRules
    if (!v1_subject_rules_review_status->nonResourceRules) {
        goto fail;
    }
    
    cJSON *nonResourceRules = cJSON_AddArrayToObject(item, "nonResourceRules");
    if(nonResourceRules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *nonResourceRulesListEntry;
    if (v1_subject_rules_review_status->nonResourceRules) {
    list_ForEach(nonResourceRulesListEntry, v1_subject_rules_review_status->nonResourceRules) {
    cJSON *itemLocal = v1_non_resource_rule_convertToJSON(nonResourceRulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(nonResourceRules, itemLocal);
    }
    }


	// v1_subject_rules_review_status->resourceRules
    if (!v1_subject_rules_review_status->resourceRules) {
        goto fail;
    }
    
    cJSON *resourceRules = cJSON_AddArrayToObject(item, "resourceRules");
    if(resourceRules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resourceRulesListEntry;
    if (v1_subject_rules_review_status->resourceRules) {
    list_ForEach(resourceRulesListEntry, v1_subject_rules_review_status->resourceRules) {
    cJSON *itemLocal = v1_resource_rule_convertToJSON(resourceRulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resourceRules, itemLocal);
    }
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_subject_rules_review_status_t *v1_subject_rules_review_status_parseFromJSON(cJSON *v1_subject_rules_review_statusJSON){

    v1_subject_rules_review_status_t *v1_subject_rules_review_status_local_var = NULL;

    // v1_subject_rules_review_status->evaluationError
    cJSON *evaluationError = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "evaluationError");
    if (evaluationError) { 
    if(!cJSON_IsString(evaluationError))
    {
    goto end; //String
    }
    }

    // v1_subject_rules_review_status->incomplete
    cJSON *incomplete = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "incomplete");
    if (!incomplete) {
        goto end;
    }

    
    if(!cJSON_IsBool(incomplete))
    {
    goto end; //Bool
    }

    // v1_subject_rules_review_status->nonResourceRules
    cJSON *nonResourceRules = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "nonResourceRules");
    if (!nonResourceRules) {
        goto end;
    }

    list_t *nonResourceRulesList;
    
    cJSON *nonResourceRules_local_nonprimitive;
    if(!cJSON_IsArray(nonResourceRules)){
        goto end; //nonprimitive container
    }

    nonResourceRulesList = list_create();

    cJSON_ArrayForEach(nonResourceRules_local_nonprimitive,nonResourceRules )
    {
        if(!cJSON_IsObject(nonResourceRules_local_nonprimitive)){
            goto end;
        }
        v1_non_resource_rule_t *nonResourceRulesItem = v1_non_resource_rule_parseFromJSON(nonResourceRules_local_nonprimitive);

        list_addElement(nonResourceRulesList, nonResourceRulesItem);
    }

    // v1_subject_rules_review_status->resourceRules
    cJSON *resourceRules = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "resourceRules");
    if (!resourceRules) {
        goto end;
    }

    list_t *resourceRulesList;
    
    cJSON *resourceRules_local_nonprimitive;
    if(!cJSON_IsArray(resourceRules)){
        goto end; //nonprimitive container
    }

    resourceRulesList = list_create();

    cJSON_ArrayForEach(resourceRules_local_nonprimitive,resourceRules )
    {
        if(!cJSON_IsObject(resourceRules_local_nonprimitive)){
            goto end;
        }
        v1_resource_rule_t *resourceRulesItem = v1_resource_rule_parseFromJSON(resourceRules_local_nonprimitive);

        list_addElement(resourceRulesList, resourceRulesItem);
    }


    v1_subject_rules_review_status_local_var = v1_subject_rules_review_status_create (
        evaluationError ? strdup(evaluationError->valuestring) : NULL,
        incomplete->valueint,
        nonResourceRulesList,
        resourceRulesList
        );

    return v1_subject_rules_review_status_local_var;
end:
    return NULL;

}
