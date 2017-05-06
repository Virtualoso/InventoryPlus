#pragma once

#include <memory>

#include "Block.h"
#include "entity/BlockEntity.h"

class EntityBlock : public Block {

public:

    virtual ~EntityBlock() {}
    virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&) const;
    virtual void triggerEvent(BlockSource&, BlockPos const&, int, int) const;

    EntityBlock(std::string const&, int, Material const&);
    std::unique_ptr<BlockEntity> newBlockEntity(BlockPos const&, BlockID) const;
    
};