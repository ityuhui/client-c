/*
 * extensions_v1beta1_runtime_class_strategy_options.h
 *
 * RuntimeClassStrategyOptions define the strategy that will dictate the allowable RuntimeClasses for a pod.
 */

#ifndef _extensions_v1beta1_runtime_class_strategy_options_H_
#define _extensions_v1beta1_runtime_class_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_runtime_class_strategy_options_t {
    list_t *allowedRuntimeClassNames; //primitive container
    char *defaultRuntimeClassName; // string

} extensions_v1beta1_runtime_class_strategy_options_t;

extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_create(
    list_t *allowedRuntimeClassNames,
    char *defaultRuntimeClassName
);

void extensions_v1beta1_runtime_class_strategy_options_free(extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options);

extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_parseFromJSON(cJSON *extensions_v1beta1_runtime_class_strategy_optionsJSON);

cJSON *extensions_v1beta1_runtime_class_strategy_options_convertToJSON(extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options);

#endif /* _extensions_v1beta1_runtime_class_strategy_options_H_ */

