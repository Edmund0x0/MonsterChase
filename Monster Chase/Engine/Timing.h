#pragma once

#include <windows.h>

class Timing
{
public:
	static LARGE_INTEGER frequency, start;

	Timing();
	~Timing();

	static void GetFrequency(LARGE_INTEGER& frequency);
	void CurrentTick(LARGE_INTEGER& currentTick);
	static float CalcLastFrameTime();

	double ElapsedSeconds(LARGE_INTEGER frequency, LARGE_INTEGER start, LARGE_INTEGER end);
};

