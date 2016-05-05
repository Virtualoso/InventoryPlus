#include "NativeToolsItems.h"
#include "Barrier.h"

Item* NativeToolsItems::barrier;

void NativeToolsItems::initItems()
{
	barrier = new Barrier("barrier", 420);
}