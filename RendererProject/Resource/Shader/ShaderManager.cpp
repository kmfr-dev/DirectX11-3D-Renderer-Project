#include "ShaderManager.h"
#include "../ConstantBuffer/ConstantBuffer.h"

bool CShaderManager::Init()
{



	return true;
}

CShader* CShaderManager::FindShader(const std::string& _ShaderName)
{
	auto Iter = mShaderMap.find(_ShaderName);
	if (Iter == mShaderMap.end())
		return nullptr;

	return Iter->second;
}

void CShaderManager::ReleaseShader(const std::string& _ShaderName)
{
	auto Iter = mShaderMap.find(_ShaderName);

	if (Iter != mShaderMap.end())
	{
		mShaderMap.erase(Iter);
	}
}

bool CShaderManager::CreateConstantBuffer(const std::string& _NewCBufferName, 
	int _Size, int _Register, int ShaderBufferType)
{
	CConstantBuffer* ConstantBuffer = FindConstantBuffer(_NewCBufferName);

	if (ConstantBuffer)
		return true;

	ConstantBuffer = new CConstantBuffer;

	if (!ConstantBuffer->Init(_Size, _Register, ShaderBufferType))
	{
		SAFE_DELETE(ConstantBuffer);
		return false;
	}

	ConstantBuffer->SetName(_NewCBufferName);

	mConstantBufferMap.insert({ _NewCBufferName, ConstantBuffer });

	return true;
}

CConstantBuffer* CShaderManager::FindConstantBuffer(const std::string& _CBufferName)
{
	auto Iter = mConstantBufferMap.find(_CBufferName);
	
	if (Iter == mConstantBufferMap.end())
		return nullptr;

	return Iter->second;
}

void CShaderManager::ReleaseConstantBuffer(const std::string& _CBufferName)
{
	auto Iter = mConstantBufferMap.find(_CBufferName);

	if (Iter != mConstantBufferMap.end())
	{
		mConstantBufferMap.erase(Iter);
	}
}
