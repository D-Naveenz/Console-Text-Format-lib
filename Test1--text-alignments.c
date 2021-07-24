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
    getch();
    return 0;
}