#include "HolderItems.h"
#include "Barrier.h"

Item* HolderItems::barrier;

void HolderItems::initItems
{
	barrier = new Barrier("barrier", 420);
}