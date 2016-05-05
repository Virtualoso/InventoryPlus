#include "Barrier.h"

Barrier::Barrier(const std::string& name, short id) : Item(name, id - 0x100)
{
	Item::mItems[id] = this;
	setIcon("barrier", 0);
	setCategory(CreativeItemCategory::ITEM);
}