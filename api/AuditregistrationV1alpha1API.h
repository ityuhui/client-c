#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1alpha1_audit_sink.h"
#include "../model/v1alpha1_audit_sink_list.h"


// create an AuditSink
//
v1alpha1_audit_sink_t*
AuditregistrationV1alpha1API_createAuditregistrationV1alpha1AuditSink(apiClient_t *apiClient ,v1alpha1_audit_sink_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete an AuditSink
//
v1_status_t*
AuditregistrationV1alpha1API_deleteAuditregistrationV1alpha1AuditSink(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete collection of AuditSink
//
v1_status_t*
AuditregistrationV1alpha1API_deleteAuditregistrationV1alpha1CollectionAuditSink(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
AuditregistrationV1alpha1API_getAuditregistrationV1alpha1APIResources(apiClient_t *apiClient);


// list or watch objects of kind AuditSink
//
v1alpha1_audit_sink_list_t*
AuditregistrationV1alpha1API_listAuditregistrationV1alpha1AuditSink(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified AuditSink
//
v1alpha1_audit_sink_t*
AuditregistrationV1alpha1API_patchAuditregistrationV1alpha1AuditSink(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified AuditSink
//
v1alpha1_audit_sink_t*
AuditregistrationV1alpha1API_readAuditregistrationV1alpha1AuditSink(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// replace the specified AuditSink
//
v1alpha1_audit_sink_t*
AuditregistrationV1alpha1API_replaceAuditregistrationV1alpha1AuditSink(apiClient_t *apiClient ,char * name ,v1alpha1_audit_sink_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


