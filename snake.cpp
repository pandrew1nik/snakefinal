#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include "apple.h"
#include "field.h"
#include "main project.h"

using namespace std;

int mainx;
int mainy;

class Snake() {
public:
	void changeDirection(char key) { //зміна напряму при натисканні на певні клавіші клавіатури

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
		case 'x':
			running = false;
			break;
		}
	}

	void move(int dx, int dy) { //пересування персонажа(змійки) по ігровому полю
		int newx = mainx + dx;
		int newy = mainy + dy;
		if (Field[newx + newy * width] == -2) {
			Apple++;
			generateApple();
		}
		else if (Field[newx + newy * width] != 0) {
			running = false;
		}
		mainx = newx;
		mainy = newy;
		Field[mainx + mainy * width] = Apple + 1;
	}

	void clearScreen() {
		system("cls");
	}
	void update() { //оновлення координат при пересуванні персонажа(змійки) по ігровому полю
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
};
