#include "Vector2.h"


FVector2D::FVector2D()
{
}

FVector2D::FVector2D(float _X, float _Y)
    : X(_X), Y(_Y)
{
}

FVector2D::FVector2D(const FVector2D& _V)
    : X(_V.X), Y(_V.Y)
{
}

const FVector2D& FVector2D::operator=(const FVector2D& _V)
{
    X = _V.X;
    Y = _V.Y;
    return *this;
}

const FVector2D& FVector2D::operator=(float _Value)
{
    X = _Value;
    Y = _Value;
    return *this;
}

const FVector2D& FVector2D::operator=(int _Value)
{
    X = (float)_Value;
    Y = (float)_Value;
    return *this;
}

FVector2D FVector2D::operator+(const FVector2D& _V) const
{
    FVector2D Result;
    Result.X = X + _V.X;
    Result.Y = Y + _V.Y;
    return Result;
}

FVector2D FVector2D::operator+(float _Value) const
{
    FVector2D Result;
    Result.X = X + _Value;
    Result.Y = Y + _Value;
    return Result;
}

FVector2D FVector2D::operator+(int _Value) const
{
    FVector2D Result;
    Result.X = X + (float)_Value;
    Result.Y = Y + (float)_Value;
    return Result;
}

const FVector2D& FVector2D::operator+=(const FVector2D& _V)
{
    X += _V.X;
    Y += _V.Y;
    return *this;
}

const FVector2D& FVector2D::operator+=(float _Value)
{
    X += _Value;
    Y += _Value;
    return *this;
}

const FVector2D& FVector2D::operator+=(int _Value)
{
    X += (float)_Value;
    Y += (float)_Value;
    return *this;
}

FVector2D FVector2D::operator-(const FVector2D& _V) const
{
    FVector2D Result;
    Result.X = X - _V.X;
    Result.Y = Y - _V.Y;
    return Result;
}

FVector2D FVector2D::operator-(float _Value) const
{
    FVector2D Result;
    Result.X = X - _Value;
    Result.Y = Y - _Value;
    return Result;
}

FVector2D FVector2D::operator-(int _Value) const
{
    FVector2D Result;
    Result.X = X - (float)_Value;
    Result.Y = Y - (float)_Value;
    return Result;
}

const FVector2D& FVector2D::operator-=(const FVector2D& _V)
{
    X -= _V.X;
    Y -= _V.Y;
    return *this;
}

const FVector2D& FVector2D::operator-=(float _Value)
{
    X -= _Value;
    Y -= _Value;
    return *this;
}

const FVector2D& FVector2D::operator-=(int _Value)
{
    X -= (float)_Value;
    Y -= (float)_Value;
    return *this;
}

FVector2D FVector2D::operator * (const FVector2D& _V)	const
{
    FVector2D	Result;
    Result.X = X * _V.X;
    Result.Y = Y * _V.Y;
    return Result;
}

FVector2D FVector2D::operator * (float _Value)	const
{
    FVector2D	Result;
    Result.X = X * _Value;
    Result.Y = Y * _Value;
    return Result;
}

FVector2D FVector2D::operator * (int _Value)	const
{
    FVector2D	Result;
    Result.X = X * (float)_Value;
    Result.Y = Y * (float)_Value;
    return Result;
}

const FVector2D& FVector2D::operator *= (const FVector2D& _V)
{
    X *= _V.X;
    Y *= _V.Y;
    return *this;
}

const FVector2D& FVector2D::operator *= (float _Value)
{
    X *= _Value;
    Y *= _Value;
    return *this;
}

const FVector2D& FVector2D::operator *= (int _Value)
{
    X *= (float)_Value;
    Y *= (float)_Value;
    return *this;
}

FVector2D FVector2D::operator / (const FVector2D& _V)	const
{
    FVector2D	Result;
    Result.X = X / _V.X;
    Result.Y = Y / _V.Y;
    return Result;
}

FVector2D FVector2D::operator / (float _Value)	const
{
    FVector2D	Result;
    Result.X = X / _Value;
    Result.Y = Y / _Value;
    return Result;
}

FVector2D FVector2D::operator / (int _Value)	const
{
    FVector2D	Result;
    Result.X = X / (float)_Value;
    Result.Y = Y / (float)_Value;
    return Result;
}

// /=
const FVector2D& FVector2D::operator /= (const FVector2D& _V)
{
    X /= _V.X;
    Y /= _V.Y;
    return *this;
}

const FVector2D& FVector2D::operator /= (float _Value)
{
    X /= _Value;
    Y /= _Value;
    return *this;
}

const FVector2D& FVector2D::operator /= (int _Value)
{
    X /= (float)_Value;
    Y /= (float)_Value;
    return *this;
}

const FVector2D& FVector2D::operator ++ ()
{
    X += 1.f;
    Y += 1.f;
    return *this;
}

const FVector2D& FVector2D::operator ++ (int)
{
    X += 1.f;
    Y += 1.f;
    return *this;
}

const FVector2D& FVector2D::operator -- ()
{
    X -= 1.f;
    Y -= 1.f;
    return *this;
}

const FVector2D& FVector2D::operator -- (int)
{
    X -= 1.f;
    Y -= 1.f;
    return *this;
}

float FVector2D::Length() const
{
    return sqrt(X * X + Y * Y);
}

void FVector2D::Normalize()
{
    const float Size = Length();

    if (Size <= 0.f)
        return;

    X /= Size;
    Y /= Size;
}

float FVector2D::Distance(const FVector2D& _V) const
{
    FVector2D Vec = *this - _V;

    return Vec.Length();
}

float FVector2D::Angle(const FVector2D& _V) const
{
    FVector2D AVector = *this;
    FVector2D BVector = _V;

    AVector.Normalize();
    BVector.Normalize();

    float Angle = AVector.Dot(BVector);

    Angle = DirectX::XMConvertToDegrees(acosf(Angle));

    return Angle;
}

float FVector2D::Dot(const FVector2D& _V) const
{
    return X * _V.X + Y * _V.Y;
}
