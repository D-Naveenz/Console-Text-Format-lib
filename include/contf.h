/*
** Console Text Formatter v0.2 (staging)
** The main header file. You should include this header into your program
** Naveen Dharmathunga - 22/07/2021
*/
#ifndef CONTF_H /* Include guard */
#define CONTF_H

//The boolean header in included by default
#ifndef _STDBOOL_H
#include <stdbool.h>
#endif // !_STDBOOL_H

#pragma region defines

// Extended ASCII letters
#define ASCII_DEGREE (char)248          //Degree symbol ( ° )
#define ASCII_PI (char)227              //pi letter ( π )
#define ASCII_BOX_UPPER_LEFT (char)218  //Box drawing character single line upper left corner ( ┌ )
#define ASCII_BOX_UPPER_RIGHT (char)191 //Box drawing character single line upper right corner ( ┐ )
#define ASCII_BOX_LOWER_LEFT (char)192  // Box drawing character single line lower left corner ( └ )
#define ASCII_BOX_LOWER_RIGHT (char)217 // Box drawing character single line lower right corner ( ┘ )
#define ASCII_BOX_LINE_H_DOWN (char)194 // Box drawing character single line horizontal down ( ┬ )
#define ASCII_BOX_LINE_H_UP (char)193   // Box drawing character single line horizontal up ( ┴ )
#define ASCII_BOX_LINE_H (char)196      // Box drawing character single horizontal line ( ─ )
#define ASCII_BOX_LINE_V (char)179      // Box drawing character single vertical line ( │ )
#define ASCII_NBSP (char)255            // Non-breaking space or no-break space

#pragma endregion

#pragma region variables_n_types

const char def_placeholder; //d efault placeholder for spaces between texts

struct custom_borders
{
    char left_end;
    char right_end;
};

union ends
{
    char common;
    struct custom_borders custom;
};

//defined variable types

typedef enum alignment
{
    left,
    right,
    center
} align;

typedef struct buffer
{
    unsigned short size;
    unsigned short percentage;
} buffer_w;

typedef struct borderdef
{
    bool is_custom;    // Should be true if the left is not equal to the right.
    union ends border; // Can assign one char or two chars if you want custom ends.
} border;

#pragma endregion

#pragma region string_functions

/*
Text align with properties
text: target string to format
align: text alignment (left, right, center)
size: formatting area of a row of the console
*/
char *console_tf(char *text, align align, buffer_w *_buffer);
char *console_tfb(char *text, align align, border ends, buffer_w *_buffer);

#pragma endregion

#pragma region printing_functions

// same as printf("\\n");
void new_line();
// Print text to the left. Similar to printf() but goes to the next line after printing the text.
void print_left(char *text);
// Print text to the right. Then goes to the next line after printing the text.
void print_right(char *text);
// Print text in center. Then goes to the next line after printing the text.
void print_center(char *text);
// Print text with desired alignment covering up with user given buffer width.
// Then goes to the next line after printing the text.
void print_tf(char *text, align align, int size);
void print_tfb(char *text, align align, border ends, int size);

#pragma endregion
#endif // !HELPER_H