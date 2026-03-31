#pragma once

#include "../../Common/Define.h"
#include "Shader.h"

class CConstantBuffer;

class CShaderManager
{
private:
	std::unordered_map<std::string, CSharedPtr<CShader>> mShaderMap;
	std::unordered_map <std::string, CSharedPtr<CConstantBuffer>> mConstantBufferMap;

public:
	bool Init();

#pragma region Shader
	CShader* FindShader(const std::string& _ShaderName);
	void	 ReleaseShader(const std::string& _ShaderName);

	template<typename T>
	bool CreateShader(const std::string& _NewShaderName)
	{
		CShader* Shader = FindShader(_NewShaderName);

		if (Shader)
			return true;

		Shader = new T;

		if (!Shader->Init())
		{
			SAFE_DELETE(Shader);
			return false;
		}

		Shader->SetName(_NewShaderName);

		mShaderMap.insert({ _NewShaderName, Shader });

		return true;
	}

#pragma endregion

#pragma region ConstantBuffer
	bool CreateConstantBuffer(const std::string& _NewCBufferName, int _Size,
		int _Register, int ShaderBufferType = EShaderBufferType::Graphic);

	CConstantBuffer* FindConstantBuffer(const std::string& _CBufferName);
	
	void ReleaseConstantBuffer(const std::string& _CBufferName);

#pragma endregion

};

