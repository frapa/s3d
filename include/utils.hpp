#ifndef S3D_UTILS
#define S3D_UTILS

/* This file contains fome useful utility functions
 * not related with graphics directely, but of use for the entire
 * library.
 */

#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>

namespace s3d {

	bool init();

	// forward declaration
	class ShaderProgram;

	// This is a singleton class used for sharing some important
	// information and state between different part of the library.
	class Resource {
    public:
		ShaderProgram* program;

		static Resource& getInstance();

    private:
		// we must make constructors private (singleton)
        Resource() {}; // the {} brackets are needed here
        Resource(Resource const&); // not implemented
        void operator=(Resource const&); // not implemented
	};

	class Color {
    public:
        float r, g, b, a;

        Color();
        Color(float _r, float _g, float _b, float _a=1.0f);
    };

	// Retrives and prints error logs
	void printLog(GLuint object);

} // namespace

#endif
