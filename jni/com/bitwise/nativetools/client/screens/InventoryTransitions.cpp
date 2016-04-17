#include "InventoryTransitions.h"

#include "com/mojang/minecraftpe/client/gui/screen/InventoryScreen.h"

std::shared_ptr<Touch::TButton> InventoryTransitions::forwardButton = NULL;
std::shared_ptr<Touch::TButton> InventoryTransitions::backButton = NULL;

void InventoryTransitions::init(InventoryScreen* self)
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

void InventoryTransitions::setupPositions(InventoryScreen* self)
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

void InventoryTransitions::render(InventoryScreen* self, int i1, int i2, float f1)
{
	self->drawString(self->font, "1 / 2", 5, self->height - 15, Color::WHITE);
}

void InventoryTransitions::_buttonClicked(InventoryScreen* self, Button& button)
{
	if(button.id == forwardButton->id)
		self->_closeWindow();
}