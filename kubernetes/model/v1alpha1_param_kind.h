/*
 * v1alpha1_param_kind.h
 *
 * ParamKind is a tuple of Group Kind and Version.
 */

#ifndef _v1alpha1_param_kind_H_
#define _v1alpha1_param_kind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_param_kind_t v1alpha1_param_kind_t;




typedef struct v1alpha1_param_kind_t {
    char *api_version; // string
    char *kind; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_param_kind_t;

__attribute__((deprecated)) v1alpha1_param_kind_t *v1alpha1_param_kind_create(
    char *api_version,
    char *kind
);

void v1alpha1_param_kind_free(v1alpha1_param_kind_t *v1alpha1_param_kind);

v1alpha1_param_kind_t *v1alpha1_param_kind_parseFromJSON(cJSON *v1alpha1_param_kindJSON);

cJSON *v1alpha1_param_kind_convertToJSON(v1alpha1_param_kind_t *v1alpha1_param_kind);

#endif /* _v1alpha1_param_kind_H_ */

