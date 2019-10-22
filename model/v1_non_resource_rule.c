#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_non_resource_rule.h"



v1_non_resource_rule_t *v1_non_resource_rule_create(
    list_t *nonResourceURLs,
    list_t *verbs
    ) {
	v1_non_resource_rule_t *v1_non_resource_rule_local_var = malloc(sizeof(v1_non_resource_rule_t));
    if (!v1_non_resource_rule_local_var) {
        return NULL;
    }
	v1_non_resource_rule_local_var->nonResourceURLs = nonResourceURLs;
	v1_non_resource_rule_local_var->verbs = verbs;

	return v1_non_resource_rule_local_var;
}


void v1_non_resource_rule_free(v1_non_resource_rule_t *v1_non_resource_rule) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_non_resource_rule->nonResourceURLs) {
		free(listEntry->data);
	}
	list_free(v1_non_resource_rule->nonResourceURLs);
	list_ForEach(listEntry, v1_non_resource_rule->verbs) {
		free(listEntry->data);
	}
	list_free(v1_non_resource_rule->verbs);
	free(v1_non_resource_rule);
}

cJSON *v1_non_resource_rule_convertToJSON(v1_non_resource_rule_t *v1_non_resource_rule) {
	cJSON *item = cJSON_CreateObject();

	// v1_non_resource_rule->nonResourceURLs
    if(v1_non_resource_rule->nonResourceURLs) { 
	cJSON *non_resource_ur_ls = cJSON_AddArrayToObject(item, "nonResourceURLs");
	if(non_resource_ur_ls == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *non_resource_ur_lsListEntry;
    list_ForEach(non_resource_ur_lsListEntry, v1_non_resource_rule->nonResourceURLs) {
    if(cJSON_AddStringToObject(non_resource_ur_ls, "", (char*)non_resource_ur_lsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_non_resource_rule->verbs
    if (!v1_non_resource_rule->verbs) {
        goto fail;
    }
    
	cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
	if(verbs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1_non_resource_rule->verbs) {
    if(cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
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

v1_non_resource_rule_t *v1_non_resource_rule_parseFromJSON(cJSON *v1_non_resource_ruleJSON){

    v1_non_resource_rule_t *v1_non_resource_rule_local_var = NULL;

    // v1_non_resource_rule->nonResourceURLs
    cJSON *nonResourceURLs = cJSON_GetObjectItemCaseSensitive(v1_non_resource_ruleJSON, "nonResourceURLs");
    list_t *non_resource_ur_lsList;
    if (nonResourceURLs) { 
    cJSON *non_resource_ur_ls_local;
    if(!cJSON_IsArray(nonResourceURLs)) {
        goto end;//primitive container
    }
    non_resource_ur_lsList = list_create();

    cJSON_ArrayForEach(non_resource_ur_ls_local, nonResourceURLs)
    {
        if(!cJSON_IsString(non_resource_ur_ls_local))
        {
            goto end;
        }
        list_addElement(non_resource_ur_lsList , strdup(non_resource_ur_ls_local->valuestring));
    }
    }

    // v1_non_resource_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1_non_resource_ruleJSON, "verbs");
    if (!verbs) {
        goto end;
    }

    list_t *verbsList;
    
    cJSON *verbs_local;
    if(!cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_create();

    cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1_non_resource_rule_local_var = v1_non_resource_rule_create (
        nonResourceURLs ? non_resource_ur_lsList : NULL,
        verbsList
        );

    return v1_non_resource_rule_local_var;
end:
    return NULL;

}
