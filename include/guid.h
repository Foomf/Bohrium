#pragma once

#include "sds.h"

#define GUID_STRING_LEN 36

#ifdef _WIN32
#include <objbase.h>
typedef GUID BOH_GUID;
#endif

void make_guid(BOH_GUID* guid);

sds guid_to_string(BOH_GUID* self);
