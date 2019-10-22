#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/apps_v1beta1_deployment.h"
#include "../model/apps_v1beta1_deployment_list.h"
#include "../model/apps_v1beta1_deployment_rollback.h"
#include "../model/apps_v1beta1_scale.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_controller_revision.h"
#include "../model/v1beta1_controller_revision_list.h"
#include "../model/v1beta1_stateful_set.h"
#include "../model/v1beta1_stateful_set_list.h"


// create a ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_createAppsV1beta1NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,v1beta1_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_createAppsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,apps_v1beta1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create rollback of a Deployment
//
v1_status_t*
AppsV1beta1API_createAppsV1beta1NamespacedDeploymentRollback(apiClient_t *apiClient ,char * name ,char * namespace ,apps_v1beta1_deployment_rollback_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create a StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_createAppsV1beta1NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,v1beta1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of ControllerRevision
//
v1_status_t*
AppsV1beta1API_deleteAppsV1beta1CollectionNamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Deployment
//
v1_status_t*
AppsV1beta1API_deleteAppsV1beta1CollectionNamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of StatefulSet
//
v1_status_t*
AppsV1beta1API_deleteAppsV1beta1CollectionNamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a ControllerRevision
//
v1_status_t*
AppsV1beta1API_deleteAppsV1beta1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Deployment
//
v1_status_t*
AppsV1beta1API_deleteAppsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a StatefulSet
//
v1_status_t*
AppsV1beta1API_deleteAppsV1beta1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
AppsV1beta1API_getAppsV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind ControllerRevision
//
v1beta1_controller_revision_list_t*
AppsV1beta1API_listAppsV1beta1ControllerRevisionForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
apps_v1beta1_deployment_list_t*
AppsV1beta1API_listAppsV1beta1DeploymentForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ControllerRevision
//
v1beta1_controller_revision_list_t*
AppsV1beta1API_listAppsV1beta1NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
apps_v1beta1_deployment_list_t*
AppsV1beta1API_listAppsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind StatefulSet
//
v1beta1_stateful_set_list_t*
AppsV1beta1API_listAppsV1beta1NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind StatefulSet
//
v1beta1_stateful_set_list_t*
AppsV1beta1API_listAppsV1beta1StatefulSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_patchAppsV1beta1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_patchAppsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified Deployment
//
apps_v1beta1_scale_t*
AppsV1beta1API_patchAppsV1beta1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_patchAppsV1beta1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_patchAppsV1beta1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified StatefulSet
//
apps_v1beta1_scale_t*
AppsV1beta1API_patchAppsV1beta1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_patchAppsV1beta1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_readAppsV1beta1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_readAppsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified Deployment
//
apps_v1beta1_scale_t*
AppsV1beta1API_readAppsV1beta1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_readAppsV1beta1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_readAppsV1beta1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified StatefulSet
//
apps_v1beta1_scale_t*
AppsV1beta1API_readAppsV1beta1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_readAppsV1beta1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_replaceAppsV1beta1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_replaceAppsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,apps_v1beta1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified Deployment
//
apps_v1beta1_scale_t*
AppsV1beta1API_replaceAppsV1beta1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,apps_v1beta1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_replaceAppsV1beta1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,apps_v1beta1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_replaceAppsV1beta1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified StatefulSet
//
apps_v1beta1_scale_t*
AppsV1beta1API_replaceAppsV1beta1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,apps_v1beta1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_replaceAppsV1beta1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


