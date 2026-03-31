#pragma once

#include "../../Common/Define.h"

class CRef
{
public:
	CRef();
	virtual ~CRef();

protected:
	std::string mName = "";
	int			mRefCount = 0;
	bool		mEnable = true;
	bool		mActive = true;

public:
	virtual void Enable(bool bEnable) { mEnable = bEnable; }
	virtual void Destroy() { mActive = false; }
	virtual void Release();

	bool IsEnable() const { return mActive; }
	bool IsActive() const { return mActive; }

	void AddRef() { ++mRefCount; }
	int	 GetRefCount() const { return mRefCount; }

	void SetName(const std::string& _NewName) { mName = _NewName; }
	const std::string& GetName() const { return mName; }

};

