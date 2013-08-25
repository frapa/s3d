#ifndef S3D_SCENE
#define S3D_SCENE

#include <GL/gl.h>
#include "matrix.hpp"

namespace s3d {

	class Scene {
	public:
		Matrix4 projection;
		Matrix4 view;
		
		void Draw();
	};
	
} // namespace

#endif
