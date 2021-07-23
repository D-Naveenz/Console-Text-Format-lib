#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <core.h>

#pragma region string_functions

char *console_left(char *text, buffer *_buffer)
{
    unsigned short size = gen_target_buffer(_buffer);
    char *spaces = get_spaces_ptr(text, left, size);
    char *result = malloc(strlen(text) + strlen(spaces) + 1); // +1 for the null-terminator
    if (result == NULL)
    {
        printf("An error occurred while allocating memory for the string!\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(result, text);
    strcat(result, spaces);

    free(spaces);
    return result;
}

char *console_right(char *text, buffer *_buffer)
{
    unsigned short size = gen_target_buffer(_buffer);
    char *spaces = get_spaces_ptr(text, right, size);
    char *result = malloc(strlen(text) + strlen(spaces) + 1); // +1 for the null-terminator
    if (result == NULL)
    {
        printf("An error occurred while allocating memory for the string!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, spaces);
    strcat(result, text);

    free(spaces);
    return result;
}

char *console_center(char *text, buffer *_buffer)
{
    unsigned short size = gen_target_buffer(_buffer);
    char *spaces = get_spaces_ptr(text, center, size);
    char *result = malloc(strlen(text) + strlen(spaces) * 2 + 1); // +1 for the null-terminator
    if (result == NULL)
    {
        printf("An error occurred while allocating memory for the string!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, spaces);
    strcat(result, text);
    strcat(result, spaces);

    free(spaces);
    return result;
}

char *console_tf(char *text, alignment align, buffer _buffer)
{
    if (align == left)
    {
        return console_left(text, &_buffer);
    }
    else if (align == right)
    {
        return console_right(text, &_buffer);
    }
    else
    {
        return console_center(text, &_buffer);
    }
}

#pragma endregion

#pragma region printing_functions

void new_line()
{
    printf("\n");
}

void print_left(char *text)
{
    buffer b;
    b.size = 0;
    b.percentage = 100;

    char *result = console_left(text, &b);
    printf("%s\n", result);
    free(result);
}

void print_right(char *text)
{
    buffer b;
    b.size = 0;
    b.percentage = 100;

    char *result = console_right(text, &b);
    printf("%s\n", result);
    free(result);
}

void print_center(char *text)
{
    buffer b;
    b.size = 0;
    b.percentage = 100;

    char *result = console_center(text, &b);
    printf("%s\n", result);
    free(result);
}

void print_tf(char *text, alignment align, int size)
{
    buffer b;
    b.size = 0;
    b.percentage = size;

    char *result = console_tf(text, align, b);
    printf("%s\n", result);
    free(result);
}
#pragma endregion
