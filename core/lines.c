#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <contf.h>
#include <ctf-core.h>

// Defined def_placeholder here
const char def_placeholder = ASCII_BOX_LINE_H;

#pragma region string_functions
char *genln(char placeholder, buffer_w *_buffer)
{
    // genarate buffer width from the percentage
    _buffer = validate_buffer(_buffer);
    // create a string from the placeholder
    char ph_str[2] = {placeholder, '\0'};
    char *result = (char *)malloc(_buffer->size + 1); // +1 for the null-terminator
    if (result == NULL)
    {
        printf("An error occurred while allocating memory for the string!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        strcpy(result, ph_str);
    }
    

    int i = 0;
    while (i < _buffer->size - 1)
    {
        strcat(result, ph_str);
        i++;
    }
    return result;
}

char *genlne(char placeholder, border ends, buffer_w *_buffer)
{
    // genarate buffer width from the percentage
    _buffer = validate_buffer(_buffer);
    // margines would take 2 spaces from the buffer.
    _buffer->size -= 2;
    // genarate the text string using console_tf()
    char *textstr = genln(placeholder, _buffer);
    char left[2] = "\0";
    char right[2] = "\0";

    if (is_custom_border(ends))
    {
        left[0] = ends.custom.left_end;
        right[0] = ends.custom.right_end;
    }
    else
    {
        left[0] = right[0] = ends.common;
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

#pragma region prints
void drawln(char placeholder, int size)
{
    buffer_w new_bf = {0, size};

    char *result = genln(placeholder, &new_bf);
    printf("%s", result);
    free(result);
}

void drawlne(char placeholder, border ends, int size)
{
    buffer_w new_bf = {0, size};

    char *result = genlne(placeholder, ends, &new_bf);
    printf("%s", result);
    free(result);
}
#pragma endregion

#pragma region print_lines
void separator()
{
    char *result = genln(def_placeholder, &full_width);
    printf("%s\n", result);
    free(result);
}

void separator_c(char placeholder)
{
    char *result = genln(placeholder, &full_width);
    printf("%s\n", result);
    free(result);
}
#pragma endregion
