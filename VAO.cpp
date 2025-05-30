#include "VAO.h"

VAO::VAO()
{
	// Generate the VAO and VBO with the only one object each
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	// Configure the Vertex Attribute so that OpenGL know how to read the VBO
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout); // (layout = 0) zero is the position of vertex attribute
	VBO.Unbind();
}

void VAO::Bind()
{
	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}