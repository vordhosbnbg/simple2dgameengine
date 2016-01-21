#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
public:
    Vector2D(double x = 0, double y = 0);
    static Vector2D CreateVectorFromAngle(double degree);
    ~Vector2D();

    Vector2D operator*(double scalar) const;
    Vector2D operator*=(double scalar) const;
    Vector2D operator/(double scalar) const;
    Vector2D operator/=(double scalar) const;
    Vector2D operator+(const Vector2D &vect) const;
    Vector2D operator-(const Vector2D &vect) const;
    Vector2D operator-() const;
    void operator+=(const Vector2D &vect);
    void operator-=(const Vector2D &vect);
    void Rotate(double angle);
    double GetAngle() const;
    Vector2D CrossProduct(Vector2D &vect) const;
    Vector2D DotProduct(Vector2D &vect) const;
    double Magnitude();
    void Normalize();

    double X;
    double Y;
};

#endif // VECTOR2D_H
