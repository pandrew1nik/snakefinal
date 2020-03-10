#include <iostream>
#include <conio.h>
#include "field.h"

using namespace std;

int Apple = 3;

class Food {
public:
	void generateApple() { //спавн(поява) корму(яблука) для персонажа(змійки)
		int x = 0;
		int y = 0;
		do {

			x = rand() % (width - 2) + 1;
			y = rand() % (height - 2) + 1;


		} while (Field[x + y * width] != 0);


		Field[x + y * width] = -2;
	}
};
