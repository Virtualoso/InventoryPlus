#pragma once

#include "com/mojang/minecraftpe/client/gui/screen/Screen.h"

class NinePatchLayer;
class ImageWithBackground;
class InventoryTab;
class CreativeTab;

class ExtendedInventoryScreen : public Screen
{
public:
	std::shared_ptr<ImageWithBackground> closeButton;
	std::shared_ptr<NinePatchLayer> backgroundLayer;
	std::shared_ptr<NinePatchLayer> leftButtonLayer;
	std::shared_ptr<NinePatchLayer> rightButtonLayer;
	std::vector<std::shared_ptr<InventoryTab>> renderedTabs;
	std::vector<CreativeTab*> ownedTabs;
	
	ExtendedInventoryScreen(MinecraftClient&, std::vector<CreativeTab*>);

	virtual bool renderGameBehind() const;
	virtual bool closeOnPlayerHurt() const;
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void _buttonClicked(Button&);
	virtual void handleBackEvent(bool);
	virtual bool isModal() const;
	virtual void tick();
	virtual std::string getScreenName();
	
	std::shared_ptr<InventoryTab> createInventoryTab(int, bool);
};
