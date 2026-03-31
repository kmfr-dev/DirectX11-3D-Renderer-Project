#pragma once

#include "../../Engine/Ref/Ref.h"

class CShader abstract :
	public CRef
{
	friend class CShaderManager;

protected:
	CShader();
	virtual ~CShader();

public:
	virtual bool Init() = 0;
	virtual void SetShader() = 0;
};

