/*
 * v1alpha1_volume_attachment.h
 *
 * VolumeAttachment captures the intent to attach or detach the specified volume to/from the specified node.  VolumeAttachment objects are non-namespaced.
 */

#ifndef _v1alpha1_volume_attachment_H_
#define _v1alpha1_volume_attachment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1alpha1_volume_attachment_spec.h"
#include "v1alpha1_volume_attachment_status.h"



typedef struct v1alpha1_volume_attachment_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1alpha1_volume_attachment_spec_t *spec; //model
    v1alpha1_volume_attachment_status_t *status; //model

} v1alpha1_volume_attachment_t;

v1alpha1_volume_attachment_t *v1alpha1_volume_attachment_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_volume_attachment_spec_t *spec,
    v1alpha1_volume_attachment_status_t *status
);

void v1alpha1_volume_attachment_free(v1alpha1_volume_attachment_t *v1alpha1_volume_attachment);

v1alpha1_volume_attachment_t *v1alpha1_volume_attachment_parseFromJSON(cJSON *v1alpha1_volume_attachmentJSON);

cJSON *v1alpha1_volume_attachment_convertToJSON(v1alpha1_volume_attachment_t *v1alpha1_volume_attachment);

#endif /* _v1alpha1_volume_attachment_H_ */

