#include "plugin_loader.h"

#include "cute_files.h"

void list_plugins(void) {
    cf_dir_t dir;
    cf_dir_open(&dir, "plugins");

    while (dir.has_next)
    {
        cf_file_t file;
        cf_read_file(&dir, &file);
        printf("%s\n", file.name);
        cf_dir_next(&dir);
    }

    cf_dir_close(&dir);
}