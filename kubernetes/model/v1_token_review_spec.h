/*
 * v1_token_review_spec.h
 *
 * TokenReviewSpec is a description of the token authentication request.
 */

#ifndef _v1_token_review_spec_H_
#define _v1_token_review_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_token_review_spec_t v1_token_review_spec_t;




typedef struct v1_token_review_spec_t {
    list_t *audiences; //primitive container
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_token_review_spec_t;

__attribute__((deprecated)) v1_token_review_spec_t *v1_token_review_spec_create(
    list_t *audiences,
    char *token
);

void v1_token_review_spec_free(v1_token_review_spec_t *v1_token_review_spec);

v1_token_review_spec_t *v1_token_review_spec_parseFromJSON(cJSON *v1_token_review_specJSON);

cJSON *v1_token_review_spec_convertToJSON(v1_token_review_spec_t *v1_token_review_spec);

#endif /* _v1_token_review_spec_H_ */

