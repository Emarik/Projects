#pragma once
class Scene
{
public:
	int format;
	int numbVerts;
	int numbInd;
	int sizeVerts;
	int sizeInd;
	void *verts;
	unsigned short* indicies;
};