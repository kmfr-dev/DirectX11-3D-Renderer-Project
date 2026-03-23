#pragma once

#include "EngineMath.h"

struct FVector2D
{
	// Construct
	FVector2D();
	FVector2D(float _X, float _Y);
	FVector2D(const FVector2D& _V);

	// operator =
	const FVector2D& operator = (const FVector2D& _V);
	const FVector2D& operator = (float _Value);
	const FVector2D& operator = (int _Value);

	// operator +
	FVector2D operator + (const FVector2D& _V) const;
	FVector2D operator + (float _Value) const;
	FVector2D operator + (int _Value) const;

	// operator +=
	const FVector2D& operator += (const FVector2D& _V);
	const FVector2D& operator += (float _Value);
	const FVector2D& operator += (int _Value);

	// operator -
	FVector2D operator - (const FVector2D& _V) const;
	FVector2D operator - (float _Value) const;
	FVector2D operator - (int _Value) const;

	// operator -=
	const FVector2D& operator -= (const FVector2D& _V);
	const FVector2D& operator -= (float _Value);
	const FVector2D& operator -= (int _Value);

	// operator *
	FVector2D operator * (const FVector2D& _V) const;
	FVector2D operator * (float _Value) const;
	FVector2D operator * (int _Value) const;

	// operator *=
	const FVector2D& operator *= (const FVector2D& _V);
	const FVector2D& operator *= (float _Value);
	const FVector2D& operator *= (int _Value);

	// operator /
	FVector2D operator / (const FVector2D& _V) const;
	FVector2D operator / (float _Value) const;
	FVector2D operator / (int _Value) const;

	// operator /=
	const FVector2D& operator /= (const FVector2D& _V);
	const FVector2D& operator /= (float _Value);
	const FVector2D& operator /= (int _Value);

	// operator ++
	const FVector2D& operator ++ ();
	const FVector2D& operator ++ (int);

	// operator --
	const FVector2D& operator -- ();
	const FVector2D& operator -- (int);

	// Func
	float	Length() const;
	void	Normalize();
	float	Distance(const FVector2D& _V) const;
	float	Angle(const FVector2D& _V) const;
	float	Dot(const FVector2D& _V) const;

	// Variable
	float X = 0.f;
	float Y = 0.f;
};