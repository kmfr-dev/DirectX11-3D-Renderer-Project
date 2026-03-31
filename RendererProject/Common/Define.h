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

#include "../Engine/SharedPtr.h"
#include "../Engine/Math/Vector2.h"
#include "../Engine/Math/Vector3.h"
#include "../Engine/Math/Vector4.h"

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

namespace EShaderBufferType
{
	enum Type
	{
		Vertex = 0x1,
		Pixel = 0x2,
		Hull = 0x4,
		Domain = 0x8,
		Geometry = 0x10,
		Compute = 0x20,
		Graphic = Vertex | Pixel | Hull | Domain | Geometry,
		All = Graphic | Compute
	};
}

struct FVertexBuffer
{
	FVertexBuffer() {};
	~FVertexBuffer()
	{
		SAFE_RELEASE(Buffer);
		SAFE_DELETE_ARRAY(Data);
	};

	ID3D11Buffer* Buffer = nullptr;
	int			Size = 0;
	int			Count = 0;
	void*		Data = nullptr;
};

struct FVertexColor
{
	FVertexColor() {};

	FVertexColor(const FVector3D& _Pos, const FVector4D& _Color)
		: Pos(_Pos), Color(_Color)
	{
	}

	FVertexColor(float _X, float _Y, float _Z, float _R, float _G, float _B, float _A)
		: Pos(_X, _Y, _Z), Color(_R, _G, _B, _A)
	{
	}

	~FVertexColor() {};

	FVector3D Pos;
	FVector4D Color;
};

struct FIndexBuffer
{
	FIndexBuffer() {};
	~FIndexBuffer()
	{
		SAFE_RELEASE(Buffer);
		SAFE_DELETE_ARRAY(Data);
	}

	ID3D11Buffer* Buffer = nullptr;
	int			Size = 0;
	int			Count = 0;
	DXGI_FORMAT Format = DXGI_FORMAT_UNKNOWN;
	void* Data = nullptr;
};

