#version 460 core
uniform float x;
uniform float y;
uniform float scale;
uniform float ci;
uniform float cr;
in vec3 fPos;
out vec3 FragColor;

const float gold = 1.61803398875;


const vec3 colors[8] = {
    vec3(011.0f, 112.0f, 104.0f)/256.0f,
    vec3(152.0f,  92.0f,  19.0f)/256.0f,
    vec3(208.0f, 162.0f,  80.0f)/256.0f,
    vec3(172.0f, 220.0f, 195.0f)/256.0f,
    vec3(150.0f, 220.0f, 250.0f)/256.0f,
    vec3(180.0f, 225.0f, 228.0f)/256.0f,
    vec3(089.0f, 176.0f, 167.0f)/256.0f,
    vec3(011.0f, 112.0f, 104.0f)/256.0f
};


const float interpMax = float(7);


// All components are in the range [0…1], including hue.
vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

vec3 interpColor(float fac){
    for(int i=0;i<7;++i){
        if(float(i) <= fac && fac <= float(i+1)){
            return colors[i]+(fac-float(i))*(colors[i+1]-colors[i]);
        }
    }
    
}

void func(inout float zr, inout float zi){
    float zrt = (zr*zr-zi*zi);
    zi = 2.0*zr*zi+ci;
    zr = zrt+cr;
}

void main()
{
    
    float zr = fPos.x/scale + x;
    float zi = fPos.y/scale + y;
    int i = 0;
    int max = 1000;
    for(; i < max; i++){
        func(zr,zi);
        if(abs(zr*zr+zi*zi)>4.0){
            break;
        }
    }

    //float fac = (float(i)*interpMax/float(max));
    //float fac = (fPos.y+1.0)*interpMax/2.0;
    float fac = mod(float(i)/6.14159265,interpMax*4.0)/4.0;
    FragColor = interpColor(fac)*1.5*pow(float(i+100)/float(max),0.2);
}
