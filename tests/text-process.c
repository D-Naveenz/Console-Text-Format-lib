#include <stdio.h>
#include <conio.h>
#include <contf.h>
#include <ctf-tests.h>

int main()
{
    // printing the header of the program
    header();

    printf("Contf library brings a more easier way to process text outputs of your program.\n");
    printf("\n||||Text processing features||||\n");
    
    printf("\n1) Format text alignment.\n");
    println("Left aligned text");
    printlnR("Right aligned text");
    printlnC("Center aligned text");

    printf("\n2) Format text alignment with user defined buffer width.\n");
    printFText(textRight, 40, NULL, 0, "Right aligned text");
    printf("|<- with 40%% console buffer width\n");
    printFText(textCenter, 60, NULL, 0, "Center aligned text");
    printf("|<- with 60%% console buffer width\n");
    // contf lib printf functions doesn't work as printf() at everytime
    // cannot print variables like printf("%s", anystring);
    printFText(textLeft, 50, NULL, 0, "50% left aligned text");
    printFText(textRight, 50, NULL, 0, "50% right aligned text");

    printf("\n3) Can print a text with a border.\n");
    char common_b[] = {(char)178, '\0'};
    char custom_b[] = {'{', ',', '}', '\0'};
    println_ab(textLeft, 80, common_b, "Text with common borders");
    println_ab(textLeft, 80, custom_b, "Text with custom borders");
    getch();
    return 0;
}