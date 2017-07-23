#pragma once

#include "Block.h"

class Color;

// Size : 140
class HeavyBlock : public Block
{
public:
	HeavyBlock(std::string const&, int, Material const&);
	virtual void tick(BlockSource&, BlockPos const&, Random&) const;
	virtual void onPlace(BlockSource&, BlockPos const&) const;
	virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&) const;
	virtual void animateTick(BlockSource&, BlockPos const&, Random&) const;
	virtual Color* getDustColor(unsigned char) const = 0;
	virtual void falling() const;
	virtual void onLand(BlockSource&, BlockPos const&) const;
	virtual void isFree(BlockSource&, BlockPos const&) const;
	virtual void startFalling(BlockSource&, const BlockPos&, const Block*, bool) const;
	void checkSlide(BlockSource&, const BlockPos&) const;
	void _findBottomSlidingBlock(BlockSource&, const BlockPos&) const;
	void _scheduleCheck(BlockSource&, const BlockPos&, const Block*, int) const;
	void _scheduleCheckIfSliding(BlockSource&, const BlockPos&, const Block*) const;
	void _tickBlocksAround2D(BlockSource&, const BlockPos&, const Block*) const;
};
