#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_role.h"



v1_role_t *v1_role_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
    ) {
	v1_role_t *v1_role_local_var = malloc(sizeof(v1_role_t));
    if (!v1_role_local_var) {
        return NULL;
    }
	v1_role_local_var->apiVersion = apiVersion;
	v1_role_local_var->kind = kind;
	v1_role_local_var->metadata = metadata;
	v1_role_local_var->rules = rules;

	return v1_role_local_var;
}


void v1_role_free(v1_role_t *v1_role) {
    listEntry_t *listEntry;
    free(v1_role->apiVersion);
    free(v1_role->kind);
    v1_object_meta_free(v1_role->metadata);
	list_ForEach(listEntry, v1_role->rules) {
		v1_policy_rule_free(listEntry->data);
	}
	list_free(v1_role->rules);
	free(v1_role);
}

cJSON *v1_role_convertToJSON(v1_role_t *v1_role) {
	cJSON *item = cJSON_CreateObject();

	// v1_role->apiVersion
    if(v1_role->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_role->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_role->kind
    if(v1_role->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_role->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_role->metadata
    if(v1_role->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_role->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_role->rules
    if(v1_role->rules) { 
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_role->rules) {
    list_ForEach(rulesListEntry, v1_role->rules) {
    cJSON *itemLocal = v1_policy_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_role_t *v1_role_parseFromJSON(cJSON *v1_roleJSON){

    v1_role_t *v1_role_local_var = NULL;

    // v1_role->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_role->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_role->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_role->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "rules");
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
        v1_policy_rule_t *rulesItem = v1_policy_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }


    v1_role_local_var = v1_role_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        rules ? rulesList : NULL
        );

    return v1_role_local_var;
end:
    return NULL;

}
