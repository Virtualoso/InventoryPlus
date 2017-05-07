#pragma once

#include "Button.h"
#include "IntRectangle.h"
#include "../renderer/TexturePtr.h"

struct ImageDef {
	mce::TexturePtr& texturePtr; // 0
	int x; // 12
	int y; // 16
	float width; // 20
	float height; // 24
	IntRectangle src; // 28
	bool hasSrc; // 44
};

class ImageButton : public Button {
public:
	ImageDef imageDef; // 108
	Color overlay; // 156
	bool scaleWhenPressed; // 172
	int yOffset; // 176

	virtual ~ImageButton();
	virtual void render(MinecraftGame*, int, int);
	virtual void renderBg(MinecraftGame*, int, int);
	virtual void setYOffset(int);
	virtual void setupDefault();
	virtual bool isSecondImage(bool);

	ImageButton(int, std::string const&);
	ImageButton(int, std::string const&, ImageDef);
	void setImageDef(ImageDef, bool);
};