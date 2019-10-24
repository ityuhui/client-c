#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ego_v1_activity.h"

activity_t *ego_v1_activity_create() {
    activity_t *object = malloc(sizeof(activity_t));

    return object;
}

void activity_free(activity_t *object) {
    free (object);
}

cJSON *activity_convertToJSON(activity_t *activity) {
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

activity_t *activity_parseFromJSON(char *jsonString){
    activity_t *activity = NULL;

    // activity_t->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(jsonString, "apiVersion");
    if (apiVersion) {
        if (!cJSON_IsString(apiVersion)) {
            goto end; //String
        }
    }

    // activity_t->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(jsonString, "kind");
    if (kind) {
        if (!cJSON_IsString(kind)) {
            goto end; //String
        }
    }

    // activity_t->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(jsonString, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) {
        metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // activity_t->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(jsonString, "spec");
    ego_v1_activity_spec_t *spec_local_nonprim = NULL;
    if (spec) {
        spec_local_nonprim = ego_v1_activity_spec_parseFromJSON(spec); //nonprimitive
    }

    // activity_t->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(jsonString, "status");
    ego_v1_activity_status_t *status_local_nonprim = NULL;
    if (status) {
        status_local_nonprim = ego_v1_activity_status_parseFromJSON(status); //nonprimitive
    }


    activity = activity_create(
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
