#pragma once
#include "../../Engine/Ref/Ref.h"

class CConstantBuffer :
    public CRef
{
    friend class CShaderManager;

private: 
    CConstantBuffer();
    ~CConstantBuffer();

private:
    ID3D11Buffer* mBuffer = nullptr;
    int     mSize = 0;
    int     mRegister = 0;
    int     mShaderBufferType = 0;

public:
    bool Init(int _Size, int _Register, int _ShaderBufferType);
    void UpdateBuffer(void* _Data);
};

