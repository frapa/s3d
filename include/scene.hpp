#ifndef S3D_SCENE
#define S3D_SCENE

#include <GL/glew.h>
#include <GL/gl.h>
#include "utils.hpp"
#include "matrix.hpp"
#include "shader.hpp"

namespace s3d {

	class Scene {
	public:
		Matrix4 projection;
		Matrix4 view;

		void loadMatrices();
	};

} // namespace

#endif
