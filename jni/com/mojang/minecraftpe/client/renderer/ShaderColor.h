#pragma once

#include "../../util/Color.h"

struct ShaderColor {
	Color color; // 0
	bool dirty; // 16
	
	Color getColor();
	bool isDirty() const;
	void makeClean();
	void setColor(Color const&);
};

ShaderColor currentShaderColor;