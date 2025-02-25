/*
 * v1_self_subject_rules_review_spec.h
 *
 * SelfSubjectRulesReviewSpec defines the specification for SelfSubjectRulesReview.
 */

#ifndef _v1_self_subject_rules_review_spec_H_
#define _v1_self_subject_rules_review_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_self_subject_rules_review_spec_t v1_self_subject_rules_review_spec_t;




typedef struct v1_self_subject_rules_review_spec_t {
    char *_namespace; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_self_subject_rules_review_spec_t;

__attribute__((deprecated)) v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_create(
    char *_namespace
);

void v1_self_subject_rules_review_spec_free(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec);

v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_parseFromJSON(cJSON *v1_self_subject_rules_review_specJSON);

cJSON *v1_self_subject_rules_review_spec_convertToJSON(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec);

#endif /* _v1_self_subject_rules_review_spec_H_ */

