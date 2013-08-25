#include "utils.hpp"

namespace s3d {

bool init() {
	// init glew
	glewInit();

	// check if OpenGL version is at least 2.0
	// otherwise S3D will not work
    if (!GLEW_VERSION_2_0) {
        std::cerr << "S3D needs at least OpenGL 2.0, which is not available." << std::endl;
		return false;
    }

	// init some OpenGL 3D stuff
	// depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// backface culling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
}

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
