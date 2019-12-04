#include "guid.h"

#include <string.h>

#ifdef _WIN32

void make_guid(BOH_GUID* guid) {
    CoCreateGuid(guid);
}

wchar_t* guid_to_string(BOH_GUID* self) {
    OLECHAR* str;
    StringFromCLSID(self, &str);
    size_t len = wcslen(str);
    wchar_t* out = calloc(1, sizeof(wchar_t) * (len + 1));
    wcsncpy(out, str, len);
    CoTaskMemFree(str);
    return out;
}

#endif