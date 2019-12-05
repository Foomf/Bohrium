#include "guid.h"

#include <string.h>

#include "boh_except.h"

#ifdef _WIN32

void make_guid(BOH_GUID* guid) {
    if (CoCreateGuid(guid) != S_OK) {
        boh_throw(BOH_ERR_UNKNOWN);
    }
}

wchar_t* guid_to_string(BOH_GUID* self) {
    OLECHAR* str;
    if (StringFromCLSID(self, &str) != S_OK) {
        boh_throw(BOH_ERR_OUT_OF_MEMORY);
    }
    size_t len = wcslen(str);
    wchar_t* out = calloc(1, sizeof(wchar_t) * (len + 1));
    wcsncpy(out, str, len);
    CoTaskMemFree(str);
    return out;
}

#endif