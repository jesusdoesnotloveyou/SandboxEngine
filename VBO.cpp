#include "VBO.h"

VBO::VBO(std::vector<Vertex>& vertices)
{
	// Generate the VAO and VBO with the only one object each
	glGenBuffers(1, &ID);
	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	// Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}