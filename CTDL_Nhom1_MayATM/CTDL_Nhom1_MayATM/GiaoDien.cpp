#include "GiaoDien.h"

void GiaoDien::SET_COLOR(int x) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}

