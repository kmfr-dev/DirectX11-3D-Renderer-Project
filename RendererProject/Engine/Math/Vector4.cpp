#include "Vector4.h"

FVector4D::FVector4D()
{
}

FVector4D::FVector4D(float _X, float _Y, float _Z, float _W)
	: X(_X), Y(_Y), Z(_Z), W(_W)
{
}

FVector4D::FVector4D(const FVector4D& _V)
	: X(_V.X), Y(_V.Y), Z(_V.Z), W(_V.W)
{
}

FVector4D::FVector4D(const DirectX::XMVECTOR& _V)
{
	DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, _V);
}

const FVector4D& FVector4D::operator=(const FVector4D& _V)
{
    X = _V.X;
    Y = _V.Y;
    Z = _V.Z;
    W = _V.W;

    return *this;
}

const FVector4D& FVector4D::operator=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, _V);
    return *this;
}

const FVector4D& FVector4D::operator=(float _Value)
{
    X = _Value;
    Y = _Value;
    Z = _Value;
    W = _Value;
    return *this;
}

const FVector4D& FVector4D::operator=(int _Value)
{
    X = (float)_Value;
    Y = (float)_Value;
    Z = (float)_Value;
    W = (float)_Value;
    return *this;
}

FVector4D FVector4D::operator+(const FVector4D& _V) const
{
    FVector4D Result;
    Result.X = X + _V.X;
    Result.Y = Y + _V.Y;
    Result.Z = Z + _V.Z;
    Result.W = W + _V.W;
    return Result;
}

FVector4D FVector4D::operator+(const DirectX::XMVECTOR& _V) const
{
    return FVector4D(DirectX::XMVectorAdd(Convert(), _V));
}

FVector4D FVector4D::operator+(float _Value) const
{
    FVector4D Result;
    Result.X = X + _Value;
    Result.Y = Y + _Value;
    Result.Z = Z + _Value;
    Result.W = W + _Value;
    return Result;
}

FVector4D FVector4D::operator+(int _Value) const
{
    FVector4D Result;
    Result.X = X + (float)_Value;
    Result.Y = Y + (float)_Value;
    Result.Z = Z + (float)_Value;
    Result.W = W + (float)_Value;
    return Result;
}

const FVector4D& FVector4D::operator+=(const FVector4D& _V)
{
    X += _V.X;
    Y += _V.Y;
    Z += _V.Z;
    W += _V.W;

    return *this;
}

const FVector4D& FVector4D::operator+=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, _V);
    return *this;
}

const FVector4D& FVector4D::operator+=(float _Value)
{
    X += _Value;
    Y += _Value;
    Z += _Value;
    W += _Value;
    return *this;
}

const FVector4D& FVector4D::operator+=(int _Value)
{
    X += (float)_Value;
    Y += (float)_Value;
    Z += (float)_Value;
    W += (float)_Value;
    return *this;
}

FVector4D FVector4D::operator-(const FVector4D& _V) const
{
    FVector4D Result;
    Result.X = X - _V.X;
    Result.Y = Y - _V.Y;
    Result.Z = Z - _V.Z;
    Result.W = W - _V.W;
    return Result;
}

FVector4D FVector4D::operator-(const DirectX::XMVECTOR& _V) const
{
    return FVector4D(DirectX::XMVectorSubtract(Convert(), _V));
}

FVector4D FVector4D::operator-(float _Value) const
{
    FVector4D Result;
    Result.X = X - _Value;
    Result.Y = Y - _Value;
    Result.Z = Z - _Value;
    Result.W = W - _Value;
    return Result;
}

FVector4D FVector4D::operator-(int _Value) const
{
    FVector4D Result;
    Result.X = X - (float)_Value;
    Result.Y = Y - (float)_Value;
    Result.Z = Z - (float)_Value;
    Result.W = W - (float)_Value;
    return Result;
}

const FVector4D& FVector4D::operator-=(const FVector4D& _V)
{
    X -= _V.X;
    Y -= _V.Y;
    Z -= _V.Z;
    W -= _V.W;

    return *this;
}

const FVector4D& FVector4D::operator-=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, _V);
    return *this;
}

const FVector4D& FVector4D::operator-=(float _Value)
{
    X -= _Value;
    Y -= _Value;
    Z -= _Value;
    W -= _Value;
    return *this;
}

const FVector4D& FVector4D::operator-=(int _Value)
{
    X -= (float)_Value;
    Y -= (float)_Value;
    Z -= (float)_Value;
    W -= (float)_Value;
    return *this;
}

FVector4D FVector4D::operator*(const FVector4D& _V) const
{
    FVector4D Result;
    Result.X = X * _V.X;
    Result.Y = Y * _V.Y;
    Result.Z = Z * _V.Z;
    Result.W = W * _V.W;
    return Result;
}

FVector4D FVector4D::operator*(const DirectX::XMVECTOR& _V) const
{
    return FVector4D(DirectX::XMVectorMultiply(Convert(), _V));
}

FVector4D FVector4D::operator*(float _Value) const
{
    FVector4D Result;
    Result.X = X * _Value;
    Result.Y = Y * _Value;
    Result.Z = Z * _Value;
    Result.W = W * _Value;
    return Result;
}

FVector4D FVector4D::operator*(int _Value) const
{
    FVector4D Result;
    Result.X = X * (float)_Value;
    Result.Y = Y * (float)_Value;
    Result.Z = Z * (float)_Value;
    Result.W = W * (float)_Value;
    return Result;
}

const FVector4D& FVector4D::operator*=(const FVector4D& _V)
{
    X *= _V.X;
    Y *= _V.Y;
    Z *= _V.Z;
    W *= _V.W;

    return *this;
}

const FVector4D& FVector4D::operator*=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, _V);
    return *this;
}

const FVector4D& FVector4D::operator*=(float _Value)
{
    X *= _Value;
    Y *= _Value;
    Z *= _Value;
    W *= _Value;
    return *this;
}

const FVector4D& FVector4D::operator*=(int _Value)
{
    X *= (float)_Value;
    Y *= (float)_Value;
    Z *= (float)_Value;
    W *= (float)_Value;
    return *this;
}

FVector4D FVector4D::operator/(const FVector4D& _V) const
{
    FVector4D Result;
    Result.X = X / _V.X;
    Result.Y = Y / _V.Y;
    Result.Z = Z / _V.Z;
    Result.W = W / _V.W;
    return Result;
}

FVector4D FVector4D::operator/(const DirectX::XMVECTOR& _V) const
{
    return FVector4D(DirectX::XMVectorDivide(Convert(), _V));
}

FVector4D FVector4D::operator/(float _Value) const
{
    FVector4D Result;
    Result.X = X / _Value;
    Result.Y = Y / _Value;
    Result.Z = Z / _Value;
    Result.W = W / _Value;
    return Result;
}

FVector4D FVector4D::operator/(int _Value) const
{
    FVector4D Result;
    Result.X = X / (float)_Value;
    Result.Y = Y / (float)_Value;
    Result.Z = Z / (float)_Value;
    Result.W = W / (float)_Value;
    return Result;
}

const FVector4D& FVector4D::operator/=(const FVector4D& _V)
{
    X /= _V.X;
    Y /= _V.Y;
    Z /= _V.Z;
    W /= _V.W;

    return *this;
}

const FVector4D& FVector4D::operator/=(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, _V);
    return *this;
}

const FVector4D& FVector4D::operator/=(float _Value)
{
    X /= _Value;
    Y /= _Value;
    Z /= _Value;
    W /= _Value;
    return *this;
}

const FVector4D& FVector4D::operator/=(int _Value)
{
    X /= (float)_Value;
    Y /= (float)_Value;
    Z /= (float)_Value;
    W /= (float)_Value;
    return *this;
}

const FVector4D& FVector4D::operator++()
{
    X += 1.f;
    Y += 1.f;
    Z += 1.f;
    W += 1.f;

    return *this;
}

const FVector4D& FVector4D::operator++(int)
{
    X += 1.f;
    Y += 1.f;
    Z += 1.f;
    W += 1.f;

    return *this;
}

const FVector4D& FVector4D::operator--()
{
    X -= 1.f;
    Y -= 1.f;
    Z -= 1.f;
    W -= 1.f;

    return *this;
}

const FVector4D& FVector4D::operator--(int)
{
    X -= 1.f;
    Y -= 1.f;
    Z -= 1.f;
    W -= 1.f;

    return *this;
}

float& FVector4D::operator[] (int _Index)
{
    assert(0 <= _Index && _Index <= 3);

    switch (_Index)
    {
    case 0:
        return X;
    case 1:
        return Y;
    case 2:
        return Z;
    }

    return W;
}

DirectX::XMVECTOR FVector4D::Convert() const
{
    return DirectX::XMLoadFloat4((DirectX::XMFLOAT4*)this);
}

void FVector4D::Convert(const DirectX::XMVECTOR& _V)
{
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, _V);
}

FVector4D FVector4D::Red = { 1.f, 0.f, 0.f, 1.f };
FVector4D FVector4D::Blue = { 0.f, 0.f, 1.f, 1.f };
FVector4D FVector4D::Green = { 0.f, 1.f, 0.f, 1.f };
FVector4D FVector4D::White = { 1.f, 1.f, 1.f, 1.f };
FVector4D FVector4D::Black = { 0.f, 0.f, 0.f, 1.f };