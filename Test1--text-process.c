#include <stdio.h>
#include <conio.h>
#include <contf.h>



int main()
{
    println_c("Console Text Formatter - v0.1");
    println_c("------------------------------------------------------");
    new_line();
    printf("Hello Guys! This is a c library which provides easy functions to format your prints on the console.\n");
    printf("\nExamples\n");
    
    println_l("Left align text");
    println_r("Right align text");
    println_c("Center align text");
    println_tf("Text with right align and 40\% buffer_width", right, 40);
    // https://stackoverflow.com/questions/17556780/how-can-i-assign-value-to-the-struct-inside-union-here
    border common_b = {'|'};
    border custom_b = {.custom = {'{', '}'}};
    println_tfb("Text with common borders", left, common_b, 80);
    println_tfb("Text with custom borders", center, custom_b, 40);
    getch();
    return 0;
}