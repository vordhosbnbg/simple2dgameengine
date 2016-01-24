#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
public:
    Vector2D(double x = 0, double y = 0);
    static Vector2D CreateVectorFromAngle(double degree);
    ~Vector2D();

    Vector2D operator*(double scalar) const;
    void operator*=(double scalar);
    Vector2D operator/(double scalar) const;
    void operator/=(double scalar);
    Vector2D operator+(const Vector2D &vect) const;
    Vector2D operator-(const Vector2D &vect) const;
    Vector2D operator-() const;
    void operator+=(const Vector2D &vect);
    void operator-=(const Vector2D &vect);
    void Rotate(double angle);
    double GetAngle() const;
    Vector2D CrossProduct(Vector2D &vect) const;
    Vector2D DotProduct(Vector2D &vect) const;
    double Distance(Vector2D &vect) const;
    double Magnitude();
    Vector2D Normalize();
    Vector2D AddLength(double length);
    Vector2D ToLeft(double val);
    Vector2D ToRight(double val);

    double X;
    double Y;
};

#endif // VECTOR2D_H
