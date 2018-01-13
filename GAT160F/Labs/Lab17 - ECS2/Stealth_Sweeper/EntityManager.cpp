#include "EntityManager.h"

Entity player;
MovementComponent playerMovement;
CameraComponent playerCamera;
KeyboardComponent playerKeyboard;
MouseComponent playerMouse;
//MeshComponent playerMesh;
//SpatialComponent playerSpacial;

Entity dragon;
MeshComponent dragonMesh;
SpatialComponent dragonSpacial;

Entity scene;
MeshComponent sceneMesh;

EntityManager::EntityManager()
{
}

bool EntityManager::Initialize(Logger* logs,Config* config)
{
	logs;
	//player.setLogger(logs);
	player.SetName("Player");
	player.AddComponent(&playerMovement, "Player Movement");
	player.AddComponent(&playerCamera, "Player Camera");
	player.AddComponent(&playerKeyboard, "Player Keyboard");
	player.AddComponent(&playerMouse, "Player Mouse");
	playerCamera.Initialize(logs, config);
	playerKeyboard.setMovementController(&playerMovement);
	playerMovement.setCameraComponent(&playerCamera);
	playerMouse.setMovementComponent(&playerMovement);
	//playerKeyboard.setMoveForward((&playerMovement.moveForward));
	//playerKeyboard.setMoveStrafe((&playerMovement.moveStrafe));
	//playerKeyboard.setMoveUp((playerMovement.moveUp));
	activeCamera = playerCamera.setActiveCamera();
	player.Initialize();

	//dragon.setLogger(logs);
	
	dragon.SetName("Dragon");
	dragon.AddComponent(&dragonMesh, "Dragon Mesh");
	dragon.AddComponent(&dragonSpacial, "Dragon Spacial");
	dragonMesh.setRenderable(renderables.getRenderable("Dragon"));
	dragonSpacial.GetCorrospondingData(&dragonMesh.renderable->translation, &dragonMesh.renderable->rotation, &dragonMesh.renderable->scale);
	dragon.Initialize();
	dragonSpacial.Update(glm::vec3(0.0f, 10.0f, 0.0f), glm::vec3(40.0f,40.0f,0.0f));


	//scene.setLogger(logs);
	scene.SetName("Building Scene");
	scene.AddComponent(&sceneMesh, "Scene Building");
	sceneMesh.setRenderable(renderables.getRenderable("Scene"));
	scene.Initialize();
	return true;
}

void EntityManager::addRenderable(Renderable * render)
{
	renderables.add(render);
}

bool EntityManager::Update(float dt)
{
	playerKeyboard.checkKeys(dt);
	//dragonSpacial.Update(glm::vec3(0.0f, 5.0f*dt, 0.0f), glm::vec3(00.0f,0.0f,0.0f));
	return true;
}

void EntityManager::mouseEvent(glm::vec2 newMousePos)
{
	playerMouse.mouseUpdate(newMousePos);
}

Renderable* EntityManager::FindRenderable(std::string renderName)
{
	Renderable* result = renderables.getRenderable(renderName);
	if (result == nullptr)
	{
		std::string logging = "Renderable " + renderName + " was not found in the Renderable list in Entity Manager";
		m_logs->Log(LOG_ERROR, logging.c_str());
	}
	return result;
}

EntityManager::~EntityManager()
{
}
