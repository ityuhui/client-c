#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lease_spec.h"



v1_lease_spec_t *v1_lease_spec_create(
    char *acquireTime,
    char *holderIdentity,
    int leaseDurationSeconds,
    int leaseTransitions,
    char *renewTime
    ) {
	v1_lease_spec_t *v1_lease_spec_local_var = malloc(sizeof(v1_lease_spec_t));
    if (!v1_lease_spec_local_var) {
        return NULL;
    }
	v1_lease_spec_local_var->acquireTime = acquireTime;
	v1_lease_spec_local_var->holderIdentity = holderIdentity;
	v1_lease_spec_local_var->leaseDurationSeconds = leaseDurationSeconds;
	v1_lease_spec_local_var->leaseTransitions = leaseTransitions;
	v1_lease_spec_local_var->renewTime = renewTime;

	return v1_lease_spec_local_var;
}


void v1_lease_spec_free(v1_lease_spec_t *v1_lease_spec) {
    listEntry_t *listEntry;
    free(v1_lease_spec->acquireTime);
    free(v1_lease_spec->holderIdentity);
    free(v1_lease_spec->renewTime);
	free(v1_lease_spec);
}

cJSON *v1_lease_spec_convertToJSON(v1_lease_spec_t *v1_lease_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_lease_spec->acquireTime
    if(v1_lease_spec->acquireTime) { 
    if(cJSON_AddStringToObject(item, "acquireTime", v1_lease_spec->acquireTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_lease_spec->holderIdentity
    if(v1_lease_spec->holderIdentity) { 
    if(cJSON_AddStringToObject(item, "holderIdentity", v1_lease_spec->holderIdentity) == NULL) {
    goto fail; //String
    }
     } 


	// v1_lease_spec->leaseDurationSeconds
    if(v1_lease_spec->leaseDurationSeconds) { 
    if(cJSON_AddNumberToObject(item, "leaseDurationSeconds", v1_lease_spec->leaseDurationSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_lease_spec->leaseTransitions
    if(v1_lease_spec->leaseTransitions) { 
    if(cJSON_AddNumberToObject(item, "leaseTransitions", v1_lease_spec->leaseTransitions) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_lease_spec->renewTime
    if(v1_lease_spec->renewTime) { 
    if(cJSON_AddStringToObject(item, "renewTime", v1_lease_spec->renewTime) == NULL) {
    goto fail; //Date-Time
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_lease_spec_t *v1_lease_spec_parseFromJSON(cJSON *v1_lease_specJSON){

    v1_lease_spec_t *v1_lease_spec_local_var = NULL;

    // v1_lease_spec->acquireTime
    cJSON *acquireTime = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "acquireTime");
    if (acquireTime) { 
    if(!cJSON_IsString(acquireTime))
    {
    goto end; //DateTime
    }
    }

    // v1_lease_spec->holderIdentity
    cJSON *holderIdentity = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "holderIdentity");
    if (holderIdentity) { 
    if(!cJSON_IsString(holderIdentity))
    {
    goto end; //String
    }
    }

    // v1_lease_spec->leaseDurationSeconds
    cJSON *leaseDurationSeconds = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "leaseDurationSeconds");
    if (leaseDurationSeconds) { 
    if(!cJSON_IsNumber(leaseDurationSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_lease_spec->leaseTransitions
    cJSON *leaseTransitions = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "leaseTransitions");
    if (leaseTransitions) { 
    if(!cJSON_IsNumber(leaseTransitions))
    {
    goto end; //Numeric
    }
    }

    // v1_lease_spec->renewTime
    cJSON *renewTime = cJSON_GetObjectItemCaseSensitive(v1_lease_specJSON, "renewTime");
    if (renewTime) { 
    if(!cJSON_IsString(renewTime))
    {
    goto end; //DateTime
    }
    }


    v1_lease_spec_local_var = v1_lease_spec_create (
        acquireTime ? strdup(acquireTime->valuestring) : NULL,
        holderIdentity ? strdup(holderIdentity->valuestring) : NULL,
        leaseDurationSeconds ? leaseDurationSeconds->valuedouble : 0,
        leaseTransitions ? leaseTransitions->valuedouble : 0,
        renewTime ? strdup(renewTime->valuestring) : NULL
        );

    return v1_lease_spec_local_var;
end:
    return NULL;

}
