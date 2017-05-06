#pragma once

class BlockPos;
class CompoundTag;
struct FullBlock;

class StructureBlockInfo {

public:

    // TODO: Research fields
    /* size = unknown */

    StructureBlockInfo(BlockPos const&, CompoundTag const&, FullBlock const&);
    StructureBlockInfo(StructureBlockInfo const&);

};