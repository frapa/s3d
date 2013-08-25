#include "scene.hpp"

namespace s3d {

void Scene::loadMatrices() {
	Resource::getInstance().program->setUniform("projection", projection);
	Resource::getInstance().program->setUniform("view", view);
}

} // namespace