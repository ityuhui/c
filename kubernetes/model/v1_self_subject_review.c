#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_review.h"



v1_self_subject_review_t *v1_self_subject_review_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_self_subject_review_status_t *status
    ) {
    v1_self_subject_review_t *v1_self_subject_review_local_var = malloc(sizeof(v1_self_subject_review_t));
    if (!v1_self_subject_review_local_var) {
        return NULL;
    }
    v1_self_subject_review_local_var->api_version = api_version;
    v1_self_subject_review_local_var->kind = kind;
    v1_self_subject_review_local_var->metadata = metadata;
    v1_self_subject_review_local_var->status = status;

    return v1_self_subject_review_local_var;
}


void v1_self_subject_review_free(v1_self_subject_review_t *v1_self_subject_review) {
    if(NULL == v1_self_subject_review){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_self_subject_review->api_version) {
        free(v1_self_subject_review->api_version);
        v1_self_subject_review->api_version = NULL;
    }
    if (v1_self_subject_review->kind) {
        free(v1_self_subject_review->kind);
        v1_self_subject_review->kind = NULL;
    }
    if (v1_self_subject_review->metadata) {
        v1_object_meta_free(v1_self_subject_review->metadata);
        v1_self_subject_review->metadata = NULL;
    }
    if (v1_self_subject_review->status) {
        v1_self_subject_review_status_free(v1_self_subject_review->status);
        v1_self_subject_review->status = NULL;
    }
    free(v1_self_subject_review);
}

cJSON *v1_self_subject_review_convertToJSON(v1_self_subject_review_t *v1_self_subject_review) {
    cJSON *item = cJSON_CreateObject();

    // v1_self_subject_review->api_version
    if(v1_self_subject_review->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_self_subject_review->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_self_subject_review->kind
    if(v1_self_subject_review->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_self_subject_review->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_self_subject_review->metadata
    if(v1_self_subject_review->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_self_subject_review->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_self_subject_review->status
    if(v1_self_subject_review->status) {
    cJSON *status_local_JSON = v1_self_subject_review_status_convertToJSON(v1_self_subject_review->status);
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

v1_self_subject_review_t *v1_self_subject_review_parseFromJSON(cJSON *v1_self_subject_reviewJSON){

    v1_self_subject_review_t *v1_self_subject_review_local_var = NULL;

    // define the local variable for v1_self_subject_review->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_self_subject_review->status
    v1_self_subject_review_status_t *status_local_nonprim = NULL;

    // v1_self_subject_review->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_self_subject_reviewJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_self_subject_review->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_self_subject_reviewJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_self_subject_review->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_self_subject_reviewJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_self_subject_review->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_self_subject_reviewJSON, "status");
    if (status) { 
    status_local_nonprim = v1_self_subject_review_status_parseFromJSON(status); //nonprimitive
    }


    v1_self_subject_review_local_var = v1_self_subject_review_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_self_subject_review_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_self_subject_review_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
