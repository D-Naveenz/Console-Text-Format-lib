/*
** Console Text Formatter v0.2 (staging)
** The main header file. You should include this header into your program
** Naveen Dharmathunga - 22/07/2021
*/
#ifndef CONTF_H /* Include guard */
#define CONTF_H

#pragma region defines
// Extended ASCII letters
#define ASCII_DEGREE (char)248          // Degree symbol ( ° )
#define ASCII_PI (char)227              // pi letter ( π )
#define ASCII_BOX_UPPER_LEFT (char)218  // Box drawing character single line upper left corner ( ┌ )
#define ASCII_BOX_UPPER_RIGHT (char)191 // Box drawing character single line upper right corner ( ┐ )
#define ASCII_BOX_LOWER_LEFT (char)192  // Box drawing character single line lower left corner ( └ )
#define ASCII_BOX_LOWER_RIGHT (char)217 // Box drawing character single line lower right corner ( ┘ )
#define ASCII_BOX_LINE_H_DOWN (char)194 // Box drawing character single line horizontal down ( ┬ )
#define ASCII_BOX_LINE_H_UP (char)193   // Box drawing character single line horizontal up ( ┴ )
#define ASCII_BOX_LINE_H (char)196      // Box drawing character single horizontal line ( ─ )
#define ASCII_BOX_LINE_V (char)179      // Box drawing character single vertical line ( │ )
#define ASCII_NBSP (char)255            // Non-breaking space or no-break space
#pragma endregion

#ifndef CTF_VARS_H
#include <ctf-vars.h>
#endif // !CTF_VARS_H

#pragma region string_functions
/*
Text align with properties
text: target string to format
align: text alignment (left, right, center)
size: formatting area of a row of the console
*/
char *console_tf(char *text, align align, buffer_w *_buffer);
char *console_tfb(char *text, align align, border ends, buffer_w *_buffer);
char *genln(char placeholder, buffer_w *_buffer);
char *genlne(char placeholder, border ends, buffer_w *_buffer);
#pragma endregion

#pragma region text_prints
// Print text with desired alignment covering up with user given buffer width.
// Then goes to the next line after printing the text.
void print_tf(char *text, align align, int size);
void print_tfb(char *text, align align, border ends, int size);
#pragma endregion

#pragma region text_print_lines
// same as printf("\\n");
void new_line(void);
// Print text to the left. Similar to printf() but goes to the next line after printing the text.
void println_l(char *text);
// Print text to the right. Then goes to the next line after printing the text.
void println_r(char *text);
// Print text in center. Then goes to the next line after printing the text.
void println_c(char *text);
// Print text with desired alignment covering up with user given buffer width.
// Then goes to the next line after printing the text.
void println_tf(char *text, align align, int size);
void println_tfb(char *text, align align, border ends, int size);
#pragma endregion

#pragma region line_prints
void drawln(char placeholder, int size);
void drawlne(char placeholder, border ends, int size);
#pragma endregion

#pragma region line_print_lines
void separator(void);
void separator_c(char placeholder);
#pragma endregion

#endif // !HELPER_H