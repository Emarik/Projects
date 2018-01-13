#ifndef MEGLWINDOW_H
#define MEGLWINDOW_H
#pragma warning(push)
#pragma warning(disable:4127)
#pragma warning(disable:4251)
#pragma warning(disable:4800)
#include "QtOpenGL/QGLWidget"
#pragma warning(pop)
class MeGlWindow : public QGLWidget
{
	GLuint vertexBufferID;
protected:
	void initializeGL();
	void paintGL();
};
#endif
