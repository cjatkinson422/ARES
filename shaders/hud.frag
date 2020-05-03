#version 430 core
out vec4 FragColor;

uniform sampler2D texture0; // color

in vec2 fTex;

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

void main()
{   
    FragColor = texture(texture0, 0.3333*fTex+0.3333);
    FragColor.rgb += vec3(1.0);
}
