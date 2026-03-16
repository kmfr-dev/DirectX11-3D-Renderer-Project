#pragma once

#include "../Common/Define.h"

class CEngine
{
private:
	static bool mLoop;
	HINSTANCE	mhInst = 0;
	HWND		mhWnd = 0;
	HDC			mhDC = 0;
	TCHAR		mClassName[256] = {};
	TCHAR		mTitleName[256] = {};

	float		mClearColor[4] = {};

public:
	HINSTANCE	GetWindowInstance()	const { return mhInst; }
	HWND		GetWindowHandle()	const { return mhWnd; }

public:
	bool	Init(HINSTANCE hInst);
	int		RunEngine();


private:
	void	Logic();
	void	Input(float DeltaSeconds);
	bool	Tick(float DeltaSeconds);
	void	Render(float DeltaSeconds);

private:
	void	RegisterWindowClass();
	bool	Create();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_SINGLE(CEngine)
};

