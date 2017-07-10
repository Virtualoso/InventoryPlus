#pragma once

#include "Button.h"
#include "IntRectangle.h"
#include "../renderer/TexturePtr.h"

struct ImageDef {
	mce::TexturePtr texturePtr; // 0
	int x; // 20
	int y; // 24
	float width; // 28
	float height; // 32
	IntRectangle src; // 36
	bool hasSrc; // 52
};

class ImageButton : public Button {
public:
	ImageDef imageDef; // 108
	Color overlay; // 164
	bool scaleWhenPressed; // 180
	int yOffset; // 184

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