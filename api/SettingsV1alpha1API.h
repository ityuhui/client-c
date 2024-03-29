#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1alpha1_pod_preset.h"
#include "../model/v1alpha1_pod_preset_list.h"


// create a PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_createSettingsV1alpha1NamespacedPodPreset(apiClient_t *apiClient ,char * namespace ,v1alpha1_pod_preset_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of PodPreset
//
v1_status_t*
SettingsV1alpha1API_deleteSettingsV1alpha1CollectionNamespacedPodPreset(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a PodPreset
//
v1_status_t*
SettingsV1alpha1API_deleteSettingsV1alpha1NamespacedPodPreset(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
SettingsV1alpha1API_getSettingsV1alpha1APIResources(apiClient_t *apiClient);


// list or watch objects of kind PodPreset
//
v1alpha1_pod_preset_list_t*
SettingsV1alpha1API_listSettingsV1alpha1NamespacedPodPreset(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PodPreset
//
v1alpha1_pod_preset_list_t*
SettingsV1alpha1API_listSettingsV1alpha1PodPresetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_patchSettingsV1alpha1NamespacedPodPreset(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_readSettingsV1alpha1NamespacedPodPreset(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// replace the specified PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_replaceSettingsV1alpha1NamespacedPodPreset(apiClient_t *apiClient ,char * name ,char * namespace ,v1alpha1_pod_preset_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


