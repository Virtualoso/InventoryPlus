#pragma once

#include "ImageButton.h"

class LargeImageButton : public ImageButton {
public:
	float idk; // 180

	virtual ~LargeImageButton();
	virtual void render(MinecraftGame*, int, int);
	virtual void setupDefault();
	
	LargeImageButton(int, std::string const&);
	LargeImageButton(int, std::string const&, ImageDef);
};