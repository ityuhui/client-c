#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_peer.h"



v1_network_policy_peer_t *v1_network_policy_peer_create(
    v1_ip_block_t *ipBlock,
    v1_label_selector_t *namespaceSelector,
    v1_label_selector_t *podSelector
    ) {
	v1_network_policy_peer_t *v1_network_policy_peer_local_var = malloc(sizeof(v1_network_policy_peer_t));
    if (!v1_network_policy_peer_local_var) {
        return NULL;
    }
	v1_network_policy_peer_local_var->ipBlock = ipBlock;
	v1_network_policy_peer_local_var->namespaceSelector = namespaceSelector;
	v1_network_policy_peer_local_var->podSelector = podSelector;

	return v1_network_policy_peer_local_var;
}


void v1_network_policy_peer_free(v1_network_policy_peer_t *v1_network_policy_peer) {
    listEntry_t *listEntry;
    v1_ip_block_free(v1_network_policy_peer->ipBlock);
    v1_label_selector_free(v1_network_policy_peer->namespaceSelector);
    v1_label_selector_free(v1_network_policy_peer->podSelector);
	free(v1_network_policy_peer);
}

cJSON *v1_network_policy_peer_convertToJSON(v1_network_policy_peer_t *v1_network_policy_peer) {
	cJSON *item = cJSON_CreateObject();

	// v1_network_policy_peer->ipBlock
    if(v1_network_policy_peer->ipBlock) { 
    cJSON *ipBlock_local_JSON = v1_ip_block_convertToJSON(v1_network_policy_peer->ipBlock);
    if(ipBlock_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ipBlock", ipBlock_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_network_policy_peer->namespaceSelector
    if(v1_network_policy_peer->namespaceSelector) { 
    cJSON *namespaceSelector_local_JSON = v1_label_selector_convertToJSON(v1_network_policy_peer->namespaceSelector);
    if(namespaceSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namespaceSelector", namespaceSelector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_network_policy_peer->podSelector
    if(v1_network_policy_peer->podSelector) { 
    cJSON *podSelector_local_JSON = v1_label_selector_convertToJSON(v1_network_policy_peer->podSelector);
    if(podSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podSelector", podSelector_local_JSON);
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

v1_network_policy_peer_t *v1_network_policy_peer_parseFromJSON(cJSON *v1_network_policy_peerJSON){

    v1_network_policy_peer_t *v1_network_policy_peer_local_var = NULL;

    // v1_network_policy_peer->ipBlock
    cJSON *ipBlock = cJSON_GetObjectItemCaseSensitive(v1_network_policy_peerJSON, "ipBlock");
    v1_ip_block_t *ipBlock_local_nonprim = NULL;
    if (ipBlock) { 
    ipBlock_local_nonprim = v1_ip_block_parseFromJSON(ipBlock); //nonprimitive
    }

    // v1_network_policy_peer->namespaceSelector
    cJSON *namespaceSelector = cJSON_GetObjectItemCaseSensitive(v1_network_policy_peerJSON, "namespaceSelector");
    v1_label_selector_t *namespaceSelector_local_nonprim = NULL;
    if (namespaceSelector) { 
    namespaceSelector_local_nonprim = v1_label_selector_parseFromJSON(namespaceSelector); //nonprimitive
    }

    // v1_network_policy_peer->podSelector
    cJSON *podSelector = cJSON_GetObjectItemCaseSensitive(v1_network_policy_peerJSON, "podSelector");
    v1_label_selector_t *podSelector_local_nonprim = NULL;
    if (podSelector) { 
    podSelector_local_nonprim = v1_label_selector_parseFromJSON(podSelector); //nonprimitive
    }


    v1_network_policy_peer_local_var = v1_network_policy_peer_create (
        ipBlock ? ipBlock_local_nonprim : NULL,
        namespaceSelector ? namespaceSelector_local_nonprim : NULL,
        podSelector ? podSelector_local_nonprim : NULL
        );

    return v1_network_policy_peer_local_var;
end:
    return NULL;

}
