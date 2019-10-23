#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1alpha1_cluster_role.h"
#include "../model/v1alpha1_cluster_role_binding.h"
#include "../model/v1alpha1_cluster_role_binding_list.h"
#include "../model/v1alpha1_cluster_role_list.h"
#include "../model/v1alpha1_role.h"
#include "../model/v1alpha1_role_binding.h"
#include "../model/v1alpha1_role_binding_list.h"
#include "../model/v1alpha1_role_list.h"


// create a ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_createRbacAuthorizationV1alpha1ClusterRole(apiClient_t *apiClient ,v1alpha1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_createRbacAuthorizationV1alpha1ClusterRoleBinding(apiClient_t *apiClient ,v1alpha1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_createRbacAuthorizationV1alpha1NamespacedRole(apiClient_t *apiClient ,char * namespace ,v1alpha1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_createRbacAuthorizationV1alpha1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,v1alpha1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete a ClusterRole
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete collection of ClusterRole
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1CollectionClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1CollectionClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of Role
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1CollectionNamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of RoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1CollectionNamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a Role
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a RoleBinding
//
v1_status_t*
RbacAuthorizationV1alpha1API_deleteRbacAuthorizationV1alpha1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
RbacAuthorizationV1alpha1API_getRbacAuthorizationV1alpha1APIResources(apiClient_t *apiClient);


// list or watch objects of kind ClusterRole
//
v1alpha1_cluster_role_list_t*
RbacAuthorizationV1alpha1API_listRbacAuthorizationV1alpha1ClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind ClusterRoleBinding
//
v1alpha1_cluster_role_binding_list_t*
RbacAuthorizationV1alpha1API_listRbacAuthorizationV1alpha1ClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Role
//
v1alpha1_role_list_t*
RbacAuthorizationV1alpha1API_listRbacAuthorizationV1alpha1NamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind RoleBinding
//
v1alpha1_role_binding_list_t*
RbacAuthorizationV1alpha1API_listRbacAuthorizationV1alpha1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind RoleBinding
//
v1alpha1_role_binding_list_t*
RbacAuthorizationV1alpha1API_listRbacAuthorizationV1alpha1RoleBindingForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind Role
//
v1alpha1_role_list_t*
RbacAuthorizationV1alpha1API_listRbacAuthorizationV1alpha1RoleForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_patchRbacAuthorizationV1alpha1ClusterRole(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_patchRbacAuthorizationV1alpha1ClusterRoleBinding(apiClient_t *apiClient ,char * name , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_patchRbacAuthorizationV1alpha1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_patchRbacAuthorizationV1alpha1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_readRbacAuthorizationV1alpha1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_readRbacAuthorizationV1alpha1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty);


// read the specified Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_readRbacAuthorizationV1alpha1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_readRbacAuthorizationV1alpha1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// replace the specified ClusterRole
//
v1alpha1_cluster_role_t*
RbacAuthorizationV1alpha1API_replaceRbacAuthorizationV1alpha1ClusterRole(apiClient_t *apiClient ,char * name ,v1alpha1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified ClusterRoleBinding
//
v1alpha1_cluster_role_binding_t*
RbacAuthorizationV1alpha1API_replaceRbacAuthorizationV1alpha1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,v1alpha1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified Role
//
v1alpha1_role_t*
RbacAuthorizationV1alpha1API_replaceRbacAuthorizationV1alpha1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,v1alpha1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified RoleBinding
//
v1alpha1_role_binding_t*
RbacAuthorizationV1alpha1API_replaceRbacAuthorizationV1alpha1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,v1alpha1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


