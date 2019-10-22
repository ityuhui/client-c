#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_affinity.h"



v1_pod_affinity_t *v1_pod_affinity_create(
    list_t *preferredDuringSchedulingIgnoredDuringExecution,
    list_t *requiredDuringSchedulingIgnoredDuringExecution
    ) {
	v1_pod_affinity_t *v1_pod_affinity_local_var = malloc(sizeof(v1_pod_affinity_t));
    if (!v1_pod_affinity_local_var) {
        return NULL;
    }
	v1_pod_affinity_local_var->preferredDuringSchedulingIgnoredDuringExecution = preferredDuringSchedulingIgnoredDuringExecution;
	v1_pod_affinity_local_var->requiredDuringSchedulingIgnoredDuringExecution = requiredDuringSchedulingIgnoredDuringExecution;

	return v1_pod_affinity_local_var;
}


void v1_pod_affinity_free(v1_pod_affinity_t *v1_pod_affinity) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_pod_affinity->preferredDuringSchedulingIgnoredDuringExecution) {
		v1_weighted_pod_affinity_term_free(listEntry->data);
	}
	list_free(v1_pod_affinity->preferredDuringSchedulingIgnoredDuringExecution);
	list_ForEach(listEntry, v1_pod_affinity->requiredDuringSchedulingIgnoredDuringExecution) {
		v1_pod_affinity_term_free(listEntry->data);
	}
	list_free(v1_pod_affinity->requiredDuringSchedulingIgnoredDuringExecution);
	free(v1_pod_affinity);
}

cJSON *v1_pod_affinity_convertToJSON(v1_pod_affinity_t *v1_pod_affinity) {
	cJSON *item = cJSON_CreateObject();

	// v1_pod_affinity->preferredDuringSchedulingIgnoredDuringExecution
    if(v1_pod_affinity->preferredDuringSchedulingIgnoredDuringExecution) { 
    cJSON *preferredDuringSchedulingIgnoredDuringExecution = cJSON_AddArrayToObject(item, "preferredDuringSchedulingIgnoredDuringExecution");
    if(preferredDuringSchedulingIgnoredDuringExecution == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *preferredDuringSchedulingIgnoredDuringExecutionListEntry;
    if (v1_pod_affinity->preferredDuringSchedulingIgnoredDuringExecution) {
    list_ForEach(preferredDuringSchedulingIgnoredDuringExecutionListEntry, v1_pod_affinity->preferredDuringSchedulingIgnoredDuringExecution) {
    cJSON *itemLocal = v1_weighted_pod_affinity_term_convertToJSON(preferredDuringSchedulingIgnoredDuringExecutionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(preferredDuringSchedulingIgnoredDuringExecution, itemLocal);
    }
    }
     } 


	// v1_pod_affinity->requiredDuringSchedulingIgnoredDuringExecution
    if(v1_pod_affinity->requiredDuringSchedulingIgnoredDuringExecution) { 
    cJSON *requiredDuringSchedulingIgnoredDuringExecution = cJSON_AddArrayToObject(item, "requiredDuringSchedulingIgnoredDuringExecution");
    if(requiredDuringSchedulingIgnoredDuringExecution == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *requiredDuringSchedulingIgnoredDuringExecutionListEntry;
    if (v1_pod_affinity->requiredDuringSchedulingIgnoredDuringExecution) {
    list_ForEach(requiredDuringSchedulingIgnoredDuringExecutionListEntry, v1_pod_affinity->requiredDuringSchedulingIgnoredDuringExecution) {
    cJSON *itemLocal = v1_pod_affinity_term_convertToJSON(requiredDuringSchedulingIgnoredDuringExecutionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(requiredDuringSchedulingIgnoredDuringExecution, itemLocal);
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

v1_pod_affinity_t *v1_pod_affinity_parseFromJSON(cJSON *v1_pod_affinityJSON){

    v1_pod_affinity_t *v1_pod_affinity_local_var = NULL;

    // v1_pod_affinity->preferredDuringSchedulingIgnoredDuringExecution
    cJSON *preferredDuringSchedulingIgnoredDuringExecution = cJSON_GetObjectItemCaseSensitive(v1_pod_affinityJSON, "preferredDuringSchedulingIgnoredDuringExecution");
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
        v1_weighted_pod_affinity_term_t *preferredDuringSchedulingIgnoredDuringExecutionItem = v1_weighted_pod_affinity_term_parseFromJSON(preferredDuringSchedulingIgnoredDuringExecution_local_nonprimitive);

        list_addElement(preferredDuringSchedulingIgnoredDuringExecutionList, preferredDuringSchedulingIgnoredDuringExecutionItem);
    }
    }

    // v1_pod_affinity->requiredDuringSchedulingIgnoredDuringExecution
    cJSON *requiredDuringSchedulingIgnoredDuringExecution = cJSON_GetObjectItemCaseSensitive(v1_pod_affinityJSON, "requiredDuringSchedulingIgnoredDuringExecution");
    list_t *requiredDuringSchedulingIgnoredDuringExecutionList;
    if (requiredDuringSchedulingIgnoredDuringExecution) { 
    cJSON *requiredDuringSchedulingIgnoredDuringExecution_local_nonprimitive;
    if(!cJSON_IsArray(requiredDuringSchedulingIgnoredDuringExecution)){
        goto end; //nonprimitive container
    }

    requiredDuringSchedulingIgnoredDuringExecutionList = list_create();

    cJSON_ArrayForEach(requiredDuringSchedulingIgnoredDuringExecution_local_nonprimitive,requiredDuringSchedulingIgnoredDuringExecution )
    {
        if(!cJSON_IsObject(requiredDuringSchedulingIgnoredDuringExecution_local_nonprimitive)){
            goto end;
        }
        v1_pod_affinity_term_t *requiredDuringSchedulingIgnoredDuringExecutionItem = v1_pod_affinity_term_parseFromJSON(requiredDuringSchedulingIgnoredDuringExecution_local_nonprimitive);

        list_addElement(requiredDuringSchedulingIgnoredDuringExecutionList, requiredDuringSchedulingIgnoredDuringExecutionItem);
    }
    }


    v1_pod_affinity_local_var = v1_pod_affinity_create (
        preferredDuringSchedulingIgnoredDuringExecution ? preferredDuringSchedulingIgnoredDuringExecutionList : NULL,
        requiredDuringSchedulingIgnoredDuringExecution ? requiredDuringSchedulingIgnoredDuringExecutionList : NULL
        );

    return v1_pod_affinity_local_var;
end:
    return NULL;

}
