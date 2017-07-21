#pragma once

#include <vector>

class ItemGroup;
class ItemInstance;

class CreativeHandler
{
public:
	static std::vector<ItemGroup> itemsToRemove;
	static std::vector<ItemGroup> mItems[5];
	static bool init;

	static void remove(ItemGroup);
	static void addItemsToInv();
	static bool shouldRemove(ItemInstance&);
};