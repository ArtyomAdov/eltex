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

#define READ_ONLY "r+"
#define REWRITE_ONLY "w"

int main(const int argc, const char* const argv[])
{
	FILE* file = NULL;
	WINDOW* window;
	struct winsize window_size;
	int key_choice = 0;
	int window_coordinate_x = 0;
	int window_coordinate_y = 0;
	char symbol = '0';
	char flag_space = '0';
	if(QUANTITY_CORRECT_ARGUMENT_FOR_MAIN != argc)
	{
		return ERROR_ARGUMNET_FOR_MAIN;
	}
	file = fopen(argv[INDEX_ARGUMENT_WITH_NAME_FILE], READ_ONLY);
	if(NULL == file)
	{
		return ERROR_OPEN_FILE;
	}
	initscr();
	cbreak();
	ioctl(fileno(stdout), TIOCGWINSZ, (char*)&window_size);
	window = newwin(window_size.ws_row, window_size.ws_col, 0, 0);
	// window_size.ws_col--;
	// window_size.ws_row--;
	keypad(window, true);
	noecho();
	immedok(window, true);
	wclear(window);
	do
	{
		symbol = getc(file);
		if('\n' == symbol)
		{
			getyx(window, window_coordinate_y, window_coordinate_x);
			while(window_size.ws_col < window_coordinate_x)
			{
				window_coordinate_x++;
				waddch(window, ' ');
			}
			window_coordinate_x = 0;
		}
		if(EOF == symbol)
		{
			break;
		}
		waddch(window, symbol);
	} while(1);
	getyx(window, window_coordinate_y, window_coordinate_x);
	do
	{
		key_choice = wgetch(window);
		switch(key_choice)
		{
			case(KEY_LEFT):
			{
				window_coordinate_x--;
				if(window_coordinate_x < 0)
				{
					window_coordinate_x = window_size.ws_col - 1;
					window_coordinate_y--;
					wmove(window, window_coordinate_y, window_coordinate_x);
					while(' ' == (winch(window) & A_CHARTEXT))
					{
						window_coordinate_x--;
						wmove(window, window_coordinate_y, window_coordinate_x);
					}
				}
				else
				{
					wmove(window, window_coordinate_y, window_coordinate_x);
				}
				break;
			}
			case(KEY_RIGHT):
			{
				window_coordinate_x++;
				if(window_size.ws_col < window_coordinate_x)
				{
					window_coordinate_x = 0;
					window_coordinate_y++;
				}
				wmove(window, window_coordinate_y, window_coordinate_x);
				break;
			}
			case(KEY_BACKSPACE):
			{
				window_coordinate_x--;
				if(0 > window_coordinate_x)
				{
					window_coordinate_x = window_size.ws_col - 1;
					window_coordinate_y--;
					wmove(window, window_coordinate_y, window_coordinate_x);
					while(' ' == (winch(window) & A_CHARTEXT))
					{
						window_coordinate_x--;
						wmove(window, window_coordinate_y, window_coordinate_x);
					}
				}
				else
				{
					wmove(window, window_coordinate_y, window_coordinate_x);
				}
				wdelch(window);
				break;
			}
			default:
			{
				window_coordinate_x++;
				if(window_size.ws_col < window_coordinate_x)
				{
					window_coordinate_x = 0;
					window_coordinate_y++;
				}
				winsch(window, key_choice);
				wmove(window, window_coordinate_y, window_coordinate_x);
				break;
			}
		}
	} while(KEY_END != key_choice);
	window_coordinate_y = window_size.ws_row - 1;
	window_coordinate_x = window_size.ws_col - 1;
	wmove(window, window_coordinate_y, window_coordinate_x);
	while(' ' == (winch(window) & A_CHARTEXT))
	{
		window_coordinate_x--;
		if(0 > window_coordinate_x)
		{
			window_coordinate_x = window_size.ws_col - 1;
			window_coordinate_y--;
		}
		wmove(window, window_coordinate_y, window_coordinate_x);
	}
	waddch(window, EOF);
	window_coordinate_x = 0;
	window_coordinate_y = 0;
	fclose(file);
	file = fopen(argv[INDEX_ARGUMENT_WITH_NAME_FILE], REWRITE_ONLY);
	do
	{
		wmove(window, window_coordinate_y, window_coordinate_x);
		symbol = (winch(window) & A_CHARTEXT);
		if(EOF == symbol)
		{
			break;
		}
		window_coordinate_x++;
		if(window_size.ws_col < window_coordinate_x)
		{
			window_coordinate_x = 0;
			window_coordinate_y++;
		}
		if(' ' == symbol)
		{
			if('1' == flag_space)
			{
				window_coordinate_x = 0;
				window_coordinate_y++;
				putc('\n', file);
				flag_space = '0';
				continue;
			}
			flag_space = '1';
			continue;
		}
		flag_space = '0';
		putc(symbol, file);
	} while(EOF != symbol);
	delwin(window);
	endwin();
	fclose(file);
	file = NULL;
	return 0;
}