#pragma once

#include <core/renderer/model.h>
#include <core/renderer/vertex_array.h>
#include <core/renderer/vertex_buffer.h>

#include "particle.h"
#include "kdtree.h"

class CloudModel: public en61::ModelBase {
public:
	CloudModel(size_t count = 1500);
	~CloudModel();

	void Draw() override;

protected:
	KDTree *_tree;
	std::vector<Particle*> _particles;
	std::vector<Particle*> _nearParticles;

	en61::VertexBuffer _buffer;
	en61::VertexArray _array;

	float *_positions;
	size_t _count; // of particles
};
