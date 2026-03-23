#pragma once
#include "EngineMath.h"

struct FVector3D
{
	FVector3D();
	FVector3D(float _X, float _Y, float _Z);
	FVector3D(const FVector3D& _V);
	FVector3D(const DirectX::XMVECTOR& _V);

	// operator =
	const FVector3D& operator = (const FVector3D& _V);
	const FVector3D& operator = (const DirectX::XMVECTOR& _V);
	const FVector3D& operator = (float _Value);
	const FVector3D& operator = (int _Value);

	// operator +
	FVector3D operator + (const FVector3D& _V) const;
	FVector3D operator + (const DirectX::XMVECTOR& _V) const;
	FVector3D operator + (float _Value) const;
	FVector3D operator + (int _Value) const;

	// operator +=
	const FVector3D& operator += (const FVector3D& _V);
	const FVector3D& operator += (const DirectX::XMVECTOR& _V);
	const FVector3D& operator += (float _Value);
	const FVector3D& operator += (int _Value);

	// operator -
	FVector3D operator - (const FVector3D& _V) const;
	FVector3D operator - (const DirectX::XMVECTOR& _V) const;
	FVector3D operator - (float _Value) const;
	FVector3D operator - (int _Value) const;

	// operator -=
	const FVector3D& operator -= (const FVector3D& _V);
	const FVector3D& operator -= (const DirectX::XMVECTOR& _V);
	const FVector3D& operator -= (float _Value);
	const FVector3D& operator -= (int _Value);

	// operator *
	FVector3D operator * (const FVector3D& _V) const;
	FVector3D operator * (const DirectX::XMVECTOR& _V) const;
	FVector3D operator * (float _Value) const;
	FVector3D operator * (int _Value) const;

	// operator *=
	const FVector3D& operator *= (const FVector3D& _V);
	const FVector3D& operator *= (const DirectX::XMVECTOR& _V);
	const FVector3D& operator *= (float _Value);
	const FVector3D& operator *= (int _Value);

	// operator /
	FVector3D operator / (const FVector3D& _V) const;
	FVector3D operator / (const DirectX::XMVECTOR& _V) const;
	FVector3D operator / (float _Value) const;
	FVector3D operator / (int _Value) const;

	// operator /=
	const FVector3D& operator /= (const FVector3D& _V);
	const FVector3D& operator /= (const DirectX::XMVECTOR& _V);
	const FVector3D& operator /= (float _Value);
	const FVector3D& operator /= (int _Value);

	// operator ++, --
	const FVector3D& operator ++ ();
	const FVector3D& operator ++ (int);

	const FVector3D& operator -- ();
	const FVector3D& operator -- (int);

	// Func
	float		Length() const;
	float		Distance(const FVector3D& _V) const;
	void		Normalize();
	FVector3D	Normalize(const FVector3D& _V) const;

	float		Dot(const FVector3D& _V) const;
	FVector3D	Cross(const FVector3D& _V) const;
	float		Angle(const FVector3D& _V) const;
	DirectX::XMVECTOR Convert() const;

	float X = 0.f;
	float Y = 0.f;
	float Z = 0.f;
};

