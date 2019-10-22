/*
 * v1_server_address_by_client_cidr.h
 *
 * ServerAddressByClientCIDR helps the client to determine the server address that they should use, depending on the clientCIDR that they match.
 */

#ifndef _v1_server_address_by_client_cidr_H_
#define _v1_server_address_by_client_cidr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_server_address_by_client_cidr_t {
    char *clientCIDR; // string
    char *serverAddress; // string

} v1_server_address_by_client_cidr_t;

v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_create(
    char *clientCIDR,
    char *serverAddress
);

void v1_server_address_by_client_cidr_free(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr);

v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_parseFromJSON(cJSON *v1_server_address_by_client_cidrJSON);

cJSON *v1_server_address_by_client_cidr_convertToJSON(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr);

#endif /* _v1_server_address_by_client_cidr_H_ */

