#pragma once

#include "../math/Vec3.h"

class ChunkPos;

class BlockPos {

public:

    int x, y, z;

    BlockPos(int x, int y, int z) : x(x), y(y), z(z) { }
    BlockPos(float, float, float);
    BlockPos(Vec3 const&);
    BlockPos(ChunkPos const&, int);
    BlockPos(BlockPos const& b) : x(b.x), y(b.y), z(b.z) { }

    std::string toString() const;

    BlockPos neighbor(signed char) const;
    BlockPos relative(signed char, int) const;

    Vec3 center() const;

    static BlockPos MIN;
    static BlockPos MAX;
    static BlockPos ONE;
    static BlockPos ZERO;

};

