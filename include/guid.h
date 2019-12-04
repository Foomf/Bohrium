#pragma once

#include <wchar.h>

#ifdef _WIN32
#include <objbase.h>
typedef GUID BOH_GUID;
#endif

void make_guid(BOH_GUID* guid);

wchar_t* guid_to_string(BOH_GUID* self);
