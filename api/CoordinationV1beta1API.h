#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_lease.h"
#include "../model/v1beta1_lease_list.h"


// create a Lease
//
v1beta1_lease_t*
CoordinationV1beta1API_createCoordinationV1beta1NamespacedLease(apiClient_t *apiClient ,char * namespace ,v1beta1_lease_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of Lease
//
v1_status_t*
CoordinationV1beta1API_deleteCoordinationV1beta1CollectionNamespacedLease(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a Lease
//
v1_status_t*
CoordinationV1beta1API_deleteCoordinationV1beta1NamespacedLease(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
CoordinationV1beta1API_getCoordinationV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind Lease
//
v1beta1_lease_list_t*
CoordinationV1beta1API_listCoordinationV1beta1LeaseForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Lease
//
v1beta1_lease_list_t*
CoordinationV1beta1API_listCoordinationV1beta1NamespacedLease(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified Lease
//
v1beta1_lease_t*
CoordinationV1beta1API_patchCoordinationV1beta1NamespacedLease(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified Lease
//
v1beta1_lease_t*
CoordinationV1beta1API_readCoordinationV1beta1NamespacedLease(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// replace the specified Lease
//
v1beta1_lease_t*
CoordinationV1beta1API_replaceCoordinationV1beta1NamespacedLease(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_lease_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


