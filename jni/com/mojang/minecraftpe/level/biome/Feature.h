#pragma once

class BlockSource;
class BlockPos;
class Entity;
class Random;
struct FullBlock;

class Feature {
public:
    
    Entity* entity;
    /* size = 0x08 */

    // virtual
    virtual ~Feature();
    virtual void place(BlockSource&, BlockPos const&, Random&) const = 0;

    // non virtual
    Feature(Entity*);
    void _placeBlock(BlockSource&, BlockPos const&, FullBlock const&) const;
    void _setBlockAndData(BlockSource&, BlockPos const&, FullBlock const&) const;
    void _setManuallyPlaced(Entity*);
    void _getManuallyPlaced() const;

};