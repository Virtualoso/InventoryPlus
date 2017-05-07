#pragma once

#include <string>
#include <memory>
#include "GuiElement.h"

class Tessellator;
class IntRectangle;

namespace mce { 
class TextureGroup;
class ImageBuffer; 
class TexturePtr;
};

class NinePatchDescription {
public:
	NinePatchDescription(float, float, float, float, float, float, float, float, float, float, float, float);
	void* transformUVForImageSize(int, int);
	void* transformUVForImage(mce::ImageBuffer const&);
	void* createSymmetrical(int, int, IntRectangle const&, int, int);
};

class NinePatchLayer : public GuiElement {
public:
	float width1; // 48
	float height1; // 52
	char filler[124 - 56]; // 56

	class CachedQuad;

	virtual ~NinePatchLayer();

	NinePatchLayer(NinePatchDescription const&, std::string const&, mce::TexturePtr, float, float);
	void draw(Tessellator&, float, float);
	void buildQuad(int);
	void setExcluded(int);
	void exclude(int);
	void getPatchInfo(int, int, float&, float&, float&, float&);
	void setSize(float, float);
	void d(Tessellator&, NinePatchLayer::CachedQuad const&);
};

class NinePatchFactory {
public:
	mce::TextureGroup* textures;
	std::string imageName;
	int width;
	int height;
	
	NinePatchFactory(mce::TextureGroup*, ResourceLocation const&);
	NinePatchLayer* createSymmetrical(IntRectangle const&, int, int, float, float);
	NinePatchLayer* createUniqueSymmetrical(IntRectangle const&, int, int, float, float);
};