/* Generated file - do not edit. */

#include <stddef.h>
#include "sys_ro_vars.h"

const struct mgos_conf_entry sys_ro_vars_schema_[6] = {
  {.type = CONF_TYPE_OBJECT, .key = "", .num_desc = 5},
  {.type = CONF_TYPE_STRING, .key = "mac_address", .offset = offsetof(struct sys_ro_vars, mac_address)},
  {.type = CONF_TYPE_STRING, .key = "arch", .offset = offsetof(struct sys_ro_vars, arch)},
  {.type = CONF_TYPE_STRING, .key = "fw_version", .offset = offsetof(struct sys_ro_vars, fw_version)},
  {.type = CONF_TYPE_STRING, .key = "fw_timestamp", .offset = offsetof(struct sys_ro_vars, fw_timestamp)},
  {.type = CONF_TYPE_STRING, .key = "fw_id", .offset = offsetof(struct sys_ro_vars, fw_id)},
};

const struct mgos_conf_entry *sys_ro_vars_schema() {
  return sys_ro_vars_schema_;
}
