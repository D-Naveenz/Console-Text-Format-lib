#ifndef CTF_VARS_H   /* Include guard */
#define CTF_VARS_H

const char def_placeholder; // default placeholder for spaces between texts

typedef enum alignment
{
    left,
    right,
    center
} align;

typedef struct buffer
{
    unsigned short size;
    unsigned short percentage;
} buffer_w;

typedef union borderdef // Can assign one char or two chars if you want custom ends.
{
    char common;
    struct
    {
        char left_end;
        char right_end;
    } custom;
} border;

#endif // !CTF_VARS_H