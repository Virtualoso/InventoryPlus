#include "CreativeHandler.h"

#include "com/mojang/minecraftpe/item/ItemInstance.h"
#include "com/mojang/minecraftpe/item/Item.h"
#include "com/mojang/minecraftpe/block/Block.h"
#include "com/mojang/minecraftpe/client/screen/InventoryScreen.h"

std::vector<ItemGroup> CreativeHandler::itemsToRemove;
std::vector<ItemGroup> CreativeHandler::mItems[5];
bool CreativeHandler::init = false;

void CreativeHandler::remove(ItemGroup item)
{
	itemsToRemove.emplace_back(item);
}

void CreativeHandler::addItemsToInv()
{
	if(!init)
	{
		for(ItemInstance& item : Item::mCreativeList)
		{
			if(shouldRemove(item))
				continue;
			int category;
			if(item.tile != NULL)
				category = ((int) item.tile->getCreativeCategory());
			else if(item.item != NULL)
				category = ((int) Item::mItems[item.getId()]->category);
			else
				category = 1;
			mItems[category].emplace_back(ItemGroup(ItemInstance(item)));
		}
		init = true;
	}
	for(int index = 1; index < 5; index++)
	{
		InventoryScreen::mItems[index].clear();
		InventoryScreen::mItems[index] = mItems[index];
	}
}

bool CreativeHandler::shouldRemove(ItemInstance& itemToAdd)
{
	for(int index = 0; index < itemsToRemove.size(); index++)
	{
		if(itemsToRemove[index].item.sameItemAndAux(itemToAdd))
		{
			itemsToRemove.erase(itemsToRemove.begin() + index);
			return true;
		}
	}
	return false;
}