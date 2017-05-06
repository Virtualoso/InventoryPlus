#pragma once

class BlockPos;
class Vec3;

class ChunkPos {

public:

    int x, int z;

    // non virtual
    ChunkPos(BlockPos const&);
    ChunkPos(Vec3 const&);
    float distanceToSqr(Entity const&) const;
    BlockPos getMiddleBlockPosition(int) const;

    // static
    static ChunkPos INVALID;
};