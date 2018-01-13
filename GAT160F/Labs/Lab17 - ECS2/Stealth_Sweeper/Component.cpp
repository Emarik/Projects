#include "Component.h"

bool Component::s_breakable = false;

Component::Component() { }

Component::~Component() { }

bool Component::Init() {
	m_enabled = true;

	bool result = Initialize();
	if (!result) {} //Log
	else {} //Log?

	return true;
}

void Component::SetName(const char * const name) {
	for (int i = 0; i < MAX_NAME_LEN; i++)
	{
		m_name[i] = name[i];
		if (!name[i]) return;
	}
	m_name[MAX_NAME_LEN - 1] = 0;
}

void Component::SetOwner(Entity * owner) {
	m_owner = owner;
}

void Component::setLogger(Logger* logs)
{
	m_logs = logs;
}

void Component::Break(bool condition, bool keepBreakable) {
	if (condition && s_breakable) {
		__debugbreak();
		s_breakable = keepBreakable;
	}
}

void Component::BreakIf(bool condition) {
	if (condition)
		__debugbreak();
}