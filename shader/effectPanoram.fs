#version 330

// Intrări standard Raylib
in vec2 fragTexCoord;
in vec4 fragColor;

// Uniforms pasate de Raylib
uniform sampler2D texture0;
uniform vec4 colDiffuse;

out vec4 finalColor;

void main()
{
    float intensitate = 0.2;

    // Centrăm coordonatele
    vec2 coord = fragTexCoord - 0.5;

    // Calculăm distanța pătratică
    float r2 = coord.x * coord.x + coord.y * coord.y;

    // Aplicăm distorsiunea pe axe
    vec2 distorsionat = coord * (1.0 + intensitate * r2);

    // Readucem la intervalul [0, 1]
    vec2 uv = distorsionat + 0.5;

    // Dacă depășește cadrul, facem marginea neagră
    if (uv.x < 0.0  uv.x > 1.0  uv.y < 0.0 || uv.y > 1.0) 
    {
        finalColor = vec4(0.0, 0.0, 0.0, 1.0);
    } 
    else 
    {
        // Folosim texture2D pentru plăci video mai vechi (GeForce 9000 series)
        vec4 texelColor = texture2D(texture0, uv);
        finalColor = texelColor * fragColor * colDiffuse;
    }
}