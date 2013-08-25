#include <GL/glew.h>
#include <SFML/Window.hpp>
#include "shader.hpp"
#include "matrix.hpp"
#include "indexed_list.hpp"

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "S3d Test");

    glewInit();

    if (!GLEW_VERSION_2_0) {
        std::cerr << "This program need at least OpenGL 2.0, which is not available." << std::endl;
        return 1;
    }

    s3d::ShaderProgram sp("shaders/test.vert", "shaders/test.frag");
    sp.use();

    s3d::Matrix4 projection = s3d::createProjectionMatrix(60, 600.0/800.0, 0.1, 100);
    sp.setUniform("projection", projection);
    s3d::Matrix4 view;
    view.translate(0, -2, 5);
    view.rotateX(s3d::degToRad(-20));
    sp.setUniform("view", view);

	s3d::IndexedList il(GL_TRIANGLES);
	il.appendVertex(s3d::Vertex(1, 0, 0, s3d::Color(1, 0, 0)));
	il.appendVertex(s3d::Vertex(0, 0, 1, s3d::Color(0, 1, 0)));
	il.appendVertex(s3d::Vertex(-1, 0, 0, s3d::Color(0, 0, 1)));
	il.appendVertex(s3d::Vertex(0, 0, -1, s3d::Color(1, 0, 1)));
	il.appendVertex(s3d::Vertex(0, 1, 0, s3d::Color(0, 1, 1)));

	unsigned int inds[] = {
		0, 1, 2, 0, 2, 3, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4
	};
	il.setIndices(inds, 18);
	il.model_matrix.rotateY(s3d::degToRad(-45));

    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

    int c = 0;
    bool done = false;
    // mainloop
    while (window.isOpen())
    {
        // check events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        il.model_matrix.rotateY(0.01);
        if (c < 100)
			il.model_matrix.scale(1.005, 1.005, 1.005);
		else
			il.model_matrix.scale(0.995, 0.995, 0.995);
		il.draw();

        // end the current frame
        window.display();

        ++c;
        if (c == 200) {
			c = 0;

			if (not done) {
				il.appendVertex(s3d::Vertex(0, -1, 0, s3d::Color(1, 1, 0)));
				il.appendIndices({3, 5, 0, 0, 5, 1, 1, 5, 2, 2, 5, 3});
				done = true;
			}
		}
    }

    return 0;
}
