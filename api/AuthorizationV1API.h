#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_local_subject_access_review.h"
#include "../model/v1_self_subject_access_review.h"
#include "../model/v1_self_subject_rules_review.h"
#include "../model/v1_subject_access_review.h"


// create a LocalSubjectAccessReview
//
v1_local_subject_access_review_t*
AuthorizationV1API_createAuthorizationV1NamespacedLocalSubjectAccessReview(apiClient_t *apiClient ,char * namespace ,v1_local_subject_access_review_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create a SelfSubjectAccessReview
//
v1_self_subject_access_review_t*
AuthorizationV1API_createAuthorizationV1SelfSubjectAccessReview(apiClient_t *apiClient ,v1_self_subject_access_review_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create a SelfSubjectRulesReview
//
v1_self_subject_rules_review_t*
AuthorizationV1API_createAuthorizationV1SelfSubjectRulesReview(apiClient_t *apiClient ,v1_self_subject_rules_review_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// create a SubjectAccessReview
//
v1_subject_access_review_t*
AuthorizationV1API_createAuthorizationV1SubjectAccessReview(apiClient_t *apiClient ,v1_subject_access_review_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// get available resources
//
v1_api_resource_list_t*
AuthorizationV1API_getAuthorizationV1APIResources(apiClient_t *apiClient);


