#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_range.h"



static v1_limit_range_t *v1_limit_range_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_limit_range_spec_t *spec
    ) {
    v1_limit_range_t *v1_limit_range_local_var = malloc(sizeof(v1_limit_range_t));
    if (!v1_limit_range_local_var) {
        return NULL;
    }
    v1_limit_range_local_var->api_version = api_version;
    v1_limit_range_local_var->kind = kind;
    v1_limit_range_local_var->metadata = metadata;
    v1_limit_range_local_var->spec = spec;

    v1_limit_range_local_var->_library_owned = 1;
    return v1_limit_range_local_var;
}

__attribute__((deprecated)) v1_limit_range_t *v1_limit_range_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_limit_range_spec_t *spec
    ) {
    return v1_limit_range_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
}

void v1_limit_range_free(v1_limit_range_t *v1_limit_range) {
    if(NULL == v1_limit_range){
        return ;
    }
    if(v1_limit_range->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_limit_range_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limit_range->api_version) {
        free(v1_limit_range->api_version);
        v1_limit_range->api_version = NULL;
    }
    if (v1_limit_range->kind) {
        free(v1_limit_range->kind);
        v1_limit_range->kind = NULL;
    }
    if (v1_limit_range->metadata) {
        v1_object_meta_free(v1_limit_range->metadata);
        v1_limit_range->metadata = NULL;
    }
    if (v1_limit_range->spec) {
        v1_limit_range_spec_free(v1_limit_range->spec);
        v1_limit_range->spec = NULL;
    }
    free(v1_limit_range);
}

cJSON *v1_limit_range_convertToJSON(v1_limit_range_t *v1_limit_range) {
    cJSON *item = cJSON_CreateObject();

    // v1_limit_range->api_version
    if(v1_limit_range->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_limit_range->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_limit_range->kind
    if(v1_limit_range->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_limit_range->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_limit_range->metadata
    if(v1_limit_range->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_limit_range->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_limit_range->spec
    if(v1_limit_range->spec) {
    cJSON *spec_local_JSON = v1_limit_range_spec_convertToJSON(v1_limit_range->spec);
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

v1_limit_range_t *v1_limit_range_parseFromJSON(cJSON *v1_limit_rangeJSON){

    v1_limit_range_t *v1_limit_range_local_var = NULL;

    // define the local variable for v1_limit_range->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_limit_range->spec
    v1_limit_range_spec_t *spec_local_nonprim = NULL;

    // v1_limit_range->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_limit_range->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_limit_range->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_limit_range->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_limit_range_spec_parseFromJSON(spec); //nonprimitive
    }


    v1_limit_range_local_var = v1_limit_range_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1_limit_range_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_limit_range_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
