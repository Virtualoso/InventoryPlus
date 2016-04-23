#include "ExtendedInventoryScreen.h"

#include "InventoryTransitions.h"

#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/gui/Gui.h"
#include "com/mojang/minecraftpe/client/gui/NinePatchLayer.h"
#include "com/mojang/minecraftpe/client/gui/IntRectangle.h"
#include "com/mojang/minecraftpe/client/settings/Options.h"
#include "com/mojang/minecraftpe/client/renderer/Tessellator.h"

ExtendedInventoryScreen::ExtendedInventoryScreen(MinecraftClient& client)
	: Screen(client)
{
	layer1 = NULL;
	layer2 = NULL;
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
	if(renderGameBehind())
		renderBackground(1);
	else
		renderDirtBackground();
	
	Screen::render(i1, i2, f1);
	
	mcClient->getGui()->renderToolBar(f1, 1.0F, false);
	
	layer1->draw(Tessellator::instance, layer1->xPosition, layer1->yPosition);
	
	layer2->setSize(28, 28);
	layer2->draw(Tessellator::instance, layer1->xPosition - 26, layer1->yPosition);
	
	InventoryTransitions::render(this, i1, i2, f1);
}

void ExtendedInventoryScreen::init()
{
	InventoryTransitions::init(this);
	
	NinePatchFactory factory (mcClient->getTextures(), "gui/spritesheet.png");
	
	layer1 = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({34, 43, 14, 14}, 3, 3, 14.0F, 14.0F));
	layer2 = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({49, 43, 13, 14}, 2, 2, 13.0F, 14.0F));
}

void ExtendedInventoryScreen::setupPositions()
{
	layer1->xPosition = 31;
	layer1->yPosition = 2;
	layer1->setSize((float)(width - 26 - 28) - 4.0F - 6.0F, ((float) height) - 25.0F);
	
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

void ExtendedInventoryScreen::tick()
{
	
}
