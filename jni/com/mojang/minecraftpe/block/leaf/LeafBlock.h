#pragma once

#include "../TransparentBlock.h"

// Size : 124
class LeafBlock : public TransparentBlock {
public:
	bool leavesFancy;	// 121

	LeafBlock(const std::string&, int);
	virtual ~LeafBlock();
	virtual void tick(BlockSource&, BlockPos const&, Random&) const;
	virtual void onRemove(BlockSource&, BlockPos const&) const;
	virtual int getResource(Random&, int, int) const;
	virtual int getResourceCount(Random&, int, int) const;
	virtual ItemInstance asItemInstance(BlockSource&, BlockPos const&, int) const;
	virtual void spawnResources(BlockSource&, BlockPos const&, int, float, int) const;
	virtual void playerDestroy(Player*, BlockPos const&, int) const;
	virtual void getMobToSpawn(BlockSource&, BlockPos const&) const;
	virtual Color getMapColor(BlockSource&, BlockPos const&) const;
	virtual unsigned int getColor(BlockSource&, BlockPos const&, unsigned char) const;
	virtual bool isSeasonTinted(BlockSource&, BlockPos const&) const;
	virtual Block* onGraphicsModeChanged(bool, bool, bool);
	virtual int getRenderLayer(BlockSource&, BlockPos const&) const;
	virtual int getSpawnResourcesAuxValue(unsigned char) const;
	virtual void dropExtraLoot(BlockSource&, const BlockPos&, int) const = 0;

	bool isDeepLeafBlock(BlockSource&, const BlockPos&);
	void runDecay(BlockSource&, const BlockPos&, int);
	void die(BlockSource&, const BlockPos&) const;
	Color getSeasonsColor(BlockSource&, const BlockPos&, int, int) const;
};