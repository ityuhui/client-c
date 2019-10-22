#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1alpha1_endpoint_slice.h"
#include "../model/v1alpha1_endpoint_slice_list.h"


// create an EndpointSlice
//
v1alpha1_endpoint_slice_t*
DiscoveryV1alpha1API_createDiscoveryV1alpha1NamespacedEndpointSlice(apiClient_t *apiClient ,char * namespace ,v1alpha1_endpoint_slice_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of EndpointSlice
//
v1_status_t*
DiscoveryV1alpha1API_deleteDiscoveryV1alpha1CollectionNamespacedEndpointSlice(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete an EndpointSlice
//
v1_status_t*
DiscoveryV1alpha1API_deleteDiscoveryV1alpha1NamespacedEndpointSlice(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
DiscoveryV1alpha1API_getDiscoveryV1alpha1APIResources(apiClient_t *apiClient);


// list or watch objects of kind EndpointSlice
//
v1alpha1_endpoint_slice_list_t*
DiscoveryV1alpha1API_listDiscoveryV1alpha1EndpointSliceForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind EndpointSlice
//
v1alpha1_endpoint_slice_list_t*
DiscoveryV1alpha1API_listDiscoveryV1alpha1NamespacedEndpointSlice(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified EndpointSlice
//
v1alpha1_endpoint_slice_t*
DiscoveryV1alpha1API_patchDiscoveryV1alpha1NamespacedEndpointSlice(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified EndpointSlice
//
v1alpha1_endpoint_slice_t*
DiscoveryV1alpha1API_readDiscoveryV1alpha1NamespacedEndpointSlice(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// replace the specified EndpointSlice
//
v1alpha1_endpoint_slice_t*
DiscoveryV1alpha1API_replaceDiscoveryV1alpha1NamespacedEndpointSlice(apiClient_t *apiClient ,char * name ,char * namespace ,v1alpha1_endpoint_slice_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


