#include "Timing.h"

Timing::Timing()
{

}

LARGE_INTEGER Timing::start;
LARGE_INTEGER Timing::frequency;

Timing::~Timing()
{

}

void Timing::GetFrequency(LARGE_INTEGER& frequency)
{
	QueryPerformanceFrequency(&frequency);
}


void Timing::CurrentTick(LARGE_INTEGER& currentTick)
{
	QueryPerformanceCounter(&currentTick);
}

double Timing::ElapsedSeconds(LARGE_INTEGER frequency, LARGE_INTEGER start, LARGE_INTEGER end)
{
	return static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart;
}

float Timing::CalcLastFrameTime()
{
	static long long g_LastFrameStartTick = 0;
	float g_LastFrameTime;

	QueryPerformanceCounter(&start);

	if (g_LastFrameStartTick)
	{
		long long elapsedTicks = (start.QuadPart - g_LastFrameStartTick);
		GetFrequency(frequency);
		g_LastFrameTime = ((float)elapsedTicks) / frequency.QuadPart;
	}
	else
	{
		g_LastFrameTime = 13.3;
	}


	g_LastFrameStartTick = start.QuadPart;

	return g_LastFrameTime;
}

//#define DESIRED_FPS 60.0f
//#define DESIRED_FRAMETIME_MS (1000.0f / DESIRED_FPS)
//#define MAX_FRAMETIME_MS (2 * DESIRED_FRAMETIME_MS)
//
//float GetLastFrameTime_ms()
//{
//#if defined (CONSTANT_FRAMETIME)
//	return DESIRED_FRAMETIME_MS;
//#elif defined (CLAMP_FRAMETIME)
//	if (GetLastFrameTime_ms > MAX_FRAMETIME_MS)
//		return MAX_FRAMETIME_MS;
//	else
//		return LastFrameTime_ms;
//#else
//	return LastFrameTime_ms;
//#endif
//}