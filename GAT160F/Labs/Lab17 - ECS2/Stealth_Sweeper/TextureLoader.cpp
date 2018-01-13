#include "TextureLoader.h"



TextureLoader::TextureLoader(Logger* logs)
{
	m_logs = logs;
}

GLuint TextureLoader::loadBMP_custom(std::string filename)
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	unsigned char * data;     // Actual RGB data
	FILE * file;
	fopen_s(&file,filename.c_str(), "rb");
	if (!file)
	{ 
		printf("Image could not be opened\n");
		m_logs->LogErrors(LOG_ERROR, "Texture Loader File:%s failed to load",filename);
		return 0; 
	}

	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	if (imageSize == 0)
	{
		imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	}
	if (dataPos == 0)
	{
		dataPos = 54; // The BMP header is finished at 54 bytes, check if above 
	}
	// Create a buffer
	data = new unsigned char[imageSize];
	
	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);
	fclose(file);

	// Create one OpenGL texture, the returned value
	GLuint textureID;
	glGenTextures(1, &textureID);	
	
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	return textureID;
}


TextureLoader::~TextureLoader()
{
}
