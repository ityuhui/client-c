#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_binding.h"
#include "../model/v1_component_status.h"
#include "../model/v1_component_status_list.h"
#include "../model/v1_config_map.h"
#include "../model/v1_config_map_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_endpoints.h"
#include "../model/v1_endpoints_list.h"
#include "../model/v1_event.h"
#include "../model/v1_event_list.h"
#include "../model/v1_limit_range.h"
#include "../model/v1_limit_range_list.h"
#include "../model/v1_namespace.h"
#include "../model/v1_namespace_list.h"
#include "../model/v1_node.h"
#include "../model/v1_node_list.h"
#include "../model/v1_persistent_volume.h"
#include "../model/v1_persistent_volume_claim.h"
#include "../model/v1_persistent_volume_claim_list.h"
#include "../model/v1_persistent_volume_list.h"
#include "../model/v1_pod.h"
#include "../model/v1_pod_list.h"
#include "../model/v1_pod_template.h"
#include "../model/v1_pod_template_list.h"
#include "../model/v1_replication_controller.h"
#include "../model/v1_replication_controller_list.h"
#include "../model/v1_resource_quota.h"
#include "../model/v1_resource_quota_list.h"
#include "../model/v1_scale.h"
#include "../model/v1_secret.h"
#include "../model/v1_secret_list.h"
#include "../model/v1_service.h"
#include "../model/v1_service_account.h"
#include "../model/v1_service_account_list.h"
#include "../model/v1_service_list.h"
#include "../model/v1_status.h"
#include "../model/v1_token_request.h"
#include "../model/v1beta1_eviction.h"


// connect DELETE requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1DeleteNamespacedPodProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect DELETE requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1DeleteNamespacedPodProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect DELETE requests to proxy of Service
//
char*
CoreV1API_connectCoreV1DeleteNamespacedServiceProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect DELETE requests to proxy of Service
//
char*
CoreV1API_connectCoreV1DeleteNamespacedServiceProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect DELETE requests to proxy of Node
//
char*
CoreV1API_connectCoreV1DeleteNodeProxy(apiClient_t *apiClient ,char * name ,char * path);


// connect DELETE requests to proxy of Node
//
char*
CoreV1API_connectCoreV1DeleteNodeProxyWithPath(apiClient_t *apiClient ,char * name ,char * path ,char * path2);


// connect GET requests to attach of Pod
//
char*
CoreV1API_connectCoreV1GetNamespacedPodAttach(apiClient_t *apiClient ,char * name ,char * namespace ,char * container ,int stderr ,int stdin ,int stdout ,int tty);


// connect GET requests to exec of Pod
//
char*
CoreV1API_connectCoreV1GetNamespacedPodExec(apiClient_t *apiClient ,char * name ,char * namespace ,char * command ,char * container ,int stderr ,int stdin ,int stdout ,int tty);


// connect GET requests to portforward of Pod
//
char*
CoreV1API_connectCoreV1GetNamespacedPodPortforward(apiClient_t *apiClient ,char * name ,char * namespace ,int ports);


// connect GET requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1GetNamespacedPodProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect GET requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1GetNamespacedPodProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect GET requests to proxy of Service
//
char*
CoreV1API_connectCoreV1GetNamespacedServiceProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect GET requests to proxy of Service
//
char*
CoreV1API_connectCoreV1GetNamespacedServiceProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect GET requests to proxy of Node
//
char*
CoreV1API_connectCoreV1GetNodeProxy(apiClient_t *apiClient ,char * name ,char * path);


// connect GET requests to proxy of Node
//
char*
CoreV1API_connectCoreV1GetNodeProxyWithPath(apiClient_t *apiClient ,char * name ,char * path ,char * path2);


// connect HEAD requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1HeadNamespacedPodProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect HEAD requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1HeadNamespacedPodProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect HEAD requests to proxy of Service
//
char*
CoreV1API_connectCoreV1HeadNamespacedServiceProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect HEAD requests to proxy of Service
//
char*
CoreV1API_connectCoreV1HeadNamespacedServiceProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect HEAD requests to proxy of Node
//
char*
CoreV1API_connectCoreV1HeadNodeProxy(apiClient_t *apiClient ,char * name ,char * path);


// connect HEAD requests to proxy of Node
//
char*
CoreV1API_connectCoreV1HeadNodeProxyWithPath(apiClient_t *apiClient ,char * name ,char * path ,char * path2);


// connect OPTIONS requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1OptionsNamespacedPodProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect OPTIONS requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1OptionsNamespacedPodProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect OPTIONS requests to proxy of Service
//
char*
CoreV1API_connectCoreV1OptionsNamespacedServiceProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect OPTIONS requests to proxy of Service
//
char*
CoreV1API_connectCoreV1OptionsNamespacedServiceProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect OPTIONS requests to proxy of Node
//
char*
CoreV1API_connectCoreV1OptionsNodeProxy(apiClient_t *apiClient ,char * name ,char * path);


// connect OPTIONS requests to proxy of Node
//
char*
CoreV1API_connectCoreV1OptionsNodeProxyWithPath(apiClient_t *apiClient ,char * name ,char * path ,char * path2);


// connect PATCH requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1PatchNamespacedPodProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect PATCH requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1PatchNamespacedPodProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect PATCH requests to proxy of Service
//
char*
CoreV1API_connectCoreV1PatchNamespacedServiceProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect PATCH requests to proxy of Service
//
char*
CoreV1API_connectCoreV1PatchNamespacedServiceProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect PATCH requests to proxy of Node
//
char*
CoreV1API_connectCoreV1PatchNodeProxy(apiClient_t *apiClient ,char * name ,char * path);


// connect PATCH requests to proxy of Node
//
char*
CoreV1API_connectCoreV1PatchNodeProxyWithPath(apiClient_t *apiClient ,char * name ,char * path ,char * path2);


// connect POST requests to attach of Pod
//
char*
CoreV1API_connectCoreV1PostNamespacedPodAttach(apiClient_t *apiClient ,char * name ,char * namespace ,char * container ,int stderr ,int stdin ,int stdout ,int tty);


// connect POST requests to exec of Pod
//
char*
CoreV1API_connectCoreV1PostNamespacedPodExec(apiClient_t *apiClient ,char * name ,char * namespace ,char * command ,char * container ,int stderr ,int stdin ,int stdout ,int tty);


// connect POST requests to portforward of Pod
//
char*
CoreV1API_connectCoreV1PostNamespacedPodPortforward(apiClient_t *apiClient ,char * name ,char * namespace ,int ports);


// connect POST requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1PostNamespacedPodProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect POST requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1PostNamespacedPodProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect POST requests to proxy of Service
//
char*
CoreV1API_connectCoreV1PostNamespacedServiceProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect POST requests to proxy of Service
//
char*
CoreV1API_connectCoreV1PostNamespacedServiceProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect POST requests to proxy of Node
//
char*
CoreV1API_connectCoreV1PostNodeProxy(apiClient_t *apiClient ,char * name ,char * path);


// connect POST requests to proxy of Node
//
char*
CoreV1API_connectCoreV1PostNodeProxyWithPath(apiClient_t *apiClient ,char * name ,char * path ,char * path2);


// connect PUT requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1PutNamespacedPodProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect PUT requests to proxy of Pod
//
char*
CoreV1API_connectCoreV1PutNamespacedPodProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect PUT requests to proxy of Service
//
char*
CoreV1API_connectCoreV1PutNamespacedServiceProxy(apiClient_t *apiClient ,char * name ,char * namespace ,char * path);


// connect PUT requests to proxy of Service
//
char*
CoreV1API_connectCoreV1PutNamespacedServiceProxyWithPath(apiClient_t *apiClient ,char * name ,char * namespace ,char * path ,char * path2);


// connect PUT requests to proxy of Node
//
char*
CoreV1API_connectCoreV1PutNodeProxy(apiClient_t *apiClient ,char * name ,char * path);


// connect PUT requests to proxy of Node
//
char*
CoreV1API_connectCoreV1PutNodeProxyWithPath(apiClient_t *apiClient ,char * name ,char * path ,char * path2);


// create a Namespace
//
v1_namespace_t*
CoreV1API_createCoreV1Namespace(apiClient_t *apiClient ,v1_namespace_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Binding
//
v1_binding_t*
CoreV1API_createCoreV1NamespacedBinding(apiClient_t *apiClient ,char * namespace ,v1_binding_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create a ConfigMap
//
v1_config_map_t*
CoreV1API_createCoreV1NamespacedConfigMap(apiClient_t *apiClient ,char * namespace ,v1_config_map_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create Endpoints
//
v1_endpoints_t*
CoreV1API_createCoreV1NamespacedEndpoints(apiClient_t *apiClient ,char * namespace ,v1_endpoints_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create an Event
//
v1_event_t*
CoreV1API_createCoreV1NamespacedEvent(apiClient_t *apiClient ,char * namespace ,v1_event_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a LimitRange
//
v1_limit_range_t*
CoreV1API_createCoreV1NamespacedLimitRange(apiClient_t *apiClient ,char * namespace ,v1_limit_range_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_createCoreV1NamespacedPersistentVolumeClaim(apiClient_t *apiClient ,char * namespace ,v1_persistent_volume_claim_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Pod
//
v1_pod_t*
CoreV1API_createCoreV1NamespacedPod(apiClient_t *apiClient ,char * namespace ,v1_pod_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create binding of a Pod
//
v1_binding_t*
CoreV1API_createCoreV1NamespacedPodBinding(apiClient_t *apiClient ,char * name ,char * namespace ,v1_binding_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create eviction of a Pod
//
v1beta1_eviction_t*
CoreV1API_createCoreV1NamespacedPodEviction(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_eviction_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create a PodTemplate
//
v1_pod_template_t*
CoreV1API_createCoreV1NamespacedPodTemplate(apiClient_t *apiClient ,char * namespace ,v1_pod_template_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ReplicationController
//
v1_replication_controller_t*
CoreV1API_createCoreV1NamespacedReplicationController(apiClient_t *apiClient ,char * namespace ,v1_replication_controller_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ResourceQuota
//
v1_resource_quota_t*
CoreV1API_createCoreV1NamespacedResourceQuota(apiClient_t *apiClient ,char * namespace ,v1_resource_quota_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Secret
//
v1_secret_t*
CoreV1API_createCoreV1NamespacedSecret(apiClient_t *apiClient ,char * namespace ,v1_secret_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Service
//
v1_service_t*
CoreV1API_createCoreV1NamespacedService(apiClient_t *apiClient ,char * namespace ,v1_service_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ServiceAccount
//
v1_service_account_t*
CoreV1API_createCoreV1NamespacedServiceAccount(apiClient_t *apiClient ,char * namespace ,v1_service_account_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create token of a ServiceAccount
//
v1_token_request_t*
CoreV1API_createCoreV1NamespacedServiceAccountToken(apiClient_t *apiClient ,char * name ,char * namespace ,v1_token_request_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create a Node
//
v1_node_t*
CoreV1API_createCoreV1Node(apiClient_t *apiClient ,v1_node_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_createCoreV1PersistentVolume(apiClient_t *apiClient ,v1_persistent_volume_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of ConfigMap
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedConfigMap(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Endpoints
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedEndpoints(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Event
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedEvent(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of LimitRange
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedLimitRange(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of PersistentVolumeClaim
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedPersistentVolumeClaim(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Pod
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedPod(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of PodTemplate
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedPodTemplate(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ReplicationController
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedReplicationController(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ResourceQuota
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedResourceQuota(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Secret
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedSecret(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ServiceAccount
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNamespacedServiceAccount(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Node
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionNode(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of PersistentVolume
//
v1_status_t*
CoreV1API_deleteCoreV1CollectionPersistentVolume(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a Namespace
//
v1_status_t*
CoreV1API_deleteCoreV1Namespace(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ConfigMap
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedConfigMap(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete Endpoints
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedEndpoints(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete an Event
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedEvent(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a LimitRange
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedLimitRange(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a PersistentVolumeClaim
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedPersistentVolumeClaim(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Pod
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedPod(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a PodTemplate
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedPodTemplate(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ReplicationController
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedReplicationController(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ResourceQuota
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedResourceQuota(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Secret
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedSecret(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Service
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedService(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ServiceAccount
//
v1_status_t*
CoreV1API_deleteCoreV1NamespacedServiceAccount(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a Node
//
v1_status_t*
CoreV1API_deleteCoreV1Node(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a PersistentVolume
//
v1_status_t*
CoreV1API_deleteCoreV1PersistentVolume(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
CoreV1API_getCoreV1APIResources(apiClient_t *apiClient);


// list objects of kind ComponentStatus
//
v1_component_status_list_t*
CoreV1API_listCoreV1ComponentStatus(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ConfigMap
//
v1_config_map_list_t*
CoreV1API_listCoreV1ConfigMapForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Endpoints
//
v1_endpoints_list_t*
CoreV1API_listCoreV1EndpointsForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Event
//
v1_event_list_t*
CoreV1API_listCoreV1EventForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind LimitRange
//
v1_limit_range_list_t*
CoreV1API_listCoreV1LimitRangeForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Namespace
//
v1_namespace_list_t*
CoreV1API_listCoreV1Namespace(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ConfigMap
//
v1_config_map_list_t*
CoreV1API_listCoreV1NamespacedConfigMap(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Endpoints
//
v1_endpoints_list_t*
CoreV1API_listCoreV1NamespacedEndpoints(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Event
//
v1_event_list_t*
CoreV1API_listCoreV1NamespacedEvent(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind LimitRange
//
v1_limit_range_list_t*
CoreV1API_listCoreV1NamespacedLimitRange(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PersistentVolumeClaim
//
v1_persistent_volume_claim_list_t*
CoreV1API_listCoreV1NamespacedPersistentVolumeClaim(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Pod
//
v1_pod_list_t*
CoreV1API_listCoreV1NamespacedPod(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PodTemplate
//
v1_pod_template_list_t*
CoreV1API_listCoreV1NamespacedPodTemplate(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicationController
//
v1_replication_controller_list_t*
CoreV1API_listCoreV1NamespacedReplicationController(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ResourceQuota
//
v1_resource_quota_list_t*
CoreV1API_listCoreV1NamespacedResourceQuota(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Secret
//
v1_secret_list_t*
CoreV1API_listCoreV1NamespacedSecret(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Service
//
v1_service_list_t*
CoreV1API_listCoreV1NamespacedService(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ServiceAccount
//
v1_service_account_list_t*
CoreV1API_listCoreV1NamespacedServiceAccount(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Node
//
v1_node_list_t*
CoreV1API_listCoreV1Node(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PersistentVolume
//
v1_persistent_volume_list_t*
CoreV1API_listCoreV1PersistentVolume(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PersistentVolumeClaim
//
v1_persistent_volume_claim_list_t*
CoreV1API_listCoreV1PersistentVolumeClaimForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Pod
//
v1_pod_list_t*
CoreV1API_listCoreV1PodForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PodTemplate
//
v1_pod_template_list_t*
CoreV1API_listCoreV1PodTemplateForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ReplicationController
//
v1_replication_controller_list_t*
CoreV1API_listCoreV1ReplicationControllerForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ResourceQuota
//
v1_resource_quota_list_t*
CoreV1API_listCoreV1ResourceQuotaForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Secret
//
v1_secret_list_t*
CoreV1API_listCoreV1SecretForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ServiceAccount
//
v1_service_account_list_t*
CoreV1API_listCoreV1ServiceAccountForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Service
//
v1_service_list_t*
CoreV1API_listCoreV1ServiceForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified Namespace
//
v1_namespace_t*
CoreV1API_patchCoreV1Namespace(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Namespace
//
v1_namespace_t*
CoreV1API_patchCoreV1NamespaceStatus(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ConfigMap
//
v1_config_map_t*
CoreV1API_patchCoreV1NamespacedConfigMap(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Endpoints
//
v1_endpoints_t*
CoreV1API_patchCoreV1NamespacedEndpoints(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Event
//
v1_event_t*
CoreV1API_patchCoreV1NamespacedEvent(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified LimitRange
//
v1_limit_range_t*
CoreV1API_patchCoreV1NamespacedLimitRange(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_patchCoreV1NamespacedPersistentVolumeClaim(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_patchCoreV1NamespacedPersistentVolumeClaimStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Pod
//
v1_pod_t*
CoreV1API_patchCoreV1NamespacedPod(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Pod
//
v1_pod_t*
CoreV1API_patchCoreV1NamespacedPodStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified PodTemplate
//
v1_pod_template_t*
CoreV1API_patchCoreV1NamespacedPodTemplate(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_patchCoreV1NamespacedReplicationController(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update scale of the specified ReplicationController
//
v1_scale_t*
CoreV1API_patchCoreV1NamespacedReplicationControllerScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_patchCoreV1NamespacedReplicationControllerStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_patchCoreV1NamespacedResourceQuota(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_patchCoreV1NamespacedResourceQuotaStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Secret
//
v1_secret_t*
CoreV1API_patchCoreV1NamespacedSecret(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Service
//
v1_service_t*
CoreV1API_patchCoreV1NamespacedService(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ServiceAccount
//
v1_service_account_t*
CoreV1API_patchCoreV1NamespacedServiceAccount(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Service
//
v1_service_t*
CoreV1API_patchCoreV1NamespacedServiceStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Node
//
v1_node_t*
CoreV1API_patchCoreV1Node(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified Node
//
v1_node_t*
CoreV1API_patchCoreV1NodeStatus(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_patchCoreV1PersistentVolume(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_patchCoreV1PersistentVolumeStatus(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified ComponentStatus
//
v1_component_status_t*
CoreV1API_readCoreV1ComponentStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified Namespace
//
v1_namespace_t*
CoreV1API_readCoreV1Namespace(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read status of the specified Namespace
//
v1_namespace_t*
CoreV1API_readCoreV1NamespaceStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified ConfigMap
//
v1_config_map_t*
CoreV1API_readCoreV1NamespacedConfigMap(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified Endpoints
//
v1_endpoints_t*
CoreV1API_readCoreV1NamespacedEndpoints(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified Event
//
v1_event_t*
CoreV1API_readCoreV1NamespacedEvent(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified LimitRange
//
v1_limit_range_t*
CoreV1API_readCoreV1NamespacedLimitRange(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_readCoreV1NamespacedPersistentVolumeClaim(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_readCoreV1NamespacedPersistentVolumeClaimStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified Pod
//
v1_pod_t*
CoreV1API_readCoreV1NamespacedPod(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read log of the specified Pod
//
char*
CoreV1API_readCoreV1NamespacedPodLog(apiClient_t *apiClient ,char * name ,char * namespace ,char * container ,int follow ,int insecureSkipTLSVerifyBackend ,int limitBytes ,char * pretty ,int previous ,int sinceSeconds ,int tailLines ,int timestamps);


// read status of the specified Pod
//
v1_pod_t*
CoreV1API_readCoreV1NamespacedPodStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified PodTemplate
//
v1_pod_template_t*
CoreV1API_readCoreV1NamespacedPodTemplate(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_readCoreV1NamespacedReplicationController(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read scale of the specified ReplicationController
//
v1_scale_t*
CoreV1API_readCoreV1NamespacedReplicationControllerScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read status of the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_readCoreV1NamespacedReplicationControllerStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_readCoreV1NamespacedResourceQuota(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_readCoreV1NamespacedResourceQuotaStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified Secret
//
v1_secret_t*
CoreV1API_readCoreV1NamespacedSecret(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified Service
//
v1_service_t*
CoreV1API_readCoreV1NamespacedService(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read the specified ServiceAccount
//
v1_service_account_t*
CoreV1API_readCoreV1NamespacedServiceAccount(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified Service
//
v1_service_t*
CoreV1API_readCoreV1NamespacedServiceStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified Node
//
v1_node_t*
CoreV1API_readCoreV1Node(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read status of the specified Node
//
v1_node_t*
CoreV1API_readCoreV1NodeStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_readCoreV1PersistentVolume(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read status of the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_readCoreV1PersistentVolumeStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// replace the specified Namespace
//
v1_namespace_t*
CoreV1API_replaceCoreV1Namespace(apiClient_t *apiClient ,char * name ,v1_namespace_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace finalize of the specified Namespace
//
v1_namespace_t*
CoreV1API_replaceCoreV1NamespaceFinalize(apiClient_t *apiClient ,char * name ,v1_namespace_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// replace status of the specified Namespace
//
v1_namespace_t*
CoreV1API_replaceCoreV1NamespaceStatus(apiClient_t *apiClient ,char * name ,v1_namespace_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ConfigMap
//
v1_config_map_t*
CoreV1API_replaceCoreV1NamespacedConfigMap(apiClient_t *apiClient ,char * name ,char * namespace ,v1_config_map_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Endpoints
//
v1_endpoints_t*
CoreV1API_replaceCoreV1NamespacedEndpoints(apiClient_t *apiClient ,char * name ,char * namespace ,v1_endpoints_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Event
//
v1_event_t*
CoreV1API_replaceCoreV1NamespacedEvent(apiClient_t *apiClient ,char * name ,char * namespace ,v1_event_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified LimitRange
//
v1_limit_range_t*
CoreV1API_replaceCoreV1NamespacedLimitRange(apiClient_t *apiClient ,char * name ,char * namespace ,v1_limit_range_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_replaceCoreV1NamespacedPersistentVolumeClaim(apiClient_t *apiClient ,char * name ,char * namespace ,v1_persistent_volume_claim_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_replaceCoreV1NamespacedPersistentVolumeClaimStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_persistent_volume_claim_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Pod
//
v1_pod_t*
CoreV1API_replaceCoreV1NamespacedPod(apiClient_t *apiClient ,char * name ,char * namespace ,v1_pod_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Pod
//
v1_pod_t*
CoreV1API_replaceCoreV1NamespacedPodStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_pod_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified PodTemplate
//
v1_pod_template_t*
CoreV1API_replaceCoreV1NamespacedPodTemplate(apiClient_t *apiClient ,char * name ,char * namespace ,v1_pod_template_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_replaceCoreV1NamespacedReplicationController(apiClient_t *apiClient ,char * name ,char * namespace ,v1_replication_controller_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace scale of the specified ReplicationController
//
v1_scale_t*
CoreV1API_replaceCoreV1NamespacedReplicationControllerScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_replaceCoreV1NamespacedReplicationControllerStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_replication_controller_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_replaceCoreV1NamespacedResourceQuota(apiClient_t *apiClient ,char * name ,char * namespace ,v1_resource_quota_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_replaceCoreV1NamespacedResourceQuotaStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_resource_quota_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Secret
//
v1_secret_t*
CoreV1API_replaceCoreV1NamespacedSecret(apiClient_t *apiClient ,char * name ,char * namespace ,v1_secret_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Service
//
v1_service_t*
CoreV1API_replaceCoreV1NamespacedService(apiClient_t *apiClient ,char * name ,char * namespace ,v1_service_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ServiceAccount
//
v1_service_account_t*
CoreV1API_replaceCoreV1NamespacedServiceAccount(apiClient_t *apiClient ,char * name ,char * namespace ,v1_service_account_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Service
//
v1_service_t*
CoreV1API_replaceCoreV1NamespacedServiceStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_service_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Node
//
v1_node_t*
CoreV1API_replaceCoreV1Node(apiClient_t *apiClient ,char * name ,v1_node_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified Node
//
v1_node_t*
CoreV1API_replaceCoreV1NodeStatus(apiClient_t *apiClient ,char * name ,v1_node_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_replaceCoreV1PersistentVolume(apiClient_t *apiClient ,char * name ,v1_persistent_volume_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_replaceCoreV1PersistentVolumeStatus(apiClient_t *apiClient ,char * name ,v1_persistent_volume_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


