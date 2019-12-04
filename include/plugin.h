#pragma once

#include "guid.h"

typedef struct plugin_t {
    BOH_GUID plugin_id;
} plugin;

void plugin_init(plugin* p);
