#ifndef vektor
#define vektor_h
#include <string>
#include <iostream>

class Vector3D
{
    const float x = 0;
    const float y = 0;
    const float z = 0;

public:
    Vector3D(float x=0, float y=0, float z=0) : x(x), y(y), z(z){};
    // Keins der Dreierregel noetig, da nicht verwendet, keine tiefe Kopie
    // und keine Zeiger genutzt werden wegen const ist Zuweisungsoperator nicht moeglich
    // keine Objekte werden mit new auf dem Heap erzeugt

    friend std::ostream &operator<<(std::ostream &os, const Vector3D &p);
    friend Vector3D operator+(const Vector3D &dieser, const Vector3D &other);
    friend Vector3D operator-(const Vector3D &dieser, const Vector3D &other);
    friend Vector3D operator*(const float &k, const Vector3D &other);
    friend Vector3D operator*(const Vector3D &other, const float &k);
    friend float operator*(const Vector3D &dieser, const Vector3D &other);
};

#endif
