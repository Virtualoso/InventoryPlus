#include "InvPlusItems.h"
#include "Barrier.h"
#include "../creative/CreativeTab.h"

Item* InvPlusItems::barrier;

void InvPlusItems::initItems()
{	
	//registerItemIds();
	
	//barrier = new Barrier("barrier", getNextItemId());
	CreativeTab* newTab = new CreativeTab(262, 0);
	newTab->addItem(262, 0);
	newTab->addItem(43, 0);
	newTab->addItem(17, 0);
	newTab->addItem(77, 0);
	newTab->addItem(55, 0);
	newTab->addItem(101, 0);
	newTab->addToTabsList();
}

int InvPlusItems::index;
std::vector<int> InvPlusItems::freeIds;

void InvPlusItems::registerItemIds()
{
	for(int counter = 256; counter < 4096; counter++)
	{
		if(Item::mItems[counter] == NULL)
			freeIds.emplace_back(counter);
	}
}

int InvPlusItems::getNextItemId()
{	
	int id = freeIds[index];
	index++;
	return id;
}