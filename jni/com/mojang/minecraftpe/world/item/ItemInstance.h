#pragma once
class Item;
class CompoundTag;
class Block;
class Mob;

#include <string>

class ItemInstance {
public:
	short count, aux;
	CompoundTag* userData;
	bool valid;
	Item* item;
	Block* block;

	ItemInstance();
	ItemInstance(int, int, int);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const ItemInstance&);
	
	const ItemInstance& operator=(const ItemInstance&);
	
	bool isLiquidClipItem();
	void hurtAndBreak(int, Mob*);
	bool sameItemAndAux(const ItemInstance*) const;
	int getMaxStackSize() const;
	std::string getName() const;
	std::string getEffectName() const;
};
