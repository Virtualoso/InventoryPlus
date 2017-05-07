#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/client/screen/InventoryScreen.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/player/LocalPlayer.h"
#include "com/mojang/minecraftpe/item/Item.h"
#include "com/mojang/minecraftpe/block/Block.h"

#include "client/screens/InventoryTransitions.h"
#include "item/NativeToolsItems.h"
#include "NativeTools.h"
#include "mods/ModHandler.h"

static void (*_InventoryScreen$init)(InventoryScreen*, ClientInstance&);
static void InventoryScreen$init(InventoryScreen* self, ClientInstance& client)
{
	if(self->mcClient->getLocalPlayer()->isCreative() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::init(self, client);

	_InventoryScreen$init(self, client);
}

static void (*_InventoryScreen$setupPositions)(InventoryScreen*);
static void InventoryScreen$setupPositions(InventoryScreen* self)
{
	_InventoryScreen$setupPositions(self);
	
	if(self->mcClient->getLocalPlayer()->isCreative() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::setupPositions(self);
}

static void (*_InventoryScreen$render)(InventoryScreen*, int, int, float);
static void InventoryScreen$render(InventoryScreen* self, int i1, int i2, float f1)
{
	_InventoryScreen$render(self, i1, i2, f1);
	
	if(self->mcClient->getLocalPlayer()->isCreative() && self->craftingType != CraftingType::FULLCRAFTING)
	{
		InventoryTransitions::render(self, i1, i2, f1);
		InventoryTransitions::currentPage = 1;
	}
}

static void (*_InventoryScreen$_buttonClicked)(InventoryScreen*, Button&);
static void InventoryScreen$_buttonClicked(InventoryScreen* self, Button& button)
{
	_InventoryScreen$_buttonClicked(self, button);
	
	if(self->mcClient->getLocalPlayer()->isCreative() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::_buttonClicked(self, button);
}

static bool initItems = false;

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems()
{
	_Item$initCreativeItems();
	
	if(!initItems)
	{
		NativeToolsItems::initItems();
		ModHandler::initModItems();
		initItems = true;
	}
	ModHandler::initModCreativeItems();
}

static void (*_Block$initBlocks)();
static void Block$initBlocks()
{
	_Block$initBlocks();
	
	ModHandler::initModBlocks();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	MSHookFunction((void*) &InventoryScreen::init, (void*) &InventoryScreen$init, (void**) &_InventoryScreen$init);
	MSHookFunction((void*) &InventoryScreen::setupPositions, (void*) &InventoryScreen$setupPositions, (void**) &_InventoryScreen$setupPositions);
	MSHookFunction((void*) &InventoryScreen::render, (void*) &InventoryScreen$render, (void**) &_InventoryScreen$render);
	MSHookFunction((void*) &InventoryScreen::_buttonClicked, (void*) &InventoryScreen$_buttonClicked, (void**) &_InventoryScreen$_buttonClicked);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	
	NativeTools::init = true;
	
	return JNI_VERSION_1_2;
}
