/*
 * v1_token_request_status.h
 *
 * TokenRequestStatus is the result of a token request.
 */

#ifndef _v1_token_request_status_H_
#define _v1_token_request_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_token_request_status_t {
    char *expirationTimestamp; //date time
    char *token; // string

} v1_token_request_status_t;

v1_token_request_status_t *v1_token_request_status_create(
    char *expirationTimestamp,
    char *token
);

void v1_token_request_status_free(v1_token_request_status_t *v1_token_request_status);

v1_token_request_status_t *v1_token_request_status_parseFromJSON(cJSON *v1_token_request_statusJSON);

cJSON *v1_token_request_status_convertToJSON(v1_token_request_status_t *v1_token_request_status);

#endif /* _v1_token_request_status_H_ */

