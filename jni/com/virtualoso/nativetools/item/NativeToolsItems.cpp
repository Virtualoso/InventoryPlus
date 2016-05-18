#include "NativeToolsItems.h"
#include "Barrier.h"

#include "../creative/CreativeTab.h"

Item* NativeToolsItems::barrier;

void NativeToolsItems::initItems()
{
	barrier = new Barrier("barrier", 420);
	
	CreativeTab* myTab1 = new CreativeTab();
	myTab1->addItem(4, 0);
	myTab1->addItem(11, 0);
	myTab1->addItem(4, 0);
	myTab1->addItem(110, 0);
	myTab1->addItem(5, 0);
	myTab1->addItem(11, 0);
	myTab1->addItem(46, 0);
	myTab1->addItem(49, 0);
	myTab1->addItem(4, 0);
	myTab1->addItem(11, 0);
	myTab1->addItem(4, 0);
	myTab1->addItem(110, 0);
	myTab1->addItem(5, 0);
	myTab1->addItem(11, 0);
	myTab1->addItem(46, 0);
	myTab1->addItem(49, 0);
	myTab1->addToTabsList();
	CreativeTab* myTab2 = new CreativeTab();
	myTab2->addItem(4, 0);
	myTab2->addItem(110, 0);
	myTab2->addItem(5, 0);
	myTab2->addItem(11, 0);
	myTab2->addItem(5, 0);
	myTab2->addItem(11, 0);
	myTab2->addItem(46, 0);
	myTab2->addItem(49, 0);
	myTab2->addItem(4, 0);
	myTab2->addItem(11, 0);
	myTab2->addItem(4, 0);
	myTab2->addItem(110, 0);
	myTab2->addItem(11, 0);
	myTab2->addItem(46, 0);
	myTab2->addItem(49, 0);
	myTab2->addItem(4, 0);
	myTab2->addToTabsList();
	CreativeTab* myTab3 = new CreativeTab();
	myTab3->addItem(5, 0);
	myTab3->addItem(11, 0);
	myTab3->addItem(5, 0);
	myTab3->addItem(4, 0);
	myTab3->addItem(110, 0);
	myTab3->addItem(49, 0);
	myTab3->addItem(4, 0);
	myTab3->addItem(11, 0);
	myTab3->addItem(110, 0);
	myTab3->addItem(11, 0);
	myTab3->addItem(46, 0);
	myTab3->addItem(4, 0);
	myTab3->addItem(11, 0);
	myTab3->addItem(46, 0);
	myTab3->addItem(49, 0);
	myTab3->addItem(4, 0);
	myTab3->addToTabsList();
	CreativeTab* myTab4 = new CreativeTab();
	myTab4->addItem(5, 0);
	myTab4->addItem(4, 0);
	myTab4->addItem(110, 0);
	myTab4->addItem(46, 0);
	myTab4->addItem(49, 0);
	myTab4->addItem(5, 0);
	myTab4->addItem(11, 0);
	myTab4->addItem(4, 0);
	myTab4->addItem(11, 0);
	myTab4->addItem(110, 0);
	myTab4->addItem(49, 0);
	myTab4->addItem(11, 0);
	myTab4->addItem(46, 0);
	myTab4->addItem(4, 0);
	myTab4->addItem(11, 0);
	myTab4->addItem(4, 0);
	myTab4->addToTabsList();
	CreativeTab* myTab5 = new CreativeTab();
	myTab5->addItem(11, 0);
	myTab5->addItem(11, 0);
	myTab5->addItem(4, 0);
	myTab5->addItem(4, 0);
	myTab5->addItem(49, 0);
	myTab5->addItem(5, 0);
	myTab5->addItem(5, 0);
	myTab5->addItem(110, 0);
	myTab5->addItem(46, 0);
	myTab5->addItem(4, 0);
	myTab5->addItem(4, 0);
	myTab5->addItem(11, 0);
	myTab5->addItem(110, 0);
	myTab5->addItem(49, 0);
	myTab5->addItem(11, 0);
	myTab5->addItem(46, 0);
	myTab5->addToTabsList();
}