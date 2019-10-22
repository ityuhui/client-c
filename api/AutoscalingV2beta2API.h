#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v2beta2_horizontal_pod_autoscaler.h"
#include "../model/v2beta2_horizontal_pod_autoscaler_list.h"


// create a HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_t*
AutoscalingV2beta2API_createAutoscalingV2beta2NamespacedHorizontalPodAutoscaler(apiClient_t *apiClient ,char * namespace ,v2beta2_horizontal_pod_autoscaler_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of HorizontalPodAutoscaler
//
v1_status_t*
AutoscalingV2beta2API_deleteAutoscalingV2beta2CollectionNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a HorizontalPodAutoscaler
//
v1_status_t*
AutoscalingV2beta2API_deleteAutoscalingV2beta2NamespacedHorizontalPodAutoscaler(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
AutoscalingV2beta2API_getAutoscalingV2beta2APIResources(apiClient_t *apiClient);


// list or watch objects of kind HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_list_t*
AutoscalingV2beta2API_listAutoscalingV2beta2HorizontalPodAutoscalerForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_list_t*
AutoscalingV2beta2API_listAutoscalingV2beta2NamespacedHorizontalPodAutoscaler(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_t*
AutoscalingV2beta2API_patchAutoscalingV2beta2NamespacedHorizontalPodAutoscaler(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_t*
AutoscalingV2beta2API_patchAutoscalingV2beta2NamespacedHorizontalPodAutoscalerStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_t*
AutoscalingV2beta2API_readAutoscalingV2beta2NamespacedHorizontalPodAutoscaler(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_t*
AutoscalingV2beta2API_readAutoscalingV2beta2NamespacedHorizontalPodAutoscalerStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_t*
AutoscalingV2beta2API_replaceAutoscalingV2beta2NamespacedHorizontalPodAutoscaler(apiClient_t *apiClient ,char * name ,char * namespace ,v2beta2_horizontal_pod_autoscaler_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified HorizontalPodAutoscaler
//
v2beta2_horizontal_pod_autoscaler_t*
AutoscalingV2beta2API_replaceAutoscalingV2beta2NamespacedHorizontalPodAutoscalerStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v2beta2_horizontal_pod_autoscaler_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


