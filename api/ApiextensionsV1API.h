#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_custom_resource_definition.h"
#include "../model/v1_custom_resource_definition_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"


// create a CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_createApiextensionsV1CustomResourceDefinition(apiClient_t *apiClient ,v1_custom_resource_definition_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of CustomResourceDefinition
//
v1_status_t*
ApiextensionsV1API_deleteApiextensionsV1CollectionCustomResourceDefinition(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a CustomResourceDefinition
//
v1_status_t*
ApiextensionsV1API_deleteApiextensionsV1CustomResourceDefinition(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
ApiextensionsV1API_getApiextensionsV1APIResources(apiClient_t *apiClient);


// list or watch objects of kind CustomResourceDefinition
//
v1_custom_resource_definition_list_t*
ApiextensionsV1API_listApiextensionsV1CustomResourceDefinition(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_patchApiextensionsV1CustomResourceDefinition(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_patchApiextensionsV1CustomResourceDefinitionStatus(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_readApiextensionsV1CustomResourceDefinition(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read status of the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_readApiextensionsV1CustomResourceDefinitionStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// replace the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_replaceApiextensionsV1CustomResourceDefinition(apiClient_t *apiClient ,char * name ,v1_custom_resource_definition_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_replaceApiextensionsV1CustomResourceDefinitionStatus(apiClient_t *apiClient ,char * name ,v1_custom_resource_definition_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


