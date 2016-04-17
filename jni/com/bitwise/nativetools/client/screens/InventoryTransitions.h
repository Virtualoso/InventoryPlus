#pragma once

#include <memory>

#include "com/mojang/minecraftpe/client/gui/TButton.h"

class Screen;

class InventoryTransitions {
public:
	static std::shared_ptr<Touch::TButton> forwardButton;
	static std::shared_ptr<Touch::TButton> backButton;

	static void init(Screen*);
	static void setupPositions(Screen*);
	static void render(Screen*, int, int, float);
	static void _buttonClicked(Screen*, Button&);
};