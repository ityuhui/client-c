#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta2_controller_revision.h"
#include "../model/v1beta2_controller_revision_list.h"
#include "../model/v1beta2_daemon_set.h"
#include "../model/v1beta2_daemon_set_list.h"
#include "../model/v1beta2_deployment.h"
#include "../model/v1beta2_deployment_list.h"
#include "../model/v1beta2_replica_set.h"
#include "../model/v1beta2_replica_set_list.h"
#include "../model/v1beta2_scale.h"
#include "../model/v1beta2_stateful_set.h"
#include "../model/v1beta2_stateful_set_list.h"


// create a ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_createAppsV1beta2NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,v1beta2_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_createAppsV1beta2NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,v1beta2_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_createAppsV1beta2NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,v1beta2_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_createAppsV1beta2NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,v1beta2_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_createAppsV1beta2NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,v1beta2_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of ControllerRevision
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2CollectionNamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of DaemonSet
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2CollectionNamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Deployment
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2CollectionNamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ReplicaSet
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2CollectionNamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of StatefulSet
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2CollectionNamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a ControllerRevision
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a DaemonSet
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Deployment
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ReplicaSet
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a StatefulSet
//
v1_status_t*
AppsV1beta2API_deleteAppsV1beta2NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
AppsV1beta2API_getAppsV1beta2APIResources(apiClient_t *apiClient);


// list or watch objects of kind ControllerRevision
//
v1beta2_controller_revision_list_t*
AppsV1beta2API_listAppsV1beta2ControllerRevisionForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind DaemonSet
//
v1beta2_daemon_set_list_t*
AppsV1beta2API_listAppsV1beta2DaemonSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
v1beta2_deployment_list_t*
AppsV1beta2API_listAppsV1beta2DeploymentForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ControllerRevision
//
v1beta2_controller_revision_list_t*
AppsV1beta2API_listAppsV1beta2NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind DaemonSet
//
v1beta2_daemon_set_list_t*
AppsV1beta2API_listAppsV1beta2NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
v1beta2_deployment_list_t*
AppsV1beta2API_listAppsV1beta2NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicaSet
//
v1beta2_replica_set_list_t*
AppsV1beta2API_listAppsV1beta2NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind StatefulSet
//
v1beta2_stateful_set_list_t*
AppsV1beta2API_listAppsV1beta2NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicaSet
//
v1beta2_replica_set_list_t*
AppsV1beta2API_listAppsV1beta2ReplicaSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind StatefulSet
//
v1beta2_stateful_set_list_t*
AppsV1beta2API_listAppsV1beta2StatefulSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_patchAppsV1beta2NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_patchAppsV1beta2NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_patchAppsV1beta2NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_patchAppsV1beta2NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified Deployment
//
v1beta2_scale_t*
AppsV1beta2API_patchAppsV1beta2NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_patchAppsV1beta2NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_patchAppsV1beta2NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified ReplicaSet
//
v1beta2_scale_t*
AppsV1beta2API_patchAppsV1beta2NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_patchAppsV1beta2NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_patchAppsV1beta2NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified StatefulSet
//
v1beta2_scale_t*
AppsV1beta2API_patchAppsV1beta2NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_patchAppsV1beta2NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_readAppsV1beta2NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_readAppsV1beta2NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_readAppsV1beta2NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_readAppsV1beta2NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified Deployment
//
v1beta2_scale_t*
AppsV1beta2API_readAppsV1beta2NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_readAppsV1beta2NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_readAppsV1beta2NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified ReplicaSet
//
v1beta2_scale_t*
AppsV1beta2API_readAppsV1beta2NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_readAppsV1beta2NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_readAppsV1beta2NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified StatefulSet
//
v1beta2_scale_t*
AppsV1beta2API_readAppsV1beta2NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_readAppsV1beta2NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified Deployment
//
v1beta2_scale_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified ReplicaSet
//
v1beta2_scale_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified StatefulSet
//
v1beta2_scale_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_replaceAppsV1beta2NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta2_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


