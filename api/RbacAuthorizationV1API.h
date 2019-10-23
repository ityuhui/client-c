#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_cluster_role.h"
#include "../model/v1_cluster_role_binding.h"
#include "../model/v1_cluster_role_binding_list.h"
#include "../model/v1_cluster_role_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_role.h"
#include "../model/v1_role_binding.h"
#include "../model/v1_role_binding_list.h"
#include "../model/v1_role_list.h"
#include "../model/v1_status.h"


// create a ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_createRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,v1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_createRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,v1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Role
//
v1_role_t*
RbacAuthorizationV1API_createRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * namespace ,v1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_createRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,v1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete a ClusterRole
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete collection of ClusterRole
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Role
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionNamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of RoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionNamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a Role
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a RoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
RbacAuthorizationV1API_getRbacAuthorizationV1APIResources(apiClient_t *apiClient);


// list or watch objects of kind ClusterRole
//
v1_cluster_role_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ClusterRoleBinding
//
v1_cluster_role_binding_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Role
//
v1_role_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind RoleBinding
//
v1_role_binding_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind RoleBinding
//
v1_role_binding_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1RoleBindingForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Role
//
v1_role_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1RoleForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Role
//
v1_role_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_readRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_readRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified Role
//
v1_role_t*
RbacAuthorizationV1API_readRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_readRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name ,v1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,v1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Role
//
v1_role_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,v1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,v1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


