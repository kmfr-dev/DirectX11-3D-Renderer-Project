#pragma once
#include "Shader.h"

class CGraphicShader :
    public CShader
{
    friend class CShaderManager;

protected:
    CGraphicShader();
    virtual ~CGraphicShader();

private:
    ID3D11InputLayout* mInputLayout = nullptr;
    std::vector<D3D11_INPUT_ELEMENT_DESC> mInputDesc;
    unsigned int mInputLayoutSize = 0;

    // VertexShader 객체 / 버퍼
    ID3D11VertexShader* mVS = nullptr;
    ID3DBlob* mVSBlob = nullptr;
    
    // PixelShader 객체 / 버퍼
    ID3D11PixelShader* mPS = nullptr;
    ID3DBlob* mPSBlob = nullptr;

    // HullShader 객체 / 버퍼
    ID3D11HullShader* mHS = nullptr;
    ID3DBlob* mHSBlob = nullptr;

    // DomainShader 객체 / 버퍼
    ID3D11DomainShader* mDS = nullptr;
    ID3DBlob* mDSBlob = nullptr;
    
    // GeometryShader 객체 / 버퍼
    ID3D11GeometryShader* mGS = nullptr;
    ID3DBlob* mGSBlob = nullptr;

public:
    virtual bool Init() = 0;
    virtual void SetShader() final;

public:
    void AddInputLayoutDesc(const char* _Semantic, unsigned int _SemanticIndex,
        DXGI_FORMAT _Format, unsigned int _Slot, unsigned int _Size,
        D3D11_INPUT_CLASSIFICATION _InputSlotClass,
        unsigned int _InstanceDataStepRate);
    bool CreateInputLayout();




};

