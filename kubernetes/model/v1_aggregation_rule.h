/*
 * v1_aggregation_rule.h
 *
 * AggregationRule describes how to locate ClusterRoles to aggregate into the ClusterRole
 */

#ifndef _v1_aggregation_rule_H_
#define _v1_aggregation_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_aggregation_rule_t v1_aggregation_rule_t;

#include "v1_label_selector.h"



typedef struct v1_aggregation_rule_t {
    list_t *cluster_role_selectors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_aggregation_rule_t;

__attribute__((deprecated)) v1_aggregation_rule_t *v1_aggregation_rule_create(
    list_t *cluster_role_selectors
);

void v1_aggregation_rule_free(v1_aggregation_rule_t *v1_aggregation_rule);

v1_aggregation_rule_t *v1_aggregation_rule_parseFromJSON(cJSON *v1_aggregation_ruleJSON);

cJSON *v1_aggregation_rule_convertToJSON(v1_aggregation_rule_t *v1_aggregation_rule);

#endif /* _v1_aggregation_rule_H_ */

