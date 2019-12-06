#include "guid.h"

#include <string.h>

#include "boh_except.h"

#ifdef _WIN32

void make_guid(BOH_GUID* guid) {
    if (CoCreateGuid(guid) != S_OK) {
        boh_throw(BOH_ERR_UNKNOWN);
    }
}

sds guid_to_string(BOH_GUID* self) {
    // Use windows api to generate guid string
    OLECHAR* str;
    if (StringFromCLSID(self, &str) != S_OK) {
        boh_throw(BOH_ERR_OUT_OF_MEMORY);
    }

    // Copy string to buffer, then delete the string
    // allocated by windows. The str pointer is offset
    // by 1 because the windows string function adds {}
    // characters around the guid string.
    char buff[GUID_STRING_LEN];
    wcstombs(buff, str + 1, sizeof(buff));
    CoTaskMemFree(str);

    // Copy buffer to sds managed string and return.
    return sdsnewlen(buff, sizeof(buff));
}

#endif