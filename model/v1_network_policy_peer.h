/*
 * v1_network_policy_peer.h
 *
 * NetworkPolicyPeer describes a peer to allow traffic from. Only certain combinations of fields are allowed
 */

#ifndef _v1_network_policy_peer_H_
#define _v1_network_policy_peer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_ip_block.h"
#include "v1_label_selector.h"



typedef struct v1_network_policy_peer_t {
    v1_ip_block_t *ipBlock; //model
    v1_label_selector_t *namespaceSelector; //model
    v1_label_selector_t *podSelector; //model

} v1_network_policy_peer_t;

v1_network_policy_peer_t *v1_network_policy_peer_create(
    v1_ip_block_t *ipBlock,
    v1_label_selector_t *namespaceSelector,
    v1_label_selector_t *podSelector
);

void v1_network_policy_peer_free(v1_network_policy_peer_t *v1_network_policy_peer);

v1_network_policy_peer_t *v1_network_policy_peer_parseFromJSON(cJSON *v1_network_policy_peerJSON);

cJSON *v1_network_policy_peer_convertToJSON(v1_network_policy_peer_t *v1_network_policy_peer);

#endif /* _v1_network_policy_peer_H_ */

