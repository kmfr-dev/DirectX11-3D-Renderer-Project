#pragma once

#include "EngineMath.h"

struct FVector4D
{
	FVector4D();
	FVector4D(float _X, float _Y, float _Z, float _W);
	FVector4D(const FVector4D& _V);
	FVector4D(const DirectX::XMVECTOR& _V);

	// operator =
	const FVector4D& operator = (const FVector4D& _V);
	const FVector4D& operator = (const DirectX::XMVECTOR& _V);
	const FVector4D& operator = (float _Value);
	const FVector4D& operator = (int _Value);

	// operator +
	FVector4D operator + (const FVector4D& _V) const;
	FVector4D operator + (const DirectX::XMVECTOR& _V) const;
	FVector4D operator + (float _Value) const;
	FVector4D operator + (int _Value) const;

	// operator +=
	const FVector4D& operator += (const FVector4D& _V);
	const FVector4D& operator += (const DirectX::XMVECTOR& _V);
	const FVector4D& operator += (float _Value);
	const FVector4D& operator += (int _Value);
	

	// operator -
	FVector4D operator - (const FVector4D& _V) const;
	FVector4D operator - (const DirectX::XMVECTOR& _V) const;
	FVector4D operator - (float _Value) const;
	FVector4D operator - (int _Value) const;

	// operator -=
	const FVector4D& operator -= (const FVector4D& _V);
	const FVector4D& operator -= (const DirectX::XMVECTOR& _V);
	const FVector4D& operator -= (float _Value);
	const FVector4D& operator -= (int _Value);

	// operator *
	FVector4D operator * (const FVector4D& _V) const;
	FVector4D operator * (const DirectX::XMVECTOR& _V) const;
	FVector4D operator * (float _Value) const;
	FVector4D operator * (int _Value) const;

	// operator *=
	const FVector4D& operator *= (const FVector4D& _V);
	const FVector4D& operator *= (const DirectX::XMVECTOR& _V);
	const FVector4D& operator *= (float _Value);
	const FVector4D& operator *= (int _Value);

	// operator /
	FVector4D operator / (const FVector4D& _V) const;
	FVector4D operator / (const DirectX::XMVECTOR& _V) const;
	FVector4D operator / (float _Value) const;
	FVector4D operator / (int _Value) const;

	// operator /=
	const FVector4D& operator /= (const FVector4D& _V);
	const FVector4D& operator /= (const DirectX::XMVECTOR& _V);
	const FVector4D& operator /= (float _Value);
	const FVector4D& operator /= (int _Value);

	// operator ++, --
	const FVector4D& operator ++();
	const FVector4D& operator ++(int);

	const FVector4D& operator --();
	const FVector4D& operator --(int);

	// operator []
	float& operator[](int _Index);

	// Func
	DirectX::XMVECTOR Convert() const;
	void Convert(const DirectX::XMVECTOR& _V);

	// Variable
	static FVector4D Red;
	static FVector4D Blue;
	static FVector4D Green;
	static FVector4D White;
	static FVector4D Black;

	float X = 0.f;
	float Y = 0.f;
	float Z = 0.f;
	float W = 0.f;
};

