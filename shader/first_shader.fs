#version 330

// Date primite de la Raylib
in vec2 fragTexCoord; // Coordonatele pixelului curent (de la 0.0 la 1.0)
in vec4 fragColor;    // Culoarea originală trimisă de DrawTexture

// Textura originală a camerei pasată de Raylib
uniform sampler2D texture0;

// Culoarea finală pe care o va scoate placa video pe ecran
out vec4 finalColor;

void main()
{
    // 1. Luăm culoarea pixelului original din textură
    vec4 texelColor = texture2D(texture0, fragTexCoord);

    // 2. Calculăm luminozitatea (transformăm imaginea în alb-negru)
    float brightness = (texelColor.r + texelColor.g + texelColor.b) / 3.0;

    // 3. Creăm o nuanță puternică de verde (specifică camerelor de noapte)
    vec3 greenTint = vec3(0.0, brightness * 1.5, 0.0);

    // 4. Aplicăm și un efect subtil de linii de scanare (scanlines) bazat pe coordonata Y
    float scanline = sin(fragTexCoord.y * 800.0) * 0.1;
    
    // Combinăm totul și trimitem spre ecran
    finalColor = vec4(greenTint - scanline, texelColor.a) * fragColor;
}