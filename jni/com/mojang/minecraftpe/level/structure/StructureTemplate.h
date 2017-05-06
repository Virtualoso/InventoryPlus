#pragma once

#include <string>
#include <memory>

#include "StructureBlockInfo.h"
#include "StructureSettings.h"
#include "../../block/BlockID.h"
#include "../../math/Vec3.h"

class BlockSource;
class BlockPos;
class CompoundTag;

class StructureTemplate {

public:
    
    // TODO: Research fields
    char filler[0x44];
    /* size = 0x44 */

    StructureTemplate();
    StructureTemplate(StructureTemplate const&);
    ~StructureTemplate();
    void calculateConnectedPosition(StructureSettings const&, BlockPos const&, StructureSettings const&, BlockPos const&) const;
    void placeEntities(BlockSource&, BlockPos const&, Mirror, Rotation, BoundingBox const&);
    void load(CompoundTag&);
    void _mapToData(BlockID, StructureBlockInfo&, StructureSettings const&);
    void _mapToString(CompoundTag&, unsigned char);
    void fillEntityList(BlockSource&, BlockPos const&, BlockPos&);
    void setAuthor(std::string);
    StructureTemplate& operator=(StructureTemplate const&);
    void _transform(BlockPos, Mirror, Rotation) const;
    void _calculateRelativePosition(BlockPos, StructureSettings const&) const;
    void placeInWorld(BlockSource&, BlockPos const&, StructureSettings&);
    void fillFromWorld(BlockSource&, BlockPos const&, BlockPos const&, bool);
    void save(CompoundTag&);
    void getSize(Rotation);
    void getMarkers(BlockPos const&, StructureSettings&);
    void placeInWorldChunk(BlockSource&, BlockPos const&, StructureSettings&);
    void _mapToBlock(std::string&, int&);
    void _mapToProperty(std::string const&, std::string const&, std::string const&);
    void _mapTag(std::unique_ptr<CompoundTag>);
    void _transform(Vec3, Mirror, Rotation) const;
    void _calculateRelativePosition(Vec3, StructureSettings const&) const;

    // static
    static StructureSettings defaultSettings;
    static std::string MINECRAFT_PREFIX;
    static std::string AUTHOR_TAG;
    static std::string BLOCKS_TAG;
    static std::string PALETTE_TAG;
    static std::string VERSION_TAG;
    static std::string ENTITIES_TAG;
    static std::string BLOCK_TAG_NBT;
    static std::string BLOCK_TAG_POS;
    static std::string ENTITY_TAG_NBT;
    static std::string ENTITY_TAG_POS;
    static std::string BLOCK_TAG_STATE;
    static std::string ENTITY_TAG_BLOCKPOS;
    static std::string SIZE_TAG;

};