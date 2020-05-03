#pragma once
#include "linalg.hh"

class quaternion{
public:
    double s = 1.0;
    vec3 v;


    // Default constructor 
    quaternion() : quaternion(0.0,0.0,0.0,1.0){};

    // Axis angle constructor
    quaternion(const vec3&, double, bool degrees = false);

    // Quaternion constructor
    // Format is (S,Vx,Vy,Vz)
    quaternion(double,double,double,double);
    quaternion(const vec4& vec);

    // Normalize the quaternion
    void normalize();

    // Conjugate of the quaternion
    quaternion conj();

    // Rotate a vector using the quaternion
    vec3 rotate (const vec3& to_rotate) const;

    // Converts the quaternion to a 3x3 matrix
    // Algorith source:
    // https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix/index.htm
    mat3 toMat3() const;

    // Prints the contents of the quaternion
    void print() const;

    // Prints the contents of the quaternion with a newline terminator
    void println() const;

    // Tests the equivalence of two quaternions by rotating a vector (1,1,1)
    // using the two quaternions and then checks if the rotated vectors are the same
    static bool testEquivalence(const quaternion&, const quaternion&);
};

quaternion operator*(const quaternion& q1, const quaternion& q2);
//quaternion operator*(const mat4&,const quaternion&);
quaternion operator* (const double&,const quaternion&);
quaternion operator* (const quaternion&,const double&);

quaternion& operator+=(quaternion&, const quaternion&);
quaternion& operator-=(quaternion&, const quaternion&);

bool operator==(quaternion&, quaternion&);

