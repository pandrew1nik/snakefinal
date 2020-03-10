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
int headx;
int heady;
int direction;
int Apple = 3;

bool running;
class Snake {
public:
	void run()
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

	void changeDirection(char key) {

		switch (key) {
		case 'w':
			if (direction != 2) direction = 0;
			break;
		case 'd':
			if (direction != 3) direction = 1;
			break;
		case 's':
			if (direction != 4) direction = 2;
			break;
		case 'a':
			if (direction != 5) direction = 3;
			break;
		case 'k':
			running = false;
			break;
		}
	}

	void move(int dx, int dy) {

		int newx = headx + dx;
		int newy = heady + dy;

		if (Field[newx + newy * width] == -2) {
			Apple++;
			generateApple();
		}
		else if (Field[newx + newy * width] != 0) {
			running = false;
		}

		headx = newx;
		heady = newy;
		Field[headx + heady * width] = Apple + 1;
	}

	void clearScreen() {
		system("cls");
	}

	void generateApple() {
		int x = 0;
		int y = 0;
		do {
			x = rand() % (width - 2) + 1;
			y = rand() % (height - 2) + 1;
		} while (Field[x + y * width] != 0);

		Field[x + y * width] = -2;
	}

	void update() {
		switch (direction) {
		case 0: move(-1, 0);
			break;
		case 1: move(0, 1);
			break;
		case 2: move(1, 0);
			break;
		case 3: move(0, -1);
			break;
		}

		for (int i = 0; i < width * height; i++) {
			if (Field[i] > 0) Field[i]--;
		}
	}

	void initField()
	{
		headx = width / 2;
		heady = height / 2;
		Field[headx + heady * width] = 1;

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

	void printField()
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