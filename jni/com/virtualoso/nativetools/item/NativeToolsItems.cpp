#include "NativeToolsItems.h"
#include "Barrier.h"

#include "../creative/CreativeTab.h"

Item* NativeToolsItems::barrier;

void NativeToolsItems::initItems()
{
	barrier = new Barrier("barrier", 420);
}