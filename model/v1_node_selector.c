#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_selector.h"



v1_node_selector_t *v1_node_selector_create(
    list_t *nodeSelectorTerms
    ) {
	v1_node_selector_t *v1_node_selector_local_var = malloc(sizeof(v1_node_selector_t));
    if (!v1_node_selector_local_var) {
        return NULL;
    }
	v1_node_selector_local_var->nodeSelectorTerms = nodeSelectorTerms;

	return v1_node_selector_local_var;
}


void v1_node_selector_free(v1_node_selector_t *v1_node_selector) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_node_selector->nodeSelectorTerms) {
		v1_node_selector_term_free(listEntry->data);
	}
	list_free(v1_node_selector->nodeSelectorTerms);
	free(v1_node_selector);
}

cJSON *v1_node_selector_convertToJSON(v1_node_selector_t *v1_node_selector) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_selector->nodeSelectorTerms
    if (!v1_node_selector->nodeSelectorTerms) {
        goto fail;
    }
    
    cJSON *nodeSelectorTerms = cJSON_AddArrayToObject(item, "nodeSelectorTerms");
    if(nodeSelectorTerms == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *nodeSelectorTermsListEntry;
    if (v1_node_selector->nodeSelectorTerms) {
    list_ForEach(nodeSelectorTermsListEntry, v1_node_selector->nodeSelectorTerms) {
    cJSON *itemLocal = v1_node_selector_term_convertToJSON(nodeSelectorTermsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(nodeSelectorTerms, itemLocal);
    }
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_node_selector_t *v1_node_selector_parseFromJSON(cJSON *v1_node_selectorJSON){

    v1_node_selector_t *v1_node_selector_local_var = NULL;

    // v1_node_selector->nodeSelectorTerms
    cJSON *nodeSelectorTerms = cJSON_GetObjectItemCaseSensitive(v1_node_selectorJSON, "nodeSelectorTerms");
    if (!nodeSelectorTerms) {
        goto end;
    }

    list_t *nodeSelectorTermsList;
    
    cJSON *nodeSelectorTerms_local_nonprimitive;
    if(!cJSON_IsArray(nodeSelectorTerms)){
        goto end; //nonprimitive container
    }

    nodeSelectorTermsList = list_create();

    cJSON_ArrayForEach(nodeSelectorTerms_local_nonprimitive,nodeSelectorTerms )
    {
        if(!cJSON_IsObject(nodeSelectorTerms_local_nonprimitive)){
            goto end;
        }
        v1_node_selector_term_t *nodeSelectorTermsItem = v1_node_selector_term_parseFromJSON(nodeSelectorTerms_local_nonprimitive);

        list_addElement(nodeSelectorTermsList, nodeSelectorTermsItem);
    }


    v1_node_selector_local_var = v1_node_selector_create (
        nodeSelectorTermsList
        );

    return v1_node_selector_local_var;
end:
    return NULL;

}
