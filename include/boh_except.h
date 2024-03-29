#pragma once

#include "cexception.h"

#define boh_error_buffer_size 512
#define boh_filename_buffer_size 128
#define boh_complete_message_size boh_error_buffer_size + boh_filename_buffer_size + 32

char boh_error_message[boh_error_buffer_size];
char boh_error_file[boh_filename_buffer_size];
int boh_error_line_number;
CEXCEPTION_T boh_last_error_id;
char boh_full_message[boh_complete_message_size];

#define boh_throw(e) do { boh_throw_except(e, __FILE__, __LINE__, ""); } while (0)

#define boh_throwmsg(e, m) do { boh_throw_except(e, __FILE__, __LINE__, m); } while (0)

void boh_throw_except(CEXCEPTION_T id, char* file, int line_num, char* msg);

void boh_except_reset(void);

enum ExceptionType {
    BOH_ERR_NONE = 0,
    BOH_ERR_UNKNOWN = 1,
    BOH_ERR_OUT_OF_MEMORY = 2
};
