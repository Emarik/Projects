#include "SpatialComponent.h"



SpatialComponent::SpatialComponent()
{
}

void SpatialComponent::GetCorrospondingData(glm::vec3* transform, glm::vec3* rotate, glm::vec3* scaler)
{
	translation = transform;
	rotation = rotate;
	scale = scaler;
}

bool SpatialComponent::Update(glm::vec3 transform, glm::vec3 rotates)
{
	*translation += transform;
	*rotation += rotates;
	return true;
}



SpatialComponent::~SpatialComponent()
{
}
