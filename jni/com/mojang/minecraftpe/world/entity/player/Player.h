#pragma once
#include "../Mob.h"

class Inventory;

class Player : public Mob {
public:
	char filler2[192]; // 3288
	Inventory* inventory; // 3488

	void drop(const ItemInstance*);
	ItemInstance* getSelectedItem() const;
	bool IsCreative() const;
};
