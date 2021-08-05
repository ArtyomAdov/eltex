#include <malloc.h>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define ERROR_ARGUMNET_FOR_MAIN 0b00000001
#define ERROR_OPEN_FILE 0b00000010
#define ERROR_CREATE_WINDOW 0b00000100

#define QUANTITY_CORRECT_ARGUMENT_FOR_MAIN 2
#define INDEX_ARGUMENT_WITH_NAME_FILE 1

#define READ_AND_WRITE "r+"

// #define DEATH_KEY_RIGHT 'd'
// #define DEATH_KEY_LEFT 'a'
#define DEATH_KEY_QUIT 7 //'q'

int main(const int argc, const char* const argv[])
{
	FILE* file = NULL;
	WINDOW* window;
	struct winsize window_size;
	unsigned int key_choice = 0;
	char symbol = '0';
	if(QUANTITY_CORRECT_ARGUMENT_FOR_MAIN != argc)
	{
		return ERROR_ARGUMNET_FOR_MAIN;
	}
	file = fopen(argv[INDEX_ARGUMENT_WITH_NAME_FILE], READ_AND_WRITE);
	if(NULL == file)
	{
		return ERROR_OPEN_FILE;
	}
	initscr();
	cbreak(); //off_bufferization
	ioctl(fileno(stdout), TIOCGWINSZ, (char*)&window_size);
	window = newwin(window_size.ws_row, window_size.ws_col, 0, 0);
	keypad(window, true);
	curs_set(0);
	noecho();
	do
	{
		symbol = getc(file);
		if(EOF == symbol)
		{
			break;
		}
		wprintw(window, "%c", symbol);
	} while(1);
	//
	do
	{
		// wrefresh(window);//flush buffer
		key_choice = wgetch(window);
		switch(key_choice)
		{
			case(KEY_DOWN):
			{
				wmove(window, , 0);
				break;
			}
			case(KEY_RIGHT):
			{
				wmove(window, , 0) break;
			}
			case(KEY_BACKSPACE):
			{
				//nado udalit i vse sdvinut kak to
				break;
			}
			default:
			{
				wprintw(window, "%c", key_choice);
				break;
			}
		}
	} while(KEY_END != key_choice);
	//
	endwin();
	fclose(file);
	file = NULL;
	return 0;
}