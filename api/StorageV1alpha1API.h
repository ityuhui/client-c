#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1alpha1_volume_attachment.h"
#include "../model/v1alpha1_volume_attachment_list.h"


// create a VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_createStorageV1alpha1VolumeAttachment(apiClient_t *apiClient ,v1alpha1_volume_attachment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of VolumeAttachment
//
v1_status_t*
StorageV1alpha1API_deleteStorageV1alpha1CollectionVolumeAttachment(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a VolumeAttachment
//
v1_status_t*
StorageV1alpha1API_deleteStorageV1alpha1VolumeAttachment(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
StorageV1alpha1API_getStorageV1alpha1APIResources(apiClient_t *apiClient);


// list or watch objects of kind VolumeAttachment
//
v1alpha1_volume_attachment_list_t*
StorageV1alpha1API_listStorageV1alpha1VolumeAttachment(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_patchStorageV1alpha1VolumeAttachment(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_readStorageV1alpha1VolumeAttachment(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// replace the specified VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_replaceStorageV1alpha1VolumeAttachment(apiClient_t *apiClient ,char * name ,v1alpha1_volume_attachment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


