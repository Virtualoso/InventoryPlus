#pragma once

#include <vector>

class Block;
class Item;

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

class CreativeTab
{
public:
	CreativeTab(ItemInstance*);
	CreativeTab(Item*, int);
	CreativeTab(Block*, int);
	CreativeTab(int, int);
	CreativeTab();
	void setTabIcon(ItemInstance*);
	void setTabIcon(Item*, int);
	void setTabIcon(Block*, int);
	void setTabIcon(int, int);
	ItemInstance* getTabIcon();
	void addItem(ItemInstance*);
	void addItem(Item*, int);
	void addItem(int, int);
	void addItem(Block*, int);
	void addToTabsList();
	
	std::vector<const ItemInstance*> itemsInTab;
	ItemInstance* tabIcon;
};