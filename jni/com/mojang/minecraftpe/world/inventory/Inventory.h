#pragma once

#include "FillingContainer.h"

class Block;
class Entity;

// Size : 40
class Inventory : public FillingContainer {
public:
	Inventory(Player*);
	virtual ~Inventory();
	virtual int getContainerSize() const;
	virtual void add(ItemInstance&, bool);
	virtual bool canAdd(const ItemInstance&) const;
	virtual void dropAll(bool);
	virtual void clearSlot(int);
	virtual void load(const ListTag&);
	virtual void doDrop(ItemInstance&, bool);
	virtual int getEmptySlotsCount() const;
	virtual void setContainerSize(int);
	bool canDestroy(Block *);
	void clearInventoryWithDefault(bool);
	void getAttackDamage(Entity *);
	void getDestroySpeed(Block *);
	int getLinkedSlotForItem(int);
	int getLinkedSlotForItemIdAndAux(int, int);
	int getLinkedSlotForExactItem(const ItemInstance&) const;
	void getSelectedItem() const;
	int getSelectedSlot() const;
	int getSelectionSize();
	void moveToEmptySelectionSlot(int);
	void moveToSelectedSlot(int);
	void moveToSelectionSlot(int, int);
	void selectSlot(int);
	void setupDefault();
};
