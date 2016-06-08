#pragma once

class NativeTools
{
public:
	static bool init;
	static bool hasNativeTools() { return init; };
};