/*
** Console Text Format lib v1.0
** The main header file. Include this header into your program
** Naveen Dharmathunga - 31/07/2021
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

#pragma region variables
const char def_placeholder; // default placeholder for spaces between texts
#pragma endregion

#pragma region string functions
/*
Aligns text with given properties and border and returns the string
Parameters:
text: target string to format
align: text alignment (left, right, center)
ends: dorder definition
_buffer: Buffer width
*/
// char *console_tfb(char *text, align align, border ends, buffer_w *_buffer);  // deprecated
char *textLeft(int _buffer, char *text);
char *textRight(int _buffer, char *text);
char *textCenter(int _buffer, char *text);

/*
Generates a line and returns the string
Parameters:
placeholder: drawing element for the line. ex: if placeholder is ─, then line will be ─────
_buffer: Buffer width
*/
char *genln(int width, char *ends, char placeholder);
#pragma endregion

#pragma region print text
/*
Print text with given alignment and buffer width.
text: target string to format
align: text alignment (left, right, center)
size: Buffer width as a percentage
*/
void printFText(char *(*align)(int _buffer, char *text), int width, char *ends, int next_ln, char *text);
#pragma endregion

#pragma region print a row with text
// same as printf("\\n");
void new_line(void);
// Print text to the left. Similar to printf() but goes to the next line after printing the text.
void println(char *text);
// Print text to the right. Then goes to the next line after printing the text.
void printlnR(char *text);
// Print text in center. Then goes to the next line after printing the text.
void printlnC(char *text);
/*
Print text with given alignment and buffer width. Goes to the next line after printing.
text: target string to format
align: text alignment (left, right, center)
size: Buffer width as a percentage
*/
void println_a(char *(*align)(int _buffer, char *text), int width, char *text);
/*
Print text with given alignment and buffer width with a border. Goes to the next line after printing.
text: target string to format
align: text alignment (left, right, center)
ends: dorder definition
size: Buffer width as a percentage
*/
void println_ab(char *(*align)(int _buffer, char *text), int width, char *ends, char *text);
#pragma endregion

#pragma region print a line
/*
Draw (print) a line.
Parameters:
placeholder: drawing element for the line. ex: if placeholder is ─, then line will be ─────
_buffer: Buffer width
*/
void drawln(char *ends, int width, int next_ln, char placeholder);
#pragma endregion

#pragma region print a row with a line
// print a row with straight line
void separator(void);
// print a row with a given placeholder
void separator_c(char placeholder);
#pragma endregion

#endif // !HELPER_H