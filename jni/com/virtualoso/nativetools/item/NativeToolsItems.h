#pragma once

#include <vector>

class Item;

class NativeToolsItems
{
public:
	static Item* barrier;

	static void initItems();
	
	static int index;
	static std::vector<int> freeIds;
	static void registerItemIds();
	static int getNextItemId();
};