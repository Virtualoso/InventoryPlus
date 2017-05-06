#pragma once

#include <stdint.h>

enum class BlockProperty;

struct BlockID {

    uint_fast8_t id;

    BlockID(uint_fast8_t id) : id(id) { }
    BlockID(BlockID const& b) : BlockID(b.id) { }

    bool operator==(BlockID const& b) { return id == b.id; }
    bool operator!=(BlockID const& b) { return !(*this == b); }

    bool hasProperty(BlockProperty) const;

    static BlockID AIR;

};
