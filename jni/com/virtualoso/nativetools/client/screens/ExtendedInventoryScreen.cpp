#include "ExtendedInventoryScreen.h"

#include "InventoryTransitions.h"

#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/gui/Gui.h"
#include "com/mojang/minecraftpe/client/gui/NinePatchLayer.h"
#include "com/mojang/minecraftpe/client/gui/IntRectangle.h"
#include "com/mojang/minecraftpe/client/gui/ImageWithBackground.h"
#include "com/mojang/minecraftpe/client/settings/Options.h"
#include "com/mojang/minecraftpe/client/renderer/Tessellator.h"

ExtendedInventoryScreen::ExtendedInventoryScreen(MinecraftClient& client)
	: Screen(client)
{
	closeButton = NULL;
	layer1 = NULL;
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
	
	mcClient->getGui()->renderToolBar(f1, 1.0F, false);
	
	layer1->draw(Tessellator::instance, layer1->xPosition, layer1->yPosition);
	
	InventoryTransitions::render(this, i1, i2, f1);
	
	Screen::render(i1, i2, f1);
}

void ExtendedInventoryScreen::init()
{
	InventoryTransitions::init(this);
	
	closeButton = std::make_shared<ImageWithBackground>(2);
	closeButton->init(mcClient->getTextures(), 28, 28, {49, 43, 14, 14}, {49, 43, 14, 14}, 2, 2, "gui/spritesheet.png");
	closeButton->setImageDef({mce::TexturePtr(*(mcClient->getTextures()), "gui/spritesheet.png"), 0, 1, 18.0F, 18.0F, {60, 0, 18, 18}, true}, true);
	
	
	NinePatchFactory factory (mcClient->getTextures(), "gui/spritesheet.png");
	
	layer1 = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({34, 43, 14, 14}, 3, 3, 14.0F, 14.0F));
	
	buttonList.emplace_back(closeButton);
}

void ExtendedInventoryScreen::setupPositions()
{
	layer1->xPosition = 31;
	layer1->yPosition = 2;
	layer1->setSize((float)(width - 26 - 28) - 4.0F - 6.0F, ((float) height) - 25.0F);
	
	closeButton->xPosition = layer1->xPosition - 26;
	closeButton->yPosition = layer1->yPosition;
	
	closeButton->setSize(29, 28);
	
	InventoryTransitions::setupPositions(this);
}

void ExtendedInventoryScreen::_buttonClicked(Button& button)
{
	InventoryTransitions::_buttonClicked(this, button);
	
	if(button.id == closeButton->id)
		InventoryTransitions::pushPreviousScreen(this);
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
