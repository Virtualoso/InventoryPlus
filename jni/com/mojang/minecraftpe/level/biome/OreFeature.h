#pragma once

#include "Feature.h"
#include "../../block/BlockID.h"

class BlockSource;
class BlockPos;
class Random;

class OreFeature : public Feature {
    
public:
    
    /* 0x08 */ BlockID blockId;
    /* 0x09 */ unsigned char data;
    /* 0x0C */ int count;
    /* size = 0x10 */

    // virtuals
    virtual void place(BlockSource&, BlockPos const&, Random&) const;

    // non virtuals
    OreFeature(BlockID, unsigned char, int);
    OreFeature(BlockID, int);
    void _isDiggable(BlockID);
};