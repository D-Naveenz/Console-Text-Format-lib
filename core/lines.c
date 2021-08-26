#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <contf.h>
#include <ctf-core.h>

// Defined def_placeholder here
const char def_placeholder = ASCII_BOX_LINE_H;

// Main string function for generate lines
char *genln(int width, char *ends, char placeholder)
{
    // genarate buffer width from the percentage
    unsigned short _buffer = get_buffer(width);
    // create a string from the placeholder
    char ph_str[2] = {placeholder, '\0'};

    // creating 2D array for ends of the line
    char **_end = (char **)malloc(sizeof(char *) * 2);
    int _endSize = 0;

    if (ends != NULL)
    {
        int count = 0;
        char *token = strtok(ends, BORDER_DELIM);

        // get border ends
        while (token != NULL)
        {
            // Trimiing the token first
            token = trim(token);

            _end[count] = (char *)malloc(strlen(token));
            strcpy(_end[count++], token);
            _endSize += strlen(token);
            token = strtok(NULL, BORDER_DELIM);
        }

        // If there is only one token in the array
        if (count < 2)
        {
            _end[count] = strdup(_end[count - 1]);
            _endSize++;
        }
    }

    // margines would take some spaces from the buffer.
    _buffer -= _endSize;

    // allocate new memory for the result string
    char *result = (char *)calloc(_buffer + _endSize + 1, sizeof(char)); // +1 for the null-terminator
    if (result == NULL)
    {
        printf("An error occurred while allocating memory for the string!\n");
        exit(EXIT_FAILURE);
    }

    // genarate the final string
    //building the final string
    if (ends)
    {
        strcpy(result, _end[0]);
        for (int i = 0; i < _buffer; i++)
        {
            strcat(result, ph_str);
        }
        strcat(result, _end[1]);
    }
    else
    {
        for (int i = 0; i < _buffer; i++)
        {
            strcat(result, ph_str);
        }
    }

    // freeing allocated memory
    free(_end);

    return result;
}

// Main print function for generate lines
void drawln(char *ends, int width, int next_ln, char placeholder)
{
    char *result = genln(width, ends, placeholder);
    printf("%s", result);
    // free(result);

    // print if next line is enabled
    if (next_ln)
        printf("\n");
}

#pragma region print_lines
void separator()
{
    drawln(NULL, FULL_WIDTH, 1, def_placeholder);
}

void separator_c(char placeholder)
{
    drawln(NULL, FULL_WIDTH, 1, placeholder);
}
#pragma endregion
