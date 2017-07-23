#pragma once

#include "BlockID.h"

class FullBlock
{
public:
	static FullBlock AIR;

public:
	BlockID id;
	unsigned char data;

public:
	FullBlock() : id(0), data(0) {};
	FullBlock(BlockID tileId, unsigned char aux_) : id(tileId), data(aux_) {}
};
