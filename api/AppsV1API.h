#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_controller_revision.h"
#include "../model/v1_controller_revision_list.h"
#include "../model/v1_daemon_set.h"
#include "../model/v1_daemon_set_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_deployment.h"
#include "../model/v1_deployment_list.h"
#include "../model/v1_replica_set.h"
#include "../model/v1_replica_set_list.h"
#include "../model/v1_scale.h"
#include "../model/v1_stateful_set.h"
#include "../model/v1_stateful_set_list.h"
#include "../model/v1_status.h"


// create a ControllerRevision
//
v1_controller_revision_t*
AppsV1API_createAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,v1_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a DaemonSet
//
v1_daemon_set_t*
AppsV1API_createAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,v1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Deployment
//
v1_deployment_t*
AppsV1API_createAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,v1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ReplicaSet
//
v1_replica_set_t*
AppsV1API_createAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,v1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a StatefulSet
//
v1_stateful_set_t*
AppsV1API_createAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,v1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of ControllerRevision
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of DaemonSet
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Deployment
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ReplicaSet
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of StatefulSet
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a ControllerRevision
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a DaemonSet
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Deployment
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ReplicaSet
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a StatefulSet
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
AppsV1API_getAppsV1APIResources(apiClient_t *apiClient);


// list or watch objects of kind ControllerRevision
//
v1_controller_revision_list_t*
AppsV1API_listAppsV1ControllerRevisionForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind DaemonSet
//
v1_daemon_set_list_t*
AppsV1API_listAppsV1DaemonSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
v1_deployment_list_t*
AppsV1API_listAppsV1DeploymentForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ControllerRevision
//
v1_controller_revision_list_t*
AppsV1API_listAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind DaemonSet
//
v1_daemon_set_list_t*
AppsV1API_listAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
v1_deployment_list_t*
AppsV1API_listAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicaSet
//
v1_replica_set_list_t*
AppsV1API_listAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind StatefulSet
//
v1_stateful_set_list_t*
AppsV1API_listAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicaSet
//
v1_replica_set_list_t*
AppsV1API_listAppsV1ReplicaSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind StatefulSet
//
v1_stateful_set_list_t*
AppsV1API_listAppsV1StatefulSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_patchAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_patchAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_patchAppsV1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Deployment
//
v1_deployment_t*
AppsV1API_patchAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified Deployment
//
v1_scale_t*
AppsV1API_patchAppsV1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Deployment
//
v1_deployment_t*
AppsV1API_patchAppsV1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_patchAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_patchAppsV1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_patchAppsV1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_patchAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_patchAppsV1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_patchAppsV1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_readAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_readAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_readAppsV1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified Deployment
//
v1_deployment_t*
AppsV1API_readAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified Deployment
//
v1_scale_t*
AppsV1API_readAppsV1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified Deployment
//
v1_deployment_t*
AppsV1API_readAppsV1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_readAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_readAppsV1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_readAppsV1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_readAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_readAppsV1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_readAppsV1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_replaceAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,v1_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_replaceAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_replaceAppsV1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Deployment
//
v1_deployment_t*
AppsV1API_replaceAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,v1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified Deployment
//
v1_scale_t*
AppsV1API_replaceAppsV1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Deployment
//
v1_deployment_t*
AppsV1API_replaceAppsV1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_replaceAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_replaceAppsV1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_replaceAppsV1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_replaceAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_replaceAppsV1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_replaceAppsV1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


