#version 330
in vec2 fragTexCoord;
out vec4 finalColor;

uniform float radius;
uniform float softness;
void main(){
    vec2 center = vec2(0.5, 0.5);
    float dist = distance(fragTexCoord, center);
    float alpha = smoothstep(radius - softness, radius, dist);
    finalColor = vec4(0.0, 0.0, 0.0, alpha);
}