#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <core.h>

buffer_w full_width = {0, 100};

#pragma region string_functions

char *console_tf(char *text, align align, buffer_w *_buffer)
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

char *console_tfb(char *text, align align, border ends, buffer_w *_buffer)
{
    // genarate buffer width from the percentage
    _buffer = validate_buffer(_buffer);
    // margines would take 2 spaces from the buffer.
    _buffer->size -= 2;
    // genarate the text string using console_tf()
    char *textstr = console_tf(text, align, _buffer);
    char left[2] = "\0";
    char right[2] = "\0";

    if (ends.is_custom)
    {
        left[0] = ends.border.custom.left_end;
        right[0] = ends.border.custom.right_end;
    }
    else
    {
        left[0] = right[0] = ends.border.common;
    }

    // allocate new memory for the result string
    char *result = malloc(strlen(textstr) + 2 * sizeof(char));

    // genarate the final string
    strcpy(result, left);
    strcat(result, textstr);
    strcat(result, right);

    free(textstr);
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
    printf("%s\n", text);
}

void print_right(char *text)
{
    char *result = console_tf(text, right, &full_width);
    printf("%s\n", result);
    free(result);
}

void print_center(char *text)
{
    char *result = console_tf(text, center, &full_width);
    printf("%s\n", result);
    free(result);
}

void print_tf(char *text, align align, int size)
{
    buffer_w new_bf = {0, size};

    char *result = console_tf(text, align, &new_bf);
    printf("%s\n", result);
    free(result);
}

void print_tfb(char *text, align align, border ends, int size)
{
    buffer_w new_bf = {0, size};

    char *result = console_tfb(text, align, ends, &new_bf);
    printf("%s\n", result);
    //free(result);
}
#pragma endregion
