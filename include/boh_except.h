#pragma once

#include "cexception.h"

#define boh_error_buffer_size 512
#define boh_filename_buffer_size 128

char boh_error_message[boh_error_buffer_size];
char boh_error_file[boh_filename_buffer_size];
int boh_error_line_number;
CEXCEPTION_T boh_last_error_id;

#define boh_throw(e) do { boh_throw_except(e, __FILE__, __LINE__, ""); } while (0)

#define boh_throwmsg(e, m) do { boh_throw_except(e, __FILE__, __LINE__, m); } while (0)

void boh_throw_except(CEXCEPTION_T id, char* file, int line_num, char* msg);

void boh_except_reset(void);
