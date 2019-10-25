#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ego_v1_activity.h"

ego_v1_activity_t *ego_v1_activity_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    ego_v1_activity_spec_t *spec,
    ego_v1_activity_status_t *status
) {
    ego_v1_activity_t *ego_v1_activity_local_var = malloc(sizeof(ego_v1_activity_t));
    if (!ego_v1_activity_local_var) {
        return NULL;
    }
    ego_v1_activity_local_var->apiVersion = apiVersion;
    ego_v1_activity_local_var->kind = kind;
    ego_v1_activity_local_var->metadata = metadata;
    ego_v1_activity_local_var->spec = spec;
    ego_v1_activity_local_var->status = status;

    return ego_v1_activity_local_var;
}


void ego_v1_activity_free(ego_v1_activity_t *object) {
    FREEUP(object->apiVersion);
    FREEUP(object->kind);
    if (object->metadata) {
        v1_object_meta_free(object->metadata);
    }
    if (object->spec) {
        ego_v1_activity_spec_free(object->spec);
    }
    if (object->status) {
        ego_v1_activity_status_free(object->status);
    }
    FREEUP(object);
}

cJSON *ego_v1_activity_convertToJSON(ego_v1_activity_t *activity) {
    cJSON *item = cJSON_CreateObject();

    // activity->apiVersion
    if (activity->apiVersion) {
        if (cJSON_AddStringToObject(item, "apiVersion", activity->apiVersion) == NULL) {
            goto fail; //String
        }
    }


    // activity->kind
    if (activity->kind) {
        if (cJSON_AddStringToObject(item, "kind", activity->kind) == NULL) {
            goto fail; //String
        }
    }


    // activity->metadata
    if (activity->metadata) {
        cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(activity->metadata);
        if (metadata_local_JSON == NULL) {
            goto fail; //model
        }
        cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
        if (item->child == NULL) {
            goto fail;
        }
    }


    // activity->spec
    if (activity->spec) {
        cJSON *spec_local_JSON = ego_v1_activity_spec_convertToJSON(activity->spec);
        if (spec_local_JSON == NULL) {
            goto fail; //model
        }
        cJSON_AddItemToObject(item, "spec", spec_local_JSON);
        if (item->child == NULL) {
            goto fail;
        }
    }


    // activity->status
    if (activity->status) {
        cJSON *status_local_JSON = ego_v1_activity_status_convertToJSON(activity->status);
        if (status_local_JSON == NULL) {
            goto fail; //model
        }
        cJSON_AddItemToObject(item, "status", status_local_JSON);
        if (item->child == NULL) {
            goto fail;
        }
    }

    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

ego_v1_activity_t *ego_v1_activity_parseFromJSON(cJSON *ego_v1_JSON){
    ego_v1_activity_t *activity = NULL;

    // activity_t->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(ego_v1_JSON, "apiVersion");
    if (apiVersion) {
        if (!cJSON_IsString(apiVersion)) {
            goto end; //String
        }
    }

    // activity_t->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(ego_v1_JSON, "kind");
    if (kind) {
        if (!cJSON_IsString(kind)) {
            goto end; //String
        }
    }

    // activity_t->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(ego_v1_JSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) {
        metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // activity_t->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(ego_v1_JSON, "spec");
    ego_v1_activity_spec_t *spec_local_nonprim = NULL;
    if (spec) {
        spec_local_nonprim = ego_v1_activity_spec_parseFromJSON(spec); //nonprimitive
    }

    // activity_t->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ego_v1_JSON, "status");
    ego_v1_activity_status_t *status_local_nonprim = NULL;
    if (status) {
        status_local_nonprim = ego_v1_activity_status_parseFromJSON(status); //nonprimitive
    }


    activity = ego_v1_activity_create(
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
    );

    return activity;
end:
    return NULL;
}
