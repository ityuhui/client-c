#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validating_webhook.h"



v1_validating_webhook_t *v1_validating_webhook_create(
    list_t *admissionReviewVersions,
    admissionregistration_v1_webhook_client_config_t *clientConfig,
    char *failurePolicy,
    char *matchPolicy,
    char *name,
    v1_label_selector_t *namespaceSelector,
    v1_label_selector_t *objectSelector,
    list_t *rules,
    char *sideEffects,
    int timeoutSeconds
    ) {
	v1_validating_webhook_t *v1_validating_webhook_local_var = malloc(sizeof(v1_validating_webhook_t));
    if (!v1_validating_webhook_local_var) {
        return NULL;
    }
	v1_validating_webhook_local_var->admissionReviewVersions = admissionReviewVersions;
	v1_validating_webhook_local_var->clientConfig = clientConfig;
	v1_validating_webhook_local_var->failurePolicy = failurePolicy;
	v1_validating_webhook_local_var->matchPolicy = matchPolicy;
	v1_validating_webhook_local_var->name = name;
	v1_validating_webhook_local_var->namespaceSelector = namespaceSelector;
	v1_validating_webhook_local_var->objectSelector = objectSelector;
	v1_validating_webhook_local_var->rules = rules;
	v1_validating_webhook_local_var->sideEffects = sideEffects;
	v1_validating_webhook_local_var->timeoutSeconds = timeoutSeconds;

	return v1_validating_webhook_local_var;
}


void v1_validating_webhook_free(v1_validating_webhook_t *v1_validating_webhook) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_validating_webhook->admissionReviewVersions) {
		free(listEntry->data);
	}
	list_free(v1_validating_webhook->admissionReviewVersions);
    admissionregistration_v1_webhook_client_config_free(v1_validating_webhook->clientConfig);
    free(v1_validating_webhook->failurePolicy);
    free(v1_validating_webhook->matchPolicy);
    free(v1_validating_webhook->name);
    v1_label_selector_free(v1_validating_webhook->namespaceSelector);
    v1_label_selector_free(v1_validating_webhook->objectSelector);
	list_ForEach(listEntry, v1_validating_webhook->rules) {
		v1_rule_with_operations_free(listEntry->data);
	}
	list_free(v1_validating_webhook->rules);
    free(v1_validating_webhook->sideEffects);
	free(v1_validating_webhook);
}

cJSON *v1_validating_webhook_convertToJSON(v1_validating_webhook_t *v1_validating_webhook) {
	cJSON *item = cJSON_CreateObject();

	// v1_validating_webhook->admissionReviewVersions
    if (!v1_validating_webhook->admissionReviewVersions) {
        goto fail;
    }
    
	cJSON *admission_review_versions = cJSON_AddArrayToObject(item, "admissionReviewVersions");
	if(admission_review_versions == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *admission_review_versionsListEntry;
    list_ForEach(admission_review_versionsListEntry, v1_validating_webhook->admissionReviewVersions) {
    if(cJSON_AddStringToObject(admission_review_versions, "", (char*)admission_review_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// v1_validating_webhook->clientConfig
    if (!v1_validating_webhook->clientConfig) {
        goto fail;
    }
    
    cJSON *clientConfig_local_JSON = admissionregistration_v1_webhook_client_config_convertToJSON(v1_validating_webhook->clientConfig);
    if(clientConfig_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientConfig", clientConfig_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_validating_webhook->failurePolicy
    if(v1_validating_webhook->failurePolicy) { 
    if(cJSON_AddStringToObject(item, "failurePolicy", v1_validating_webhook->failurePolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_validating_webhook->matchPolicy
    if(v1_validating_webhook->matchPolicy) { 
    if(cJSON_AddStringToObject(item, "matchPolicy", v1_validating_webhook->matchPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_validating_webhook->name
    if (!v1_validating_webhook->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_validating_webhook->name) == NULL) {
    goto fail; //String
    }


	// v1_validating_webhook->namespaceSelector
    if(v1_validating_webhook->namespaceSelector) { 
    cJSON *namespaceSelector_local_JSON = v1_label_selector_convertToJSON(v1_validating_webhook->namespaceSelector);
    if(namespaceSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namespaceSelector", namespaceSelector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_validating_webhook->objectSelector
    if(v1_validating_webhook->objectSelector) { 
    cJSON *objectSelector_local_JSON = v1_label_selector_convertToJSON(v1_validating_webhook->objectSelector);
    if(objectSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "objectSelector", objectSelector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_validating_webhook->rules
    if(v1_validating_webhook->rules) { 
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_validating_webhook->rules) {
    list_ForEach(rulesListEntry, v1_validating_webhook->rules) {
    cJSON *itemLocal = v1_rule_with_operations_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }
     } 


	// v1_validating_webhook->sideEffects
    if (!v1_validating_webhook->sideEffects) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "sideEffects", v1_validating_webhook->sideEffects) == NULL) {
    goto fail; //String
    }


	// v1_validating_webhook->timeoutSeconds
    if(v1_validating_webhook->timeoutSeconds) { 
    if(cJSON_AddNumberToObject(item, "timeoutSeconds", v1_validating_webhook->timeoutSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_validating_webhook_t *v1_validating_webhook_parseFromJSON(cJSON *v1_validating_webhookJSON){

    v1_validating_webhook_t *v1_validating_webhook_local_var = NULL;

    // v1_validating_webhook->admissionReviewVersions
    cJSON *admissionReviewVersions = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "admissionReviewVersions");
    if (!admissionReviewVersions) {
        goto end;
    }

    list_t *admission_review_versionsList;
    
    cJSON *admission_review_versions_local;
    if(!cJSON_IsArray(admissionReviewVersions)) {
        goto end;//primitive container
    }
    admission_review_versionsList = list_create();

    cJSON_ArrayForEach(admission_review_versions_local, admissionReviewVersions)
    {
        if(!cJSON_IsString(admission_review_versions_local))
        {
            goto end;
        }
        list_addElement(admission_review_versionsList , strdup(admission_review_versions_local->valuestring));
    }

    // v1_validating_webhook->clientConfig
    cJSON *clientConfig = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "clientConfig");
    if (!clientConfig) {
        goto end;
    }

    admissionregistration_v1_webhook_client_config_t *clientConfig_local_nonprim = NULL;
    
    clientConfig_local_nonprim = admissionregistration_v1_webhook_client_config_parseFromJSON(clientConfig); //nonprimitive

    // v1_validating_webhook->failurePolicy
    cJSON *failurePolicy = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "failurePolicy");
    if (failurePolicy) { 
    if(!cJSON_IsString(failurePolicy))
    {
    goto end; //String
    }
    }

    // v1_validating_webhook->matchPolicy
    cJSON *matchPolicy = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "matchPolicy");
    if (matchPolicy) { 
    if(!cJSON_IsString(matchPolicy))
    {
    goto end; //String
    }
    }

    // v1_validating_webhook->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_validating_webhook->namespaceSelector
    cJSON *namespaceSelector = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "namespaceSelector");
    v1_label_selector_t *namespaceSelector_local_nonprim = NULL;
    if (namespaceSelector) { 
    namespaceSelector_local_nonprim = v1_label_selector_parseFromJSON(namespaceSelector); //nonprimitive
    }

    // v1_validating_webhook->objectSelector
    cJSON *objectSelector = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "objectSelector");
    v1_label_selector_t *objectSelector_local_nonprim = NULL;
    if (objectSelector) { 
    objectSelector_local_nonprim = v1_label_selector_parseFromJSON(objectSelector); //nonprimitive
    }

    // v1_validating_webhook->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "rules");
    list_t *rulesList;
    if (rules) { 
    cJSON *rules_local_nonprimitive;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_create();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        v1_rule_with_operations_t *rulesItem = v1_rule_with_operations_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }

    // v1_validating_webhook->sideEffects
    cJSON *sideEffects = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "sideEffects");
    if (!sideEffects) {
        goto end;
    }

    
    if(!cJSON_IsString(sideEffects))
    {
    goto end; //String
    }

    // v1_validating_webhook->timeoutSeconds
    cJSON *timeoutSeconds = cJSON_GetObjectItemCaseSensitive(v1_validating_webhookJSON, "timeoutSeconds");
    if (timeoutSeconds) { 
    if(!cJSON_IsNumber(timeoutSeconds))
    {
    goto end; //Numeric
    }
    }


    v1_validating_webhook_local_var = v1_validating_webhook_create (
        admission_review_versionsList,
        clientConfig_local_nonprim,
        failurePolicy ? strdup(failurePolicy->valuestring) : NULL,
        matchPolicy ? strdup(matchPolicy->valuestring) : NULL,
        strdup(name->valuestring),
        namespaceSelector ? namespaceSelector_local_nonprim : NULL,
        objectSelector ? objectSelector_local_nonprim : NULL,
        rules ? rulesList : NULL,
        strdup(sideEffects->valuestring),
        timeoutSeconds ? timeoutSeconds->valuedouble : 0
        );

    return v1_validating_webhook_local_var;
end:
    return NULL;

}
