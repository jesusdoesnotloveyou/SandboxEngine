#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>
#include <vector>

class EBO
{
public:
	GLuint ID;
	EBO(std::vector<GLuint>& indices);

	// Binds the EBO
	void Bind();
	// Unbinds the EBO
	void Unbind();
	// Deletes the EBO
	void Delete();
};

#endif