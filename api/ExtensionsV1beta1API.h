#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/extensions_v1beta1_deployment.h"
#include "../model/extensions_v1beta1_deployment_list.h"
#include "../model/extensions_v1beta1_deployment_rollback.h"
#include "../model/extensions_v1beta1_ingress.h"
#include "../model/extensions_v1beta1_ingress_list.h"
#include "../model/extensions_v1beta1_pod_security_policy.h"
#include "../model/extensions_v1beta1_pod_security_policy_list.h"
#include "../model/extensions_v1beta1_scale.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_daemon_set.h"
#include "../model/v1beta1_daemon_set_list.h"
#include "../model/v1beta1_network_policy.h"
#include "../model/v1beta1_network_policy_list.h"
#include "../model/v1beta1_replica_set.h"
#include "../model/v1beta1_replica_set_list.h"


// create a DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_createExtensionsV1beta1NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,v1beta1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_createExtensionsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,extensions_v1beta1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create rollback of a Deployment
//
v1_status_t*
ExtensionsV1beta1API_createExtensionsV1beta1NamespacedDeploymentRollback(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_deployment_rollback_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create an Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_createExtensionsV1beta1NamespacedIngress(apiClient_t *apiClient ,char * namespace ,extensions_v1beta1_ingress_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_createExtensionsV1beta1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * namespace ,v1beta1_network_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_createExtensionsV1beta1NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,v1beta1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_createExtensionsV1beta1PodSecurityPolicy(apiClient_t *apiClient ,extensions_v1beta1_pod_security_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of DaemonSet
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1CollectionNamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Deployment
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1CollectionNamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Ingress
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1CollectionNamespacedIngress(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of NetworkPolicy
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1CollectionNamespacedNetworkPolicy(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ReplicaSet
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1CollectionNamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of PodSecurityPolicy
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1CollectionPodSecurityPolicy(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a DaemonSet
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Deployment
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete an Ingress
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1NamespacedIngress(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a NetworkPolicy
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ReplicaSet
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a PodSecurityPolicy
//
v1_status_t*
ExtensionsV1beta1API_deleteExtensionsV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
ExtensionsV1beta1API_getExtensionsV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind DaemonSet
//
v1beta1_daemon_set_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1DaemonSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
extensions_v1beta1_deployment_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1DeploymentForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Ingress
//
extensions_v1beta1_ingress_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1IngressForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind DaemonSet
//
v1beta1_daemon_set_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Deployment
//
extensions_v1beta1_deployment_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Ingress
//
extensions_v1beta1_ingress_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1NamespacedIngress(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind NetworkPolicy
//
v1beta1_network_policy_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicaSet
//
v1beta1_replica_set_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind NetworkPolicy
//
v1beta1_network_policy_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1NetworkPolicyForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicaSet
//
v1beta1_replica_set_list_t*
ExtensionsV1beta1API_listExtensionsV1beta1ReplicaSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified Deployment
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedIngress(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedIngressStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified ReplicaSet
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified ReplicationControllerDummy
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_patchExtensionsV1beta1NamespacedReplicationControllerDummyScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_patchExtensionsV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified Deployment
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedIngress(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedIngressStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified ReplicaSet
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read scale of the specified ReplicationControllerDummy
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_readExtensionsV1beta1NamespacedReplicationControllerDummyScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_readExtensionsV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// replace the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified Deployment
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedIngress(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_ingress_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedIngressStatus(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_ingress_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedNetworkPolicy(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_network_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified ReplicaSet
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified ReplicationControllerDummy
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1NamespacedReplicationControllerDummyScale(apiClient_t *apiClient ,char * name ,char * namespace ,extensions_v1beta1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_replaceExtensionsV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name ,extensions_v1beta1_pod_security_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


