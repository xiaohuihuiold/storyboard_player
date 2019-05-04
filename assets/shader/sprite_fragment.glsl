#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform float alpha = 1.0;
uniform vec3 color = vec3(1.0f, 1.0f, 1.0f);
uniform sampler2D ourTexture;

void main() {
    FragColor = texture(ourTexture, TexCoord) * vec4(color, alpha);
}
