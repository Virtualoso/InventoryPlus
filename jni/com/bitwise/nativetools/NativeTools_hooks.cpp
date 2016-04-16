#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/client/gui/screen/InventoryScreen.h"

#include "client/screens/InventoryScreenExtras.h"


static void (*_InventoryScreen$init)(InventoryScreen*);
static void InventoryScreen$init(InventoryScreen* self)
{
	InventoryScreenExtras::init(self);

	_InventoryScreen$init(self);
}

static void (*_InventoryScreen$setupPositions)(InventoryScreen*);
static void InventoryScreen$setupPositions(InventoryScreen* self)
{
	_InventoryScreen$setupPositions(self);
	
	InventoryScreenExtras::setupPositions(self);
}

static void (*_InventoryScreen$render)(InventoryScreen*, int, int, float);
static void InventoryScreen$render(InventoryScreen* self, int i1, int i2, float f1)
{
	_InventoryScreen$render(self, i1, i2, f1);
	
	InventoryScreenExtras::render(self, i1, i2, f1);
}

static void (*_InventoryScreen$_buttonClicked)(InventoryScreen*, Button&);
static void InventoryScreen$_buttonClicked(InventoryScreen* self, Button& button)
{
	_InventoryScreen$_buttonClicked(self, button);
	
	InventoryScreenExtras::_buttonClicked(self, button);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	MSHookFunction((void*) &InventoryScreen::init, (void*) &InventoryScreen$init, (void**) &_InventoryScreen$init);
	MSHookFunction((void*) &InventoryScreen::setupPositions, (void*) &InventoryScreen$setupPositions, (void**) &_InventoryScreen$setupPositions);
	MSHookFunction((void*) &InventoryScreen::render, (void*) &InventoryScreen$render, (void**) &_InventoryScreen$render);
	MSHookFunction((void*) &InventoryScreen::_buttonClicked, (void*) &InventoryScreen$_buttonClicked, (void**) &_InventoryScreen$_buttonClicked);
	
	return JNI_VERSION_1_2;
}
