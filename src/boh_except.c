#include "boh_except.h"

#include <stdio.h>
#include <string.h>

#include "zf_log.h"

void boh_throw_except(CEXCEPTION_T id, char* file, int line_num, char* msg) {
    boh_error_line_number = line_num;
    strncpy(boh_error_file, file, boh_filename_buffer_size);
    strncpy(boh_error_message, msg, boh_error_buffer_size);
    boh_last_error_id = id;

    ZF_LOGI("Message: %s", msg);

    snprintf(
        boh_full_message,
        boh_complete_message_size,
        "ERROR at %s:%d: %s (%d)",
        boh_error_file,
        boh_error_line_number,
        boh_error_message,
        boh_last_error_id);

    Throw(id);
}

void boh_except_reset(void) {
    boh_error_line_number = 0;
    boh_error_file[0] = '\0';
    boh_error_message[0] = '\0';
    boh_last_error_id = 0;
    boh_full_message[0] = '\0';
}