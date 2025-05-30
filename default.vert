#version 330 core

// Layout with coordinates specifiers
layout (location = 0) in vec3 aPos;
// Layout with with normals (not necessarily normalized)
layout (location = 1) in vec3 aNormal;
// Layout with colors specifiers
layout (location = 2) in vec3 aColor;
// Texture coordinates
layout (location = 3) in vec2 aTex;

// Ouputs the current position for the Fragment Shader
out vec3 crntPos;
// Outputs the normal for the Fragment Shader
out vec3 Normal;
// Outputs the color for the Fragment Shader
out vec3 color;
// Ouputs the texture coordinates to the Fragment Shader
out vec2 texCoord;

// Imports the camera matrix from the main function
uniform mat4 camMatrix;
// Imports the model matrix from the main function
uniform mat4 model;

void main()
{
	// calculates the current position
	crntPos = vec3(model * vec4(aPos, 1.0));
	// Assigns the normal from the Vertex Data to "Normal"
	Normal = aNormal;
	// Assigns the colors from the Vertex Data to "color" 
	color = aColor;
	// Assigns the texture coordinates from the Vertex Data to "texCoord"
	texCoord = aTex;
	// Outputs the positions/coordinates of all vertices
	gl_Position = camMatrix * vec4(crntPos, 1.0);
	
}