#include "InvPlusItems.h"
#include "Barrier.h"
#include "../creative/CreativeTab.h"

Item* InvPlusItems::barrier;

void InvPlusItems::initItems()
{	
	//registerItemIds();
	
	//barrier = new Barrier("barrier", getNextItemId());

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