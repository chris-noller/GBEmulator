#pragma once

#include <vector>

class Gameboy
{
	public:

		uint8_t memory[0x10000];

		Gameboy();
		bool loadROM(char const* filename);
};