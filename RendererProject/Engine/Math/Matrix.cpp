#include "Matrix.h"
#include "Vector2.h"
#include "Vector3.h"
#include "../../Common/Define.h"

FMatrix::FMatrix()
{
	mMatrix = DirectX::XMMatrixIdentity();
}

FMatrix::FMatrix(const FMatrix& _M)
{
	mMatrix = _M.mMatrix;
}

FMatrix::FMatrix(const DirectX::XMMATRIX& _M)
 : mMatrix(_M)
{

}

FMatrix::FMatrix(const FVector4D _V[4])
{
	memcpy(V, _V, sizeof(FVector4D) * 4);
}

FVector4D& FMatrix::operator[](int _Index)
{
	assert(0 <= _Index && _Index <= 3);
	
	return V[_Index];
}

const FMatrix& FMatrix::operator= (const FMatrix& _M)
{
	mMatrix = _M.mMatrix;
	return *this;
}

const FMatrix& FMatrix::operator= (const DirectX::XMMATRIX& _M)
{
	mMatrix = _M;
	return *this;
}

const FMatrix& FMatrix::operator= (const FVector4D _V[4])
{
	memcpy(V, _V, sizeof(FVector4D) * 4);
	return *this;
}

FMatrix FMatrix::operator* (const FMatrix& _M) const
{
	return FMatrix(mMatrix * _M.mMatrix);
}

FMatrix FMatrix::operator* (const DirectX::XMMATRIX& _M) const
{
	return FMatrix(mMatrix * _M);
}

const FMatrix& FMatrix::operator*= (const FMatrix& _M)
{
	mMatrix *= _M.mMatrix;
	return *this;
}

const FMatrix& FMatrix::operator*= (const DirectX::XMMATRIX& _M)
{
	mMatrix* _M;
	return *this;
}

void FMatrix::Identity()
{
	mMatrix = DirectX::XMMatrixIdentity();
}

void FMatrix::Transpose()
{
	mMatrix = DirectX::XMMatrixTranspose(mMatrix);
}

void FMatrix::Inverse()
{
	DirectX::XMVECTOR Det = DirectX::XMMatrixDeterminant(mMatrix);
	mMatrix = DirectX::XMMatrixInverse(&Det, mMatrix);
}

void FMatrix::Scaling(const FVector3D& _V)
{
	mMatrix = DirectX::XMMatrixScaling(_V.X, _V.Y, _V.Z);
}

void FMatrix::Scaling(const FVector2D& _V)
{
	mMatrix = DirectX::XMMatrixScaling(_V.X, _V.Y, 1.f);
}

void FMatrix::Scaling(float _X, float _Y, float _Z)
{
	mMatrix = DirectX::XMMatrixScaling(_X, _Y, _Z);
}

void FMatrix::Scaling(float _X, float _Y)
{
	mMatrix = DirectX::XMMatrixScaling(_X, _Y, 1.f);
}

void FMatrix::Rotation(const FVector3D& _V)
{
	float X = DirectX::XMConvertToRadians(_V.X);
	float Y = DirectX::XMConvertToRadians(_V.Y);
	float Z = DirectX::XMConvertToRadians(_V.Z);

	// X, Y, Z 회전값을 이용하여 사원수를 구한다.
	DirectX::XMVECTOR Quat = DirectX::XMQuaternionRotationRollPitchYaw(X, Y, Z);

	// 사원수를 이용하여 회전행렬을 만들어준다.
	mMatrix = DirectX::XMMatrixRotationQuaternion(Quat);
}

void FMatrix::Rotation(float _X, float _Y, float _Z)
{
	float X = DirectX::XMConvertToRadians(_X);
	float Y = DirectX::XMConvertToRadians(_Y);
	float Z = DirectX::XMConvertToRadians(_Z);

	// X, Y, Z 회전값을 이용하여 사원수를 구한다.
	DirectX::XMVECTOR Quat = DirectX::XMQuaternionRotationRollPitchYaw(X, Y, Z);

	// 사원수를 이용하여 회전행렬을 만들어준다.
	mMatrix = DirectX::XMMatrixRotationQuaternion(Quat);
}

void FMatrix::RotationX(float _X)
{
	float X = DirectX::XMConvertToRadians(_X);
	
	mMatrix = DirectX::XMMatrixRotationX(X);
}

void FMatrix::RotationY(float _Y)
{
	float Y = DirectX::XMConvertToRadians(_Y);

	mMatrix = DirectX::XMMatrixRotationY(Y);
}

void FMatrix::RotationZ(float _Z)
{
	float Z = DirectX::XMConvertToRadians(_Z);

	mMatrix = DirectX::XMMatrixRotationY(Z);
}

void FMatrix::RotationQuaternion(const FVector4D& _Quat)
{
}

void FMatrix::RotationAxis(const FVector3D& _Axis, float _Angle)
{
	float Angle = DirectX::XMConvertToRadians(_Angle);

	DirectX::XMVECTOR Axis = DirectX::XMLoadFloat3((DirectX::XMFLOAT3*)&_Axis);
	
	mMatrix = DirectX::XMMatrixRotationAxis(Axis, Angle);
}

void FMatrix::Translation(const FVector3D& _V)
{
	mMatrix = DirectX::XMMatrixTranslation(_V.X, _V.Y, _V.Z);
}

void FMatrix::Translation(const FVector2D& _V)
{
	mMatrix = DirectX::XMMatrixTranslation(_V.X, _V.Y, 0.f);
}

void FMatrix::Translation(float _X, float _Y, float _Z)
{
	mMatrix = DirectX::XMMatrixTranslation(_X, _Y, _Z);
}

void FMatrix::Translation(float _X, float _Y)
{
	mMatrix = DirectX::XMMatrixTranslation(_X, _Y, 0.f);
}

FMatrix FMatrix::StaticIdentitiy()
{
	return DirectX::XMMatrixIdentity();
}

FMatrix FMatrix::StaticTranspose(const FMatrix& _M)
{
	return DirectX::XMMatrixTranspose(_M.mMatrix);
}

FMatrix FMatrix::StaticInverse(const FMatrix& _M)
{
	DirectX::XMVECTOR Det = DirectX::XMMatrixDeterminant(_M.mMatrix);

	return DirectX::XMMatrixInverse(&Det, _M.mMatrix);
}

FMatrix FMatrix::StaticScaling(const FVector3D& _V)
{
	return DirectX::XMMatrixScaling(_V.X, _V.Y, _V.Z);
}

FMatrix FMatrix::StaticScaling(const FVector2D& _V)
{
	return DirectX::XMMatrixScaling(_V.X, _V.Y, 1.f);
}

FMatrix FMatrix::StaticScaling(float _X, float _Y, float _Z)
{
	return DirectX::XMMatrixScaling(_X, _Y, _Z);
}

FMatrix FMatrix::StaticScaling(float _X, float _Y)
{
	return DirectX::XMMatrixScaling(_X, _Y, 1.f);
}

FMatrix FMatrix::StaticRotation(const FVector3D& _V)
{
	float X = DirectX::XMConvertToRadians(_V.X);
	float Y = DirectX::XMConvertToRadians(_V.Y);
	float Z = DirectX::XMConvertToRadians(_V.Z);

	// X, Y, Z 회전값을 이용하여 사원수를 구한다.
	DirectX::XMVECTOR Quat = DirectX::XMQuaternionRotationRollPitchYaw(X, Y, Z);

	// 사원수를 이용하여 회전행렬을 만들어준다.
	return FMatrix(DirectX::XMMatrixRotationQuaternion(Quat));
}

FMatrix FMatrix::StaticRotation(float _X, float _Y, float _Z)
{
	float X = DirectX::XMConvertToRadians(_X);
	float Y = DirectX::XMConvertToRadians(_Y);
	float Z = DirectX::XMConvertToRadians(_Z);

	// X, Y, Z 회전값을 이용하여 사원수를 구한다.
	DirectX::XMVECTOR Quat = DirectX::XMQuaternionRotationRollPitchYaw(X, Y, Z);

	// 사원수를 이용하여 회전행렬을 만들어준다.
	return DirectX::XMMatrixRotationQuaternion(Quat);
}

FMatrix FMatrix::StaticRotationX(float _X)
{
	float X = DirectX::XMConvertToRadians(_X);

	return DirectX::XMMatrixRotationX(X);
}

FMatrix FMatrix::StaticRotationY(float _Y)
{
	float Y = DirectX::XMConvertToRadians(_Y);

	return DirectX::XMMatrixRotationY(Y);
}

FMatrix FMatrix::StaticRotationZ(float _Z)
{
	float Z = DirectX::XMConvertToRadians(_Z);

	return DirectX::XMMatrixRotationZ(Z);
}

FMatrix FMatrix::StaticRotationQuaternion(const FVector4D& _Quat)
{
	return DirectX::XMMatrixRotationQuaternion(_Quat.Convert());
}

FMatrix FMatrix::StaticRotationAxis(const FVector3D& _Axis, float _Angle)
{
	float Angle = DirectX::XMConvertToRadians(_Angle);

	DirectX::XMVECTOR Axis = DirectX::XMLoadFloat3((DirectX::XMFLOAT3*)&_Axis);

	return DirectX::XMMatrixRotationAxis(Axis, Angle);
}

FMatrix FMatrix::StaticTranslation(const FVector3D& _V)
{
	return DirectX::XMMatrixTranslation(_V.X, _V.Y, _V.Z);
}

FMatrix FMatrix::StaticTranslation(const FVector2D& _V)
{
	return DirectX::XMMatrixTranslation(_V.X, _V.Y, 0.f);
}

FMatrix FMatrix::StaticTranslation(float _X, float _Y, float _Z)
{
	return DirectX::XMMatrixTranslation(_X, _Y, _Z);
}

FMatrix FMatrix::StaticTranslation(float _X, float _Y)
{
	return DirectX::XMMatrixTranslation(_X, _Y, 0.f);
}
