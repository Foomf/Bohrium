#include "boh_except.h"

#include <stdio.h>
#include <string.h>

#define min(x, y) (x < y ? x : y)

void boh_throw_except(CEXCEPTION_T id, char* file, int line_num, char* msg) {
    boh_error_line_number = line_num;
    strncpy(boh_error_file, file, boh_filename_buffer_size - 1);
    strncpy(boh_error_message, msg, boh_error_buffer_size - 1);
    boh_last_error_id = id;
}

void boh_except_reset(void) {
    boh_error_line_number = 0;
    boh_error_file[0] = '\0';
    boh_error_message[0] = '\0';
    boh_last_error_id = 0;
}