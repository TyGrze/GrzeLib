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

/*
 * @brief Compares two Strings
 *
 * @param[in] s1, to compare with s2
 * @param[in] s2, to compare with s1
 *
 * @return 0 if the two Strings are equivalent, else -1
 */
int string_cmp(String *s1, String *s2) {
  if (!s1 || !s2)
    return -1;
  if (!s1->ch || !s2->ch)
    return -1;
  if (s1->length != s2->length)
    return -1;

  for (int i = 0; i < s1->length; i++) {
    if (s1->ch[i] != s2->ch[i])
      return -1;
  }

  return 0;
}
// ================================================================================
// ===                            Private Function
// ================================================================================
