#include <stdio.h>
#include <conio.h>
#include <contf.h>
#include <ctf-tests.h>

int main()
{
    char custom_top[] = {ASCII_BOX_UPPER_LEFT, ',', ASCII_BOX_UPPER_RIGHT, '\0'};
    char custom_bottom[] = {ASCII_BOX_LOWER_LEFT, ',', ASCII_BOX_LOWER_RIGHT, '\0'};
    char common_cell[] = {ASCII_BOX_LINE_V, '\0'};

    // printing the header of the program
    header();

    printf("You can do awsome things with Contf library.\n");
    printf("\n||||Text Formats and Line Drawing combinations||||\n");

    printf("\n1) Print a text in a cell\n");
    // print the top line of the cell
    drawln(custom_top, 40, 1, def_placeholder);
    // print the text with a common border
    println_ab(textCenter, 40, common_cell, "Text in the cell");
    // print the bottom line of the cell
    drawln(custom_bottom, 40, 1, def_placeholder);
    getch();
    return 0;
}