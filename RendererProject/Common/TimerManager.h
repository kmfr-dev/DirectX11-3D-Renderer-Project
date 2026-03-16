#pragma once
#include "Define.h"

class CTimerManager
{
	friend class CEngine;

private:
	LARGE_INTEGER	mSecond = {};
	LARGE_INTEGER	mTime = {};
	float mDeltaSeconds = 0.f;

private:
	void  InitTimer();
	float Tick();

public:
	float GetDeltaSeconds() { return mDeltaSeconds; }

	DECLARE_SINGLE(CTimerManager)
};

