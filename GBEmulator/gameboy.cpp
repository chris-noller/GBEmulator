#include "gameboy.h"
#include <fstream>

Gameboy::Gameboy()
{
	// empty
}

bool Gameboy::loadROM(char const* filename)
{
	FILE* fp;
	fp = fopen(filename, "rb");

	if (fp == NULL)
	{
		printf("Can't open file");
		return false;
	}

	// Get file size and print to console
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	rewind(fp);
	printf("Size of file is: %d\n", file_size);

	// Allocate memory to contain entire ROM
	uint8_t* buffer = (uint8_t*)malloc(sizeof(uint8_t) * file_size);
	if (buffer == NULL)
	{
		printf("Error with buffer, is NULL");
		return false;
	}

	// Copy ROM contents into buffer
	size_t result = fread(buffer, 1, file_size, fp);
	if (result != file_size)
	{
		printf("Error copying ROM contents into buffer\n");
		return false;
	}

	// Copy buffer to Gameboy memory
	for (int i = 0; i < sizeof(memory); i++)
	{
		memory[i] = buffer[i];
	}

	fclose(fp);
	free(buffer);
	printf("ROM loaded successfully");
	return true;
}