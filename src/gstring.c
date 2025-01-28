/*
 * string.c
 *
 *  Created on: January 28, 2025
 *      Author: Tyler Gregorcyk
 */

#include <gstring.h>
#include <stdlib.h>
#include <string.h>

// ================================================================================
// ===                               Documentation
// ================================================================================

// ================================================================================
// ===                                Macros
// ================================================================================

// ================================================================================
// ===                            Type Definitions
// ================================================================================

// ================================================================================
// ===                       Private Function Declarations
// ================================================================================

// ================================================================================
// ===                            Private Variables
// ================================================================================

// ================================================================================
// ===                             Public Function
// ================================================================================

/*
 * @brief allocates data on a heap for an input C str
 *
 * @param[in] C str ending with \0
 *
 * @return String with the correct data and length allocated
 * @note: Can return NULL in returned String.ch
 *
 * @note: Will add \0 to end of String.ch but its not counted in String.length
 */
String string_malloc(const char *ch) {
  String results = {NULL, 0};

  if (!ch)
    return results;

  int length = strlen(ch);

  results.ch = (uint8_t *)malloc(sizeof(uint8_t) * (length + 1));

  // NOTE: Since we are keeping the \0 for our Strings this will always be true
  // due to us needing to malloc (length +1) for the null terminator
  if (!results.ch)
    return results;

  // NOTE: Still not sure if I want the C str terminator or not in my Strings.
  // It is nice when looking at the String in a debugger...
  // Might want to add an option for it???
  memcpy(results.ch, ch, length + 1);
  results.length = length;

  return results;
}

// ================================================================================
// ===                            Private Function
// ================================================================================
