#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <ctf-core.h>


// The following code segment works for all for all Windows OS
#ifdef _WIN32
#include <Windows.h>

unsigned short get_window_buffer_width()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (ret)
	{
		return csbi.dwSize.X; // Returns Console Buffer Width
	}
	else
	{
		printf("An error occurred while getting window buffer width!\n");
		printf("Please run this program in externel console!");
		getch();
		// should raise an error
		exit(EXIT_FAILURE);
	}
}

// The following code segment works for all for linux
#elif __linux__
//#include <Windows.h>

unsigned short get_window_buffer_width()
{
}
#endif

char *get_spaces_ptr(char *text, align align, size_t buffer_size)
{
	char *spaces_ptr; // padding str pointer
	if (align == left || align == right)
	{
		buffer_size = buffer_size - strlen(text);
	}
	else
	{
		buffer_size = (buffer_size - strlen(text)) / 2;
	}

	// allocate the required mem, calloc ensures zero terminated
	spaces_ptr = calloc(buffer_size + 1, sizeof(char));
	// set a chars to hold spaces
	memset(spaces_ptr, ' ', buffer_size);

	return spaces_ptr;
}

unsigned short get_buffer(int percentage)
{
	unsigned short res;

	unsigned short width = get_window_buffer_width();
	res = width * percentage / 100;
	
	return res;
}

char *strdup(const char *s) {
    size_t size = strlen(s) + 1;
    char *p = malloc(size);
    if (p != NULL) {
        memcpy(p, s, size);
    }
    return p;
}

char *strndup(const char *s, size_t n) {
    char *p;
    size_t n1;

    for (n1 = 0; n1 < n && s[n1] != '\0'; n1++)
        continue;
    p = malloc(n + 1);
    if (p != NULL) {
        memcpy(p, s, n1);
        p[n1] = '\0';
    }
    return p;
}

char * trim(char * s) {
	// https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
    int l = strlen(s);
	if (l == 0) return s;

    while(isspace(s[l - 1])) --l;
    while(* s && isspace(* s)) ++s, --l;
    return strndup(s, l);
}
