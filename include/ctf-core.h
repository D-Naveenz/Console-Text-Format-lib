#ifndef CTF_CORE_H /* Include guard */
#define CTF_CORE_H

//The boolean header in included by default
#ifndef _STDBOOL_H
#include <stdbool.h>
#endif // !_STDBOOL_H

#define FULL_WIDTH 100
#define BORDER_DELIM ","

// Enumeration of text alignment (left, Right, Center)
typedef enum alignment
{
    left,
    right,
    center
} align;

#pragma region functions
unsigned short get_buffer(int percentage);
char *trim(char *str);
char *strdup(const char *s);
char *strndup(const char *s, size_t n);
//Returns a string of spaces according to the alignment and buffer size
//Dynamically allocated - It should be freed memory after being used.
char *get_spaces_ptr(char *text, align align, size_t buffer_size);
#pragma endregion

#endif // !CTF_CORE_H