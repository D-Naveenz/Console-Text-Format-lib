#ifndef CTF_CORE_H   /* Include guard */
#define CTF_CORE_H

//The boolean header in included by default
#ifndef _STDBOOL_H
#include <stdbool.h>
#endif // !_STDBOOL_H

#ifndef CTF_VARS_H
#include <ctf-vars.h>
#endif // !CTF_VARS_H

buffer_w full_width;

#pragma region functions
unsigned short get_window_buffer_width();
buffer_w *validate_buffer(buffer_w *_buffer);
//Returns a string of spaces according to the alignment and buffer size
//Dynamically allocated - It should be freed memory after being used.
char *get_spaces_ptr(char *text, align align, size_t buffer_size);
bool is_custom_border(border target);
#pragma endregion

#endif // !CTF_CORE_H