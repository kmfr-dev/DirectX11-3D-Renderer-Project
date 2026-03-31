#include "Ref.h"

CRef::CRef()
{
}

CRef::~CRef()
{
}

void CRef::Release()
{
	--mRefCount;

	if (mRefCount == 0)
		delete this;
}
