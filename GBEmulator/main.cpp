#include <stdlib.h>
#include "gameboy.h"

Gameboy myGameboy;

int main(int argc, char** argv)
{
	myGameboy.loadROM(argv[1]);

	return 0;
}