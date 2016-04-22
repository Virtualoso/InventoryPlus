#include "ExtendedInventoryScreen.h"

#include "InventoryTransitions.h"

#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/gui/Gui.h"
#include "com/mojang/minecraftpe/client/settings/Options.h"

ExtendedInventoryScreen::ExtendedInventoryScreen(MinecraftClient& client)
	: Screen(client)
{
	
}

bool ExtendedInventoryScreen::renderGameBehind() const
{
	return mcClient->getOptions()->getFancyGraphics();
}

bool ExtendedInventoryScreen::closeOnPlayerHurt() const
{
	return true;
}

void ExtendedInventoryScreen::render(int i1, int i2, float f1)
{
	Screen::render(i1, i2, f1);
	
	mcClient->getGui()->renderToolBar(f1, 1.0F, false);
	
	InventoryTransitions::render(this, i1, i2, f1);
}

void ExtendedInventoryScreen::init()
{
	InventoryTransitions::init(this);
}

void ExtendedInventoryScreen::setupPositions()
{
	InventoryTransitions::setupPositions(this);
}

void ExtendedInventoryScreen::_buttonClicked(Button& button)
{
	InventoryTransitions::_buttonClicked(this, button);
}

void ExtendedInventoryScreen::handleBackEvent(bool b1)
{
	if(!b1)
		InventoryTransitions::pushPreviousScreen(this);
}

bool ExtendedInventoryScreen::isModal() const
{
	return true;
}