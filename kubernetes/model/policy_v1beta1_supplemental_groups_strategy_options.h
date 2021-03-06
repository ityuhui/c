/*
 * policy_v1beta1_supplemental_groups_strategy_options.h
 *
 * SupplementalGroupsStrategyOptions defines the strategy type and options used to create the strategy.
 */

#ifndef _policy_v1beta1_supplemental_groups_strategy_options_H_
#define _policy_v1beta1_supplemental_groups_strategy_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct policy_v1beta1_supplemental_groups_strategy_options_t policy_v1beta1_supplemental_groups_strategy_options_t;

#include "policy_v1beta1_id_range.h"



typedef struct policy_v1beta1_supplemental_groups_strategy_options_t {
    list_t *ranges; //nonprimitive container
    char *rule; // string

} policy_v1beta1_supplemental_groups_strategy_options_t;

policy_v1beta1_supplemental_groups_strategy_options_t *policy_v1beta1_supplemental_groups_strategy_options_create(
    list_t *ranges,
    char *rule
);

void policy_v1beta1_supplemental_groups_strategy_options_free(policy_v1beta1_supplemental_groups_strategy_options_t *policy_v1beta1_supplemental_groups_strategy_options);

policy_v1beta1_supplemental_groups_strategy_options_t *policy_v1beta1_supplemental_groups_strategy_options_parseFromJSON(cJSON *policy_v1beta1_supplemental_groups_strategy_optionsJSON);

cJSON *policy_v1beta1_supplemental_groups_strategy_options_convertToJSON(policy_v1beta1_supplemental_groups_strategy_options_t *policy_v1beta1_supplemental_groups_strategy_options);

#endif /* _policy_v1beta1_supplemental_groups_strategy_options_H_ */

