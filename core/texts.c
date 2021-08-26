#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <contf.h>
#include <ctf-core.h>

#pragma region string_functions
char *textLeft(int _buffer, char *text)
{
    char *spaces = get_spaces_ptr(text, left, _buffer);
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

char *textRight(int _buffer, char *text)
{
    char *spaces = get_spaces_ptr(text, right, _buffer);
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

char *textCenter(int _buffer, char *text)
{
    char *spaces = get_spaces_ptr(text, center, _buffer);
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
#pragma endregion

// Main print function
void printFText(char *(*align)(int _buffer, char *text), int width, char *ends, int next_ln, char *text)
{
    // genarate buffer width from the percentage
    unsigned short _buffer = get_buffer(width);

    // creating 2D array for borders
    char **border = (char **)malloc(sizeof(char *) * 2);
    int border_size = 0;

    if (ends != NULL)
    {
        int count = 0;
        char *token = strtok(ends, BORDER_DELIM);

        // get border ends
        while (token != NULL)
        {
            // Trimiing the token first
            token = trim(token);

            border[count] = (char *)malloc(strlen(token));
            strcpy(border[count++], token);
            border_size += strlen(token);
            token = strtok(NULL, BORDER_DELIM);
        }

        // If there is only one token in the array
        if (count < 2)
        {
            /*border[count + 1] = (char *)malloc(strlen(border[count]));
            strcat(border[count + 1], border[count]);*/
            border[count] = strdup(border[count - 1]);
            border_size++;
        }
    }

    // margines would take some spaces from the buffer.
    _buffer -= border_size;

    // genarate the text string
    char *textstr = align(_buffer, text);

    char *result;

    //building the final string
    if (ends)
    {
        // allocate new memory for the result string
        result = malloc(strlen(textstr) + border_size);

        strcpy(result, border[0]);
        strcat(result, textstr);
        strcat(result, border[1]);

        // freeing allocated memory
        free(border);
        free(textstr);
    }
    else
    {
        result = textstr;

        // freeing allocated memory
        free(border);
    }

    // printing the text string
    printf("%s", result);
    // print if next line is enabled
    if (next_ln)
        printf("\n");
}

#pragma region print_lines
void new_line()
{
    printf("\n");
}

void println(char *text)
{
    printf("%s\n", text);
}

void printlnR(char *text)
{
    printFText(textRight, FULL_WIDTH, NULL, 1, text);
}

void printlnC(char *text)
{
    printFText(textCenter, FULL_WIDTH, NULL, 1, text);
}

void println_a(char *(*align)(int _buffer, char *text), int width, char *text)
{
    printFText(align, width, NULL, 1, text);
}

void println_ab(char *(*align)(int _buffer, char *text), int width, char *ends, char *text)
{
    printFText(align, width, ends, 1, text);
}
#pragma endregion
