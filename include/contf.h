/*
** Console Text Formatter v1.0
** Naveen Dharmathunga - 22/07/2021
*/
#ifndef CONTF_H   /* Include guard */
#define CONTF_H


#pragma region defines

//Extended ASCII letters
#define ASCII_DEGREE			(char)248	//Degree symbol '°'
#define ASCII_PI				(char)227	//pi letter 'π'
#define ASCII_BOX_UPPER_LEFT	(char)218	//Box drawing character single line upper left corner '┌'
#define ASCII_BOX_UPPER_RIGHT	(char)191	//Box drawing character single line upper right corner '┐'
#define ASCII_BOX_LOWER_LEFT	(char)192	//Box drawing character single line lower left corner '└'
#define ASCII_BOX_LOWER_RIGHT	(char)217	//Box drawing character single line lower right corner '┘'
#define ASCII_BOX_LINE_H_DOWN	(char)194	//Box drawing character single line horizontal down '┬'
#define ASCII_BOX_LINE_H_UP		(char)193	//Box drawing character single line horizontal up '┴'
#define ASCII_BOX_LINE_H		(char)196	//Box drawing character single horizontal line '─'
#define ASCII_BOX_LINE_V		(char)179	//Box drawing character single vertical line '│'
#define ASCII_NBSP				(char)255	//Non-breaking space or no-break space

#pragma endregion


#pragma region variables_n_types

const char def_placeholder;       //default placeholder for spaces between texts

typedef enum
{
    left, right, center
} alignment;

typedef struct
{
    unsigned short size;
    unsigned short percentage;
} buffer;

#pragma endregion


#pragma region string_functions

//Text align: left
char *console_left(char *text, buffer *_buffer);
//Text align: Right
char *console_right(char *text, buffer *_buffer);
//Text align: Center
char *console_center(char *text, buffer *_buffer);
/*
Text align with properties
text: target string to format
align: text alignment (left, right, center)
size: formatting area of a row of the console
*/
char *console_tf(char *text, alignment align, buffer _buffer);

#pragma endregion


#pragma region printing_functions

//same as printf("\\n");
void new_line();
void print_left(char *text);  
void print_right(char *text);
void print_center(char *text);
void print_tf(char *text, alignment align, int size);

#pragma endregion
#endif // !HELPER_H