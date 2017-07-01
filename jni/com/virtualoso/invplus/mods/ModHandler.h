#pragma once

#include <vector>

class Mod;

class ModHandler
{
public:
	static std::vector<Mod*> modList;

	static void initMod(Mod*);
	static void initModBlocks();
	static void initModItems();
	static void initModCreativeItems();
};