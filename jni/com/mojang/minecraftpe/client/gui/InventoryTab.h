#pragma once

#include "ImageButton.h"

class NinePatchLayer;

class InventoryTab : public ImageButton {
public:
	NinePatchLayer* layer1;

	InventoryTab(int, const std::string&, NinePatchLayer*);
	virtual void renderBg(MinecraftClient*, int, int);
	virtual bool isSecondImage(bool);
};