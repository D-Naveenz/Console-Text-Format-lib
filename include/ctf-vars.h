#ifndef CTF_VARS_H   /* Include guard */
#define CTF_VARS_H

const char def_placeholder; // default placeholder for spaces between texts

// Enumeration of text alignment (left, Right, Center)
typedef enum alignment
{
    left,
    right,
    center
} align;

// Console window buffer size type definition
// A percentage or a fixed value can be retained
typedef struct buffer   
{
    unsigned short size;
    unsigned short percentage;
} buffer_w;

// Border definition for the function parameters 
// Can assign one char (common border) or two chars (custom border) if you want custom ends.
typedef union borderdef
{
    char common;
    struct
    {
        char left_end;
        char right_end;
    } custom;
} border;

#endif // !CTF_VARS_H