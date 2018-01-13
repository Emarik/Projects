#version 430

in layout(location = 0) vec3 position;
in layout(location = 1) vec3 vertexColor;
in layout(location = 2) vec2 textures;
in layout(location = 3) vec3 normals;

uniform mat4 modelPositionMatrix;

out vec3 theColor;
out vec2 UV;


void main()
{
	vec4 v = vec4(position, 1.0);
	gl_Position = modelPositionMatrix * v;
	theColor = vertexColor;
}