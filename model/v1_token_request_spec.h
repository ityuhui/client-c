/*
 * v1_token_request_spec.h
 *
 * TokenRequestSpec contains client provided parameters of a token request.
 */

#ifndef _v1_token_request_spec_H_
#define _v1_token_request_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_bound_object_reference.h"



typedef struct v1_token_request_spec_t {
    list_t *audiences; //primitive container
    v1_bound_object_reference_t *boundObjectRef; //model
    long expirationSeconds; //numeric

} v1_token_request_spec_t;

v1_token_request_spec_t *v1_token_request_spec_create(
    list_t *audiences,
    v1_bound_object_reference_t *boundObjectRef,
    long expirationSeconds
);

void v1_token_request_spec_free(v1_token_request_spec_t *v1_token_request_spec);

v1_token_request_spec_t *v1_token_request_spec_parseFromJSON(cJSON *v1_token_request_specJSON);

cJSON *v1_token_request_spec_convertToJSON(v1_token_request_spec_t *v1_token_request_spec);

#endif /* _v1_token_request_spec_H_ */

