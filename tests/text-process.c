#include <stdio.h>
#include <conio.h>
#include <contf.h>

void header()
{
    println_c("Console Text Formatter - v1.0");
    print_tf("Test v0.2", left, 50);
    print_tf("Naveen Dharmathunga", right, 50);
    separator();
    //new_line();
}

int main()
{
    // printing the header of the program
    header();

    printf("Console text formatter library brings a more easier way to process text outputs of your program.\n");
    printf("\n||||Text processing features||||\n");
    
    printf("\n1) Format text alignment.\n");
    println_l("Left align text");
    println_r("Right align text");
    println_c("Center align text");

    printf("\n2) Format text alignment with user defined buffer width.\n");
    print_tf("Right aligned text", right, 40);
    printf("|<- with 40%% console buffer width\n");
    print_tf("Center aligned text", center, 60);
    printf("|<- with 60%% console buffer width\n");
    // contf lib printf functions doesn't work as printf() at everytime
    // cannot print variables like printf("%s", anystring);
    print_tf("50% left aligned text", left, 50);
    print_tf("50% right aligned text", right, 50);

    printf("\n3) Can print a text with a border.\n");
    border common_b = {(char)178};
    border custom_b = {.custom = {'{', '}'}};
    println_tfb("Text with common borders", left, common_b, 80);
    println_tfb("Text with custom borders", center, custom_b, 40);
    getch();
    return 0;
}