#include "InventoryTransitions.h"

#include <sstream>

#include "ExtendedInventoryScreen.h"
#include "../../creative/CreativeTab.h"
#include "../../loader/JsonLoader.h"

#include "com/mojang/minecraftpe/client/ClientInstance.h"
#include "com/mojang/minecraftpe/client/screen/Screen.h"
#include "com/mojang/minecraftpe/client/screen/InventoryScreen.h"
#include "com/mojang/minecraftpe/client/ScreenChooser.h"
#include "com/mojang/minecraftpe/util/String.h"
#include "com/mojang/minecraftpe/client/gui/GuiData.h"

std::shared_ptr<Touch::TButton> InventoryTransitions::forwardButton = NULL;
std::shared_ptr<Touch::TButton> InventoryTransitions::backButton = NULL;

int InventoryTransitions::currentPage = 1;

std::vector<std::shared_ptr<Screen>> InventoryTransitions::pages;
std::vector<CreativeTab*> InventoryTransitions::creativeTabs;

void InventoryTransitions::init(Screen* self)
{
	if(!forwardButton)
	{
		forwardButton = std::make_shared<Touch::TButton>(0, ">", self->mcGame, false, 0x7FFFFFFF);
		forwardButton->init(self->mcGame);

		backButton = std::make_shared<Touch::TButton>(1, "<", self->mcGame, false, 0x7FFFFFFF);
		backButton->init(self->mcGame);

		initCreativeTabs(self);
	}
	
	self->buttonList.emplace_back(forwardButton);
	self->buttonList.emplace_back(backButton);
}

void InventoryTransitions::setupPositions(Screen* self)
{
	forwardButton->xPosition = self->width - 25;
	forwardButton->yPosition = self->height - 20;
	forwardButton->width = 20;
	forwardButton->height = 20;
	
	backButton->xPosition = self->width - 50;
	backButton->yPosition = self->height - 20;
	backButton->width = 20;
	backButton->height = 20;
}

void InventoryTransitions::render(Screen* self, int i1, int i2, float f1)
{
	std::ostringstream pageNum;
	pageNum << currentPage << " / " << pages.size() + 1;
	self->drawString(self->font, pageNum.str(), 5, self->height - 15, Color::WHITE);
	
	backButton->enabled = true;
	forwardButton->enabled = true;
	
	if(currentPage == 1)
		backButton->enabled = false;
	else if(currentPage == pages.size() + 1)
		forwardButton->enabled = false;
	if(creativeTabs.empty())
		forwardButton->enabled = false;
}

void InventoryTransitions::_buttonClicked(Screen* self, Button& button)
{
	if(button.id == forwardButton->id)
		pushNextScreen(self);
		
	if(button.id == backButton->id)
		pushPreviousScreen(self);
}

void InventoryTransitions::pushNextScreen(Screen* self)
{
	self->mcClient->getScreenChooser()->_pushScreen(pages[currentPage - 1], false);
	currentPage++; // increase the current page by 1
}

void InventoryTransitions::pushPreviousScreen(Screen* self)
{	
	self->mcClient->getScreenChooser()->schedulePopScreen(1);
	currentPage--; // reduce the currentPage by 1
}

void InventoryTransitions::initCreativeTabs(Screen* self)
{
	JsonLoader::setup(self->mcGame->getResourcePackManager());
	JsonLoader::registerCreativeTabs(self->mcGame->getGuiData());
	setupCreativeTabs(self);
}

void InventoryTransitions::setupCreativeTabs(Screen* self)
{
	if(!creativeTabs.empty())
	{
		std::vector<CreativeTab*> tabSets;
		for(int tab = 0; tab < creativeTabs.size(); tab++)
		{
			tabSets.emplace_back(creativeTabs[tab]);
			if((tab + 1) % 8 == 0) // if divisble by 8
			{
				pages.emplace_back(std::make_shared<ExtendedInventoryScreen>(*(self->mcGame), *(self->mcClient), tabSets));
				tabSets.clear();
			}
			else if(tab == creativeTabs.size() - 1)
			{
				pages.emplace_back(std::make_shared<ExtendedInventoryScreen>(*(self->mcGame), *(self->mcClient), tabSets));
				tabSets.clear();
				break;
			}
		}
	}
}

void InventoryTransitions::closeScreens(Screen* self)
{
	self->mcClient->getScreenChooser()->schedulePopScreen(currentPage);
	currentPage = 1;
}