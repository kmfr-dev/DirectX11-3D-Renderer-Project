#pragma once

#include "../../Common/Define.h"

class CDevice
{
private:
	ID3D11Device* mDevice = nullptr;
	ID3D11DeviceContext* mContext = nullptr;
	
	// 페이지 플리핑 처리를 위한 스왑체인
	IDXGISwapChain* mSwapChain = nullptr;

	ID3D11RenderTargetView* mTargetView = nullptr;
	ID3D11DepthStencilView* mDepthView = nullptr;
	
	HWND			mhWnd = {};
	FResolution		mRS = {};

	bool			mWindowMode = true;
	UINT			mSampleCount = 0;

private:
	//ID2D1RenderTarget* m2DTarget = nullptr;
	//ID2D1Factory* m2DFacotry = nullptr;

public: 
	ID3D11Device*			GetDevice() const { return mDevice; }
	ID3D11DeviceContext*	GetContext() const { return mContext; }
	IDXGISwapChain*			GetSwapChain() const { return mSwapChain; }
	const FResolution&		GetResolution() const { return mRS; }
	bool					GetWindowMode()	const { return mWindowMode; }

public:
	bool Init(HWND hWnd, unsigned int Width, unsigned int Height, bool WindowMode);

	void ClearBackBuffer(float ClearColor[4]);
	void ClearDepthStencil(float Depth, unsigned char Stencil);
	void SetTarget();
	void Render();

private:
	bool CreateDevice();
	bool CreateSwapChain();
	bool CreateRenderTargetView();

	DECLARE_SINGLE(CDevice)
};

