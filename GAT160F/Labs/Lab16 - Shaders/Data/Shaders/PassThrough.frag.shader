#version 430

in vec3 theColor;
in vec2 UV;
out vec4 daColor;

uniform sampler2D TextureID;

void main()
{
	daColor = vec4(theColor,1.0);
}