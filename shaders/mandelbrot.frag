#version 460 core
uniform float x;
uniform float y;
uniform float scale;
in vec3 fPos;
out vec3 FragColor;

// All components are in the range [0…1], including hue.
vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

vec3 interpColor(vec3 v1, vec3 v2, float fac){
    return v1+fac*(v2-v1);
}
float xc = fPos.x/scale+x;
float yc = fPos.y/scale+y;
void func(inout float zr, inout float zi){
    float zrt = zr*zr-zi*zi+xc;
    zi = 2.0*zr*zi+yc;
    zr = zrt;
}
/*
void nova(inout float zr, inout float zi){
    float zrt = zr;
    zrt =(-1.0/3.0*pow(zi, 4)*zr + pow(zi, 4) - 2.0/3.0*pow(zi, 2)*pow(zr, 3) + 2*pow(zi, 2)*pow(zr, 2) - pow(zi, 2)*zr - 1.0/3.0*pow(zi, 2) - 1.0/3.0*pow(zr, 5) + pow(zr, 4) - pow(zr, 3) + (1.0/3.0)*pow(zr, 2) + (fPos.x/scale + x + zr)*(pow(zi, 4) + 2*pow(zi, 2)*pow(zr, 2) + pow(zr, 4)))/(pow(zi, 4) + 2*pow(zi, 2)*pow(zr, 2) + pow(zr, 4));
    zi = (zi*(pow(zi, 2) + pow(zr, 2)) - 1.0/3.0*zi*(pow(zi, 4) + 2*pow(zi, 2)*pow(zr, 2) + pow(zr, 4) + 2*zr) + (fPos.y/scale + y + zi)*(pow(zi, 4) + 2*pow(zi, 2)*pow(zr, 2) + pow(zr, 4)))/(pow(zi, 4) + 2*pow(zi, 2)*pow(zr, 2) + pow(zr, 4));
    zr = zrt;
}
*/
void main()
{
    
    float zr = 0.0;
    float zi = 0.0;
    int i = 0;
    int max = 1000;
    for(; i < max; i++){
        func(zr,zi);
        if(abs(zr*zr+zi*zi)>10.0){
            break;
        }
    }
    vec3 color1 = vec3(0.1171875 , 0.1953125 , 0.34765625);
    vec3 color2 = vec3(0.777343 , 0.7695312, 0.1914062);
    float fac = sqrt(float(i)/float(max));
    if(i==max){
        FragColor=color1;
    }
    else{
        FragColor = interpColor(color1,color2,fac);
    }
}
