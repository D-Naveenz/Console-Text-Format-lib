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
    buffer_w b_width = {0, 60};
    // printing the header of the program
    header();

    printf("Console text formatter library brings a more easier way for drawings of your console program.\n");
    printf("\n||||Line drawing features||||\n");
    
    printf("\n1) Print a separator:\n");
    separator();

    printf("\n2) Print a separator with custom placeholder:\n");
    separator_c(ASCII_BOX_LINE_V);

    printf("\n3) Draw a line with user given buffer size\n");
    printf("%s |<- line with 60%% buffer width\n", genln((char)240, &b_width));

    printf("\nCan compine text alignments functions with lines to do amazing things\n");
    printf("4) Draw a line with user given buffer size and aligned to the right:\n");
    println_r(genln(ASCII_DEGREE, &b_width));

    printf("\n5) Draw a line with both custom ends and user given settings:\n");
    printf("i) Draw a line with a common border: (border: %c)\n", (char)254);
    border common_b = {(char)254};
    println_c(genlne(def_placeholder, common_b, &b_width));
    printf("ii) Draw a line with a custom border: (left: %c, right: >)\n", (char)195);
    border custom_b = {.custom = {(char)195, '>'}};
    println_c(genlne(def_placeholder, custom_b, &b_width));
    getch();
    return 0;
}