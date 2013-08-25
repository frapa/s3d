#include "utils.hpp"

namespace s3d {

Resource& Resource::getInstance() {
	static Resource instance;
	return instance;
}

Color::Color():
	r(1.0f), g(1.0f), b(1.0f), a(1.0f)
{}

Color::Color(float _r, float _g, float _b, float _a):
	r(_r), g(_g), b(_b), a(_a)
{}

void printLog(GLuint object) {
	GLint log_length;
	glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);

	char *log = new char[log_length];

	std::cerr << log << std::endl;

	delete log;
}

} // namespace
