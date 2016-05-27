#include "ExtendedInventoryScreen.h"

#include "InventoryTransitions.h"
#include "../../creative/CreativeTab.h"

#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/gui/NinePatchLayer.h"
#include "com/mojang/minecraftpe/client/gui/IntRectangle.h"
#include "com/mojang/minecraftpe/client/gui/ImageWithBackground.h"
#include "com/mojang/minecraftpe/client/gui/InventoryTab.h"
#include "com/mojang/minecraftpe/client/gui/GuiData.h"
#include "com/mojang/minecraftpe/client/settings/Options.h"
#include "com/mojang/minecraftpe/client/renderer/Tessellator.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureGroup.h"
#include "com/mojang/minecraftpe/client/renderer/entity/ItemRenderer.h"
#include "com/mojang/minecraftpe/client/renderer/ShaderColor.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/entity/player/LocalPlayer.h"
#include "com/mojang/minecraftpe/world/inventory/Inventory.h"

ExtendedInventoryScreen::ExtendedInventoryScreen(MinecraftClient& client, std::vector<CreativeTab*> creativeTabs)
	: Screen(client)
{
	closeButton = NULL;
	backgroundLayer = NULL;
	leftButtonLayer = NULL;
	rightButtonLayer = NULL;
	ownedTabs = creativeTabs;
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
	if(!closeButton)
	{
		InventoryTransitions::init(this);
		
		NinePatchFactory factory (mcClient->getTextures(), "gui/spritesheet.png");
		
		backgroundLayer = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({34, 43, 14, 14}, 3, 3, 14.0F, 14.0F));
		leftButtonLayer = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({49, 43, 14, 14}, 3, 3, 14.0F, 14.0F));
		rightButtonLayer = std::shared_ptr<NinePatchLayer>(factory.createSymmetrical({65, 55, 14, 14}, 3, 3, 14.0F, 14.0F));
		
		closeButton = std::make_shared<ImageWithBackground>(2);
		closeButton->init(mcClient->getTextures(), 28, 28, {49, 43, 14, 14}, {49, 43, 14, 14}, 2, 2, "gui/spritesheet.png");
		closeButton->setImageDef({mcClient->getTextures()->getTexture("gui/spritesheet.png", TextureLocation::Default), 0, 1, 18.0F, 18.0F, {60, 0, 18, 18}, true}, true);
		
		for(int tab = 0; tab < ownedTabs.size(); tab++)
		{
			renderedTabs.emplace_back(createInventoryTab(tab + 3, ((tab < 4) ? false : true)));
		}
		
		selectedTabIndex = 0;
		
		buttonList.emplace_back(closeButton);
	}
}

void ExtendedInventoryScreen::render(int i1, int i2, float f1)
{
	if(renderGameBehind())
		renderBackground(1);
	else
		renderDirtBackground();
	
	renderToolBar(f1, 1.0F, false);
	
	for(int tab = 0; tab < renderedTabs.size(); tab++)
	{
		if(tab != selectedTabIndex)
		{
			renderedTabs[tab]->renderBg(mcClient, i1, i2);
			drawTabIcon(ownedTabs[tab], renderedTabs[tab], renderedTabs[tab]->pressed, false);
		}
	}
	
	backgroundLayer->draw(Tessellator::instance, backgroundLayer->xPosition, backgroundLayer->yPosition);
	
	renderedTabs[selectedTabIndex]->renderBg(mcClient, i1, i2);
	drawTabIcon(ownedTabs[selectedTabIndex], renderedTabs[selectedTabIndex], renderedTabs[selectedTabIndex]->pressed, true);	
	
	InventoryTransitions::render(this, i1, i2, f1);
	
	Screen::render(i1, i2, f1);
	
	currentShaderColor.setColor(Color::WHITE);
	
	fill(paneBgX, paneBgY, paneBgWidth + paneBgX, paneBgHeight + paneBgY, {0.2F, 0.2F, 0.2F, 1.0F});
	
	inventoryPanes[selectedTabIndex]->render(i1, i2, f1, mcClient);
	
	renderOnSelectItemNameText(width, mcClient->getFont(), height - 41);
}

void ExtendedInventoryScreen::setupPositions()
{
	int inventoryHeight = height - 23 - 2; // total height - bottom span - top span = height of inv
	
	if(inventoryHeight < (29 + 2) * 5) // if height of inv < 5 category buttons (including the space of 2 between each)
		tabScale = (inventoryHeight / 5) - 2; // scale of tabs is 1/5 the height of inv - 2 (the space between)
	else
		tabScale = inventoryHeight > ((30 + 2) * 5) ? 30 : 29; // if inv height is greater than 5 tabs, tab scale is 30, else 29
	
	int inventoryWidth = width - (tabScale - 2) * 2 - 10;
	
	backgroundLayer->yPosition = 2;
	backgroundLayer->xPosition = 5 + tabScale - 3;
	backgroundLayer->setSize((float)inventoryWidth, (float)inventoryHeight);
	
	closeButton->xPosition = 5;
	closeButton->yPosition = backgroundLayer->yPosition;
	
	closeButton->setSize(tabScale, tabScale - 1);
	
	paneBgX = backgroundLayer->xPosition + 5;
	paneBgY = backgroundLayer->yPosition + 4;
	paneBgWidth = inventoryWidth - 10;
	paneBgHeight = inventoryHeight - paneBgY - 2;
	
	int paneOffset = (paneBgWidth % 26) / 2;
	paneWidth = paneBgWidth - (paneOffset * 2);
	paneHeight = paneBgHeight - 8;
	paneX = paneBgX + paneOffset;
	paneY = paneBgY + 4;
	
	
	for(int tab = 0; tab < renderedTabs.size(); tab++)
	{
		if(!renderedTabs[tab]->isRight)
		{
			renderedTabs[tab]->xPosition = 5;
			renderedTabs[tab]->yPosition = height - 25 - tabScale - (tab * (tabScale + 2));
		}
		else
		{
			renderedTabs[tab]->xPosition = width - 6 - tabScale;
			renderedTabs[tab]->yPosition = height - 25 - tabScale - ((tab - 4) * (tabScale + 2));
		}
		renderedTabs[tab]->width = tabScale;
		renderedTabs[tab]->height = tabScale;	
		
		inventoryPanes[tab] = new Touch::InventoryPane(this, *mcClient, {paneX, paneY, paneWidth, paneHeight}, 1, 1.0F, 5, 26, 1, false, true, false);
		
		inventoryPanes[tab]->xPosition = paneX;
		inventoryPanes[tab]->yPosition = paneY;
		inventoryPanes[tab]->width = paneWidth;
		inventoryPanes[tab]->height = paneHeight;
	}
	
	InventoryTransitions::setupPositions(this);
}

void ExtendedInventoryScreen::_buttonClicked(Button& button)
{
	InventoryTransitions::_buttonClicked(this, button);
	
	if(button.id == closeButton->id)
		InventoryTransitions::closeScreens(this);
}

void ExtendedInventoryScreen::_pointerReleased(int x, int y)
{
	Screen::_pointerReleased(x, y);
	
	for(int tab = 0; tab < renderedTabs.size(); tab++)
	{
		if(tab != selectedTabIndex && renderedTabs[tab]->isInside(x, y) && renderedTabs[tab]->pressed)
			selectedTabIndex = tab;
		
		renderedTabs[tab]->pressed = false;
	}
}

void ExtendedInventoryScreen::_pointerPressed(int x, int y)
{
	Screen::_pointerPressed(x, y);
	
	for(int tab = 0; tab < renderedTabs.size(); tab++)
	{
		if(renderedTabs[tab]->isInside(x, y))
		{
			renderedTabs[tab]->pressed = true;
			return;
		}
	}
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
	inventoryPanes[selectedTabIndex]->tick();
}

std::string ExtendedInventoryScreen::getScreenName()
{
	return "extended_creative_screen";
}

std::shared_ptr<InventoryTab> ExtendedInventoryScreen::createInventoryTab(int id, bool isRight)
{
	NinePatchLayer* buttonLayer = isRight ? rightButtonLayer.get() : leftButtonLayer.get();
	std::shared_ptr<InventoryTab> button = std::make_shared<InventoryTab>(id, "", buttonLayer, isRight);
	button->setOverrideScreenRendering(true);
	return button;
}

void ExtendedInventoryScreen::drawTabIcon(CreativeTab* ownedTab, std::shared_ptr<InventoryTab> imageButton, bool isPressed, bool isSelected)
{
	ItemRenderer::getInstance()->renderGuiItemNew(ownedTab->getTabIcon(), 0, ((float)imageButton->xPosition + (float)((imageButton->width / 2) - 8) + (isPressed ? 1.0F : 0.7F)), ((float)imageButton->yPosition + (float)((imageButton->height / 2) - 8)), 1.0F, (isSelected ? 1.0F : 0.7F), (((float)imageButton->width) - (isPressed ? 2.0F : 0.0F)) * 0.04F, false);
}

int ExtendedInventoryScreen::putItemInInventory(ItemInstance& item, bool fullStack)
{
	Inventory* inv = mcClient->getLocalPlayer()->inventory;
	int slot = inv->getLinkedSlotForExactItem(item);
	int selectedSlot = inv->getSelectedSlot();
	int linkedSlot;
	if(slot < mcClient->getGuiData()->getNumSlots() && slot != -1)
	{
		linkedSlot = inv->getLinkedSlot(selectedSlot);
		ItemInstance* selectedItem = inv->getItem(linkedSlot);
		if(selectedItem && selectedItem->sameItemAndAux(&item))
		{
			if(selectedItem->count < selectedItem->getMaxStackSize())
				selectedItem->count = fullStack ? selectedItem->getMaxStackSize() : selectedItem->count + 1;
		}
		else
		{
			inv->linkSlot(selectedSlot, inv->getLinkedSlot(slot));
			inv->linkSlot(slot, linkedSlot);
		}
	}
	else
	{ 
		inv->add(item, false);
		linkedSlot = inv->getSlotWithItem(item, true, true);
		if(inv->getLinkedSlot(selectedSlot) <= 44 || linkedSlot >= 0)
		{
			item.count = fullStack ? item.getMaxStackSize() : 1;
			inv->setItem(linkedSlot, &item);
			inv->linkSlot(selectedSlot, linkedSlot);
			inv->setItem(selectedSlot, &item);
		}
		else
		{
			linkedSlot = -1;
		}
	}
	
	ItemInstance* currentItem = mcClient->getLocalPlayer()->getSelectedItem();
	if(currentItem)
		mcClient->getGuiData()->showPopupNotice(currentItem->getName(), currentItem->getEffectName());
	mcClient->getGuiData()->flashSlot(inv->getSelectedSlot());
	return linkedSlot;
}

bool ExtendedInventoryScreen::addItem(Touch::InventoryPane& pane, int slot)
{
	pane.resetHoldTime();
	for(int tab = 0; tab < renderedTabs.size(); tab++)
	{
		if(&pane == inventoryPanes[tab])
		{
			ItemInstance item;
			item = *(ownedTabs[tab]->itemsInTab[slot]);
			return putItemInInventory(item, true);
		}
	}
	return false;
}

bool ExtendedInventoryScreen::isAllowed(int slot)
{
	return true;
}

std::vector<const ItemInstance*> ExtendedInventoryScreen::getItems(const Touch::InventoryPane& pane)
{
	for(int tab = 0; tab < renderedTabs.size(); tab++)
	{
		if(&pane == inventoryPanes[tab] && !(ownedTabs[tab]->itemsInTab.empty()))
			return ownedTabs[tab]->itemsInTab;
	}
	std::vector<const ItemInstance*> itemVecNull;
	return itemVecNull;
}
