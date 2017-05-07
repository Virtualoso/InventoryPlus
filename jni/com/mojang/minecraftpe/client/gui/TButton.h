#pragma once

#include "Button.h"

class ResourceLocation;

namespace Touch {

class TButton : public Button {
public:
	char filler[8];

	virtual ~TButton();
	virtual void renderBg(MinecraftGame*, int, int);

	TButton(int, std::string const&, MinecraftGame*, bool, int);
	TButton(int, int, int, std::string const&, MinecraftGame*, int);
	TButton(int, int, int, int, int, std::string const&, MinecraftGame*, bool, int);
	void init(MinecraftGame*);
	void init(MinecraftGame*, std::string const&, IntRectangle const&, IntRectangle const&, int, int, int, int);
	void init(MinecraftGame*, ResourceLocation const&, IntRectangle const&, IntRectangle const&, int, int, int, int);
};

};