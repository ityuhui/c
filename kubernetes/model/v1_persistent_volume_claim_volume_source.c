#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim_volume_source.h"



static v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_create_internal(
    char *claim_name,
    int read_only
    ) {
    v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_local_var = malloc(sizeof(v1_persistent_volume_claim_volume_source_t));
    if (!v1_persistent_volume_claim_volume_source_local_var) {
        return NULL;
    }
    v1_persistent_volume_claim_volume_source_local_var->claim_name = claim_name;
    v1_persistent_volume_claim_volume_source_local_var->read_only = read_only;

    v1_persistent_volume_claim_volume_source_local_var->_library_owned = 1;
    return v1_persistent_volume_claim_volume_source_local_var;
}

__attribute__((deprecated)) v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_create(
    char *claim_name,
    int read_only
    ) {
    return v1_persistent_volume_claim_volume_source_create_internal (
        claim_name,
        read_only
        );
}

void v1_persistent_volume_claim_volume_source_free(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source) {
    if(NULL == v1_persistent_volume_claim_volume_source){
        return ;
    }
    if(v1_persistent_volume_claim_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_persistent_volume_claim_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_claim_volume_source->claim_name) {
        free(v1_persistent_volume_claim_volume_source->claim_name);
        v1_persistent_volume_claim_volume_source->claim_name = NULL;
    }
    free(v1_persistent_volume_claim_volume_source);
}

cJSON *v1_persistent_volume_claim_volume_source_convertToJSON(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_persistent_volume_claim_volume_source->claim_name
    if (!v1_persistent_volume_claim_volume_source->claim_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "claimName", v1_persistent_volume_claim_volume_source->claim_name) == NULL) {
    goto fail; //String
    }


    // v1_persistent_volume_claim_volume_source->read_only
    if(v1_persistent_volume_claim_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_persistent_volume_claim_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_parseFromJSON(cJSON *v1_persistent_volume_claim_volume_sourceJSON){

    v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_local_var = NULL;

    // v1_persistent_volume_claim_volume_source->claim_name
    cJSON *claim_name = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_volume_sourceJSON, "claimName");
    if (cJSON_IsNull(claim_name)) {
        claim_name = NULL;
    }
    if (!claim_name) {
        goto end;
    }

    
    if(!cJSON_IsString(claim_name))
    {
    goto end; //String
    }

    // v1_persistent_volume_claim_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    v1_persistent_volume_claim_volume_source_local_var = v1_persistent_volume_claim_volume_source_create_internal (
        strdup(claim_name->valuestring),
        read_only ? read_only->valueint : 0
        );

    return v1_persistent_volume_claim_volume_source_local_var;
end:
    return NULL;

}
