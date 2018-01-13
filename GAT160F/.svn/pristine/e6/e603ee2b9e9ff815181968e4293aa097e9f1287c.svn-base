#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"

class Component {
	enum {
		MAX_NAME_LEN = 30
	};

public:
	Component();
	~Component();
	Logger*		m_logs;

	bool Init();
	virtual bool Initialize() { return true; }
	virtual bool Update(float dt) { dt; return true; }

	void Enable(bool enabled = true) { m_enabled = enabled; }
	bool IsEnabled() { return m_enabled; }
	bool IsDisabled() { return !m_enabled; }
	void SetName(const char* const name);
	void SetOwner(Entity* owner);
	void setLogger(Logger*logs);

	static void SetBreak(bool enabled = true) { s_breakable = enabled; }
	static void Break(bool condition = true, bool keepBreakable = true);
	static void BreakIf(bool condition = true);

protected:
	template <class T> T* GetSiblingComponent() {
		//assert(m_owner);
		if (m_owner) {
			return m_owner->GetComponentByType<T>();
		}
	}

private:
	Entity*		m_owner;
	char		m_name[MAX_NAME_LEN];
	bool		m_enabled;

	static bool s_breakable;
};

#endif