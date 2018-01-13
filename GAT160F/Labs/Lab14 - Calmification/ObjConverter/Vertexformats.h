#ifndef VERTEXFORMATS_H
#define VERTEXFORMATS_H
enum VertexFormats {
	HasPosition = 1,
	HasColor = 2,
	HasTexture = 4,
	HasNormal = 8,
	PositionOnly = HasPosition,
	PositionColor = HasPosition | HasColor,
	PositionTexture = HasPosition | HasTexture,
	PositionNormal = HasPosition | HasNormal,
	PositionColorNormal = HasPosition | HasColor | HasNormal,
	PositionTextureNormal = HasPosition | HasTexture | HasNormal,
	PositionColorTexture = HasPosition | HasColor | HasTexture,
	PositionColorTextureNormal = HasPosition | HasColor | HasTexture | HasNormal,
};
struct Index
{
	int indicies[4];
};
#define positionVari 0
#define colorVari 1
#define textureVari 2
#define normalVari 3
#endif