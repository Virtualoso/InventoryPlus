#pragma once

#include "com/mojang/minecraftpe/client/gui/screen/Screen.h"

class NinePatchLayer;

class ExtendedInventoryScreen : public Screen
{
public:
	std::shared_ptr<NinePatchLayer> layer1;
	std::shared_ptr<NinePatchLayer> layer2;
	
	ExtendedInventoryScreen(MinecraftClient&);

	virtual bool renderGameBehind() const;
	virtual bool closeOnPlayerHurt() const;
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void _buttonClicked(Button&);
	virtual void handleBackEvent(bool);
	virtual bool isModal() const;
	virtual void tick();
};
