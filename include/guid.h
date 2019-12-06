#pragma once

#include "sds.h"

#define GUID_STRING_LEN 36

#ifdef _WIN32
#include <objbase.h>
typedef GUID BOH_GUID;
#endif

/**
 * @brief Generates a guid.
 * 
 * @param guid The guid to create.
 */
void make_guid(BOH_GUID* guid);

/**
 * @brief Converts a guid to a string.
 * 
 * @param self The guid to convert to string.
 * @return sds The string representing the guid. Ownership is passed
 *             to the caller, who must call sdsfree().
 */
sds guid_to_string(BOH_GUID* self);
