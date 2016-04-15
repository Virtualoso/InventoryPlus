#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/client/gui/screen/InventoryScreen.h"
#include "com/mojang/minecraftpe/client/gui/TButton.h"

static std::shared_ptr<Touch::TButton> forwardButton = NULL;
static std::shared_ptr<Touch::TButton> backButton = NULL;

static void (*_InventoryScreen$init)(InventoryScreen*);
static void InventoryScreen$init(InventoryScreen* self)
{
	if(!forwardButton)
	{
		forwardButton = std::make_shared<Touch::TButton>(0, ">", self->mcClient, false, 0x7FFFFFFF);
		forwardButton->init(self->mcClient);
	}
	
	if(!backButton)
	{
		backButton = std::make_shared<Touch::TButton>(0, "<", self->mcClient, false, 0x7FFFFFFF);
		backButton->init(self->mcClient);
	}
	
	self->buttonList.emplace_back(forwardButton);
	self->buttonList.emplace_back(backButton);
	
	_InventoryScreen$init(self);
}

static void (*_InventoryScreen$setupPositions)(InventoryScreen*);
static void InventoryScreen$setupPositions(InventoryScreen* self)
{
	_InventoryScreen$setupPositions(self);
	
	forwardButton->xPosition = self->width - 25;
	forwardButton->yPosition = self->height - 20;
	forwardButton->width = 20;
	forwardButton->height = 20;
	
	backButton->xPosition = self->width - 50;
	backButton->yPosition = self->height - 20;
	backButton->width = 20;
	backButton->height = 20;
}

static void (*_InventoryScreen$render)(InventoryScreen*, int, int, float);
static void InventoryScreen$render(InventoryScreen* self, int i1, int i2, float f1)
{
	_InventoryScreen$render(self, i1, i2, f1);
	
	self->drawString(self->font, "1 / 2", 5, self->height - 15, Color::WHITE);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	MSHookFunction((void*) &InventoryScreen::init, (void*) &InventoryScreen$init, (void**) &_InventoryScreen$init);
	MSHookFunction((void*) &InventoryScreen::setupPositions, (void*) &InventoryScreen$setupPositions, (void**) &_InventoryScreen$setupPositions);
	MSHookFunction((void*) &InventoryScreen::render, (void*) &InventoryScreen$render, (void**) &_InventoryScreen$render);	
	
	return JNI_VERSION_1_2;
}
