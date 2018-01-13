#version 430

in layout(location = 0) vec2 position;
in layout(location = 1) vec3 vertexColor;

uniform mat4 modelPositionMatrix;
uniform vec3 dominatingColor;

out vec3 theColor;


void main()
{
	vec4 v = vec4(position, 0.0, 1.0);
	gl_Position = modelPositionMatrix * v;
	theColor = (vertexColor+dominatingColor)/2;
}