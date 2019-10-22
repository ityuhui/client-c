#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_api_service.h"
#include "../model/v1beta1_api_service_list.h"


// create an APIService
//
v1beta1_api_service_t*
ApiregistrationV1beta1API_createApiregistrationV1beta1APIService(apiClient_t *apiClient ,v1beta1_api_service_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete an APIService
//
v1_status_t*
ApiregistrationV1beta1API_deleteApiregistrationV1beta1APIService(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete collection of APIService
//
v1_status_t*
ApiregistrationV1beta1API_deleteApiregistrationV1beta1CollectionAPIService(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
ApiregistrationV1beta1API_getApiregistrationV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind APIService
//
v1beta1_api_service_list_t*
ApiregistrationV1beta1API_listApiregistrationV1beta1APIService(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified APIService
//
v1beta1_api_service_t*
ApiregistrationV1beta1API_patchApiregistrationV1beta1APIService(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified APIService
//
v1beta1_api_service_t*
ApiregistrationV1beta1API_patchApiregistrationV1beta1APIServiceStatus(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified APIService
//
v1beta1_api_service_t*
ApiregistrationV1beta1API_readApiregistrationV1beta1APIService(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read status of the specified APIService
//
v1beta1_api_service_t*
ApiregistrationV1beta1API_readApiregistrationV1beta1APIServiceStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// replace the specified APIService
//
v1beta1_api_service_t*
ApiregistrationV1beta1API_replaceApiregistrationV1beta1APIService(apiClient_t *apiClient ,char * name ,v1beta1_api_service_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified APIService
//
v1beta1_api_service_t*
ApiregistrationV1beta1API_replaceApiregistrationV1beta1APIServiceStatus(apiClient_t *apiClient ,char * name ,v1beta1_api_service_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


