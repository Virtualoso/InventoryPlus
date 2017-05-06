#pragma once

#include <string>
#include "ContainerType.h"

class ItemInstance;
class Player;
class ContainerListener;
class Random;
class BlockSource;
class Vec3;
class CompoundTag;

class Container {
public:
	Container(ContainerType);
	virtual ~Container();
	virtual void addListener(ContainerListener*);
	virtual void removeListener(ContainerListener*);
	virtual ItemInstance* getItem(int) const = 0;
	virtual void addItem(ItemInstance*);
	virtual void addItemToFirstEmptySlot(ItemInstance*);
	virtual void setItem(int, ItemInstance*) = 0;
	virtual void removeItem(int, int) = 0;
	virtual int getRandomEmptySlot(Random&);
	virtual void dropContents(BlockSource&, const Vec3&);
	virtual std::string getName() const = 0;
	virtual int getContainerSize() const = 0;
	virtual int getMaxStackSize() const = 0;
	virtual void startOpen(Player&) = 0;
	virtual void stopOpen(Player&) = 0;
	virtual int getSlotCopies() const;
	virtual int getSlots();
	virtual int getItemCount();
	virtual bool canPushInItem(int, int, ItemInstance*);
	virtual bool canPullOutItem(int, int, ItemInstance*);
	virtual void setContainerChanged(int);
	virtual void setCustomName(const std::string&);
	virtual bool hasCustomName() const;
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
	
	ContainerType getContainerType();
};