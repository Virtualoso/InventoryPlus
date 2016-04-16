#pragma once

#include <memory>

#include "com/mojang/minecraftpe/client/gui/TButton.h"

class InventoryScreen;

class InventoryScreenExtras {
public:
	static std::shared_ptr<Touch::TButton> forwardButton;
	static std::shared_ptr<Touch::TButton> backButton;

	static void init(InventoryScreen*);
	static void setupPositions(InventoryScreen*);
	static void render(InventoryScreen*, int, int, float);
	static void _buttonClicked(InventoryScreen*, Button&);
};