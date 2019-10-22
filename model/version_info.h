/*
 * version_info.h
 *
 * Info contains versioning information. how we&#39;ll want to distribute that information.
 */

#ifndef _version_info_H_
#define _version_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct version_info_t {
    char *buildDate; // string
    char *compiler; // string
    char *gitCommit; // string
    char *gitTreeState; // string
    char *gitVersion; // string
    char *goVersion; // string
    char *major; // string
    char *minor; // string
    char *platform; // string

} version_info_t;

version_info_t *version_info_create(
    char *buildDate,
    char *compiler,
    char *gitCommit,
    char *gitTreeState,
    char *gitVersion,
    char *goVersion,
    char *major,
    char *minor,
    char *platform
);

void version_info_free(version_info_t *version_info);

version_info_t *version_info_parseFromJSON(cJSON *version_infoJSON);

cJSON *version_info_convertToJSON(version_info_t *version_info);

#endif /* _version_info_H_ */

