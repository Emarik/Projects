#include "Entity.h"

#include <string.h>

#include "Component.h"

Entity::Entity() { }

Entity::~Entity() { }

void Entity::SetName(const char * const name) {
	for (int i = 0; i < MAX_NAME_LEN; i++) {
		m_name[i] = name[i];
		if (!name[i]) return;
	}
	m_name[MAX_NAME_LEN - 1] = 0;
}

bool Entity::AddComponent(Component * c, const char * const name) {
	for (int i = 0; i < MAX_COMPONENTS; i++) {
		if (!m_components[i]) {
			m_components[i] = c;
			c->SetOwner(this);
			c->SetName(name);
			c->setLogger(m_logs);
			return true;
		}
	}
	//assert/log
	return false;
}

bool Entity::Update(float dt) {
	for (int i = 0; i < MAX_COMPONENTS; i++) {
		if (m_components[i] && m_components[i]->IsEnabled()) {
			bool result = m_components[i]->Update(dt);
			result;
			//assert/log
		}
	}
	//Draw?
	return true;
}

bool Entity::Draw() {
	return true;
}

void Entity::setLogger(Logger*logs)
{
	m_logs = logs;
}

bool Entity::Initialize() {
	for (int i = 0; i < MAX_COMPONENTS; i++) {
		if (m_components[i]) {
			if (!m_components[i]->Init()) return false;
		}
	}
	memset(m_components, 0, MAX_COMPONENTS * sizeof(m_components[0]));
	return true;
}