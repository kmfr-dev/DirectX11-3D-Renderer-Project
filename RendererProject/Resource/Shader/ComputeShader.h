#pragma once
#include "Shader.h"

class CComputeShader :
    public CShader
{
    friend class CShaderManager;

protected:
    CComputeShader();
    ~CComputeShader();

private:
    ID3D11ComputeShader* mCS = nullptr;
    ID3DBlob* mCSBlob = nullptr;

public:
    virtual bool Init() override;
    virtual void SetShader() final;
};