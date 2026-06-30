#version 330

// Intrări standard de la Raylib
in vec2 fragTexCoord;
in vec4 fragColor;

// Textura jocului trimisă de placa video
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Ieșirea: culoarea finală a pixelului
out vec4 finalColor;

void main() {
    // Setați intensitatea curbării (0.0 = ecran plat, 0.1 - 0.2 = efect FNAF perfect)
    float intensitate = 0.1; 

    // Centrăm coordonatele ecranului de la (0 la 1) la (-1.0 la 1.0)
    vec2 coord = fragTexCoord - 0.5;
    
    // Calculăm distanța de la centrul ecranului
    float r2 = coord.x * coord.x + coord.y * coord.y;
    
    // Aplicăm distorsiunea pe axe
    vec2 distorsionat = coord * (1.0 + intensitate * r2);
    
    // Readucem coordonatele înapoi în formatul normal (0 la 1)
    vec2 uv = distorsionat + 0.5;

    // Dacă pixelul distorsionat iese în afara ecranului, îl facem negru (marginile curbate)
    if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0) {
        finalColor = vec4(0.0, 0.0, 0.0, 1.0);
    } else {
        // Altfel, desenăm pixelul normal din jocul tău
        finalColor = texture(texture0, uv) * fragColor * colDiffuse;
    }
}