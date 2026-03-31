#pragma once

template<typename T>
class CSharedPtr
{
public:
	CSharedPtr()
	{

	}
	CSharedPtr(T* _Ptr)
	{
		mPtr = _Ptr;

		if (mPtr)
			mPtr->AddRef();
	}
	CSharedPtr(const CSharedPtr<T>& _Ptr)
	{
		mPtr = _Ptr.mPtr;

		if (mPtr)
			mPtr->AddRef();
	}
	CSharedPtr(CSharedPtr<T>&& _Ptr)
	{
		mPtr = _Ptr.mPtr;

		if (mPtr)
			mPtr->AddRef();
	}
	~CSharedPtr()
	{
		if (mPtr)
			mPtr->Release();
	}

public:
	void operator = (T* _Ptr)
	{
		if (mPtr)
			mPtr->Release();

		mPtr = _Ptr;

		if (mPtr)
			mPtr->AddRef();
	}
	void operator = (const CSharedPtr<T>& _Ptr)
	{
		if (mPtr)
			mPtr->Release();

		mPtr = _Ptr.mPtr;

		if (mPtr)
			mPtr->AddRef();
	}
	void operator = (CSharedPtr<T>&& _Ptr)
	{
		if (mPtr)
			mPtr->Release();

		mPtr = _Ptr.mPtr;

		if (mPtr)
			mPtr->AddRef();
	}
	 
	bool operator == (T* _Obj) const { return mPtr == _Obj; }
	bool operator == (const CSharedPtr<T>& _Ptr) const { return mPtr == _Ptr.mPtr; }
	bool operator == (CSharedPtr<T>&& _Ptr) const { return mPtr == _Ptr.mPtr; }

	bool operator != (T* _Obj) const { return mPtr != _Obj; }
	bool operator != (const CSharedPtr<T>& _Ptr) const { return mPtr != _Ptr.mPtr; }
	bool operator != (CSharedPtr<T>&& _Ptr) const { return mPtr != _Ptr.mPtr; }

	T* operator -> () const { return mPtr; };
	operator T* () const { return mPtr; };

	T* Get() const { return mPtr; }

private:
	T* mPtr = nullptr;
};

