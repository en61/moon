#include "cloud.h"

#include "cloud_mesh.h"

Cloud::Cloud() {

	auto model = en61::MakeRef<CloudMesh>();
	auto shader = en61::MakeRef<en61::Shader>();
	auto texture = en61::MakeRef<en61::Texture>();

	texture->Load("../assets/blue_particle.png");
	shader->Load("../assets/particle.vs", "../assets/particle.fs", "../assets/particle.gs");

	AddTexture(texture);
	SetShader(shader);
	SetModel(model);

	SetPosition({-0.3f, 1, -3.f});
}

void Cloud::Render(const glm::mat4 &view, const glm::mat4 &proj) {
	glDepthMask(false);
	Object::Render(view, proj);
	glDepthMask(true);
}

