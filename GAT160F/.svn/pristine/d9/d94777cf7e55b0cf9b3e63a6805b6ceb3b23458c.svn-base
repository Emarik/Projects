#include "RenderEngine.h"
#include "..\ObjConverter\Vertexformats.h"

void RenderEngine::addShape(ShapeData * s)
{
	s->buffer = manage.getBuffer(s->format, s);
}

void RenderEngine::addRenderable(Renderable * renderable)
{
	manage.addRenderinfo(renderable);
	//BufferInfo*b = &manage.buffers[0];
	//for (int I = 0; I < manage.usedBuffers; I++)
	//{
	//	if (renderable->data->buffer == b)
	//	{
	//		b->renderables.add(renderable);
	//	}
	//	b++;
	//}
}

void RenderEngine::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width, height);

}
void RenderEngine::drawAllRenderables( )
{
	BufferInfo* m = &manage.buffers[0];
	for (int k = 0; k < manage.usedBuffers; k++)
	{
		Node* n = &m->renderables.start;
		while (n->next != NULL)
		{
			n->next->r->Draw();
			n = n->next;
		}
		m++;
	}
}
void RenderEngine::initialize(Logger*m_log,int widths,int heights)
{
	this->m_logs = m_log;
	this->width = widths;
	this->height = heights;
	m_logs->Log(LOG_INFO, "Render Engine Initialized");
	manage.initialize(m_logs);
}
void RenderEngine::shutdown()
{
	manage.shutdown();
	m_logs->Log(LOG_INFO, "Render Engine Shutdown");
}
std::string readShaderCode(const char* filename)
{
	std::ifstream input(filename);
	if (!input.good())
	{
		std::cout << "File failed to load" << std::endl;//log
		exit(1);
	}
	std::string ret = std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
	input.close();
	return ret;
}

bool checkCompile(GLuint shaderID)
{
	GLint compileStatus;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* buffer = new char[infoLogLength];
		GLsizei bufferSize;
		glGetShaderInfoLog(shaderID, infoLogLength, &bufferSize, buffer);
		std::cout << buffer << std::endl;
		delete buffer;
		return false;
	}
	return true;
}

bool checkLinker(GLuint programIDe)
{

	GLint linkStatus;
	glGetProgramiv(programIDe, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetProgramiv(programIDe, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* buffer = new char[infoLogLength];
		GLsizei bufferSize;
		glGetProgramInfoLog(programIDe, infoLogLength, &bufferSize, buffer);
		std::cout << buffer << std::endl;
		delete buffer;
		return false;
	}
	return true;
}

void RenderEngine::installShaders(ShaderInfo *shader)
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	std::string vertexCode;
	std::string fragmentCode;
	if (!(shader->vertexType & HasTexture))
	{
		vertexCode = readShaderCode("../Data/Shaders/PassThrough.vert.shader");
		fragmentCode = readShaderCode("../Data/Shaders/PassThrough.frag.shader");
	}
	else if (shader->vertexType  & HasTexture)
	{
		if (shader->vertexType & HasColor)
		{
			vertexCode = readShaderCode("../Data/Shaders/PassThrough.vert.textureColor.shader");
			fragmentCode = readShaderCode("../Data/Shaders/PassThrough.frag.textureColor.shader");
		}
		else
		{
			vertexCode = readShaderCode("../Data/Shaders/PassThrough.vert.texture.shader");
			fragmentCode = readShaderCode("../Data/Shaders/PassThrough.frag.texture.shader");
		}
	}
	else
	{
		m_logs->Log(LOG_ERROR, "Something happened to the program ID, none connected correctly");
		return;
	}
	//std::cout << vertexCode << std::endl;
	adapter[0] = vertexCode.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	//std::cout << fragmentCode << std::endl;
	adapter[0] = fragmentCode.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);
	if (!checkCompile(vertexShaderID) || !checkCompile(fragmentShaderID))
	{
		m_logs->Log(LOG_FATAL, "Shaders failed to compile");
		std::cout << "Shaders Failed the compile, Shutting down" << std::endl;
		return;
	}

	shader->programID = glCreateProgram();
	glAttachShader(shader->programID, vertexShaderID);
	glAttachShader(shader->programID, fragmentShaderID);
	glLinkProgram(shader->programID);
	if (!checkLinker(shader->programID))
	{
		m_logs->Log(LOG_FATAL, " Program failed to link");
		std::cout << "Program failed to link, Shutting down" << std::endl;
		return;
	}
	glUseProgram(shader->programID);
	m_logs->Log(LOG_INFO, "Shaders Intialized");
}

RenderEngine::~RenderEngine()
{
}
