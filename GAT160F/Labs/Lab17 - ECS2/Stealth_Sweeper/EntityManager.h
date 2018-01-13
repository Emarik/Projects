#pragma once
#include "Entity.h"
#include "MeshComponent.h"
#include "SpatialComponent.h"
#include "CameraComponent.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"
#include "MouseComponent.h"
class EntityManager
{
	LinkedList renderables;
	Logger* m_logs;
public:
	Camera* activeCamera;
	EntityManager();
	bool Initialize(Logger* logs,Config* config);
	void addRenderable(Renderable* render);
	bool Update(float dt);
	void mouseEvent(glm::vec2 newMousePos);
	Renderable * FindRenderable(std::string renderName);
	~EntityManager();
};

