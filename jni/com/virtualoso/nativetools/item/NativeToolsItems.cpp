#include "NativeToolsItems.h"
#include "Barrier.h"

#include "../creative/CreativeTab.h"

Item* NativeToolsItems::barrier;

void NativeToolsItems::initItems()
{
	barrier = new Barrier("barrier", 420);
	
	CreativeTab* myTab1 = new CreativeTab();
	CreativeTab* myTab2 = new CreativeTab();
	CreativeTab* myTab3 = new CreativeTab();
	CreativeTab* myTab4 = new CreativeTab();
	CreativeTab* myTab5 = new CreativeTab();
	CreativeTab* myTab6 = new CreativeTab();
	myTab1->addToTabsList();
	myTab2->addToTabsList();
	myTab3->addToTabsList();
	myTab4->addToTabsList();
	myTab5->addToTabsList();
	myTab6->addToTabsList();
}