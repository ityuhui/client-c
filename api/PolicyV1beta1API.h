#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/policy_v1beta1_pod_security_policy.h"
#include "../model/policy_v1beta1_pod_security_policy_list.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_pod_disruption_budget.h"
#include "../model/v1beta1_pod_disruption_budget_list.h"


// create a PodDisruptionBudget
//
v1beta1_pod_disruption_budget_t*
PolicyV1beta1API_createPolicyV1beta1NamespacedPodDisruptionBudget(apiClient_t *apiClient ,char * namespace ,v1beta1_pod_disruption_budget_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// create a PodSecurityPolicy
//
policy_v1beta1_pod_security_policy_t*
PolicyV1beta1API_createPolicyV1beta1PodSecurityPolicy(apiClient_t *apiClient ,policy_v1beta1_pod_security_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete collection of PodDisruptionBudget
//
v1_status_t*
PolicyV1beta1API_deletePolicyV1beta1CollectionNamespacedPodDisruptionBudget(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete collection of PodSecurityPolicy
//
v1_status_t*
PolicyV1beta1API_deletePolicyV1beta1CollectionPodSecurityPolicy(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// delete a PodDisruptionBudget
//
v1_status_t*
PolicyV1beta1API_deletePolicyV1beta1NamespacedPodDisruptionBudget(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete a PodSecurityPolicy
//
v1_status_t*
PolicyV1beta1API_deletePolicyV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
PolicyV1beta1API_getPolicyV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind PodDisruptionBudget
//
v1beta1_pod_disruption_budget_list_t*
PolicyV1beta1API_listPolicyV1beta1NamespacedPodDisruptionBudget(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PodDisruptionBudget
//
v1beta1_pod_disruption_budget_list_t*
PolicyV1beta1API_listPolicyV1beta1PodDisruptionBudgetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch objects of kind PodSecurityPolicy
//
policy_v1beta1_pod_security_policy_list_t*
PolicyV1beta1API_listPolicyV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified PodDisruptionBudget
//
v1beta1_pod_disruption_budget_t*
PolicyV1beta1API_patchPolicyV1beta1NamespacedPodDisruptionBudget(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified PodDisruptionBudget
//
v1beta1_pod_disruption_budget_t*
PolicyV1beta1API_patchPolicyV1beta1NamespacedPodDisruptionBudgetStatus(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update the specified PodSecurityPolicy
//
policy_v1beta1_pod_security_policy_t*
PolicyV1beta1API_patchPolicyV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified PodDisruptionBudget
//
v1beta1_pod_disruption_budget_t*
PolicyV1beta1API_readPolicyV1beta1NamespacedPodDisruptionBudget(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export);


// read status of the specified PodDisruptionBudget
//
v1beta1_pod_disruption_budget_t*
PolicyV1beta1API_readPolicyV1beta1NamespacedPodDisruptionBudgetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty);


// read the specified PodSecurityPolicy
//
policy_v1beta1_pod_security_policy_t*
PolicyV1beta1API_readPolicyV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// replace the specified PodDisruptionBudget
//
v1beta1_pod_disruption_budget_t*
PolicyV1beta1API_replacePolicyV1beta1NamespacedPodDisruptionBudget(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_pod_disruption_budget_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace status of the specified PodDisruptionBudget
//
v1beta1_pod_disruption_budget_t*
PolicyV1beta1API_replacePolicyV1beta1NamespacedPodDisruptionBudgetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1beta1_pod_disruption_budget_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace the specified PodSecurityPolicy
//
policy_v1beta1_pod_security_policy_t*
PolicyV1beta1API_replacePolicyV1beta1PodSecurityPolicy(apiClient_t *apiClient ,char * name ,policy_v1beta1_pod_security_policy_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


