#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_cluster_role.h"
#include "../model/v1beta1_cluster_role_binding.h"
#include "../model/v1beta1_cluster_role_binding_list.h"
#include "../model/v1beta1_cluster_role_list.h"
#include "../model/v1beta1_role.h"
#include "../model/v1beta1_role_binding.h"
#include "../model/v1beta1_role_binding_list.h"
#include "../model/v1beta1_role_list.h"


// create a ClusterRole
//
v1beta1_cluster_role_t*
RbacAuthorizationV1beta1API_createRbacAuthorizationV1beta1ClusterRole(apiClient_t *apiClient ,v1beta1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ClusterRoleBinding
//
v1beta1_cluster_role_binding_t*
RbacAuthorizationV1beta1API_createRbacAuthorizationV1beta1ClusterRoleBinding(apiClient_t *apiClient ,v1beta1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Role
//
v1beta1_role_t*
RbacAuthorizationV1beta1API_createRbacAuthorizationV1beta1NamespacedRole(apiClient_t *apiClient ,char * namespace ,v1beta1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a RoleBinding
//
v1beta1_role_binding_t*
RbacAuthorizationV1beta1API_createRbacAuthorizationV1beta1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,v1beta1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete a ClusterRole
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete collection of ClusterRole
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1CollectionClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1CollectionClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Role
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1CollectionNamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of RoleBinding
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1CollectionNamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a Role
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a RoleBinding
//
v1_status_t*
RbacAuthorizationV1beta1API_deleteRbacAuthorizationV1beta1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
RbacAuthorizationV1beta1API_getRbacAuthorizationV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind ClusterRole
//
v1beta1_cluster_role_list_t*
RbacAuthorizationV1beta1API_listRbacAuthorizationV1beta1ClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ClusterRoleBinding
//
v1beta1_cluster_role_binding_list_t*
RbacAuthorizationV1beta1API_listRbacAuthorizationV1beta1ClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Role
//
v1beta1_role_list_t*
RbacAuthorizationV1beta1API_listRbacAuthorizationV1beta1NamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind RoleBinding
//
v1beta1_role_binding_list_t*
RbacAuthorizationV1beta1API_listRbacAuthorizationV1beta1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind RoleBinding
//
v1beta1_role_binding_list_t*
RbacAuthorizationV1beta1API_listRbacAuthorizationV1beta1RoleBindingForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Role
//
v1beta1_role_list_t*
RbacAuthorizationV1beta1API_listRbacAuthorizationV1beta1RoleForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified ClusterRole
//
v1beta1_cluster_role_t*
RbacAuthorizationV1beta1API_patchRbacAuthorizationV1beta1ClusterRole(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ClusterRoleBinding
//
v1beta1_cluster_role_binding_t*
RbacAuthorizationV1beta1API_patchRbacAuthorizationV1beta1ClusterRoleBinding(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Role
//
v1beta1_role_t*
RbacAuthorizationV1beta1API_patchRbacAuthorizationV1beta1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified RoleBinding
//
v1beta1_role_binding_t*
RbacAuthorizationV1beta1API_patchRbacAuthorizationV1beta1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified ClusterRole
//
v1beta1_cluster_role_t*
RbacAuthorizationV1beta1API_readRbacAuthorizationV1beta1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified ClusterRoleBinding
//
v1beta1_cluster_role_binding_t*
RbacAuthorizationV1beta1API_readRbacAuthorizationV1beta1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified Role
//
v1beta1_role_t*
RbacAuthorizationV1beta1API_readRbacAuthorizationV1beta1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified RoleBinding
//
v1beta1_role_binding_t*
RbacAuthorizationV1beta1API_readRbacAuthorizationV1beta1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified ClusterRole
//
v1beta1_cluster_role_t*
RbacAuthorizationV1beta1API_replaceRbacAuthorizationV1beta1ClusterRole(apiClient_t *apiClient ,char * name ,v1beta1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ClusterRoleBinding
//
v1beta1_cluster_role_binding_t*
RbacAuthorizationV1beta1API_replaceRbacAuthorizationV1beta1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,v1beta1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Role
//
v1beta1_role_t*
RbacAuthorizationV1beta1API_replaceRbacAuthorizationV1beta1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified RoleBinding
//
v1beta1_role_binding_t*
RbacAuthorizationV1beta1API_replaceRbacAuthorizationV1beta1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


