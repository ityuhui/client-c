#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_aggregation_rule.h"



v1_aggregation_rule_t *v1_aggregation_rule_create(
    list_t *clusterRoleSelectors
    ) {
	v1_aggregation_rule_t *v1_aggregation_rule_local_var = malloc(sizeof(v1_aggregation_rule_t));
    if (!v1_aggregation_rule_local_var) {
        return NULL;
    }
	v1_aggregation_rule_local_var->clusterRoleSelectors = clusterRoleSelectors;

	return v1_aggregation_rule_local_var;
}


void v1_aggregation_rule_free(v1_aggregation_rule_t *v1_aggregation_rule) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_aggregation_rule->clusterRoleSelectors) {
		v1_label_selector_free(listEntry->data);
	}
	list_free(v1_aggregation_rule->clusterRoleSelectors);
	free(v1_aggregation_rule);
}

cJSON *v1_aggregation_rule_convertToJSON(v1_aggregation_rule_t *v1_aggregation_rule) {
	cJSON *item = cJSON_CreateObject();

	// v1_aggregation_rule->clusterRoleSelectors
    if(v1_aggregation_rule->clusterRoleSelectors) { 
    cJSON *clusterRoleSelectors = cJSON_AddArrayToObject(item, "clusterRoleSelectors");
    if(clusterRoleSelectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *clusterRoleSelectorsListEntry;
    if (v1_aggregation_rule->clusterRoleSelectors) {
    list_ForEach(clusterRoleSelectorsListEntry, v1_aggregation_rule->clusterRoleSelectors) {
    cJSON *itemLocal = v1_label_selector_convertToJSON(clusterRoleSelectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(clusterRoleSelectors, itemLocal);
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

v1_aggregation_rule_t *v1_aggregation_rule_parseFromJSON(cJSON *v1_aggregation_ruleJSON){

    v1_aggregation_rule_t *v1_aggregation_rule_local_var = NULL;

    // v1_aggregation_rule->clusterRoleSelectors
    cJSON *clusterRoleSelectors = cJSON_GetObjectItemCaseSensitive(v1_aggregation_ruleJSON, "clusterRoleSelectors");
    list_t *clusterRoleSelectorsList;
    if (clusterRoleSelectors) { 
    cJSON *clusterRoleSelectors_local_nonprimitive;
    if(!cJSON_IsArray(clusterRoleSelectors)){
        goto end; //nonprimitive container
    }

    clusterRoleSelectorsList = list_create();

    cJSON_ArrayForEach(clusterRoleSelectors_local_nonprimitive,clusterRoleSelectors )
    {
        if(!cJSON_IsObject(clusterRoleSelectors_local_nonprimitive)){
            goto end;
        }
        v1_label_selector_t *clusterRoleSelectorsItem = v1_label_selector_parseFromJSON(clusterRoleSelectors_local_nonprimitive);

        list_addElement(clusterRoleSelectorsList, clusterRoleSelectorsItem);
    }
    }


    v1_aggregation_rule_local_var = v1_aggregation_rule_create (
        clusterRoleSelectors ? clusterRoleSelectorsList : NULL
        );

    return v1_aggregation_rule_local_var;
end:
    return NULL;

}
