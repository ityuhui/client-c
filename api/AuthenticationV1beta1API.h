#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1beta1_token_review.h"


// create a TokenReview
//
v1beta1_token_review_t*
AuthenticationV1beta1API_createAuthenticationV1beta1TokenReview(apiClient_t *apiClient ,v1beta1_token_review_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// get available resources
//
v1_api_resource_list_t*
AuthenticationV1beta1API_getAuthenticationV1beta1APIResources(apiClient_t *apiClient);


