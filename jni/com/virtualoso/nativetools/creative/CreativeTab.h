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
	void addItem(Item*, int); // Item Ptr and Data
	void addItemInstance(const ItemInstance&); // ItemInstance
	void addBlock(Block*, int); // Block Ptr and Data
	void addItem(int, int); // Item ID and Data
	void setTabIcon(Item*, int); // Item Ptr and Data
	void setTabIcon(Block*, int); // Block Ptr and Data
	void setTabIcon(const ItemInstance&); // ItemInstance
	void setTabIcon(int, int); // Item ID and Data
	void setTabIcon(const std::string&); // file path (for image)

	std::vector<ItemInstance> itemsInTab;
	ItemInstance tabIcon;
	std::string imageIcon;
};