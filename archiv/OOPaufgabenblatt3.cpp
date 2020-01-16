#include <iostream>
#include "vektor.h"




Vector3D operator+(const Vector3D &dieser, const Vector3D &other)
{
    Vector3D result(dieser.x + other.x, dieser.y + other.y, dieser.z + other.z);
    return result;
}

Vector3D operator-(const Vector3D &dieser, const Vector3D &other)
{
    Vector3D result((dieser.x - other.x), (dieser.y - other.y), (dieser.z - other.z));
    return result;
}

std::ostream &operator<<(std::ostream &os, const Vector3D &p)
{
    os << '(' << p.x << " | " << p.y << " | " << p.z << ')';
    return os;
}

Vector3D operator*(const float &k, const Vector3D &other)
{
    Vector3D result(other.x * k, other.y * k, other.z * k);
    return result;
}

Vector3D operator*(const Vector3D &other, const float &k)
{
    Vector3D result = k * other;
    return result;
}

float operator*(const Vector3D &dieser, const Vector3D &other)
{
    float result = (dieser.x * other.x) + (dieser.y * other.y) + (dieser.z * other.y);
    return result;
}

main()
{

    Vector3D testV(3.345, 5.4345, 2.343);
    Vector3D testV1(3.45, 5.5645, 6.343);

    float test = 3;

    std::cout << 3 * testV1 << std::endl;
    std::cout << testV1 << std::endl;
    std::cout << testV1 + testV << std::endl;
    std::cout << testV1 * testV << std::endl;
    std::cout << testV1 * 3 << std::endl;
    std::cout << testV1 - testV1 << std::endl;
}

// Vector3D zuweisung = testV;
// if(zuweisung==testV){
//     std::cout
// }

// std::cout << 3 * zuweisung << std::endl;