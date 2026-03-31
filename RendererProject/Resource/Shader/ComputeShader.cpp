#include "ComputeShader.h"
#include "../../Engine/Device/Device.h"


CComputeShader::CComputeShader()
{
}

CComputeShader::~CComputeShader()
{
    SAFE_RELEASE(mCS);
    SAFE_RELEASE(mCSBlob);
}

bool CComputeShader::Init()
{
    return true;
}

void CComputeShader::SetShader()
{
    CDevice::GetInst()->GetContext()->CSSetShader(mCS, nullptr, 0);
}