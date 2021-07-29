#include <stdio.h>
#include <conio.h>
#include <contf.h>

void header()
{
    println_c("Console Text Formatter - v1.0");
    print_tf("Test v0.2", left, 50);
    print_tf("Naveen Dharmathunga", right, 50);
    separator();
    new_line();
}

int main()
{
    border custom_top = {.custom = {ASCII_BOX_UPPER_LEFT, ASCII_BOX_UPPER_RIGHT}};
    border custom_bottom = {.custom = {ASCII_BOX_LOWER_LEFT, ASCII_BOX_LOWER_RIGHT}};
    border common_cell = {ASCII_BOX_LINE_V};
    // printing the header of the program
    header();

    printf("You can do awsome things with Console text formatter library.\n");
    printf("\n||||Text Formats and Line Drawing combinations||||\n");
    
    printf("\n1) Print a text in a cell\n");
    // print the top line of the cell
    drawlne(def_placeholder, custom_top, 40);
    new_line();
    // print the text with a common border
    println_tfb("Text in the cell", center, common_cell, 40);
    // print the bottom line of the cell
    drawlne(def_placeholder, custom_bottom, 40);
    new_line();
    getch();
    return 0;
}