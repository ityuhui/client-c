/*
 * v1beta1_controller_revision.h
 *
 * DEPRECATED - This group version of ControllerRevision is deprecated by apps/v1beta2/ControllerRevision. See the release notes for more information. ControllerRevision implements an immutable snapshot of state data. Clients are responsible for serializing and deserializing the objects that contain their internal state. Once a ControllerRevision has been successfully created, it can not_ be updated. The API Server will fail validation of all requests that attempt to mutate the Data field. ControllerRevisions may, however, be deleted. Note that, due to its use by both the DaemonSet and StatefulSet controllers for update and rollback, this object is beta. However, it may be subject to name and representation changes in future releases, and clients should not_ depend on its stability. It is primarily for internal use by controllers.
 */

#ifndef _v1beta1_controller_revision_H_
#define _v1beta1_controller_revision_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"
#include "v1_object_meta.h"



typedef struct v1beta1_controller_revision_t {
    char *apiVersion; // string
    object_t *data; //object
    char *kind; // string
    v1_object_meta_t *metadata; //model
    long revision; //numeric

} v1beta1_controller_revision_t;

v1beta1_controller_revision_t *v1beta1_controller_revision_create(
    char *apiVersion,
    object_t *data,
    char *kind,
    v1_object_meta_t *metadata,
    long revision
);

void v1beta1_controller_revision_free(v1beta1_controller_revision_t *v1beta1_controller_revision);

v1beta1_controller_revision_t *v1beta1_controller_revision_parseFromJSON(cJSON *v1beta1_controller_revisionJSON);

cJSON *v1beta1_controller_revision_convertToJSON(v1beta1_controller_revision_t *v1beta1_controller_revision);

#endif /* _v1beta1_controller_revision_H_ */

