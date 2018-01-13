#version 430

in vec2 UV;
out vec4 daColor;

uniform sampler2D TextureID;

void main()
{
	daColor = texture(TextureID, UV);
}