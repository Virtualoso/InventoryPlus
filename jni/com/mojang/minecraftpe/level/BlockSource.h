#pragma once

#include "../math/AABB.h"
#include "FullBlock.h"
#include <vector>
#include <memory>

class Level;
class Dimension;
class ChunkSource;
class BlockSourceListener;
class LevelChunk;
class ChunkPos;
class BlockPos;
class Block;
struct BlockID;
struct Brightness;
class Material;
class BlockEntity;
class BlockTickingQueue;
class Bounds;
class Biome;
class Entity;
class Mob;
class HitResult;
class LightLayer;
enum class MaterialType;
enum class BlockSupportType;
enum class EntityType;

enum class DimensionId;

class BlockSource {
public:
    // virtual
    virtual ~BlockSource();

    // non virtual
    BlockSource(Level&, Dimension&, ChunkSource&, bool, bool);

    Level const& getLevel() const;
    Level& getLevel();
    Level const& getLevelConst() const;
    ChunkSource& getChunkSource();
    bool getPublicSource() const;
    bool isOwnerThread() const;
    void clearCachedLastChunk();

    Dimension const& getDimension() const;
    Dimension& getDimension();
    DimensionId getDimensionId() const;
    Dimension const& getDimensionConst() const;

    void addListener(BlockSourceListener&);
    void removeListener(BlockSourceListener&);

    LevelChunk* getChunk(ChunkPos const&);
    LevelChunk* getChunk(int, int);
    LevelChunk* getChunkAt(BlockPos const&);
    LevelChunk* getChunkAt(int, int, int);
    LevelChunk* getWritableChunk(ChunkPos const&);
    bool hasChunksAt(Bounds const&);
    bool hasChunksAt(AABB const&);
    bool hasChunksAt(BlockPos const&, int);
    bool hasChunksAt(int, int, int, int);
    bool hasChunksAt(BlockPos const&, BlockPos const&);

    Biome& getBiome(BlockPos const&);
    Biome* tryGetBiome(BlockPos const&);

    int getHeightmap(BlockPos const&);
    int getHeightmap(int, int);
    BlockPos getHeightmapPos(BlockPos const&);
    BlockID getTopBlock(int, int&, int);
    BlockPos getTopRainBlockPos(BlockPos const&);
    bool checkIsTopRainBlockPos(BlockPos const&);
    bool findNextTopSolidBlockUnder(BlockPos&);
    bool findNextSpawnBlockUnder(BlockPos&);
    int getAboveTopSolidBlock(BlockPos const&, bool, bool);
    int getAboveTopSolidBlock(int, int, bool, bool);
    int getAllocatedHeightAt(BlockPos const&);

    Block* getBlock(BlockPos const&);
    Block* getBlock(int, int, int);
    Material* getMaterial(BlockPos const&);
    Material* getMaterial(int, int, int);
    BlockID getBlockID(BlockPos const&);
    BlockID getBlockID(int, int, int);
    FullBlock getBlockAndData(BlockPos const&);
    FullBlock getBlockAndData(int, int, int);
    unsigned char getData(BlockPos const&);
    unsigned char getData(int, int, int);
    int getBrightness(LightLayer const&, BlockPos const&);
    int getBrightness(LightLayer const&, int, int, int);
    int getBrightness(BlockPos const&);
    int getBrightness(int, int, int);
    Brightness getRawBrightness(int, int, int, bool);
    Brightness getRawBrightness(BlockPos const&, bool);
    unsigned short getExtraData(BlockPos const&);
    BlockEntity* getBlockEntity(BlockPos const&);
    BlockEntity* getBlockEntity(int, int, int);
    int getGrassColor(BlockPos const&);
    bool hasBlock(BlockPos const&);
    bool hasBlock(int, int, int);
    bool isEmptyBlock(BlockPos const&);
    bool isEmptyBlock(int, int, int);
    bool isSolidBlockingBlock(int, int, int);
    bool isSolidBlockingBlock(BlockPos const&);
    bool isConsideredSolidBlock(int, int, int);
    bool isConsideredSolidBlock(BlockPos const&);
    bool isInWall(Vec3 const&);
    bool _isWaterAt(BlockPos const&);
    bool _isIceAt(BlockPos const&);
    bool isPositionUnderLiquid(BlockPos const&, MaterialType);
    bool isHumidAt(BlockPos const&);
    bool shouldFreezeIgnoreNeighbors(BlockPos const&);
    bool shouldFreeze(BlockPos const&, bool);
    bool shouldThaw(BlockPos const&, bool);
    bool canProvideSupport(BlockPos const&, signed char, BlockSupportType);

    bool checkBlockDestroyPermissions(Entity&, BlockPos const&, bool);
    bool checkBlockPermissions(Entity&, BlockPos const&, bool);
    bool _getBlockPermissions(BlockPos const&, bool);
    bool hasBorderBlock(BlockPos);

    void setBlock(int, int, int, BlockID, int);
    void setBlockAndData(BlockPos const&, FullBlock, int, Entity*);
    void setBlock(BlockPos const&, BlockID, int);
    void setBlockAndData(BlockPos const&, FullBlock, int, Entity*, std::unique_ptr<BlockEntity, std::default_delete<BlockEntity>>);
    void setBlockAndData(BlockPos const&, BlockID, unsigned char, int, Entity*);
    void setBlockAndData(int, int, int, BlockID, unsigned char, int);
    void setBlockAndData(int, int, int, FullBlock, int);
    void setBlockNoUpdate(int, int, int, BlockID);
    void setBlockAndDataNoUpdate(int, int, int, FullBlock);
    void setBrightness(LightLayer const&, BlockPos const&, Brightness);
    void setBrightness(LightLayer const&, int, int, int, Brightness);
    void* getLightColor(BlockPos const&, Brightness);
    void setExtraData(BlockPos const&, unsigned short);
    void setGrassColor(int, BlockPos const&, int);
    void setBorderBlock(BlockPos const&, bool);
    void removeBlock(int, int, int);
    void removeBlock(BlockPos const&);
    void removeBlockEntity(BlockPos const&);

    bool containsAnyLiquid(AABB const&);
    bool containsAnySolidBlocking(AABB const&);
    bool containsAny(BlockPos const&, BlockPos const&);
    bool containsFireBlock(AABB const&);
    bool containsMaterial(AABB const&, MaterialType);
    bool containsLiquid(AABB const&, MaterialType);
    bool isUnobstructedByEntities(AABB const&, Entity*);
    bool isSnowTemperature(BlockPos const&);
    bool mayPlace(BlockID, BlockPos const&, signed char, Entity*, bool, Entity*);
    bool canSeeSky(int, int, int);
    bool canSeeSky(BlockPos const&);
    bool canSeeSkyFromBelowWater(BlockPos);

    BlockTickingQueue* getTickQueue(BlockPos const&);
    void setTickingQueue(BlockTickingQueue&);

    void blockEvent(int, int, int, int, int);
    void blockEvent(BlockPos const&, int, int);
    void _blockChanged(BlockPos const&, FullBlock, FullBlock, int, Entity*);
    void neighborChanged(BlockPos const&, BlockPos const&);
    void updateNeighborsAt(BlockPos const&);
    void updateNeighborsAt(BlockPos const&, BlockPos const&);
    void updateNeighborsAtExceptFromFacing(BlockPos const&, BlockPos const&, int);
    void onChunkDiscarded(LevelChunk&);
    void fireBlockEvent(int, int, int, int, int);
    void fireBlockChanged(BlockPos const&, FullBlock, FullBlock, int, Entity*);
    void fireBlocksDirty(BlockPos const&, BlockPos const&);
    void fireAreaChanged(BlockPos const&, BlockPos const&);
    void fireBrightnessChanged(BlockPos const&);
    void fireBlockEntityChanged(BlockEntity&);
    void fireBlockEntityRemoved(std::unique_ptr<BlockEntity, std::default_delete<BlockEntity>>);
    void fireEntityChanged(Entity&);
    void _fireColumnDirty(int, int, int, int, int);
    bool shouldFireEvents(LevelChunk&) const;
    void runLightUpdates(LightLayer const&, BlockPos const&, BlockPos const&);
    void updateLightIfOtherThan(LightLayer const&, BlockPos const&, Brightness);
    float getSeenPercent(Vec3 const&, AABB const&);
    Brightness _getSkyDarken();

    std::vector<Mob*> getMobsAt(EntityType, BlockPos const&);
    std::vector<Entity*> getEntities(Entity*, AABB const&);
    std::vector<Entity*> getEntities(EntityType, AABB const&, Entity*);
    Entity* getNearestEntityOfType(Entity*, AABB const&, EntityType);
    Entity* getNearestEntityOfType(Entity*, Vec3 const&, float, EntityType);
    Entity* getNearestEntityNotOfType(Entity*, Vec3 const&, float, EntityType);

    std::vector<AABB>& fetchAABBs(AABB const&, bool);
    std::vector<AABB>& fetchBorderBlockAABBs(AABB const&);
    std::vector<AABB>& fetchCollisionShapes(BlockSource&, AABB const&, float*, bool, Entity*);
    std::vector<AABB>& fetchBorderBlockCollisions(BlockSource&, AABB const&, Entity*);
    void addUnloadedChunksAABBs(AABB const&);
    void addVoidFloor(AABB const&);

    HitResult clip(Vec3 const&, Vec3 const&, bool, bool, int, bool);

};

