#pragma once

class NativeTools
{
public:
	static bool init = false;
	static bool hasNativeTools() { return init; };
};