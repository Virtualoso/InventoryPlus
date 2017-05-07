#pragma once

#include "GuiElement.h"

class Button : public GuiElement {
public:
	char filler [96 - 46]; // 46
	std::string msg; // 96
	int id; // 100
	bool flip; // 104
	bool pressed; // 105
	bool overrideScreenRendering; // 106

	virtual ~Button();
	virtual void render(MinecraftGame*, int, int);
	virtual void pointerReleased(MinecraftGame*, int, int);
	virtual void drawPressed(int);
	virtual void clicked(MinecraftGame*, int, int);
	virtual void released(int, int);
	virtual void setPressed();
	virtual void setPressed(bool);
	virtual void setMsg(std::string const&);
	virtual void getYImage(bool);
	virtual void renderBg(MinecraftGame*, int, int);
	virtual void renderFace(MinecraftGame*, int, int);

	Button(int, int, int, int, int, std::string const&, bool);
	Button(int, int, int, std::string const&);
	Button(int, std::string const&, bool);
	int _getWidth(MinecraftGame*, std::string const&, int);
	void hovered(MinecraftGame*, int, int);
	bool isInside(int, int);
	bool isOveridingScreenRendering();
	bool isPressed(int, int);
	void setOverrideScreenRendering(bool);
};