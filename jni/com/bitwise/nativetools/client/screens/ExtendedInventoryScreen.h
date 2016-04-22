#pragma once

#include "com/mojang/minecraftpe/client/gui/screen/Screen.h"

class ExtendedInventoryScreen : public Screen
{
public:
	ExtendedInventoryScreen(MinecraftClient&);
	
	virtual bool renderGameBehind() const;
	virtual bool closeOnPlayerHurt() const;
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void _buttonClicked(Button&);
	virtual void handleBackEvent(bool);
	virtual bool isModal() const;
};
