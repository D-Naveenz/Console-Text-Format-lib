#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <core.h>

buffer_w full_width;

#pragma region string_functions

char *console_tf(char *text, alignment align, buffer_w *_buffer)
{
    _buffer = validate_buffer(_buffer);
    char *spaces = get_spaces_ptr(text, align, _buffer->size);
    char *result;

    if (align == left)
    {
        result = malloc(strlen(text) + strlen(spaces) + 1); // +1 for the null-terminator
        if (result == NULL)
        {
            printf("An error occurred while allocating memory for the string!\n");
            exit(EXIT_FAILURE);
        }

        strcpy(result, text);
        strcat(result, spaces);
    }
    else if (align == right)
    {
        result = malloc(strlen(text) + strlen(spaces) + 1); // +1 for the null-terminator
        if (result == NULL)
        {
            printf("An error occurred while allocating memory for the string!\n");
            exit(EXIT_FAILURE);
        }

        strcpy(result, spaces);
        strcat(result, text);
    }
    else
    {
        result = malloc(strlen(text) + strlen(spaces) * 2 + 1); // +1 for the null-terminator
        if (result == NULL)
        {
            printf("An error occurred while allocating memory for the string!\n");
            exit(EXIT_FAILURE);
        }

        strcpy(result, spaces);
        strcat(result, text);
        strcat(result, spaces);
    }

    free(spaces);
    return result;
}

#pragma endregion

#pragma region printing_functions

void new_line()
{
    printf("\n");
}

void print_left(char *text)
{
    full_width.size = 0;
    full_width.percentage = 100;

    char *result = console_tf(text, left, &full_width);
    printf("%s\n", result);
    free(result);
}

void print_right(char *text)
{
    full_width.size = 0;
    full_width.percentage = 100;

    char *result = console_tf(text, right, &full_width);
    printf("%s\n", result);
    free(result);
}

void print_center(char *text)
{
    full_width.size = 0;
    full_width.percentage = 100;

    char *result = console_tf(text, center, &full_width);
    printf("%s\n", result);
    free(result);
}

void print_tf(char *text, alignment align, int size)
{
    buffer_w new_bf;
    new_bf.size = 0;
    new_bf.percentage = size;

    char *result = console_tf(text, align, &new_bf);
    printf("%s\n", result);
    free(result);
}
#pragma endregion
