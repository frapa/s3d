#include "shader.hpp"

namespace s3d {

ShaderProgram::ShaderProgram():
	vertex_shader(0), fragment_shader(0), program(0)
{}

ShaderProgram::ShaderProgram(const char *vertex_shader_file,
			   const char *fragment_shader_file)
{
	loadShader(vertex_shader_file, GL_VERTEX_SHADER);
	loadShader(fragment_shader_file, GL_FRAGMENT_SHADER);
}

ShaderProgram::~ShaderProgram() {
	glUseProgram(0);

	glDetachShader(program, vertex_shader);
	glDetachShader(program, fragment_shader);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	glDeleteProgram(program);
}

bool ShaderProgram::loadShader(const char *filename, GLenum type) {
    std::vector<GLchar> shader_source;
	std::ifstream shader_file(filename);

	// check if the file was correctely opened
	if (!shader_file) {
		std::cerr << "Error: unable to read shader source: " << filename << std::endl;
		return false;
	} else {
		// ignore spaces
		shader_file >> std::noskipws;

		// copy source into vector
		std::copy(std::istream_iterator<char>(shader_file),
				  std::istream_iterator<char>(),
				  std::back_inserter(shader_source));

		shader_file.close();

		GLint length = shader_source.size();

		// create and compile shader
		GLuint shader = glCreateShader(type);
		glShaderSource(shader, 1, (const GLchar**)&shader_source, &length);
		glCompileShader(shader);

		// check for compile errors
		GLint is_shader_ok;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &is_shader_ok);
		if (!is_shader_ok) {
			// compilation failed, retrive log and print an error message
			std::cerr << "Error: failed to compile shader:" << filename << std::endl;

			printLog(shader);

			// cleanup
			glDeleteShader(shader);
			shader = 0;
			return false;
		}

		// store shader in the appropiate member variable
		if (type == GL_VERTEX_SHADER) {
			vertex_shader = shader;
		} else if (type == GL_FRAGMENT_SHADER) {
			fragment_shader = shader;
		}

		// if necessary link the program (both shaders have been set)
		makeProgram();

		return true;
	}
}

void ShaderProgram::makeProgram() {
	if (vertex_shader && fragment_shader) {
		program = glCreateProgram();
		glAttachShader(program, vertex_shader);
		glAttachShader(program, fragment_shader);
		glLinkProgram(program);

		// check for link errors
		GLint is_program_ok;
		glGetShaderiv(program, GL_COMPILE_STATUS, &is_program_ok);
		if (!is_program_ok) {
			// compilation failed, retrive log and print an error message
			std::cerr << "Error: failed to link shader program:" << std::endl;

			printLog(program);

			// cleanup
			glDeleteProgram(program);
			program = 0;
		}
	}
}

void ShaderProgram::use() {
	if (program) {
		glUseProgram(program);
		Resource::getInstance().program = this;
	} else {
		std::cerr << "Error: trying to use ShaderProgram which is not complete." << std::endl;
	}
}

void ShaderProgram::remove() {
	glUseProgram(0);
		Resource::getInstance().program = 0;
}

void ShaderProgram::setUniform(const char* name, float x) {
	if (!program)
		std::cerr << "Error: setting uniform for ShaderProgram not in use." << std::endl;

	// get location of the uniform variable
	GLint location = glGetUniformLocation(program, name);

	glUniform1f(location, x);
}

void ShaderProgram::setUniform(const char* name, float x, float y) {
	if (!program)
		std::cerr << "Error: setting uniform for ShaderProgram not in use." << std::endl;

	// get location of the uniform variable
	GLint location = glGetUniformLocation(program, name);

	glUniform2f(location, x, y);
}

void ShaderProgram::setUniform(const char* name, float x, float y, float z) {
	if (!program)
		std::cerr << "Error: setting uniform for ShaderProgram not in use." << std::endl;

	// get location of the uniform variable
	GLint location = glGetUniformLocation(program, name);

	glUniform3f(location, x, y, z);
}

void ShaderProgram::setUniform(const char* name, float x, float y, float z, float w) {
	if (!program)
		std::cerr << "Error: setting uniform for ShaderProgram not in use." << std::endl;

	// get location of the uniform variable
	GLint location = glGetUniformLocation(program, name);

	glUniform4f(location, x, y, z, w);
}

void ShaderProgram::setUniform(const char* name, Color& color) {
	if (!program) std::cerr << "Error: setting uniform for ShaderProgram not in use." << std::endl;

	// get location of the uniform variable
	GLint location = glGetUniformLocation(program, name);

	glUniform4f(location, color.r, color.g, color.b, color.a);
}

void ShaderProgram::setUniform(const char* name, Matrix4& m) {
	if (!program)
		std::cerr << "Error: setting uniform for ShaderProgram not in use." << std::endl;

	// get location of the uniform variable
	GLint location = glGetUniformLocation(program, name);

	glUniformMatrix4fv(location, 1, GL_TRUE, m.m);
}

int ShaderProgram::getAttributeLocation(const char *name) {
	return glGetUniformLocation(program, name);
}

unsigned int ShaderProgram::getProgram() {
	return program;
}

} // namespace
