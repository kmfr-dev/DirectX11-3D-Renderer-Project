#include "ConstantBuffer.h"
#include "../../Engine/Device/Device.h"

CConstantBuffer::CConstantBuffer()
{
}

CConstantBuffer::~CConstantBuffer()
{
    SAFE_RELEASE(mBuffer);
}

bool CConstantBuffer::Init(int _Size, int _Register, int _ShaderBufferType)
{
    mSize = _Size;
    mRegister = _Register;
    mShaderBufferType = _ShaderBufferType;

    D3D11_BUFFER_DESC   Desc = {};

    // 상수버퍼는 정보 갱신이 많기 때문에 용도를 Dynamic으로 설정
    Desc.Usage = D3D11_USAGE_DYNAMIC;
    // 버퍼 크기
    Desc.ByteWidth = _Size;
    // 상수 버퍼로 사용하겠다고 플래그 지정
    Desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    // CPU에서 상수버퍼에 값을 쓰겠다고 플래그 지정
    Desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    if (FAILED(CDevice::GetInst()->GetDevice()->CreateBuffer(
        &Desc, nullptr, &mBuffer)))
        return false;

    return true;
}

void CConstantBuffer::UpdateBuffer(void* _Data)
{
    // Buffer 안에 있는 데이터를 저장하기 위한 배열의 주소를 가져온다.
    D3D11_MAPPED_SUBRESOURCE    Map = {};

    CDevice::GetInst()->GetContext()->Map(mBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &Map);
    
    memcpy(Map.pData, _Data, mSize);

    CDevice::GetInst()->GetContext()->Unmap(mBuffer, 0);

    // 위에서 인자로 들어온 데이터로 버퍼를 채워주면
    // 지정된 Shader에 상수버퍼의 데이터를 넘겨준다.

    if (mShaderBufferType & EShaderBufferType::Vertex)
        CDevice::GetInst()->GetContext()->VSSetConstantBuffers(mRegister, 1, &mBuffer);

    if (mShaderBufferType & EShaderBufferType::Pixel)
        CDevice::GetInst()->GetContext()->PSSetConstantBuffers(mRegister, 1, &mBuffer);

    if (mShaderBufferType & EShaderBufferType::Hull)
        CDevice::GetInst()->GetContext()->HSSetConstantBuffers(mRegister, 1, &mBuffer);

    if (mShaderBufferType & EShaderBufferType::Domain)
        CDevice::GetInst()->GetContext()->DSSetConstantBuffers(mRegister, 1, &mBuffer);

    if (mShaderBufferType & EShaderBufferType::Geometry)
        CDevice::GetInst()->GetContext()->GSSetConstantBuffers(mRegister, 1, &mBuffer);

    if (mShaderBufferType & EShaderBufferType::Compute)
        CDevice::GetInst()->GetContext()->CSSetConstantBuffers(mRegister, 1, &mBuffer);
}
