#pragma once

#include <vector>
#include "Container.h"
#include "../item/ItemInstance.h"

class ListTag;

// Size : 32
class FillingContainer : public Container {
public:
	FillingContainer(Player*, int, int, ContainerType);
	virtual ~FillingContainer();
	virtual ItemInstance* getItem(int) const;
	virtual void setItem(int, ItemInstance *);
	virtual void removeItem(int, int);
	virtual std::string getName() const;
	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
	virtual void startOpen(Player&);
	virtual void stopOpen(Player&);
	virtual void add(ItemInstance&, bool);
	virtual bool canAdd(const ItemInstance&) const;
	virtual void dropAll(bool);
	virtual void clearSlot(int);
	virtual void load(const ListTag&);
	virtual void doDrop(ItemInstance&, bool);
	virtual int getEmptySlotsCount() const;
	void _addResource(const ItemInstance&, bool);
	void clearInventory(int);
	void compressLinkedSlotList(int);
	bool contains(ItemInstance&) const;
	void dropAll(int, int, bool);
	void dropSlot(int, bool, bool, bool);
	void _fixBackwardCompabilityItem(ItemInstance&);
	int _getEmptySlotsCount() const;
	void _getFreeSlot() const;
	void getLinked(int) const;
	int getLinkedSlot(int) const;
	void getLinkedSlots();
	void getLinkedSlotsCount() const;
	void _getSlot(int) const;
	void _getSlot(int, int) const;
	void _getSlotWithRemainingSpace(const ItemInstance&) const;
	int getSlotWithItem(const ItemInstance&, bool, bool) const;
	void hasResource(int);
	bool _isCreative() const;
	void _linkEmptySlot(int);
	void linkSlot(int, int);
	void _release(int);
	void removeResource(const ItemInstance&);
	void removeResource(const ItemInstance&, bool);
	void removeResource(int);
	void replace(std::vector<ItemInstance>, int);
	void replaceSlot(int, ItemInstance&);
	void save();
	void swapSlots(int, int);
	void unlinkSlot(int);
};