#pragma once

#include <string>
#include <vector>

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

class Item;
class Block;

class CreativeTab
{
public:
	CreativeTab(); // constructor
	ItemInstance* getTabIcon();
	void addItem(Item*, int); // Item Ptr and Data
	void addItemInstance(ItemInstance*); // ItemInstance
	void addBlock(Block*, int); // Block Ptr and Data
	void addItem(int, int); // Item ID and Data
	void addToTabsList();
	
	ItemInstance* tabIcon;
	std::vector<ItemInstance*> itemsInTab;
};