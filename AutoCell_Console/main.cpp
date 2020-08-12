#include <iostream>
#include <limits>
#include <windows.h>
#include <Cell.h>
#pragma comment(lib, "Cell.lib")

using namespace std; 

#define ROWS 30
#define COLS 30
#define ROWS_2 32
#define COLS_2 62
#define INTERVAL 50
#undef max


#define SET_CONSOLE_SIZE_STR(rows, cols) "mode con:lines="#rows" cols="#cols
#define SET_CONSOLE_SIZE(rows, cols) system(SET_CONSOLE_SIZE_STR(rows, cols))

int main()
{
	int seed = 0;
	cout << "Please input a 32-bit integer as the seed: " << flush;
	cin >> seed;
	while (!cin)
	{
		cout << "Illegal! Please input a 32-bit integer as the seed: " << flush; 
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max()); 
		cin >> seed; 
	}

	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SET_CONSOLE_SIZE(ROWS_2, COLS_2);
	const COORD consoleBeginPos = { 0, 0 };

	CellMap map(ROWS, COLS, seed); 
	for (;;)
	{
		//Draw map
		SetConsoleCursorPosition(hConsoleOutput, consoleBeginPos);
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLS; ++j)
				if (map[i][j]) printf("0 ");
				else printf("  ");
			putchar('\n');
		}

		map.Grow(); 

		Sleep(INTERVAL); 
	}
	return 0; 
}
