#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_validation.h"



v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation_create(
    v1beta1_json_schema_props_t *openAPIV3Schema
    ) {
	v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation_local_var = malloc(sizeof(v1beta1_custom_resource_validation_t));
    if (!v1beta1_custom_resource_validation_local_var) {
        return NULL;
    }
	v1beta1_custom_resource_validation_local_var->openAPIV3Schema = openAPIV3Schema;

	return v1beta1_custom_resource_validation_local_var;
}


void v1beta1_custom_resource_validation_free(v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation) {
    listEntry_t *listEntry;
    v1beta1_json_schema_props_free(v1beta1_custom_resource_validation->openAPIV3Schema);
	free(v1beta1_custom_resource_validation);
}

cJSON *v1beta1_custom_resource_validation_convertToJSON(v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_custom_resource_validation->openAPIV3Schema
    if(v1beta1_custom_resource_validation->openAPIV3Schema) { 
    cJSON *openAPIV3Schema_local_JSON = v1beta1_json_schema_props_convertToJSON(v1beta1_custom_resource_validation->openAPIV3Schema);
    if(openAPIV3Schema_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "openAPIV3Schema", openAPIV3Schema_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation_parseFromJSON(cJSON *v1beta1_custom_resource_validationJSON){

    v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation_local_var = NULL;

    // v1beta1_custom_resource_validation->openAPIV3Schema
    cJSON *openAPIV3Schema = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_validationJSON, "openAPIV3Schema");
    v1beta1_json_schema_props_t *openAPIV3Schema_local_nonprim = NULL;
    if (openAPIV3Schema) { 
    openAPIV3Schema_local_nonprim = v1beta1_json_schema_props_parseFromJSON(openAPIV3Schema); //nonprimitive
    }


    v1beta1_custom_resource_validation_local_var = v1beta1_custom_resource_validation_create (
        openAPIV3Schema ? openAPIV3Schema_local_nonprim : NULL
        );

    return v1beta1_custom_resource_validation_local_var;
end:
    return NULL;

}
