#include "NativeToolsItems.h"
#include "Barrier.h"

#include "../NativeTools.h"

Item* NativeToolsItems::barrier;

void NativeToolsItems::initItems()
{	
	registerItemIds();
	
	barrier = new Barrier("barrier", getNextItemId());
}

int NativeToolsItems::index;
std::vector<int> NativeToolsItems::freeIds;

void NativeToolsItems::registerItemIds()
{
	for(int counter = 256; counter < 4096; counter++)
	{
		if(Item::mItems[counter] == NULL)
			freeIds.emplace_back(counter);
	}
}

int NativeToolsItems::getNextItemId()
{	
	int id = freeIds[index];
	index++;
	return id;
}