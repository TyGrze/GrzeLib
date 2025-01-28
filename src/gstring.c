/*
 * string.c
 *
 *  Created on: January 28, 2025
 *      Author: Tyler Gregorcyk
 */

#include <stdint.h>
#include <stdlib.h>
#include <gstring.h>
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
 * @breif allocats data on a heap for an inputed C str
 *
 * @para[in] C str ending with /0
 *
 * @return String with the correct data and length allocated
 *
 * @note: Can return NULL in returned String.char
 * @note: Will add \0 to end of String.ch but its not counted in String.length
 */
String string_malloc(const char *ch) {
  String results = {NULL, 0};

  if (!ch)
    return results;

  int length = 0;

  while (ch[length] != '\0') {
    length++;
  }

  results.ch = (uint8_t *)malloc(sizeof(uint8_t) * length);
  if (!results.ch)
    return results;

  // NOTE: Still not sure if I want the C str terminator or not in my Strings.
  // It is nice when looking at the String in a debugger...
  // Might want to add an option for it???
  memcpy(results.ch, ch, length + 1);
  results.ch[length] = '\0';
  results.length = length;

  return results;
}

// ================================================================================
// ===                            Private Function
// ================================================================================
