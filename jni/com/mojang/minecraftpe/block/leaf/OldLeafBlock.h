#pragma once

#include "LeafBlock.h"

// Size : 124
class OldLeafBlock : public LeafBlock {
public:
	OldLeafBlock(const std::string&, int);
	virtual ~OldLeafBlock();
	virtual Color getMapColor(BlockSource&, BlockPos const&) const;
	virtual std::string buildDescriptionName(unsigned char) const;
	virtual unsigned int getColor(BlockSource&, BlockPos const&, unsigned char) const;
	virtual int getVariant(int) const;
	virtual int getSpawnResourcesAuxValue(unsigned char) const;
	virtual void dropExtraLoot(BlockSource&, const BlockPos&, int) const;
};