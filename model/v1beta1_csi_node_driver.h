/*
 * v1beta1_csi_node_driver.h
 *
 * CSINodeDriver holds information about the specification of one CSI driver installed on a node
 */

#ifndef _v1beta1_csi_node_driver_H_
#define _v1beta1_csi_node_driver_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_volume_node_resources.h"



typedef struct v1beta1_csi_node_driver_t {
    v1beta1_volume_node_resources_t *allocatable; //model
    char *name; // string
    char *nodeID; // string
    list_t *topologyKeys; //primitive container

} v1beta1_csi_node_driver_t;

v1beta1_csi_node_driver_t *v1beta1_csi_node_driver_create(
    v1beta1_volume_node_resources_t *allocatable,
    char *name,
    char *nodeID,
    list_t *topologyKeys
);

void v1beta1_csi_node_driver_free(v1beta1_csi_node_driver_t *v1beta1_csi_node_driver);

v1beta1_csi_node_driver_t *v1beta1_csi_node_driver_parseFromJSON(cJSON *v1beta1_csi_node_driverJSON);

cJSON *v1beta1_csi_node_driver_convertToJSON(v1beta1_csi_node_driver_t *v1beta1_csi_node_driver);

#endif /* _v1beta1_csi_node_driver_H_ */

