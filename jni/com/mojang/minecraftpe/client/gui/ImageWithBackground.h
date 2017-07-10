#pragma once

#include "LargeImageButton.h"

class NinePatchLayer;

class ImageWithBackground : public LargeImageButton {
public:
	NinePatchLayer* layer1; // 192
	NinePatchLayer* layer2; // 196

	virtual ~ImageWithBackground();
	virtual void render(MinecraftGame*, int, int);
	virtual void renderBg(MinecraftGame*, int, int);
	
	ImageWithBackground(int);
	void setSize(float, float);
	void init(mce::TextureGroup*, int, int, IntRectangle, IntRectangle, int, int, ResourceLocation const&);
};