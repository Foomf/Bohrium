#include <stdio.h>
#include <stdlib.h>

#include "plugin.h"
#include "boh_except.h"

#include "cexception.h"

#include "zip.h"

void feef(void) {
    //Throw (10);
}

void err(void) {
    feef();
    printf("Meem\n");
}

int main(void) {
    boh_except_reset();

    // CEXCEPTION_T e;
    // Try {
    //     err();
    // } Catch (e) {
    //     printf("Caught %i\n", e);
    // }

    boh_throw(10);

    // struct zip_t* zip = zip_open("Boostnote.zip", 0, 'r');
    // int entry_count = zip_total_entries(zip);
    // printf("Read %d entries in zip.", entry_count);

    // for (int i = 0; i < entry_count; ++i) {
    //     zip_entry_openbyindex(zip, i);
    //     const char *name = zip_entry_name(zip);
    //     printf("Read file: %s\n", name);
    // }
    // zip_entry_close(zip);

    // zip_close(zip);

    // plugin p;
    // plugin_init(&p);
    // wchar_t* s = guid_to_string(&p.plugin_id);
    // wprintf(L"Generated guid: %ls\n", s);
    // free(s);

    return EXIT_SUCCESS;
}