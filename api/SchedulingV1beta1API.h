#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_priority_class.h"
#include "../model/v1beta1_priority_class_list.h"


// create a PriorityClass
//
v1beta1_priority_class_t*
SchedulingV1beta1API_createSchedulingV1beta1PriorityClass(apiClient_t *apiClient ,v1beta1_priority_class_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of PriorityClass
//
v1_status_t*
SchedulingV1beta1API_deleteSchedulingV1beta1CollectionPriorityClass(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a PriorityClass
//
v1_status_t*
SchedulingV1beta1API_deleteSchedulingV1beta1PriorityClass(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
SchedulingV1beta1API_getSchedulingV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind PriorityClass
//
v1beta1_priority_class_list_t*
SchedulingV1beta1API_listSchedulingV1beta1PriorityClass(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified PriorityClass
//
v1beta1_priority_class_t*
SchedulingV1beta1API_patchSchedulingV1beta1PriorityClass(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified PriorityClass
//
v1beta1_priority_class_t*
SchedulingV1beta1API_readSchedulingV1beta1PriorityClass(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// replace the specified PriorityClass
//
v1beta1_priority_class_t*
SchedulingV1beta1API_replaceSchedulingV1beta1PriorityClass(apiClient_t *apiClient ,char * name ,v1beta1_priority_class_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


