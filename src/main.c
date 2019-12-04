#include <stdio.h>
#include <stdlib.h>

#include "plugin.h"

int main(void) {
    plugin p;
    plugin_init(&p);
    wchar_t* s = guid_to_string(&p.plugin_id);
    wprintf(L"Generated guid: %ls\n", s);
    free(s);
    return EXIT_SUCCESS;
}