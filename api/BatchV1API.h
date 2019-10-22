#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_job.h"
#include "../model/v1_job_list.h"
#include "../model/v1_status.h"


// create a Job
//
v1_job_t*
BatchV1API_createBatchV1NamespacedJob(apiClient_t *apiClient ,char * namespace ,v1_job_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of Job
//
v1_status_t*
BatchV1API_deleteBatchV1CollectionNamespacedJob(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a Job
//
v1_status_t*
BatchV1API_deleteBatchV1NamespacedJob(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
BatchV1API_getBatchV1APIResources(apiClient_t *apiClient);


// list or watch objects of kind Job
//
v1_job_list_t*
BatchV1API_listBatchV1JobForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Job
//
v1_job_list_t*
BatchV1API_listBatchV1NamespacedJob(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified Job
//
v1_job_t*
BatchV1API_patchBatchV1NamespacedJob(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Job
//
v1_job_t*
BatchV1API_patchBatchV1NamespacedJobStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified Job
//
v1_job_t*
BatchV1API_readBatchV1NamespacedJob(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified Job
//
v1_job_t*
BatchV1API_readBatchV1NamespacedJobStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified Job
//
v1_job_t*
BatchV1API_replaceBatchV1NamespacedJob(apiClient_t *apiClient ,char * name ,char * namespace ,v1_job_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Job
//
v1_job_t*
BatchV1API_replaceBatchV1NamespacedJobStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_job_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


