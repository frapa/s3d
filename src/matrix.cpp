#include "matrix.hpp"

namespace s3d {

Matrix4::Matrix4(): m{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
} {}

Matrix4::Matrix4(const float *elements) {
	for (int i = 0; i != 16; ++i, ++elements) {
		m[i] = *elements;
	}
}

Matrix4 operator+(const Matrix4& a, const Matrix4& b) {
    Matrix4 res;

    for (int i = 0; i != 16; ++i) {
        res.m[i] = a.m[i] + b.m[i];
    }

    return res;
}

Matrix4 operator-(const Matrix4& a, const Matrix4& b) {
    Matrix4 res;

    for (int i = 0; i != 16; ++i) {
        res.m[i] = a.m[i] - b.m[i];
    }

    return res;
}

Matrix4 operator*(const Matrix4& a, const Matrix4& b) {
    Matrix4 res;

    for (int i = 0; i != 4; ++i) {
        for (int j = 0; j != 4; ++j) {
            res.m[i + j*4] =
                a.m[j*4] * b.m[i] +
                a.m[j*4 + 1] * b.m[i + 4] +
                a.m[j*4 + 2] * b.m[i + 8] +
                a.m[j*4 + 3] * b.m[i + 12];
        }
    }

    return res;
}

Matrix4 operator*(const Matrix4& a, float c) {
    Matrix4 res;

    for (int i = 0; i != 16; ++i) {
        res.m[i] = a.m[i] * c;
    }

    return res;
}

Matrix4 Matrix4::translate(float x, float y, float z) {
    Matrix4 trans;

    trans.m[3] = x;
    trans.m[7] = y;
    trans.m[11] = z;

    *this = trans * *this;

    return *this;
}

Matrix4 Matrix4::scale(float x, float y, float z) {
    Matrix4 trans;

    trans.m[0] = x;
    trans.m[5] = y;
    trans.m[10] = z;

    *this = trans * *this;

    return *this;
}

Matrix4 Matrix4::rotateX(float angle) {
    float c = cos(angle);
    float s = sin(angle);

    Matrix4 trans;

    trans.m[5] = c;
    trans.m[6] = -s;
    trans.m[9] = s;
    trans.m[10] = c;

    *this = trans * *this;

    return *this;
}

Matrix4 Matrix4::rotateY(float angle) {
    float c = cos(angle);
    float s = sin(angle);

    Matrix4 trans;

    trans.m[0] = c;
    trans.m[2] = s;
    trans.m[8] = -s;
    trans.m[10] = c;

    *this = trans * *this;

    return *this;
}

Matrix4 Matrix4::rotateZ(float angle) {
    float c = cos(angle);
    float s = sin(angle);

    Matrix4 trans;

    trans.m[0] = c;
    trans.m[1] = -s;
    trans.m[4] = s;
    trans.m[5] = c;

    *this = trans * *this;

    return *this;
}

float degToRad(float degrees) {
    return degrees / 180.0f * pi;
}

Matrix4 createProjectionMatrix(float angle, float aspect, float near, float far) {
    Matrix4 proj;

    proj.m[0] = 1.0f / tan(angle);
    proj.m[5] = aspect / tan(angle);
    proj.m[10] = (far + near) / (far - near);
    proj.m[11] = - (2 * far * near) / (far - near);
    proj.m[14] = 1;

    return proj;

}

} // namespace
