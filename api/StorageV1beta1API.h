#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_csi_driver.h"
#include "../model/v1beta1_csi_driver_list.h"
#include "../model/v1beta1_csi_node.h"
#include "../model/v1beta1_csi_node_list.h"
#include "../model/v1beta1_storage_class.h"
#include "../model/v1beta1_storage_class_list.h"
#include "../model/v1beta1_volume_attachment.h"
#include "../model/v1beta1_volume_attachment_list.h"


// create a CSIDriver
//
v1beta1_csi_driver_t*
StorageV1beta1API_createStorageV1beta1CSIDriver(apiClient_t *apiClient ,v1beta1_csi_driver_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a CSINode
//
v1beta1_csi_node_t*
StorageV1beta1API_createStorageV1beta1CSINode(apiClient_t *apiClient ,v1beta1_csi_node_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a StorageClass
//
v1beta1_storage_class_t*
StorageV1beta1API_createStorageV1beta1StorageClass(apiClient_t *apiClient ,v1beta1_storage_class_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a VolumeAttachment
//
v1beta1_volume_attachment_t*
StorageV1beta1API_createStorageV1beta1VolumeAttachment(apiClient_t *apiClient ,v1beta1_volume_attachment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete a CSIDriver
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1CSIDriver(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a CSINode
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1CSINode(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete collection of CSIDriver
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1CollectionCSIDriver(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of CSINode
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1CollectionCSINode(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of StorageClass
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1CollectionStorageClass(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of VolumeAttachment
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1CollectionVolumeAttachment(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a StorageClass
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1StorageClass(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a VolumeAttachment
//
v1_status_t*
StorageV1beta1API_deleteStorageV1beta1VolumeAttachment(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
StorageV1beta1API_getStorageV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind CSIDriver
//
v1beta1_csi_driver_list_t*
StorageV1beta1API_listStorageV1beta1CSIDriver(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind CSINode
//
v1beta1_csi_node_list_t*
StorageV1beta1API_listStorageV1beta1CSINode(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind StorageClass
//
v1beta1_storage_class_list_t*
StorageV1beta1API_listStorageV1beta1StorageClass(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind VolumeAttachment
//
v1beta1_volume_attachment_list_t*
StorageV1beta1API_listStorageV1beta1VolumeAttachment(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified CSIDriver
//
v1beta1_csi_driver_t*
StorageV1beta1API_patchStorageV1beta1CSIDriver(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified CSINode
//
v1beta1_csi_node_t*
StorageV1beta1API_patchStorageV1beta1CSINode(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified StorageClass
//
v1beta1_storage_class_t*
StorageV1beta1API_patchStorageV1beta1StorageClass(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified VolumeAttachment
//
v1beta1_volume_attachment_t*
StorageV1beta1API_patchStorageV1beta1VolumeAttachment(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified CSIDriver
//
v1beta1_csi_driver_t*
StorageV1beta1API_readStorageV1beta1CSIDriver(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read the specified CSINode
//
v1beta1_csi_node_t*
StorageV1beta1API_readStorageV1beta1CSINode(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read the specified StorageClass
//
v1beta1_storage_class_t*
StorageV1beta1API_readStorageV1beta1StorageClass(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read the specified VolumeAttachment
//
v1beta1_volume_attachment_t*
StorageV1beta1API_readStorageV1beta1VolumeAttachment(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// replace the specified CSIDriver
//
v1beta1_csi_driver_t*
StorageV1beta1API_replaceStorageV1beta1CSIDriver(apiClient_t *apiClient ,char * name ,v1beta1_csi_driver_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified CSINode
//
v1beta1_csi_node_t*
StorageV1beta1API_replaceStorageV1beta1CSINode(apiClient_t *apiClient ,char * name ,v1beta1_csi_node_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified StorageClass
//
v1beta1_storage_class_t*
StorageV1beta1API_replaceStorageV1beta1StorageClass(apiClient_t *apiClient ,char * name ,v1beta1_storage_class_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified VolumeAttachment
//
v1beta1_volume_attachment_t*
StorageV1beta1API_replaceStorageV1beta1VolumeAttachment(apiClient_t *apiClient ,char * name ,v1beta1_volume_attachment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


