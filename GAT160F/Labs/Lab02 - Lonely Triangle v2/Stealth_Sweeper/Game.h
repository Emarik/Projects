#ifndef GAME_H
#define GAME_H
class MeGlWindow;
class Game
{
	GLuint vertexBufferID;
	MeGlWindow* m_window;
public:
	bool Initialize(MeGlWindow* window);
	void BufferBind();
	bool Shutdown();
	bool Update();
};
#endif
