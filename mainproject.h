﻿#include <iostream>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include "field.h"
#include "apple.h"

using namespace std;

char getFieldValue(int value);

const int width = 20;
const int height = 40;

int Field[width * height];
int mainx;
int mainy;
int direction;
int Apple = 3;

bool running;
class Snake {
public:
	void run() //початок гри
	{

		initField();
		running = true;
		while (running) {

			if (_kbhit()) {
				changeDirection(_getch());
			}
			update();
			clearScreen();
			printField();
			_sleep(100);
		}
		cout << "\t\tGame over" << endl << "\t\tscore: " << Apple;
		cin.ignore();
	}

	void clearScreen() {
		system("cls");
	}

	void generateApple() { //додавання у гру їжі(яблука) для персонажа(змійки)
		int x = 0;
		int y = 0;
		do {
			x = rand() % (width - 2) + 1;
			y = rand() % (height - 2) + 1;
		} while (Field[x + y * width] != 0);

		Field[x + y * width] = -2;
	}

	void initField() //ініціалізація ігрового поля
	{
		headx = width / 2;
		heady = height / 2;
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

int main() {
	Snake manager;
	manager.run();
	manager.changeDirection();
	manager.move();
	manager.clearScreen();
	manager.generateApple();
	manager.update();
	manager.initField();
	manager.printField();
	manager.getFieldValue();

	return 0;

}
