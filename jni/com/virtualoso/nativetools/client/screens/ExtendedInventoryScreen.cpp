#include "ExtendedInventoryScreen.h"

#include "InventoryTransitions.h"

#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/gui/Gui.h"
#include "com/mojang/minecraftpe/client/gui/NinePatchLayer.h"
#include "com/mojang/minecraftpe/client/gui/IntRectangle.h"
#include "com/mojang/minecraftpe/client/gui/ImageWithBackground.h"
#include "com/mojang/minecraftpe/client/gui/InventoryTab.h"
#include "com/mojang/minecraftpe/client/settings/Options.h"
#include "com/mojang/minecraftpe/client/renderer/Tessellator.h"

ExtendedInventoryScreen::ExtendedInventoryScreen(MinecraftClient& client)
	: Screen(client)
{
	closeButton = NULL;
	backgroundLayer = NULL;
	leftButtonLayer = NULL;
	rightButtonLayer = NULL;
	testCatButton = NULL;
}

bool ExtendedInventoryScreen::renderGameBehind() const
{
	return mcClient->getOptions()->getFancyGraphics();
}

bool ExtendedInventoryScreen::closeOnPlayerHurt() const
{
	return true;
}

void ExtendedInventoryScreen::init()
{
	InventoryTransitions::init(this);
	
	NinePatchFactory factory (mcClient->getTextures(), "gui/spritesheet.png");
	
	backgroundLayer = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({34, 43, 14, 14}, 3, 3, 14.0F, 14.0F));
	leftButtonLayer = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({49, 43, 14, 14}, 3, 3, 14.0F, 14.0F));
	rightButtonLayer = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({65, 55, 14, 14}, 3, 3, 14.0F, 14.0F));
	
	closeButton = std::make_shared<ImageWithBackground>(2);
	closeButton->init(mcClient->getTextures(), 28, 28, {49, 43, 14, 14}, {49, 43, 14, 14}, 2, 2, "gui/spritesheet.png");
	closeButton->setImageDef({mce::TexturePtr(*(mcClient->getTextures()), "gui/spritesheet.png"), 0, 1, 18.0F, 18.0F, {60, 0, 18, 18}, true}, true);
	
	testCatButton = createInventoryTab(3, false);
	
	buttonList.emplace_back(closeButton);
}

void ExtendedInventoryScreen::render(int i1, int i2, float f1)
{
	if(renderGameBehind())
		renderBackground(1);
	else
		renderDirtBackground();
	
	mcClient->getGui()->renderToolBar(f1, 1.0F, false);
	
	testCatButton->renderBg(mcClient, i1, i2);
	
	backgroundLayer->draw(Tessellator::instance, backgroundLayer->xPosition, backgroundLayer->yPosition);
	
	InventoryTransitions::render(this, i1, i2, f1);
	
	Screen::render(i1, i2, f1);
}

void ExtendedInventoryScreen::setupPositions()
{
	backgroundLayer->xPosition = 31;
	backgroundLayer->yPosition = 2;
	backgroundLayer->setSize((float)(width - 26 - 28) - 4.0F - 6.0F, ((float) height) - 25.0F);
	
	closeButton->xPosition = backgroundLayer->xPosition - 26;
	closeButton->yPosition = backgroundLayer->yPosition;
	
	closeButton->setSize(29, 28);
	
	testCatButton->xPosition = backgroundLayer->xPosition - 26;
	testCatButton->yPosition = height - 25 - 29;
	testCatButton->width = 29;
	testCatButton->height = 29;
	
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

std::shared_ptr<InventoryTab> ExtendedInventoryScreen::createInventoryTab(int id, bool isRight)
{
	NinePatchLayer* buttonLayer = isRight ? rightButtonLayer.get() : leftButtonLayer.get();
	std::shared_ptr<InventoryTab> button = std::make_shared<InventoryTab>(id, "", buttonLayer);
	button->setOverrideScreenRendering(true);
	return button;
}
