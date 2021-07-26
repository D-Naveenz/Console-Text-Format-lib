#include <stdio.h>
#include <conio.h>
#include <core.h>

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

buffer_w *validate_buffer(buffer_w *_buffer)
{
	if (_buffer->size == 0)
	{
		unsigned short width = get_window_buffer_width();
		_buffer->size = width * _buffer->percentage / 100;
		_buffer->percentage = 0;
		return _buffer;
	}
	else
	{
		_buffer->percentage = 0;
		return _buffer;
	}
}
