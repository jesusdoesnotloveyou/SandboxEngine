#include "Mesh.h"

const unsigned int width = 1000;
const unsigned int height= 1000;

// Veticies coordinates
GLfloat vertices[] =
{//			COORDINATES								/		COLORS		//
	-0.50f, -0.50f * float(sqrt(3)) / 3,     0.0f,		0.8f, 0.3f,  0.02f,
	0.50f,  -0.50f * float(sqrt(3)) / 3,     0.0f,		0.8f, 0.3f,  0.02f,
	0.00f,   0.50f * float(sqrt(3)) * 2 / 3, 0.0f,		1.0f, 0.6f,  0.32f,
	-0.25f,  0.50f * float(sqrt(3)) / 6,	 0.0f,		0.9f, 0.45f, 0.17f,
	0.25f,   0.50f * float(sqrt(3)) / 6,	 0.0f,		0.9f, 0.45f, 0.17f,
	0.00f,  -0.50f * float(sqrt(3)) / 3,	 0.0f,		0.8f, 0.3f,  0.02f
};

GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};

GLfloat triangleVertices[] =
{//			COORDINATES			/		COLORS		//	TexCoord
	-0.5f, -0.5f,  0.0f,		1.0f, 0.0f,  0.0f,		-1.0f, -1.0f,
	 0.0f,  0.5f,  0.0f,		0.0f, 1.0f,  0.0f,		 0.5f,  2.0f,
	 0.5f, -0.5f,  0.0f,		0.0f, 0.0f,  1.0f,		 2.0f, -1.0f
};

GLuint triangleIndices[] =
{
	0, 1, 2
};

GLfloat squareVertices[] =
{//			COORDINATES		/		COLORS		//	TexCoord
	-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,		0.0f, 1.0f, 0.0f,		0.0f, 1.0f,
	 0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f
};

GLuint squareIndices[] =
{
	0, 2, 1, // Upper triangle
	0, 3, 2 // Lower triangle
};

Vertex floorVertices[] =
{ //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

GLuint floorIndices[] =
{
	0, 1, 2,
	0, 2, 3
};

GLfloat pyramidVertices[] =
{//		COORDINATES			//		COLORS			//	TexCoord
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};


GLuint pyramidIndices[] =
{
	0, 1, 2, // Lower left triangle
	0, 2, 3, // Lower right triangle
	0, 1, 4, // Upper triangle
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

GLfloat lightPyramidVertices[] =
{//			COORDINATES		/		COLORS			/	TexCoord		/	Normals
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side

	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side

	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
};

GLuint lightPyramidIndices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};

Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

int main()
{
	// Initialize GLFW
	glfwInit(); 

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Tell GLFW what version of OpenGL we're using 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Mine is OpenGL 3.5
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // functions pakage: 
																   // CORE - modern functions; 
																   // COMPATIBILITY - modern and outdated functions

	// Creating a GLFW window 800x800px with the name below
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL_god_help_me_please_i_am_tired_of_errors", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // hint for OpenGL to use the created window and make it a part of the current context
									// context it is kind of object that holds whole OpenGL 
									//abstract shit
	// Load GLAD so it configures OpenGL
	gladLoadGL(); 
	// Hint to render window area
	glViewport(0, 0, width, height);
	
	// Texture
	Texture textures[] = 
	{
		Texture("D:/Pictures/planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("D:/Pictures/planksSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	// Store mesh data in vectors
	// TODO: need to understand how it works
	std::vector<Vertex> verts(floorVertices, floorVertices + sizeof(floorVertices) / sizeof(Vertex));
	std::vector<GLuint> ind(floorIndices, floorIndices + sizeof(floorIndices) / sizeof(GLuint));
	std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create floor mesh
	Mesh floor(verts, ind, tex);

	// Shader for the light cube
	Shader lightShader("light.vert", "light.frag");
	// TODO: need to understand how it works
	std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));

	// Creates the light source
	Mesh light(lightVerts, lightInd, tex);
	
	

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// 2D image stuff and testing unform variable
	/*GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
	GLfloat scaleModify = 0.5f;*/

	// Enables the Depth Buffer
	// Чтобы учитывать глубину текстуры и корректно отобразить 3D модель
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.5f, 2.0f));

	while (!glfwWindowShouldClose(window)) // Main loop
	{
		// Set color to back buffer (background color)
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clear the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Handles inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		floor.Draw(shaderProgram, camera);
		light.Draw(lightShader, camera);
		
		glfwSwapBuffers(window); // Swap the back buffer with the front one

		glfwPollEvents(); // Process all the polled events such as window appearing, resize and other stuff
	}
	
	// Delete all objects we've created
	shaderProgram.Delete();
	lightShader.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}