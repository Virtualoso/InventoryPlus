#include "CreativeTab.h"

#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "../client/screens/InventoryTransitions.h"
#include "../item/NativeToolsItems.h"

CreativeTab::CreativeTab()
{
	tabIcon = new ItemInstance(NativeToolsItems::barrier, 0);
}

ItemInstance* CreativeTab::getTabIcon()
{
	return tabIcon;
}

void CreativeTab::addItemInstance(ItemInstance* item)
{
	itemsInTab.emplace_back(item);
}

void CreativeTab::addItem(Item* item, int data)
{
	addItemInstance(new ItemInstance(item, data));
}

void CreativeTab::addItem(int itemId, int data)
{
	addItem(Item::mItems[itemId], data);
}

void CreativeTab::addBlock(Block* block, int data)
{
	addItemInstance(new ItemInstance(block, data));
}

void CreativeTab::addToTabsList()
{
	InventoryTransitions::creativeTabs.emplace_back(this);	
}