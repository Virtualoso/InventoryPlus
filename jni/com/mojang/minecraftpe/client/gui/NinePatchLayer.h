#pragma once

#include <string>
#include <memory>
#include "GuiElement.h"

class Tessellator;
class TextureData;
class IntRectangle;
class TextureGroup;

class NinePatchDescription {
	NinePatchDescription(float, float, float, float, float, float, float, float, float, float, float, float);
	void* transformUVForImageSize(int, int);
	void* transformUVForImage(TextureData const&);
	void* createSymmetrical(int, int, IntRectangle const&, int, int);
};

class NinePatchLayer : public GuiElement {
	char filler [520 - 120];

	class CachedQuad;

	NinePatchLayer(const NinePatchDescription&, const std::string&, TextureGroup *, float, float);
	virtual ~NinePatchLayer();

	void draw(Tessellator&, float, float);
	void buildQuad(int);
	void setExcluded(int);
	void exclude(int);
	void getPatchInfo(int, int, float&, float&, float&, float&);
	void setSize(float, float);
	void d(Tessellator&, NinePatchLayer::CachedQuad const&);
};

class NinePatchFactory {	
	TextureGroup* textures;
	std::string imageName;
	int width;
	int height;
	
	NinePatchFactory(TextureGroup *, const std::string&);
	std::shared_ptr<NinePatchLayer> createSymmetrical(IntRectangle const&, int, int, float, float);
};
