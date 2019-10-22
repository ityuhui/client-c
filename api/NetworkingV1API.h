#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_network_policy.h"
#include "../model/v1_network_policy_list.h"
#include "../model/v1_status.h"


// create a NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_createNetworkingV1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * namespace ,v1_network_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of NetworkPolicy
//
v1_status_t*
NetworkingV1API_deleteNetworkingV1CollectionNamespacedNetworkPolicy(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a NetworkPolicy
//
v1_status_t*
NetworkingV1API_deleteNetworkingV1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
NetworkingV1API_getNetworkingV1APIResources(apiClient_t *apiClient);


// list or watch objects of kind NetworkPolicy
//
v1_network_policy_list_t*
NetworkingV1API_listNetworkingV1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind NetworkPolicy
//
v1_network_policy_list_t*
NetworkingV1API_listNetworkingV1NetworkPolicyForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_patchNetworkingV1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_readNetworkingV1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// replace the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_replaceNetworkingV1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace ,v1_network_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


