#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota.h"



static v1_resource_quota_t *v1_resource_quota_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_resource_quota_spec_t *spec,
    v1_resource_quota_status_t *status
    ) {
    v1_resource_quota_t *v1_resource_quota_local_var = malloc(sizeof(v1_resource_quota_t));
    if (!v1_resource_quota_local_var) {
        return NULL;
    }
    v1_resource_quota_local_var->api_version = api_version;
    v1_resource_quota_local_var->kind = kind;
    v1_resource_quota_local_var->metadata = metadata;
    v1_resource_quota_local_var->spec = spec;
    v1_resource_quota_local_var->status = status;

    v1_resource_quota_local_var->_library_owned = 1;
    return v1_resource_quota_local_var;
}

__attribute__((deprecated)) v1_resource_quota_t *v1_resource_quota_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_resource_quota_spec_t *spec,
    v1_resource_quota_status_t *status
    ) {
    return v1_resource_quota_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void v1_resource_quota_free(v1_resource_quota_t *v1_resource_quota) {
    if(NULL == v1_resource_quota){
        return ;
    }
    if(v1_resource_quota->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_quota_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_quota->api_version) {
        free(v1_resource_quota->api_version);
        v1_resource_quota->api_version = NULL;
    }
    if (v1_resource_quota->kind) {
        free(v1_resource_quota->kind);
        v1_resource_quota->kind = NULL;
    }
    if (v1_resource_quota->metadata) {
        v1_object_meta_free(v1_resource_quota->metadata);
        v1_resource_quota->metadata = NULL;
    }
    if (v1_resource_quota->spec) {
        v1_resource_quota_spec_free(v1_resource_quota->spec);
        v1_resource_quota->spec = NULL;
    }
    if (v1_resource_quota->status) {
        v1_resource_quota_status_free(v1_resource_quota->status);
        v1_resource_quota->status = NULL;
    }
    free(v1_resource_quota);
}

cJSON *v1_resource_quota_convertToJSON(v1_resource_quota_t *v1_resource_quota) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_quota->api_version
    if(v1_resource_quota->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_resource_quota->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_quota->kind
    if(v1_resource_quota->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_resource_quota->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_quota->metadata
    if(v1_resource_quota->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_resource_quota->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_quota->spec
    if(v1_resource_quota->spec) {
    cJSON *spec_local_JSON = v1_resource_quota_spec_convertToJSON(v1_resource_quota->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_quota->status
    if(v1_resource_quota->status) {
    cJSON *status_local_JSON = v1_resource_quota_status_convertToJSON(v1_resource_quota->status);
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

v1_resource_quota_t *v1_resource_quota_parseFromJSON(cJSON *v1_resource_quotaJSON){

    v1_resource_quota_t *v1_resource_quota_local_var = NULL;

    // define the local variable for v1_resource_quota->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_resource_quota->spec
    v1_resource_quota_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_resource_quota->status
    v1_resource_quota_status_t *status_local_nonprim = NULL;

    // v1_resource_quota->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_resource_quota->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_resource_quota->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_resource_quota->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_resource_quota_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_resource_quota->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_resource_quota_status_parseFromJSON(status); //nonprimitive
    }


    v1_resource_quota_local_var = v1_resource_quota_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_resource_quota_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_resource_quota_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_resource_quota_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
