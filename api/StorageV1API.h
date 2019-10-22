#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1_storage_class.h"
#include "../model/v1_storage_class_list.h"
#include "../model/v1_volume_attachment.h"
#include "../model/v1_volume_attachment_list.h"


// create a StorageClass
//
v1_storage_class_t*
StorageV1API_createStorageV1StorageClass(apiClient_t *apiClient ,v1_storage_class_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_createStorageV1VolumeAttachment(apiClient_t *apiClient ,v1_volume_attachment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of StorageClass
//
v1_status_t*
StorageV1API_deleteStorageV1CollectionStorageClass(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of VolumeAttachment
//
v1_status_t*
StorageV1API_deleteStorageV1CollectionVolumeAttachment(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a StorageClass
//
v1_status_t*
StorageV1API_deleteStorageV1StorageClass(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a VolumeAttachment
//
v1_status_t*
StorageV1API_deleteStorageV1VolumeAttachment(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
StorageV1API_getStorageV1APIResources(apiClient_t *apiClient);


// list or watch objects of kind StorageClass
//
v1_storage_class_list_t*
StorageV1API_listStorageV1StorageClass(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind VolumeAttachment
//
v1_volume_attachment_list_t*
StorageV1API_listStorageV1VolumeAttachment(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified StorageClass
//
v1_storage_class_t*
StorageV1API_patchStorageV1StorageClass(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_patchStorageV1VolumeAttachment(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_patchStorageV1VolumeAttachmentStatus(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified StorageClass
//
v1_storage_class_t*
StorageV1API_readStorageV1StorageClass(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_readStorageV1VolumeAttachment(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_readStorageV1VolumeAttachmentStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// replace the specified StorageClass
//
v1_storage_class_t*
StorageV1API_replaceStorageV1StorageClass(apiClient_t *apiClient ,char * name ,v1_storage_class_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_replaceStorageV1VolumeAttachment(apiClient_t *apiClient ,char * name ,v1_volume_attachment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_replaceStorageV1VolumeAttachmentStatus(apiClient_t *apiClient ,char * name ,v1_volume_attachment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


