/*
 * v1_node.h
 *
 * Node is a worker node in Kubernetes. Each node will have a unique identifier in the cache (i.e. in etcd).
 */

#ifndef _v1_node_H_
#define _v1_node_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_node_spec.h"
#include "v1_node_status.h"
#include "v1_object_meta.h"



typedef struct v1_node_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_node_spec_t *spec; //model
    v1_node_status_t *status; //model

} v1_node_t;

v1_node_t *v1_node_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_node_spec_t *spec,
    v1_node_status_t *status
);

void v1_node_free(v1_node_t *v1_node);

v1_node_t *v1_node_parseFromJSON(cJSON *v1_nodeJSON);

cJSON *v1_node_convertToJSON(v1_node_t *v1_node);

#endif /* _v1_node_H_ */

