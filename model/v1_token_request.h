/*
 * v1_token_request.h
 *
 * TokenRequest requests a token for a given service account.
 */

#ifndef _v1_token_request_H_
#define _v1_token_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1_token_request_spec.h"
#include "v1_token_request_status.h"



typedef struct v1_token_request_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_token_request_spec_t *spec; //model
    v1_token_request_status_t *status; //model

} v1_token_request_t;

v1_token_request_t *v1_token_request_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_request_spec_t *spec,
    v1_token_request_status_t *status
);

void v1_token_request_free(v1_token_request_t *v1_token_request);

v1_token_request_t *v1_token_request_parseFromJSON(cJSON *v1_token_requestJSON);

cJSON *v1_token_request_convertToJSON(v1_token_request_t *v1_token_request);

#endif /* _v1_token_request_H_ */

