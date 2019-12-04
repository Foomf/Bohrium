#include "plugin.h"

void plugin_init(plugin* p) {
    make_guid(&p->plugin_id);
}