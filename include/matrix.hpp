#ifndef S3D_MATRIX
#define S3D_MATRIX

#include <cmath>

namespace s3d {

    const float pi = 3.14159265358979323846;

    // matrix implementation
    class Matrix4 {
    public:
        float m[16];

		// default constructor builds an identity matrix
        Matrix4();
        Matrix4(const float *elements);

        // matrix transform functions
		Matrix4 translate(float x, float y, float z);
		Matrix4 scale(float x, float y, float z);
		Matrix4 rotateX(float angle);
		Matrix4 rotateY(float angle);
		Matrix4 rotateZ(float angle);
    };

    // matrix operators
    Matrix4 operator+ (const Matrix4& a, const Matrix4& b);
    Matrix4 operator- (const Matrix4& a, const Matrix4& b);
    Matrix4 operator* (const Matrix4& a, const Matrix4& b);
    Matrix4 operator* (const Matrix4& a, float c);

    // utility functions
    float degToRad(float degrees);
    Matrix4 createProjectionMatrix(float angle, float aspect, float near, float far);

};

#endif
