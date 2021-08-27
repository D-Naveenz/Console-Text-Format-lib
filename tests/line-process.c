#include <stdio.h>
#include <conio.h>
#include <contf.h>
#include <ctf-tests.h>

int main()
{
    int b_width = 60;
    // printing the header of the program
    header();

    printf("Contf library brings a more easier way for drawings of your console program.\n");
    printf("\n||||Line drawing features||||\n");

    printf("\n1) Print a separator:\n");
    separator();

    printf("\n2) Print a separator with custom placeholder:\n");
    separator_c(ASCII_BOX_LINE_V);

    printf("\n3) Draw a line with user given buffer size\n");
    printf("%s|<- line with 60%% buffer width\n", genln(b_width, NULL, (char)240));

    printf("\nCan combine text alignments functions with lines to do amazing things\n");
    printf("4) Draw a line with user given buffer size and aligned to the right:\n");
    printlnR(genln(b_width, NULL, ASCII_DEGREE));

    printf("\n5) Draw a line with both custom ends and user given settings:\n");
    printf("i) Draw a line with a common border: (border: %c)\n", (char)254);
    char common_b[] = {(char)254, '\0'};
    printlnC(genln(b_width, common_b, def_placeholder));
    printf("ii) Draw a line with a custom border: (left: %c, right: >)\n", (char)195);
    char custom_b[] = {(char)195, ',', '>', '\0'};
    printlnC(genln(b_width, custom_b, def_placeholder));
    getch();
    return 0;
}