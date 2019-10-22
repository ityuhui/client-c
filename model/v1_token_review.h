/*
 * v1_token_review.h
 *
 * TokenReview attempts to authenticate a token to a known user. Note: TokenReview requests may be cached by the webhook token authenticator plugin in the kube-apiserver.
 */

#ifndef _v1_token_review_H_
#define _v1_token_review_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1_token_review_spec.h"
#include "v1_token_review_status.h"



typedef struct v1_token_review_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_token_review_spec_t *spec; //model
    v1_token_review_status_t *status; //model

} v1_token_review_t;

v1_token_review_t *v1_token_review_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_review_spec_t *spec,
    v1_token_review_status_t *status
);

void v1_token_review_free(v1_token_review_t *v1_token_review);

v1_token_review_t *v1_token_review_parseFromJSON(cJSON *v1_token_reviewJSON);

cJSON *v1_token_review_convertToJSON(v1_token_review_t *v1_token_review);

#endif /* _v1_token_review_H_ */

