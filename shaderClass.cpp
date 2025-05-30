#include "shaderClass.h"

std::string get_file_context(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = get_file_context(vertexFile);
	std::string fragmentCode = get_file_context(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();
	// Create Vertex Shader Object
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	compileErrors(vertexShader, "VERTEX");
	// Create Fragment Shader Object
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Vertex Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	// Compile the Fragment Shader into machine code
	glCompileShader(fragmentShader);

	compileErrors(fragmentShader, "FRAGMENT");
	// Create Shader Program Object
	ID = glCreateProgram();
	// Attaching shaders to Shader Program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(ID);

	compileErrors(ID, "PROGRAM");
	// Now we can delete shaders because they are already in a Shader Program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const char* type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}