#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_validating_admission_policy.h"



v1beta1_validating_admission_policy_t *v1beta1_validating_admission_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_validating_admission_policy_spec_t *spec,
    v1beta1_validating_admission_policy_status_t *status
    ) {
    v1beta1_validating_admission_policy_t *v1beta1_validating_admission_policy_local_var = malloc(sizeof(v1beta1_validating_admission_policy_t));
    if (!v1beta1_validating_admission_policy_local_var) {
        return NULL;
    }
    v1beta1_validating_admission_policy_local_var->api_version = api_version;
    v1beta1_validating_admission_policy_local_var->kind = kind;
    v1beta1_validating_admission_policy_local_var->metadata = metadata;
    v1beta1_validating_admission_policy_local_var->spec = spec;
    v1beta1_validating_admission_policy_local_var->status = status;

    return v1beta1_validating_admission_policy_local_var;
}


void v1beta1_validating_admission_policy_free(v1beta1_validating_admission_policy_t *v1beta1_validating_admission_policy) {
    if(NULL == v1beta1_validating_admission_policy){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_validating_admission_policy->api_version) {
        free(v1beta1_validating_admission_policy->api_version);
        v1beta1_validating_admission_policy->api_version = NULL;
    }
    if (v1beta1_validating_admission_policy->kind) {
        free(v1beta1_validating_admission_policy->kind);
        v1beta1_validating_admission_policy->kind = NULL;
    }
    if (v1beta1_validating_admission_policy->metadata) {
        v1_object_meta_free(v1beta1_validating_admission_policy->metadata);
        v1beta1_validating_admission_policy->metadata = NULL;
    }
    if (v1beta1_validating_admission_policy->spec) {
        v1beta1_validating_admission_policy_spec_free(v1beta1_validating_admission_policy->spec);
        v1beta1_validating_admission_policy->spec = NULL;
    }
    if (v1beta1_validating_admission_policy->status) {
        v1beta1_validating_admission_policy_status_free(v1beta1_validating_admission_policy->status);
        v1beta1_validating_admission_policy->status = NULL;
    }
    free(v1beta1_validating_admission_policy);
}

cJSON *v1beta1_validating_admission_policy_convertToJSON(v1beta1_validating_admission_policy_t *v1beta1_validating_admission_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_validating_admission_policy->api_version
    if(v1beta1_validating_admission_policy->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_validating_admission_policy->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_validating_admission_policy->kind
    if(v1beta1_validating_admission_policy->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1beta1_validating_admission_policy->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_validating_admission_policy->metadata
    if(v1beta1_validating_admission_policy->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_validating_admission_policy->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_validating_admission_policy->spec
    if(v1beta1_validating_admission_policy->spec) {
    cJSON *spec_local_JSON = v1beta1_validating_admission_policy_spec_convertToJSON(v1beta1_validating_admission_policy->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_validating_admission_policy->status
    if(v1beta1_validating_admission_policy->status) {
    cJSON *status_local_JSON = v1beta1_validating_admission_policy_status_convertToJSON(v1beta1_validating_admission_policy->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
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

v1beta1_validating_admission_policy_t *v1beta1_validating_admission_policy_parseFromJSON(cJSON *v1beta1_validating_admission_policyJSON){

    v1beta1_validating_admission_policy_t *v1beta1_validating_admission_policy_local_var = NULL;

    // define the local variable for v1beta1_validating_admission_policy->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1beta1_validating_admission_policy->spec
    v1beta1_validating_admission_policy_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1beta1_validating_admission_policy->status
    v1beta1_validating_admission_policy_status_t *status_local_nonprim = NULL;

    // v1beta1_validating_admission_policy->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policyJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_validating_admission_policy->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policyJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_validating_admission_policy->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policyJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_validating_admission_policy->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policyJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1beta1_validating_admission_policy_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1beta1_validating_admission_policy->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policyJSON, "status");
    if (status) { 
    status_local_nonprim = v1beta1_validating_admission_policy_status_parseFromJSON(status); //nonprimitive
    }


    v1beta1_validating_admission_policy_local_var = v1beta1_validating_admission_policy_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1beta1_validating_admission_policy_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1beta1_validating_admission_policy_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1beta1_validating_admission_policy_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
