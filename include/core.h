#ifndef _CORE_H   /* Include guard */
#define _CORE_H

#ifndef CONTF_H
#include <contf.h>
#endif // !CONTF_H

#pragma region functions
unsigned short get_window_buffer_width();
unsigned short gen_target_buffer(buffer *_buffer);
//Returns a string of spaces according to the alignment and buffer size
//Dynamically allocated - It should be freed memory after being used.
char *get_spaces_ptr(char *text, alignment align, size_t buffer_size);
#pragma endregion

#endif // !_CORE_H