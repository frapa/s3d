#ifndef S3D_SHADER
#define S3D_SHADER

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <GL/glew.h>
#include <GL/gl.h>
#include "utils.hpp"
#include "matrix.hpp"

namespace s3d {

	class ShaderProgram {
	public:
		ShaderProgram();
		ShaderProgram(const char *vertex_shader_file,
					   const char *fragment_shader_file);
		~ShaderProgram();

		bool loadShader(const char *filename, GLenum type);

		void setUniform(const char* name, float x);
		void setUniform(const char* name, float x, float y);
		void setUniform(const char* name, float x, float y, float z);
		void setUniform(const char* name, float x, float y, float z, float w);
		void setUniform(const char* name, Color& color);
		void setUniform(const char* name, Matrix4& m);

		void use();
		void remove();

		int getAttributeLocation(const char *name);
		unsigned int getProgram();

	private:
		GLuint vertex_shader;
		GLuint fragment_shader;
		GLuint program;

		void makeProgram();
	};

} // namespace

#endif
