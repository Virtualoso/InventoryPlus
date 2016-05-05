#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/client/gui/screen/InventoryScreen.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/world/entity/player/LocalPlayer.h"
#include "com/mojang/minecraftpe/world/item/Item.h"

#include "client/screens/InventoryTransitions.h"
#include "item/HolderItems.h"

static void (*_InventoryScreen$init)(InventoryScreen*);
static void InventoryScreen$init(InventoryScreen* self)
{
	if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::init(self);

	_InventoryScreen$init(self);
}

static void (*_InventoryScreen$setupPositions)(InventoryScreen*);
static void InventoryScreen$setupPositions(InventoryScreen* self)
{
	_InventoryScreen$setupPositions(self);
	
	if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::setupPositions(self);
}

static void (*_InventoryScreen$render)(InventoryScreen*, int, int, float);
static void InventoryScreen$render(InventoryScreen* self, int i1, int i2, float f1)
{
	_InventoryScreen$render(self, i1, i2, f1);
	
	if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)
	{
		InventoryTransitions::render(self, i1, i2, f1);
		InventoryTransitions::currentPage = 1;
	}
}

static void (*_InventoryScreen$_buttonClicked)(InventoryScreen*, Button&);
static void InventoryScreen$_buttonClicked(InventoryScreen* self, Button& button)
{
	_InventoryScreen$_buttonClicked(self, button);
	
	if(self->mcClient->getLocalPlayer()->IsCreative() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::_buttonClicked(self, button);
}

static void (*_Item$initItems)();
static void Item$initItems()
{
	_Item$initItems();

	HolderItems::initItems();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	MSHookFunction((void*) &InventoryScreen::init, (void*) &InventoryScreen$init, (void**) &_InventoryScreen$init);
	MSHookFunction((void*) &InventoryScreen::setupPositions, (void*) &InventoryScreen$setupPositions, (void**) &_InventoryScreen$setupPositions);
	MSHookFunction((void*) &InventoryScreen::render, (void*) &InventoryScreen$render, (void**) &_InventoryScreen$render);
	MSHookFunction((void*) &InventoryScreen::_buttonClicked, (void*) &InventoryScreen$_buttonClicked, (void**) &_InventoryScreen$_buttonClicked);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	
	return JNI_VERSION_1_2;
}
