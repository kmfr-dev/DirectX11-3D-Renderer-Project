#include "Device.h"

DEFINITION_SINGLE(CDevice)

CDevice::CDevice()
{
}

CDevice::~CDevice()
{
	SAFE_RELEASE(mTargetView);
	SAFE_RELEASE(mDepthView);

	SAFE_RELEASE(mSwapChain);

	if (mContext)
		mContext->ClearState();

	SAFE_RELEASE(mContext);

	SAFE_RELEASE(mDevice);

}
bool CDevice::Init(HWND hWnd, unsigned int Width, unsigned int Height, bool WindowMode)
{
	mhWnd = hWnd;
	mRS.Width = Width;
	mRS.Height = Height;
	mWindowMode = WindowMode;

	if (!CreateDevice())
		return false;

	if (!CreateSwapChain())
		return false;

	if (!CreateRenderTargetView())
		return false;

    return true;
}

void CDevice::ClearBackBuffer(float ClearColor[4])
{
	mContext->ClearRenderTargetView(mTargetView, ClearColor);
}

void CDevice::ClearDepthStencil(float Depth, unsigned char Stencil)
{
	mContext->ClearDepthStencilView(mDepthView, 
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, Depth, Stencil);
}

void CDevice::SetTarget()
{
	// 출력시 값을 저장할 렌더타겟과 뎁스뷰를 지정한다.
	mContext->OMSetRenderTargets(1, &mTargetView, mDepthView);
}

void CDevice::Render()
{
	mSwapChain->Present(0, 0);
}

bool CDevice::CreateDevice()
{
	UINT Flag = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#ifdef _DEBUG
	Flag |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	D3D_FEATURE_LEVEL	FLevel = D3D_FEATURE_LEVEL_11_0;
	D3D_FEATURE_LEVEL	FLevelResult;

	// Device와 DeviceContext를 생성한다.
	if (FAILED(D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, 0, Flag, &FLevel,
		1, D3D11_SDK_VERSION, &mDevice, &FLevelResult, &mContext)))
	{
		return false;
	}

	return true;
}

bool CDevice::CreateSwapChain()
{
	mSampleCount = 4;

	// 생성된 Device를 이용하여 지원되는 멀티샘플링 수를 얻어온다.
	unsigned int	Check = 0;

	mDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &Check);

	if (Check < 1)
		mSampleCount = 1;

	// SwapChain을 생성한다
	DXGI_SWAP_CHAIN_DESC SwapDesc = {};

	// BufferDesc : 후면버퍼에 대한 정의
	// 백버퍼의 가로/세로 해상도 지정
	SwapDesc.BufferDesc.Width = mRS.Width;
	SwapDesc.BufferDesc.Height = mRS.Height;

	// 백버퍼의 픽셀 포멧 설정
	SwapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

	// 화면 주사율 지정
	SwapDesc.BufferDesc.RefreshRate.Numerator = 1;
	SwapDesc.BufferDesc.RefreshRate.Denominator = 60;

	SwapDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	SwapDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;

	// BackBuffer의 개수 지정
	SwapDesc.BufferCount = 1;
	// Buffer의 용도 지정
	SwapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	// 출력할 윈도우 핸들 지정
	SwapDesc.OutputWindow = mhWnd;

	// 멀티샘플링 지정
	SwapDesc.SampleDesc.Count = mSampleCount;
	SwapDesc.SampleDesc.Quality = 0;

	// 전체/창 모드 지정
	SwapDesc.Windowed = mWindowMode;

	// SwapChain이 Buffer 전환 시 사용하는 동작 지정
	// DXGI_SWAP_EFFECT_DISCARD : 디스플레이 구동기가 가장 효율적인 전환 방법 선택
	SwapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	IDXGIDevice* DXGIDevice = nullptr;

	mDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&DXGIDevice);

	assert(DXGIDevice);

	IDXGIAdapter* Adapter = nullptr;
	DXGIDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&Adapter);

	// IDXGIFactory 인터페이스 얻기
	IDXGIFactory* Factory = nullptr;
	Adapter->GetParent(__uuidof(IDXGIFactory), (void**)&Factory);

	// SwapChain 생성
	if (FAILED(Factory->CreateSwapChain(mDevice, &SwapDesc, &mSwapChain)))
	{
		SAFE_RELEASE(Factory);
		SAFE_RELEASE(Adapter);
		SAFE_RELEASE(DXGIDevice);
		return false;
	}
	
	SAFE_RELEASE(Factory);
	SAFE_RELEASE(Adapter);
	SAFE_RELEASE(DXGIDevice);

	return true;
}

bool CDevice::CreateRenderTargetView()
{
	ID3D11Texture2D* BackBuffer = nullptr;

	// GetBuffer를 하며 버퍼를 얻어오면 AddRef가 호출된 상태로 얻어온다.
	if (FAILED(mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&BackBuffer)))
	{
		return false;
	}

	// 백버퍼에 출력하기 위한 렌더타겟을 만든다.
	if (FAILED(mDevice->CreateRenderTargetView(BackBuffer, nullptr, &mTargetView)))
	{
		return false;
	}

	// RefCount를 감소시킨다.
	SAFE_RELEASE(BackBuffer);

	// DepthStencil Buffer를 만들어주기 위한 Texture를 생성한다.
	D3D11_TEXTURE2D_DESC	DepthDesc = {};

	DepthDesc.Width = mRS.Width;
	DepthDesc.Height = mRS.Height;
	DepthDesc.ArraySize = 1;
	DepthDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	DepthDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	DepthDesc.Usage = D3D11_USAGE_DEFAULT;
	DepthDesc.SampleDesc.Quality = 0;
	DepthDesc.SampleDesc.Count = mSampleCount;
	DepthDesc.MipLevels = 1;

	ID3D11Texture2D* DepthBuffer = nullptr;

	// 위에서 정의한 깊이버퍼용 Texture를 만든다.
	if (FAILED(mDevice->CreateTexture2D(&DepthDesc, nullptr, &DepthBuffer)))
	{
		return false;
	}
	// 깊이버퍼를 만든다.
	if (FAILED(mDevice->CreateDepthStencilView(DepthBuffer, nullptr, &mDepthView)))
	{
		return false;
	}

	SAFE_RELEASE(DepthBuffer);

	D3D11_VIEWPORT ViewPort = {};
	ViewPort.Width = (float)mRS.Width;
	ViewPort.Height = (float)mRS.Height;
	ViewPort.MaxDepth = 1.f;

	mContext->RSSetViewports(1, &ViewPort);

	return true;
}
