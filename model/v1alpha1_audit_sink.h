/*
 * v1alpha1_audit_sink.h
 *
 * AuditSink represents a cluster level audit sink
 */

#ifndef _v1alpha1_audit_sink_H_
#define _v1alpha1_audit_sink_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1alpha1_audit_sink_spec.h"



typedef struct v1alpha1_audit_sink_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1alpha1_audit_sink_spec_t *spec; //model

} v1alpha1_audit_sink_t;

v1alpha1_audit_sink_t *v1alpha1_audit_sink_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_audit_sink_spec_t *spec
);

void v1alpha1_audit_sink_free(v1alpha1_audit_sink_t *v1alpha1_audit_sink);

v1alpha1_audit_sink_t *v1alpha1_audit_sink_parseFromJSON(cJSON *v1alpha1_audit_sinkJSON);

cJSON *v1alpha1_audit_sink_convertToJSON(v1alpha1_audit_sink_t *v1alpha1_audit_sink);

#endif /* _v1alpha1_audit_sink_H_ */

