#include "surface.h"

Surface::Surface() {
	auto model = en61::MakeRef<en61::Model>();
	auto shader = en61::MakeRef<en61::Shader>();
	auto texture = en61::MakeRef<en61::Texture>();

	shader->Load("../assets/surface.vs", "../assets/surface.fs");
	model->Load("../assets/surface.obj");
	texture->Load("../assets/moon.png");

	SetModel(model);
	SetShader(shader);
	AddTexture(texture);
}
