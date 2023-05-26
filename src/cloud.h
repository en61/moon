#pragma once

#include <core/world/object.h>

class Cloud: public en61::Object {
public:
	Cloud();
	void Render(const glm::mat4 &view, const glm::mat4 &proj) override;
};
