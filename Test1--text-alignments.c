#include <stdio.h>
#include <conio.h>
#include <contf.h>



int main()
{
    print_center("Console Text Formatter - v0.1");
    print_center("------------------------------------------------------");
    new_line();
    printf("Hello Guys! This is a c library which provides easy functions to format your prints on the console.\n");
    printf("\nExamples\n");
    
    print_left("Left align text");
    print_right("Right align text");
    print_center("Center align text");
    print_tf("Text with right align and 40\% buffer_width", right, 40);
    // https://stackoverflow.com/questions/17556780/how-can-i-assign-value-to-the-struct-inside-union-here
    border common_b = {false, {'|'}};
    border custom_b = {true, {.custom = {'{', '}'}}};
    print_tfb("Text with common borders", left, common_b, 80);
    print_tfb("Text with custom borders", center, custom_b, 40);
    getch();
    return 0;
}