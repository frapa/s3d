#ifndef S3D_INDEXED_LIST
#define S3D_INDEXED_LIST

#include <algorithm>
#include <iterator>
#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>
#include "utils.hpp"
#include "matrix.hpp"
#include "shader.hpp"

namespace s3d {

    // objects
    class Vertex {
    public:
        float x, y, z;
        Color color;

        Vertex();
        Vertex(float _x, float _y, float _z);
        Vertex(float _x, float _y, float _z, Color _color);
    };

    class IndexedList {
    public:
        GLenum primitive_type;
        std::string vertex_attr;
        std::string color_attr;
        Matrix4 model_matrix;

        IndexedList();
        IndexedList(GLenum type);
		~IndexedList();

        Vertex& operator[] (unsigned int index);

		// infos about the number of vertices and indices
        unsigned int getVertexCount();
        unsigned int getIndexCount();

        // modify the list
        void clear();

		// ways for adding vertices
        void appendVertex(const Vertex& vertex);
        void appendVertices(const Vertex *verts, unsigned int length);
        void appendVertices(const std::vector<Vertex>& verts);
        void setVertices(const Vertex *verts, unsigned int length);
        void setVertices(const std::vector<Vertex>& verts);

		// ways for adding indices
        void appendIndex(unsigned int index);
        void appendIndices(const unsigned int *ids, unsigned int length);
        void appendIndices(const std::vector<unsigned int>& ids);
        void setIndices(const unsigned int *ids, unsigned int length);
        void setIndices(const std::vector<unsigned int>& ids);

        void draw();

    private:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;

        GLuint vao;
        GLuint vertex_vbo;
        GLuint color_vbo;
        GLuint index_vbo;

        GLint vert_attr_location;
        GLint color_attr_location;

        bool updated;

        void init();
        void update();
    };

} // namespace

#endif

