#pragma once

#include "Button.h"
#include "IntRectangle.h"
#include "../renderer/TexturePtr.h"

struct ImageDef {
	mce::TexturePtr texturePtr; // 12
	int x; // 16
	int y; // 20
	float width; // 24
	float height; // 28
	IntRectangle src; // 44
	bool hasSrc; // 45
};

class ImageButton : public Button {
	ImageDef imageDef; // 156
	Color overlay; // 174
	bool scaleWhenPressed; // 175~178
	int yOffset; // 180

	ImageButton(int, const std::string&);
	ImageButton(int, const std::string&, ImageDef const&);
	virtual ~ImageButton();
	virtual void render(MinecraftClient*, int, int);
	virtual void renderBg(MinecraftClient*, int, int);
	virtual void setYOffset(int);
	virtual void setupDefault();
	virtual bool isSecondImage(bool);

	void setImageDef(ImageDef, bool);
};
