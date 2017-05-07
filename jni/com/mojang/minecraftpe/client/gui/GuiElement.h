//need to update this whole header

#pragma once

#include <string>
#include "GuiComponent.h"
#include "../../util/Color.h"

class StickDirection;
class MinecraftGame;
class NinePatchLayer;
class Vec2;
class ResourceLocation;

// Size : 48
class GuiElement : public GuiComponent
{
public:
	bool enabled;						// 4
	bool visible;						// 5
	int xPosition;						// 8
	int yPosition;						// 12
	int width;							// 16
	int height;							// 20
	Color backgroundColor;				// 24
	NinePatchLayer *backgroundLayer;	// 40
	bool selected;						// 44
	bool focused;						// 45
	
	virtual ~GuiElement();
	virtual void tick();
	virtual void tick(MinecraftGame*);
	virtual void render(MinecraftGame*, int, int);
	virtual void topRender(MinecraftGame*, int, int);
	virtual void setupPositions();
	virtual void pointerPressed(MinecraftGame*, int, int);
	virtual void pointerReleased(MinecraftGame*, int, int);
	virtual void focusedMouseClicked(MinecraftGame*, int, int);
	virtual void focusedMouseReleased(MinecraftGame*, int, int);
	virtual void handleButtonPress(MinecraftGame*, short);
	virtual void handleButtonRelease(MinecraftGame*, short);
	virtual void handleTextChar(MinecraftGame*, std::string const&, bool);
	virtual void handleCaretLocation(int);
	virtual void backPressed(MinecraftGame*, bool);
	virtual void setKeyboardHeight(MinecraftGame*, float, Vec2 const&);
	virtual void pointInside(int, int);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(std::string const&);
	virtual void hasFocus() const;
	virtual void setFocus(bool);
	virtual void handleControllerDirectionHeld(int, StickDirection);
	virtual void drawSelected(int);
	virtual void drawPressed(int);
	virtual void drawSliderSelected();
	virtual void onSelectedChanged();
	virtual void hasChildren() const;
	
	GuiElement(bool, bool, int, int, int, int);
	void clearBackground();
	void isSelected();
	void setActiveAndVisibility(bool);
	void setActiveAndVisibility(bool, bool);
	void setBackground(Color const&);
	void setBackground(MinecraftGame*, ResourceLocation const&, IntRectangle const&, int, int);
	void setBackground(MinecraftGame*, std::string const&, IntRectangle const&, int, int);
	void setSelected(bool);
	void setVisible(bool);
};