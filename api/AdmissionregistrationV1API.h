#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_mutating_webhook_configuration.h"
#include "../model/v1_mutating_webhook_configuration_list.h"
#include "../model/v1_status.h"
#include "../model/v1_validating_webhook_configuration.h"
#include "../model/v1_validating_webhook_configuration_list.h"


// create a MutatingWebhookConfiguration
//
v1_mutating_webhook_configuration_t*
AdmissionregistrationV1API_createAdmissionregistrationV1MutatingWebhookConfiguration(apiClient_t *apiClient ,v1_mutating_webhook_configuration_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ValidatingWebhookConfiguration
//
v1_validating_webhook_configuration_t*
AdmissionregistrationV1API_createAdmissionregistrationV1ValidatingWebhookConfiguration(apiClient_t *apiClient ,v1_validating_webhook_configuration_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of MutatingWebhookConfiguration
//
v1_status_t*
AdmissionregistrationV1API_deleteAdmissionregistrationV1CollectionMutatingWebhookConfiguration(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ValidatingWebhookConfiguration
//
v1_status_t*
AdmissionregistrationV1API_deleteAdmissionregistrationV1CollectionValidatingWebhookConfiguration(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a MutatingWebhookConfiguration
//
v1_status_t*
AdmissionregistrationV1API_deleteAdmissionregistrationV1MutatingWebhookConfiguration(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ValidatingWebhookConfiguration
//
v1_status_t*
AdmissionregistrationV1API_deleteAdmissionregistrationV1ValidatingWebhookConfiguration(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
AdmissionregistrationV1API_getAdmissionregistrationV1APIResources(apiClient_t *apiClient);


// list or watch objects of kind MutatingWebhookConfiguration
//
v1_mutating_webhook_configuration_list_t*
AdmissionregistrationV1API_listAdmissionregistrationV1MutatingWebhookConfiguration(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ValidatingWebhookConfiguration
//
v1_validating_webhook_configuration_list_t*
AdmissionregistrationV1API_listAdmissionregistrationV1ValidatingWebhookConfiguration(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified MutatingWebhookConfiguration
//
v1_mutating_webhook_configuration_t*
AdmissionregistrationV1API_patchAdmissionregistrationV1MutatingWebhookConfiguration(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ValidatingWebhookConfiguration
//
v1_validating_webhook_configuration_t*
AdmissionregistrationV1API_patchAdmissionregistrationV1ValidatingWebhookConfiguration(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified MutatingWebhookConfiguration
//
v1_mutating_webhook_configuration_t*
AdmissionregistrationV1API_readAdmissionregistrationV1MutatingWebhookConfiguration(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read the specified ValidatingWebhookConfiguration
//
v1_validating_webhook_configuration_t*
AdmissionregistrationV1API_readAdmissionregistrationV1ValidatingWebhookConfiguration(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// replace the specified MutatingWebhookConfiguration
//
v1_mutating_webhook_configuration_t*
AdmissionregistrationV1API_replaceAdmissionregistrationV1MutatingWebhookConfiguration(apiClient_t *apiClient ,char * name ,v1_mutating_webhook_configuration_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ValidatingWebhookConfiguration
//
v1_validating_webhook_configuration_t*
AdmissionregistrationV1API_replaceAdmissionregistrationV1ValidatingWebhookConfiguration(apiClient_t *apiClient ,char * name ,v1_validating_webhook_configuration_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


