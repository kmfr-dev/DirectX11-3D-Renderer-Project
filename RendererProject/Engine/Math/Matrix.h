#pragma once

#include "Vector4.h"

struct FVector2D;
struct FVector3D;

// declspec(align(16)) : 메모리를 16바이트 단위로 정렬
// why 16? : SIMD라는 16바이트 연산을 빠르게 수행하는 레지스터로 행렬 연산을 하기위해
__declspec(align(16)) union  FMatrix
{
	DirectX::XMMATRIX mMatrix;

	struct
	{
		float	_11, _12, _13, _14;
		float	_21, _22, _23, _24;
		float	_31, _32, _33, _34;
		float	_41, _42, _43, _44;
	};

	FVector4D V[4];

	FMatrix();
	FMatrix(const FMatrix& _M);
	FMatrix(const DirectX::XMMATRIX& _M);
	FMatrix(const FVector4D _V[4]);

	// operator []
	FVector4D& operator[](int _Index);

	// operator =
	const FMatrix& operator = (const FMatrix& _M);
	const FMatrix& operator = (const DirectX::XMMATRIX& _M);
	const FMatrix& operator = (const FVector4D _V[4]);
	
	// operator *
	FMatrix operator * (const FMatrix& _M) const;
	FMatrix operator * (const DirectX::XMMATRIX& _M) const;

	// operator *=
	const FMatrix& operator *= (const FMatrix& _M);
	const FMatrix& operator *= (const DirectX::XMMATRIX& _M);

	// Func
	void Identity();
	void Transpose();
	void Inverse();

	void Scaling(const FVector3D& _V);
	void Scaling(const FVector2D& _V);
	void Scaling(float _X, float _Y, float _Z);
	void Scaling(float _X, float _Y);

	void Rotation(const FVector3D& _V);
	void Rotation(float _X, float _Y, float _Z);
	void RotationX(float _X);
	void RotationY(float _Y);
	void RotationZ(float _Z);

	void RotationQuaternion(const FVector4D& _Quat);
	void RotationAxis(const FVector3D& _Axis, float _Angle);

	void Translation(const FVector3D& _V);
	void Translation(const FVector2D& _V);
	void Translation(float _X, float _Y, float _Z);
	void Translation(float _X, float _Y);

	// static
	static FMatrix StaticIdentitiy();
	static FMatrix StaticTranspose(const FMatrix& _M);
	static FMatrix StaticInverse(const FMatrix& _M);

	static FMatrix StaticScaling(const FVector3D& _V);
	static FMatrix StaticScaling(const FVector2D& _V);
	static FMatrix StaticScaling(float _X, float _Y, float _Z);
	static FMatrix StaticScaling(float _X, float _Y);

	static FMatrix StaticRotation(const FVector3D& _V);
	static FMatrix StaticRotation(float _X, float _Y, float _Z);
	static FMatrix StaticRotationX(float _X);
	static FMatrix StaticRotationY(float _Y);
	static FMatrix StaticRotationZ(float _Z);

	static FMatrix StaticRotationQuaternion(const FVector4D& _Quat);
	static FMatrix StaticRotationAxis(const FVector3D& _Axis, float _Angle);
	static FMatrix StaticTranslation(const FVector3D& _V);
	static FMatrix StaticTranslation(const FVector2D& _V);
	static FMatrix StaticTranslation(float _X, float _Y, float _Z);
	static FMatrix StaticTranslation(float _X, float _Y);
};

