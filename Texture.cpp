#include "Texture.h"

Texture::Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType)
{
	// Texture

	// Assigns the type of the texture to the texture object
	type = texType;
	// Stores the width, height, and the number of color channels of the image
	int widthImg, heightImg, numColCh;
	// Flips the image so it appears right side up
	stbi_set_flip_vertically_on_load(true);
	// Reads an image from a file and stores it in bytes
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	// Generates an OpenGl Texture Object
	glGenTextures(1, &ID);
	// Assignes the texture to s Texture Unit
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;
	glBindTexture(GL_TEXTURE_2D, ID);

	// Configures the way the texture repeats (if it does at all)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Configures the type of algorithm that is used to minimize and magnify the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//// Extra lines if you choose to use GL_CLAMP_TO_BORDER
	//float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

	if (bytes)
	{
		// Assignes the image to the OpenGl texture object
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
		// Generates MipMaps
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
		std::cout << stbi_failure_reason();
	}
	// Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(bytes);

	// Unbindes the OpenGL Texture object so that it can't accidentally modified 
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	// Sets value of the uniform
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}