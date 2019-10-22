/*
 * v1_volume_projection.h
 *
 * Projection that may be projected along with other supported volume types
 */

#ifndef _v1_volume_projection_H_
#define _v1_volume_projection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_config_map_projection.h"
#include "v1_downward_api_projection.h"
#include "v1_secret_projection.h"
#include "v1_service_account_token_projection.h"



typedef struct v1_volume_projection_t {
    v1_config_map_projection_t *configMap; //model
    v1_downward_api_projection_t *downwardAPI; //model
    v1_secret_projection_t *secret; //model
    v1_service_account_token_projection_t *serviceAccountToken; //model

} v1_volume_projection_t;

v1_volume_projection_t *v1_volume_projection_create(
    v1_config_map_projection_t *configMap,
    v1_downward_api_projection_t *downwardAPI,
    v1_secret_projection_t *secret,
    v1_service_account_token_projection_t *serviceAccountToken
);

void v1_volume_projection_free(v1_volume_projection_t *v1_volume_projection);

v1_volume_projection_t *v1_volume_projection_parseFromJSON(cJSON *v1_volume_projectionJSON);

cJSON *v1_volume_projection_convertToJSON(v1_volume_projection_t *v1_volume_projection);

#endif /* _v1_volume_projection_H_ */

