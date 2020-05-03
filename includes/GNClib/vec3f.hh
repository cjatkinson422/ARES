#include <array>

class vec3f{
public:
    float x;
    float y;
    float z;

    float& operator[](unsigned int);
    
    // Default constructor
    vec3f() : vec3f(0.0,0.0,0.0){};
    // Standard vector 3 (x,y,z)
    vec3f(float,float,float);

    // Sets the data to some new value
    void set(std::array<float,3> dat){
        x=dat[0];
        y=dat[1];
        z=dat[2];
    }

    // Negative Operator. returns the vectors negative
    friend vec3f operator-(const vec3f&);
    // Normalizes this vector.
    void normalize();
    static vec3f normalize(const vec3f&);
    // Returns the current length of the vector.
    float length();
    // Crosses two vec3f's and returns a new vec3f with the result
    static vec3f cross(const vec3f&,const vec3f&);
    // Dots two vec3f's and returns a float with the result
    static float dot(const vec3f&,const vec3f&);

    // Prints the contents of the vector
    void print();
    // Prints the contents of the vector with a newline terminator
    void println();

    float getAngularDist(vec3f& v1, vec3f& v2);

    static const vec3f unit_x;
    static const vec3f unit_y;
    static const vec3f unit_z;

};
// Operator overloads
bool operator==(const vec3f&,const vec3f&);
bool operator!=(const vec3f&,const vec3f&);
vec3f operator+ (const vec3f&,const vec3f&);
vec3f& operator+=(vec3f&, const vec3f&);
vec3f& operator-=(vec3f&, const vec3f&);
vec3f operator- (const vec3f&,const vec3f&);
vec3f operator*(const float&,const vec3f&);
vec3f operator*(const vec3f&,const float&);
vec3f operator/(const vec3f&,const float&);
float* operator&(vec3f&);

