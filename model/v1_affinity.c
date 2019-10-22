#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_affinity.h"



v1_affinity_t *v1_affinity_create(
    v1_node_affinity_t *nodeAffinity,
    v1_pod_affinity_t *podAffinity,
    v1_pod_anti_affinity_t *podAntiAffinity
    ) {
	v1_affinity_t *v1_affinity_local_var = malloc(sizeof(v1_affinity_t));
    if (!v1_affinity_local_var) {
        return NULL;
    }
	v1_affinity_local_var->nodeAffinity = nodeAffinity;
	v1_affinity_local_var->podAffinity = podAffinity;
	v1_affinity_local_var->podAntiAffinity = podAntiAffinity;

	return v1_affinity_local_var;
}


void v1_affinity_free(v1_affinity_t *v1_affinity) {
    listEntry_t *listEntry;
    v1_node_affinity_free(v1_affinity->nodeAffinity);
    v1_pod_affinity_free(v1_affinity->podAffinity);
    v1_pod_anti_affinity_free(v1_affinity->podAntiAffinity);
	free(v1_affinity);
}

cJSON *v1_affinity_convertToJSON(v1_affinity_t *v1_affinity) {
	cJSON *item = cJSON_CreateObject();

	// v1_affinity->nodeAffinity
    if(v1_affinity->nodeAffinity) { 
    cJSON *nodeAffinity_local_JSON = v1_node_affinity_convertToJSON(v1_affinity->nodeAffinity);
    if(nodeAffinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeAffinity", nodeAffinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_affinity->podAffinity
    if(v1_affinity->podAffinity) { 
    cJSON *podAffinity_local_JSON = v1_pod_affinity_convertToJSON(v1_affinity->podAffinity);
    if(podAffinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podAffinity", podAffinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_affinity->podAntiAffinity
    if(v1_affinity->podAntiAffinity) { 
    cJSON *podAntiAffinity_local_JSON = v1_pod_anti_affinity_convertToJSON(v1_affinity->podAntiAffinity);
    if(podAntiAffinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podAntiAffinity", podAntiAffinity_local_JSON);
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

v1_affinity_t *v1_affinity_parseFromJSON(cJSON *v1_affinityJSON){

    v1_affinity_t *v1_affinity_local_var = NULL;

    // v1_affinity->nodeAffinity
    cJSON *nodeAffinity = cJSON_GetObjectItemCaseSensitive(v1_affinityJSON, "nodeAffinity");
    v1_node_affinity_t *nodeAffinity_local_nonprim = NULL;
    if (nodeAffinity) { 
    nodeAffinity_local_nonprim = v1_node_affinity_parseFromJSON(nodeAffinity); //nonprimitive
    }

    // v1_affinity->podAffinity
    cJSON *podAffinity = cJSON_GetObjectItemCaseSensitive(v1_affinityJSON, "podAffinity");
    v1_pod_affinity_t *podAffinity_local_nonprim = NULL;
    if (podAffinity) { 
    podAffinity_local_nonprim = v1_pod_affinity_parseFromJSON(podAffinity); //nonprimitive
    }

    // v1_affinity->podAntiAffinity
    cJSON *podAntiAffinity = cJSON_GetObjectItemCaseSensitive(v1_affinityJSON, "podAntiAffinity");
    v1_pod_anti_affinity_t *podAntiAffinity_local_nonprim = NULL;
    if (podAntiAffinity) { 
    podAntiAffinity_local_nonprim = v1_pod_anti_affinity_parseFromJSON(podAntiAffinity); //nonprimitive
    }


    v1_affinity_local_var = v1_affinity_create (
        nodeAffinity ? nodeAffinity_local_nonprim : NULL,
        podAffinity ? podAffinity_local_nonprim : NULL,
        podAntiAffinity ? podAntiAffinity_local_nonprim : NULL
        );

    return v1_affinity_local_var;
end:
    return NULL;

}
