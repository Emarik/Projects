#ifndef ENTITY_H
#define ENTITY_H
#include <typeinfo>
#include "Logger.h"
class Component;

class Entity {
	enum {
		MAX_COMPONENTS = 10,
		MAX_NAME_LEN = 30
	};

public:
	Entity();
	~Entity();

	void SetName(const char* const name);
	const char* GetName() const { return m_name; }
	bool AddComponent(Component* c, const char * const name);
	template <class T> T* GetComponentByType() const;
	bool Update(float dt);
	bool Draw();
	void setLogger(Logger*logs);
	bool Initialize();
	

private:
	Component*	m_components[MAX_COMPONENTS];
	char		m_name[MAX_NAME_LEN];
	Logger*     m_logs;
};

template <class T>
T* Entity::GetComponentByType() const {
	for (int i = 0; i < MAX_COMPONENTS; i++)
	{
		if (!m_components[i]) continue;
		if (typeid(T) == typeid(*m_components[i])) {
			//if (m_components[i]->IsDisabled()) return 0;
			return static_cast<T*>(m_components[i]);
		}
	}
	return 0;
}

#endif