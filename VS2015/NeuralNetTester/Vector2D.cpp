#define _USE_MATH_DEFINES
#include <cmath>
#include "Vector2D.h"


Vector2D::Vector2D(double x, double y)
{
    X = x;
    Y = y;
}

Vector2D Vector2D::CreateVectorFromAngle(double degree)
{
    return(Vector2D(cos(degree * M_PI / 180), sin(degree * M_PI / 180)));
}

Vector2D::~Vector2D()
{
}

Vector2D Vector2D::operator*(double scalar) const
{
    return Vector2D(X*scalar, Y*scalar);
}

void Vector2D::operator*=(double scalar)
{
    (*this) = (*this) * scalar;
}

Vector2D Vector2D::operator/(double scalar) const
{
    return Vector2D(X/scalar, Y/scalar);
}

void Vector2D::operator/=(double scalar)
{
    (*this) = (*this) / scalar;
}

Vector2D Vector2D::operator+(const Vector2D & vect) const
{
    return Vector2D(X + vect.X, Y + vect.Y);
}

Vector2D Vector2D::operator-(const Vector2D & vect) const
{
    return Vector2D(X - vect.X, Y - vect.Y);
}

Vector2D Vector2D::operator-() const
{
    return Vector2D(-X, -Y);
}

void Vector2D::operator+=(const Vector2D & vect)
{
    (*this) = (*this) + vect;
}

void Vector2D::operator-=(const Vector2D & vect)
{
    (*this) = (*this) - vect;
}

void Vector2D::Rotate(double angle)
{
    double tX = (X * cos(angle)) - (Y * sin(angle));
    double tY = (Y * cos(angle)) - (X * sin(angle));
    X = tX;
    Y = tY;
}

double Vector2D::GetAngle() const
{
    return (atan2(Y,X) / M_PI) * 180.0;
}

Vector2D Vector2D::CrossProduct(Vector2D & vect) const
{
    return ((X * vect.Y) - (Y * vect.X));
}

Vector2D Vector2D::DotProduct(Vector2D & vect) const
{
    return ((X * vect.X) + (Y * vect.Y));
}

double Vector2D::Distance(Vector2D & vect) const
{
    return sqrt(pow(X-vect.X,2) + pow(Y-vect.Y,2));
}

double Vector2D::Magnitude()
{
    return sqrt(X*X + Y*Y);
}

void Vector2D::Normalize()
{
    double mag = Magnitude();
    X = X / mag;
    Y = Y / mag;
}
