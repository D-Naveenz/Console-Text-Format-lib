#include <stdio.h>
#include <conio.h>
#include <contf.h>



int main()
{
    buffer_w b_width = {0, 60};
    println_c("Console Text Formatter - v0.1");
    separator();
    new_line();
    printf("Hello Guys! This is a c library which provides easy functions to format your prints on the console.\n");
    printf("\nExamples\n");
    
    printf("Separator:\n");
    separator();
    printf("Separator with custom placeholder:\n");
    separator_c(ASCII_BOX_LINE_V);
    printf("Draw a line with user given buffer size and aligned to the right:\n");
    println_r(genln(ASCII_DEGREE, &b_width));
    printf("Draw a line with both custom ends and user given settings:\n");
    border custom_b = {.custom = {ASCII_BOX_UPPER_LEFT, ASCII_BOX_UPPER_RIGHT}};
    println_c(genlne(def_placeholder, custom_b, &b_width));
    getch();
    return 0;
}