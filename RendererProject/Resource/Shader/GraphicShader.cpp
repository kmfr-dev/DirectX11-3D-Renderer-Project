#include "GraphicShader.h"
#include "../../Engine/Device/Device.h"
#include "ComputeShader.h"

CGraphicShader::CGraphicShader()
{
}

CGraphicShader::~CGraphicShader()
{
    SAFE_RELEASE(mInputLayout);

    SAFE_RELEASE(mVS);
    SAFE_RELEASE(mVSBlob);

    SAFE_RELEASE(mPS);
    SAFE_RELEASE(mPSBlob);

    SAFE_RELEASE(mHS);
    SAFE_RELEASE(mHSBlob);

    SAFE_RELEASE(mDS);
    SAFE_RELEASE(mDSBlob);

    SAFE_RELEASE(mGS);
    SAFE_RELEASE(mGSBlob);
}

bool CGraphicShader::Init()
{
    return true;
}

void CGraphicShader::SetShader()
{
    CDevice::GetInst()->GetContext()->VSSetShader(mVS, nullptr, 0);
    CDevice::GetInst()->GetContext()->PSSetShader(mPS, nullptr, 0);
    CDevice::GetInst()->GetContext()->HSSetShader(mHS, nullptr, 0);
    CDevice::GetInst()->GetContext()->DSSetShader(mDS, nullptr, 0);
    CDevice::GetInst()->GetContext()->GSSetShader(mGS, nullptr, 0);

    CDevice::GetInst()->GetContext()->IASetInputLayout(mInputLayout);
}

void CGraphicShader::AddInputLayoutDesc(const char* _Semantic, unsigned int _SemanticIndex,
    DXGI_FORMAT _Format, unsigned int _Slot, unsigned int _Size, 
    D3D11_INPUT_CLASSIFICATION _InputSlotClass, unsigned int _InstanceDataStepRate)
{
    D3D11_INPUT_ELEMENT_DESC Desc = {};

    Desc.SemanticName = _Semantic;
    Desc.SemanticIndex = _SemanticIndex;
    Desc.Format = _Format;
    Desc.InputSlot = _Slot;
    Desc.InputSlotClass = _InputSlotClass;
    Desc.InstanceDataStepRate = _InstanceDataStepRate;
    Desc.AlignedByteOffset = mInputLayoutSize;

    mInputLayoutSize += _Size;

    mInputDesc.emplace_back(Desc);
}

bool CGraphicShader::CreateInputLayout()
{
    if (FAILED(CDevice::GetInst()->GetDevice()->CreateInputLayout(&mInputDesc[0],
        (UINT)mInputDesc.size(), mVSBlob->GetBufferPointer(), mVSBlob->GetBufferSize(), &mInputLayout)))
        return false;

    return true;
}
