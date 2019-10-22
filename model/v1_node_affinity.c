#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_affinity.h"



v1_node_affinity_t *v1_node_affinity_create(
    list_t *preferredDuringSchedulingIgnoredDuringExecution,
    v1_node_selector_t *requiredDuringSchedulingIgnoredDuringExecution
    ) {
	v1_node_affinity_t *v1_node_affinity_local_var = malloc(sizeof(v1_node_affinity_t));
    if (!v1_node_affinity_local_var) {
        return NULL;
    }
	v1_node_affinity_local_var->preferredDuringSchedulingIgnoredDuringExecution = preferredDuringSchedulingIgnoredDuringExecution;
	v1_node_affinity_local_var->requiredDuringSchedulingIgnoredDuringExecution = requiredDuringSchedulingIgnoredDuringExecution;

	return v1_node_affinity_local_var;
}


void v1_node_affinity_free(v1_node_affinity_t *v1_node_affinity) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_node_affinity->preferredDuringSchedulingIgnoredDuringExecution) {
		v1_preferred_scheduling_term_free(listEntry->data);
	}
	list_free(v1_node_affinity->preferredDuringSchedulingIgnoredDuringExecution);
    v1_node_selector_free(v1_node_affinity->requiredDuringSchedulingIgnoredDuringExecution);
	free(v1_node_affinity);
}

cJSON *v1_node_affinity_convertToJSON(v1_node_affinity_t *v1_node_affinity) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_affinity->preferredDuringSchedulingIgnoredDuringExecution
    if(v1_node_affinity->preferredDuringSchedulingIgnoredDuringExecution) { 
    cJSON *preferredDuringSchedulingIgnoredDuringExecution = cJSON_AddArrayToObject(item, "preferredDuringSchedulingIgnoredDuringExecution");
    if(preferredDuringSchedulingIgnoredDuringExecution == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *preferredDuringSchedulingIgnoredDuringExecutionListEntry;
    if (v1_node_affinity->preferredDuringSchedulingIgnoredDuringExecution) {
    list_ForEach(preferredDuringSchedulingIgnoredDuringExecutionListEntry, v1_node_affinity->preferredDuringSchedulingIgnoredDuringExecution) {
    cJSON *itemLocal = v1_preferred_scheduling_term_convertToJSON(preferredDuringSchedulingIgnoredDuringExecutionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(preferredDuringSchedulingIgnoredDuringExecution, itemLocal);
    }
    }
     } 


	// v1_node_affinity->requiredDuringSchedulingIgnoredDuringExecution
    if(v1_node_affinity->requiredDuringSchedulingIgnoredDuringExecution) { 
    cJSON *requiredDuringSchedulingIgnoredDuringExecution_local_JSON = v1_node_selector_convertToJSON(v1_node_affinity->requiredDuringSchedulingIgnoredDuringExecution);
    if(requiredDuringSchedulingIgnoredDuringExecution_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "requiredDuringSchedulingIgnoredDuringExecution", requiredDuringSchedulingIgnoredDuringExecution_local_JSON);
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

v1_node_affinity_t *v1_node_affinity_parseFromJSON(cJSON *v1_node_affinityJSON){

    v1_node_affinity_t *v1_node_affinity_local_var = NULL;

    // v1_node_affinity->preferredDuringSchedulingIgnoredDuringExecution
    cJSON *preferredDuringSchedulingIgnoredDuringExecution = cJSON_GetObjectItemCaseSensitive(v1_node_affinityJSON, "preferredDuringSchedulingIgnoredDuringExecution");
    list_t *preferredDuringSchedulingIgnoredDuringExecutionList;
    if (preferredDuringSchedulingIgnoredDuringExecution) { 
    cJSON *preferredDuringSchedulingIgnoredDuringExecution_local_nonprimitive;
    if(!cJSON_IsArray(preferredDuringSchedulingIgnoredDuringExecution)){
        goto end; //nonprimitive container
    }

    preferredDuringSchedulingIgnoredDuringExecutionList = list_create();

    cJSON_ArrayForEach(preferredDuringSchedulingIgnoredDuringExecution_local_nonprimitive,preferredDuringSchedulingIgnoredDuringExecution )
    {
        if(!cJSON_IsObject(preferredDuringSchedulingIgnoredDuringExecution_local_nonprimitive)){
            goto end;
        }
        v1_preferred_scheduling_term_t *preferredDuringSchedulingIgnoredDuringExecutionItem = v1_preferred_scheduling_term_parseFromJSON(preferredDuringSchedulingIgnoredDuringExecution_local_nonprimitive);

        list_addElement(preferredDuringSchedulingIgnoredDuringExecutionList, preferredDuringSchedulingIgnoredDuringExecutionItem);
    }
    }

    // v1_node_affinity->requiredDuringSchedulingIgnoredDuringExecution
    cJSON *requiredDuringSchedulingIgnoredDuringExecution = cJSON_GetObjectItemCaseSensitive(v1_node_affinityJSON, "requiredDuringSchedulingIgnoredDuringExecution");
    v1_node_selector_t *requiredDuringSchedulingIgnoredDuringExecution_local_nonprim = NULL;
    if (requiredDuringSchedulingIgnoredDuringExecution) { 
    requiredDuringSchedulingIgnoredDuringExecution_local_nonprim = v1_node_selector_parseFromJSON(requiredDuringSchedulingIgnoredDuringExecution); //nonprimitive
    }


    v1_node_affinity_local_var = v1_node_affinity_create (
        preferredDuringSchedulingIgnoredDuringExecution ? preferredDuringSchedulingIgnoredDuringExecutionList : NULL,
        requiredDuringSchedulingIgnoredDuringExecution ? requiredDuringSchedulingIgnoredDuringExecution_local_nonprim : NULL
        );

    return v1_node_affinity_local_var;
end:
    return NULL;

}
