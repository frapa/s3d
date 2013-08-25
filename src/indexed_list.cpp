#include "indexed_list.hpp"

namespace s3d {

Vertex::Vertex() {}

Vertex::Vertex(float _x, float _y, float _z):
	x(_x), y(_y), z(_z) {}

Vertex::Vertex(float _x, float _y, float _z, Color _color):
	x(_x), y(_y), z(_z), color(_color) {}

IndexedList::IndexedList():
	vao(0), vertex_vbo(0), color_vbo(0), updated(false),
	vertex_attr("position"), color_attr("color")
{}

IndexedList::IndexedList(GLenum type):
	primitive_type(type), vao(0), vertex_vbo(0), color_vbo(0),
	updated(false), vertex_attr("position"), color_attr("color")
{}

IndexedList::~IndexedList() {
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDeleteBuffers(1, &vertex_vbo);
	glDeleteBuffers(1, &color_vbo);
	glDeleteBuffers(1, &index_vbo);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vao);
}

Vertex& IndexedList::operator[] (unsigned int index) {
	return vertices[index];
}

unsigned int IndexedList::getVertexCount() {
	return vertices.size();
}

unsigned int IndexedList::getIndexCount() {
	return indices.size();
}

void IndexedList::clear() {
	vertices.clear();
	indices.clear();

	glDeleteBuffers(1, &vertex_vbo);
	glDeleteBuffers(1, &color_vbo);
	glDeleteVertexArrays(1, &vao);

	vao = 0;
	vertex_vbo = 0;
	color_vbo = 0;

	updated = false;
}

void IndexedList::appendVertex(const Vertex& vertex) {
	vertices.push_back(vertex);

	updated = false;
}

void IndexedList::appendVertices(const Vertex *verts, unsigned int length) {
	std::copy(verts, verts + length, std::back_inserter(vertices));

	updated = false;
}

void IndexedList::appendVertices(const std::vector<Vertex>& verts) {
	std::copy(verts.begin(), verts.end(), std::back_inserter(vertices));

	updated = false;
}

void IndexedList::setVertices(const Vertex *verts, unsigned int length) {
	vertices.clear();
	std::copy(verts, verts + length, std::back_inserter(vertices));

	updated = false;
}

void IndexedList::setVertices(const std::vector<Vertex>& verts) {
	vertices.clear();
	std::copy(verts.begin(), verts.end(), std::back_inserter(vertices));

	updated = false;
}

void IndexedList::appendIndex(unsigned int index) {
	indices.push_back(index);

	updated = false;
}

void IndexedList::appendIndices(const unsigned int *ids, unsigned int length) {
	std::copy(ids, ids + length, std::back_inserter(indices));

	updated = false;
}

void IndexedList::appendIndices(const std::vector<unsigned int>& ids) {
	std::copy(ids.begin(), ids.end(), std::back_inserter(indices));

	updated = false;
}

void IndexedList::setIndices(const unsigned int *ids, unsigned int length) {
	indices.clear();
	std::copy(ids, ids + length, std::back_inserter(indices));

	updated = false;
}

void IndexedList::setIndices(const std::vector<unsigned int>& ids) {
	indices.clear();
	std::copy(ids.begin(), ids.end(), std::back_inserter(indices));

	updated = false;
}

void IndexedList::draw() {
	// If VAO (Vertex Array Object) is not initialized, we must
	// load the data onto the graphic card.
	if (!vao) {
		init();
		updated = true;
	} else if (!updated) {
		update();
		updated = true;
	}

	// set uniforms
	Resource::getInstance().program->setUniform("model", model_matrix);

	// actually render stuff
	glBindVertexArray(vao);

	glDrawElements(primitive_type, indices.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

void IndexedList::init() {
	// VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// VERTEX DATA
	glGenBuffers(1, &vertex_vbo); // create vertex buffer

	// COLOR DATA
	glGenBuffers(1, &color_vbo); // create vertex buffer

	// INDEX DATA
	glGenBuffers(1, &index_vbo); // create vertex buffer

	// load data
	update();
}

void IndexedList::update() {
	// we must convert our vector of Vertex to a float array
	unsigned int size = vertices.size() * 4;
	GLfloat points[size];
	GLfloat colors[size];

	int i = 0;
	for (Vertex& vertex: vertices) {
		colors[i] = vertex.color.r;
		points[i++] = vertex.x;
		colors[i] = vertex.color.g;
		points[i++] = vertex.y;
		colors[i] = vertex.color.b;
		points[i++] = vertex.z;
		colors[i] = vertex.color.a;
		points[i++] = 1.0f; // W
	}

	// The shader must have been already set by now.
	// Now let's get the location of GLSL attribute variable
	GLint program = Resource::getInstance().program->getProgram();
	// actually get the parameter's location
	vert_attr_location = glGetAttribLocation(program, vertex_attr.c_str());
	color_attr_location = glGetAttribLocation(program, color_attr.c_str());


	// start using our vao
	glBindVertexArray(vao);


	// VERTEX DATA
	glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo); // enable it

	// upload data to graphic card
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), points, GL_STATIC_DRAW);

	// tell OpenGL how data is formatted
	glVertexAttribPointer(vert_attr_location, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4, 0);
	glEnableVertexAttribArray(vert_attr_location);


	// COLOR DATA
	glBindBuffer(GL_ARRAY_BUFFER, color_vbo); // enable it

	// upload data
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), colors, GL_STATIC_DRAW);

	// tell OpenGL how data is formatted
	glVertexAttribPointer(color_attr_location, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4, 0);
	glEnableVertexAttribArray(color_attr_location);


	// INDEX DATA
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_vbo); // enable it

	// upload data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
		indices.data(), GL_STATIC_DRAW);


	glBindVertexArray(0); // unbind VAO
}

} // namespace
