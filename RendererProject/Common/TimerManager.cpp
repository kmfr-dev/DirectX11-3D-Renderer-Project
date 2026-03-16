#include "TimerManager.h"

DEFINITION_SINGLE(CTimerManager)

CTimerManager::CTimerManager()
{

}

CTimerManager::~CTimerManager()
{

}

void CTimerManager::InitTimer()
{
	QueryPerformanceFrequency(&mSecond);
	QueryPerformanceCounter(&mTime);
}

float CTimerManager::Tick()
{
	LARGE_INTEGER Time;
	QueryPerformanceCounter(&Time);

	mDeltaSeconds = (Time.QuadPart - mTime.QuadPart) / (float)mSecond.QuadPart;
	mTime = Time;

	return mDeltaSeconds;
}
