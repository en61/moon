#include <core/base/application.h>
#include <core/world/world.h>

#include "cloud.h"
#include "surface.h"

class MoonWorld: public en61::World {
public:
	MoonWorld(en61::Ref<en61::Window> window)
		: World(window) {
	}
	
	void OnUpdate() override {
		World::UpdateCamera();
		Scene::Clear();
	
		auto view = GetCamera()->GetViewMatrix();
		auto proj = GetCamera()->GetProjectionMatrix();

		_surface.Render(view, proj);
		_cloud.Render(view, proj);

		World::Render();
	}

protected:
	Surface _surface;
	Cloud _cloud;
};

class MoonAnimation: public en61::Application {
public:
	MoonAnimation(const en61::WindowProps &props = {}): Application(props) {
		SetMainScene(en61::MakeRef<MoonWorld>(GetWindow()));
		en61::World::SetMenuFontScale(2.0f);
	}

	static auto Create(const en61::WindowProps &props = {}) {
		return en61::MakeScoped<MoonAnimation>(props);
	}

protected:
	Cloud _cloud;
	Surface _surface;
};

int main() {
	auto app = MoonAnimation::Create({2560, 1440, "Moon animation"});
	app->Run();
	return 0;
}
