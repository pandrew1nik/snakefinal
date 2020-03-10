#include <iostream>
#include <conio.h>
#include "apple.h"

using namespace std;

char getFieldValue(int value);
const int width = 20;
const int height = 40;
int Field[width * height];

class Field {
public:
	void run() //початок гри
	{
		initField();
		running = true;
		while (running) {
			if (kbhit()) {
				changeDirection(getch());
			}

			update();
			clearScreen();
			printField();
			_sleep(100);
		}
		cout << "\t\tGame over" << endl << "\t\tscore: " << Apple;

		cin.ignore();
	}

	void initField() //ініціалізація ігрового поля
	{

		mainx = width / 2;
		mainy = height / 2;
		Field[mainx + mainy * width] = 1;

		for (int x = 0; x < width; ++x) {
			Field[x] = -1;
			Field[x + (height - 1) * width] = -1;
		}

		for (int y = 0; y < height; y++) {
			Field[0 + y * width] = -1;
			Field[(width - 1) + y * width] = -1;
		}

		generateApple();
	}

	void printField() //побудова ігрового поля
	{
		for (int x = 0; x < width; ++x) {
			for (int y = 0; y < height; ++y) {

				cout << getFieldValue(Field[x + y * width]);
			}

			cout << endl;
		}

	}

	char getFieldValue(int value)
	{

		if (value > 0) return 'o';

		switch (value) {

		case -1: return '#';

		case -2: return '$';
		}

		return ' ';
	}
};
