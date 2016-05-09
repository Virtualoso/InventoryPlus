#pragma once

#include "../../world/util/Color.h"

struct ShaderColor {
	Color color; // 0
	bool dirty; // 16
	
	Color getColor();
	bool isDirty();
	void makeClean();
	void setColor(const Color&);
};

ShaderColor currentShaderColor;