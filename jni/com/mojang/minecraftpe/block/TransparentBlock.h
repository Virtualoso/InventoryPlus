#pragma once

#include "Block.h"

// Size : 120
class TransparentBlock : public Block {
public:
	bool shouldRender;	// 120

	TransparentBlock(const std::string&, int, const Material&, bool);
	virtual ~TransparentBlock();
	virtual bool shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
};