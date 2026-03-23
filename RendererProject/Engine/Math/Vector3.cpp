#include "Vector3.h"

FVector3D::FVector3D()
{
}

FVector3D::FVector3D(float _X, float _Y, float _Z)
    : X(_X), Y(_Y), Z(_Z)
{
}

FVector3D::FVector3D(const FVector3D& _V)
    : X(_V.X), Y(_V.Y), Z(_V.Z)
{
}

FVector3D::FVector3D(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat3((DirectX::XMFLOAT3*)this, _V);
}

const FVector3D& FVector3D::operator=(const FVector3D& _V)
{
    X = _V.X;
    Y = _V.Y;
    Z = _V.Z;
    return *this;
}

const FVector3D& FVector3D::operator=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat3((DirectX::XMFLOAT3*)this, _V);
    return *this;
}

const FVector3D& FVector3D::operator=(float _Value)
{
    X = _Value;
    Y = _Value;
    Z = _Value;
    return *this;
}

const FVector3D& FVector3D::operator=(int _Value)
{
    X = (float)_Value;
    Y = (float)_Value;
    Z = (float)_Value;
    return *this;
}

FVector3D FVector3D::operator+(const FVector3D& _V) const
{
    FVector3D Result;
    Result.X = X + _V.X;
    Result.Y = Y + _V.Y;
    Result.Z = Z + _V.Z;
    return Result;
}

FVector3D FVector3D::operator+(const DirectX::XMVECTOR& _V) const
{
    return FVector3D(DirectX::XMVectorAdd(Convert(), _V));
}

FVector3D FVector3D::operator+(float _Value) const
{
    FVector3D Result;
    Result.X = X + _Value;
    Result.Y = Y + _Value;
    Result.Z = Z + _Value;
    return Result;
}

FVector3D FVector3D::operator+(int _Value) const
{
    FVector3D Result;
    Result.X = X + (float)_Value;
    Result.Y = Y + (float)_Value;
    Result.Z = Z + (float)_Value;
    return Result;
}

const FVector3D& FVector3D::operator+=(const FVector3D& _V)
{
    X += _V.X;
    Y += _V.Y;
    Z += _V.Z;
    return *this;
}

const FVector3D& FVector3D::operator+=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMVECTOR V1 = Convert();

    *this = DirectX::XMVectorAdd(V1, _V);
    return *this;
}

const FVector3D& FVector3D::operator+=(float _Value)
{
    X += _Value;
    Y += _Value;
    Z += _Value;
    return *this;
}

const FVector3D& FVector3D::operator+=(int _Value)
{
    X += (float)_Value;
    Y += (float)_Value; 
    Z += _Value;
    return *this;
}

FVector3D FVector3D::operator-(const FVector3D& _V) const
{
    FVector3D Result;
    Result.X = X - _V.X;
    Result.Y = Y - _V.Y;
    return Result;
}

FVector3D FVector3D::operator - (const DirectX::XMVECTOR& _V) const
{
    return FVector3D(DirectX::XMVectorSubtract(Convert(), _V));
}

FVector3D FVector3D::operator-(float _Value) const
{
    FVector3D Result;
    Result.X = X - _Value;
    Result.Y = Y - _Value;
    Result.Z = Z - _Value;
    return Result;
}

FVector3D FVector3D::operator-(int _Value) const
{
    FVector3D Result;
    Result.X = X - (float)_Value;
    Result.Y = Y - (float)_Value;
    Result.Z = Z - (float)_Value;
    return Result;
}

const FVector3D& FVector3D::operator-=(const FVector3D& _V)
{
    X -= _V.X;
    Y -= _V.Y;
    Z -= _V.Z;
    return *this;
}

const FVector3D& FVector3D::operator-=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMVECTOR V1 = Convert();

    *this = DirectX::XMVectorSubtract(V1, _V);
    return *this;
}

const FVector3D& FVector3D::operator-=(float _Value)
{
    X -= _Value;
    Y -= _Value;
    Z -= _Value;
    return *this;
}

const FVector3D& FVector3D::operator-=(int _Value)
{
    X -= (float)_Value;
    Y -= (float)_Value;
    Z -= (float)_Value;
    return *this;
}

FVector3D FVector3D::operator * (const FVector3D& _V)	const
{
    FVector3D	Result;
    Result.X = X * _V.X;
    Result.Y = Y * _V.Y;
    Result.Z = Z * _V.Z;
    return Result;
}

FVector3D FVector3D::operator * (const DirectX::XMVECTOR& _V)	const
{
    return FVector3D(DirectX::XMVectorMultiply(Convert(), _V));
}

FVector3D FVector3D::operator * (float _Value)	const
{
    FVector3D	Result;
    Result.X = X * _Value;
    Result.Y = Y * _Value;
    Result.Z = Z * _Value;
    return Result;
}

FVector3D FVector3D::operator * (int _Value)	const
{
    FVector3D	Result;
    Result.X = X * (float)_Value;
    Result.Y = Y * (float)_Value;
    Result.Z = Z * (float)_Value;
    return Result;
}

const FVector3D& FVector3D::operator *= (const FVector3D& _V)
{
    X *= _V.X;
    Y *= _V.Y;
    Z *= _V.Z;
    return *this;
}

const FVector3D& FVector3D::operator *= (const DirectX::XMVECTOR& _V)
{
    DirectX::XMVECTOR V1 = Convert();

    *this = DirectX::XMVectorMultiply(V1, _V);
    return *this;
}

const FVector3D& FVector3D::operator *= (float _Value)
{
    X *= _Value;
    Y *= _Value;
    Z *= _Value;
    return *this;
}

const FVector3D& FVector3D::operator *= (int _Value)
{
    X *= (float)_Value;
    Y *= (float)_Value;
    Z *= (float)_Value;
    return *this;
}

FVector3D FVector3D::operator / (const FVector3D& _V)	const
{
    FVector3D	Result;
    Result.X = X / _V.X;
    Result.Y = Y / _V.Y;
    Result.Z = Z / _V.Z;
    return Result;
}

FVector3D FVector3D::operator / (const DirectX::XMVECTOR& _V)	const
{
    
    return  FVector3D(DirectX::XMVectorDivide(Convert(), _V));
}

FVector3D FVector3D::operator / (float _Value)	const
{
    FVector3D	Result;
    Result.X = X / _Value;
    Result.Y = Y / _Value;
    Result.Z = Z / _Value;
    return Result;
}

FVector3D FVector3D::operator / (int _Value)	const
{
    FVector3D	Result;
    Result.X = X / (float)_Value;
    Result.Y = Y / (float)_Value;
    Result.Z = Z / (float)_Value;
    return Result;
}

// /=
const FVector3D& FVector3D::operator /= (const FVector3D& _V)
{
    X /= _V.X;
    Y /= _V.Y;
    Z /= _V.Z;
    return *this;
}

const FVector3D& FVector3D::operator /= (const DirectX::XMVECTOR& _V)
{
    DirectX::XMVECTOR V1 = Convert();

    *this = DirectX::XMVectorDivide(V1, _V);
    return *this;
}

const FVector3D& FVector3D::operator /= (float _Value)
{
    X /= _Value;
    Y /= _Value;
    Z /= _Value;
    return *this;
}

const FVector3D& FVector3D::operator /= (int _Value)
{
    X /= (float)_Value;
    Y /= (float)_Value;
    Z /= (float)_Value;
    return *this;
}

const FVector3D& FVector3D::operator ++ ()
{
    X += 1.f;
    Y += 1.f;
    Z += 1.f;
    return *this;
}

const FVector3D& FVector3D::operator ++ (int)
{
    X += 1.f;
    Y += 1.f;
    Z += 1.f;
    return *this;
}

const FVector3D& FVector3D::operator -- ()
{
    X -= 1.f;
    Y -= 1.f;
    Z -= 1.f;
    return *this;
}

const FVector3D& FVector3D::operator -- (int)
{
    X -= 1.f;
    Y -= 1.f;
    Z -= 1.f;
    return *this;
}

float FVector3D::Length() const
{
    return sqrt(X * X + Y * Y + Z * Z);
}

float FVector3D::Distance(const FVector3D& _V) const
{
    FVector3D Vec = *this - _V;

    return Vec.Length();
}

void FVector3D::Normalize()
{
    const float Size = Length();

    if (Size == 0.f)
        return;

    X /= Size;
    Y /= Size;
    Z /= Size;
}

FVector3D FVector3D::Normalize(const FVector3D& _V) const
{
    FVector3D Result;

    const float Size = _V.Length();

    if (Size == 0.f)
        return Result;

    Result.X = _V.X / Size;
    Result.Y = _V.Y / Size;
    Result.Z = _V.Z / Size;

    return Result;
}

float FVector3D::Angle(const FVector3D& _V) const
{
    FVector3D AVector = *this;
    FVector3D BVector = _V;

    AVector.Normalize();
    BVector.Normalize();

    float Angle = AVector.Dot(BVector);

    Angle = DirectX::XMConvertToDegrees(acosf(Angle));

    return Angle;
}

DirectX::XMVECTOR FVector3D::Convert() const
{
    return DirectX::XMLoadFloat3((DirectX::XMFLOAT3*)this);
}


float FVector3D::Dot(const FVector3D& _V) const
{
    return X * _V.X + Y * _V.Y + Z * _V.Z;
}

FVector3D FVector3D::Cross(const FVector3D& _V) const
{
    FVector3D Result;
    Result.X = Y * _V.Z - Z * _V.Y;
    Result.Y = Z * _V.X - X * _V.Z;
    Result.Z = X * _V.Y - Y * _V.X;

    return Result;
}
