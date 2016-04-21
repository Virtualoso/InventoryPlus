#include "InventoryTransitions.h"

#include "com/mojang/minecraftpe/client/gui/screen/Screen.h"

std::shared_ptr<Touch::TButton> InventoryTransitions::forwardButton = NULL;
std::shared_ptr<Touch::TButton> InventoryTransitions::backButton = NULL;

std::string selected = "0";

void InventoryTransitions::init(Screen* self)
{
	//if gamemode == creative

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
	self->drawString(self->font, selected + " / 2", 5, self->height - 15, Color::WHITE);
}

void InventoryTransitions::_buttonClicked(Screen* self, Button& button)
{
	if(forwardButton->pressed)
	{
		selected = "1";
	}
	
	if(backButton->pressed)
	{
		selected = "0";
	}
}
