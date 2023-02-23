#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_validating_admission_policy_binding.h"



v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_validating_admission_policy_binding_spec_t *spec
    ) {
    v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding_local_var = malloc(sizeof(v1alpha1_validating_admission_policy_binding_t));
    if (!v1alpha1_validating_admission_policy_binding_local_var) {
        return NULL;
    }
    v1alpha1_validating_admission_policy_binding_local_var->api_version = api_version;
    v1alpha1_validating_admission_policy_binding_local_var->kind = kind;
    v1alpha1_validating_admission_policy_binding_local_var->metadata = metadata;
    v1alpha1_validating_admission_policy_binding_local_var->spec = spec;

    return v1alpha1_validating_admission_policy_binding_local_var;
}


void v1alpha1_validating_admission_policy_binding_free(v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding) {
    if(NULL == v1alpha1_validating_admission_policy_binding){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_validating_admission_policy_binding->api_version) {
        free(v1alpha1_validating_admission_policy_binding->api_version);
        v1alpha1_validating_admission_policy_binding->api_version = NULL;
    }
    if (v1alpha1_validating_admission_policy_binding->kind) {
        free(v1alpha1_validating_admission_policy_binding->kind);
        v1alpha1_validating_admission_policy_binding->kind = NULL;
    }
    if (v1alpha1_validating_admission_policy_binding->metadata) {
        v1_object_meta_free(v1alpha1_validating_admission_policy_binding->metadata);
        v1alpha1_validating_admission_policy_binding->metadata = NULL;
    }
    if (v1alpha1_validating_admission_policy_binding->spec) {
        v1alpha1_validating_admission_policy_binding_spec_free(v1alpha1_validating_admission_policy_binding->spec);
        v1alpha1_validating_admission_policy_binding->spec = NULL;
    }
    free(v1alpha1_validating_admission_policy_binding);
}

cJSON *v1alpha1_validating_admission_policy_binding_convertToJSON(v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_validating_admission_policy_binding->api_version
    if(v1alpha1_validating_admission_policy_binding->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_validating_admission_policy_binding->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_validating_admission_policy_binding->kind
    if(v1alpha1_validating_admission_policy_binding->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_validating_admission_policy_binding->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_validating_admission_policy_binding->metadata
    if(v1alpha1_validating_admission_policy_binding->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_validating_admission_policy_binding->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_validating_admission_policy_binding->spec
    if(v1alpha1_validating_admission_policy_binding->spec) {
    cJSON *spec_local_JSON = v1alpha1_validating_admission_policy_binding_spec_convertToJSON(v1alpha1_validating_admission_policy_binding->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding_parseFromJSON(cJSON *v1alpha1_validating_admission_policy_bindingJSON){

    v1alpha1_validating_admission_policy_binding_t *v1alpha1_validating_admission_policy_binding_local_var = NULL;

    // define the local variable for v1alpha1_validating_admission_policy_binding->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha1_validating_admission_policy_binding->spec
    v1alpha1_validating_admission_policy_binding_spec_t *spec_local_nonprim = NULL;

    // v1alpha1_validating_admission_policy_binding->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_bindingJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_validating_admission_policy_binding->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_bindingJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_validating_admission_policy_binding->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_bindingJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_validating_admission_policy_binding->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_bindingJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1alpha1_validating_admission_policy_binding_spec_parseFromJSON(spec); //nonprimitive
    }


    v1alpha1_validating_admission_policy_binding_local_var = v1alpha1_validating_admission_policy_binding_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1alpha1_validating_admission_policy_binding_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha1_validating_admission_policy_binding_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
