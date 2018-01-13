#pragma once
#include "Component.h"
#pragma warning(push)
#pragma warning(disable:4201)
#pragma warning(disable:4458)
#include "glm.hpp"
#pragma warning(pop)
#include "gtc\matrix_transform.hpp"
class SpatialComponent :
	public Component
{
public:
	glm::vec3* translation;
	glm::vec3* rotation;
	glm::vec3* scale;
	SpatialComponent();
	void GetCorrospondingData(glm::vec3* tranlate, glm::vec3* rotate, glm::vec3* scaler);
	bool Update(glm::vec3 transform, glm::vec3 rotates);
	~SpatialComponent();
};

