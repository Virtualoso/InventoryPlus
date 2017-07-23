#pragma once

#include "LeafBlock.h"

// Size : 124
class NewLeafBlock : public LeafBlock {
public:
	NewLeafBlock(const std::string&, int);
	virtual ~NewLeafBlock();
	virtual std::string buildDescriptionName(unsigned char) const;
	virtual int getVariant(int) const;
	virtual int getSpawnResourcesAuxValue(unsigned char) const;
	virtual void dropExtraLoot(BlockSource&, const BlockPos&, int) const;
};