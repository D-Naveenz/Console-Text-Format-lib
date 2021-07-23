#include <stdio.h>
#include <conio.h>
#include <contf.h>

int main()
{
    print_center("Console Text Formatter - v0.1");
    print_center("------------------------------------------------------");
    printf("\nHello Guys! This is a c library which provides easy functions to format your prints on the console.\n");
    printf("\nExamples\n");
    
    print_left("Left align text");
    print_right("Right align text");
    print_center("Center align text");
    print_tf("Text with custom align and buffer", right, 70);
    getch();
    return 0;
}