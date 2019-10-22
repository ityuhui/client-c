#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_versions.h"


// get available API versions
//
v1_api_versions_t*
CoreAPI_getCoreAPIVersions(apiClient_t *apiClient);


