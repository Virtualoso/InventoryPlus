#include "InventoryTransitions.h"

#include <sstream>

#include "com/mojang/minecraftpe/client/gui/screen/Screen.h"

std::shared_ptr<Touch::TButton> InventoryTransitions::forwardButton = NULL;
std::shared_ptr<Touch::TButton> InventoryTransitions::backButton = NULL;

int InventoryTransitions::currentPage = 1;

void InventoryTransitions::init(Screen* self)
{
	if(!forwardButton)
	{
		forwardButton = std::make_shared<Touch::TButton>(0, ">", self->mcClient, false, 0x7FFFFFFF);
		forwardButton->init(self->mcClient);
	}
	
	if(!backButton)
	{
		backButton = std::make_shared<Touch::TButton>(1, "<", self->mcClient, false, 0x7FFFFFFF);
		backButton->init(self->mcClient);
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
	pageNum << currentPage << " / " << 2 /*pages.size()*/;
	self->drawString(self->font, pageNum.str(), 5, self->height - 15, Color::WHITE);
}

void InventoryTransitions::_buttonClicked(Screen* self, Button& button)
{
	if(button.id == forwardButton->id)
	{
		pushNextScreen();
	}
	
	if(button.id == backButton->id)
	{
		//do code here
	}
}

void InventoryTransitions::pushNextScreen()
{
	
}