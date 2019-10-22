/*
 * v1beta1_csi_driver_spec.h
 *
 * CSIDriverSpec is the specification of a CSIDriver.
 */

#ifndef _v1beta1_csi_driver_spec_H_
#define _v1beta1_csi_driver_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_csi_driver_spec_t {
    int attachRequired; //boolean
    int podInfoOnMount; //boolean
    list_t *volumeLifecycleModes; //primitive container

} v1beta1_csi_driver_spec_t;

v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_create(
    int attachRequired,
    int podInfoOnMount,
    list_t *volumeLifecycleModes
);

void v1beta1_csi_driver_spec_free(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec);

v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_parseFromJSON(cJSON *v1beta1_csi_driver_specJSON);

cJSON *v1beta1_csi_driver_spec_convertToJSON(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec);

#endif /* _v1beta1_csi_driver_spec_H_ */

