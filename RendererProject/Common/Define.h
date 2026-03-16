#pragma once

#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <algorithm>

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>
#include "../Resource.h"

#include <d2d1.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <dwrite_3.h>
#include <dxgidebug.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d2d1.lib")

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }
#define SAFE_RELEASE(p) if(p) { p->Release(); p = nullptr; }

#define	DECLARE_SINGLE(Type)	\
private:\
	Type();\
	~Type();\
private:\
	static Type*	mInst;\
public:\
	static Type* GetInst()\
	{\
		if(!mInst)\
			mInst = new Type;\
		return mInst;\
	}\
	static void DestroyInst()\
	{\
		SAFE_DELETE(mInst);\
	}

#define	DEFINITION_SINGLE(Type)	Type* Type::mInst = nullptr;


struct FResolution
{
	unsigned int	Width = 0;
	unsigned int	Height = 0;
};