#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/client/screen/InventoryScreen.h"
#include "com/mojang/minecraftpe/client/ClientInstance.h"
#include "com/mojang/minecraftpe/client/MinecraftGame.h"
#include "com/mojang/minecraftpe/client/ScreenChooser.h"
#include "com/mojang/minecraftpe/player/LocalPlayer.h"
#include "com/mojang/minecraftpe/item/Item.h"

#include "client/screens/InventoryTransitions.h"
#include "loader/JsonLoader.h"
#include "item/InvPlusItems.h"
#include "creative/CreativeHandler.h"

static void (*_InventoryScreen$init)(InventoryScreen*);
static void InventoryScreen$init(InventoryScreen* self)
{
	if(self->mcClient->getLocalPlayer()->isInCreativeMode() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::init(self);

	_InventoryScreen$init(self);
}

static void (*_InventoryScreen$setupPositions)(InventoryScreen*);
static void InventoryScreen$setupPositions(InventoryScreen* self)
{
	_InventoryScreen$setupPositions(self);
	
	if(self->mcClient->getLocalPlayer()->isInCreativeMode() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::setupPositions(self);
}

static void (*_InventoryScreen$render)(InventoryScreen*, int, int, float);
static void InventoryScreen$render(InventoryScreen* self, int i1, int i2, float f1)
{
	_InventoryScreen$render(self, i1, i2, f1);
	
	if(self->mcClient->getLocalPlayer()->isInCreativeMode() && self->craftingType != CraftingType::FULLCRAFTING)
	{
		InventoryTransitions::render(self, i1, i2, f1);
		InventoryTransitions::currentPage = 1;
	}
}

static void (*_InventoryScreen$_buttonClicked)(InventoryScreen*, Button&);
static void InventoryScreen$_buttonClicked(InventoryScreen* self, Button& button)
{
	_InventoryScreen$_buttonClicked(self, button);
	
	if(self->mcClient->getLocalPlayer()->isInCreativeMode() && self->craftingType != CraftingType::FULLCRAFTING)
		InventoryTransitions::_buttonClicked(self, button);
}

static void (*_InventoryScreen$_populateItems)();
static void InventoryScreen$_populateItems()
{
	CreativeHandler::addItemsToInv();
}

static bool initScreens = false;

static void (*_ScreenChooser$pushInventoryScreen)(ScreenChooser*, CraftingType);
static void ScreenChooser$pushInventoryScreen(ScreenChooser* self, CraftingType type)
{
	if(!initScreens)
	{
		JsonLoader::setup(self->mcGame->getResourcePackManager());
		JsonLoader::registerCreativeTabs();
		initScreens = true;
	}

	_ScreenChooser$pushInventoryScreen(self, type);
}


static bool initItems = false;

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems()
{
	_Item$initCreativeItems();
	
	if(!initItems)
	{
		InvPlusItems::initItems();
		initItems = true;
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	MSHookFunction((void*) &InventoryScreen::init, (void*) &InventoryScreen$init, (void**) &_InventoryScreen$init);
	MSHookFunction((void*) &InventoryScreen::setupPositions, (void*) &InventoryScreen$setupPositions, (void**) &_InventoryScreen$setupPositions);
	MSHookFunction((void*) &InventoryScreen::render, (void*) &InventoryScreen$render, (void**) &_InventoryScreen$render);
	MSHookFunction((void*) &InventoryScreen::_buttonClicked, (void*) &InventoryScreen$_buttonClicked, (void**) &_InventoryScreen$_buttonClicked);
	MSHookFunction((void*) &InventoryScreen::_populateItems, (void*) &InventoryScreen$_populateItems, (void**) &_InventoryScreen$_populateItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &ScreenChooser::pushInventoryScreen, (void*) &ScreenChooser$pushInventoryScreen, (void**) &_ScreenChooser$pushInventoryScreen);
	
	return JNI_VERSION_1_2;
}
