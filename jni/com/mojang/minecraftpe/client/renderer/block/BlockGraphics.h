#pragma once

#include <unordered_map>
#include "../../../util/Color.h"
#include "../../../math/AABB.h"
#include "../TextureAtlasItem.h"

class BlockSource;
class BlockPos;
class Block;
class AABB;
class Vec3;
class Random;
class FullBlock;
enum class BlockRenderLayer;
enum class BlockShape;
class TextureAtlas;
class TextureAtlasItem;
class ResourcePackManager;
namespace Json { class Value; }

enum class BlockSoundType {
    NORMAL, GRAVEL, WOOD, GRASS, METAL, STONE, CLOTH, GLASS, SAND, SNOW, LADDER, ANVIL, SLIME, SILENT, DEFAULT, UNDEFINED
};

class BlockGraphics {

public:

    /* 0x04 */ unsigned char id;
    /* 0x08 */ Block* block;
    /* 0x0C */ unsigned int isotropicTextureFace;
    /* 0x10 */ int unknown;
    /* 0x14 */ BlockShape blockShape;
    /* 0x1C */ float brightnessGamma;
    /* 0x20 */ Color mapColor;
    /* 0x30 */ bool fancy;
    /* 0x34 */ BlockSoundType soundType;
    /* 0x38 */ AABB visualShape;
    /* 0x54 */ TextureAtlasItem texture[6];
    /* 0xCC */ TextureAtlasItem carriedTexture[6];
    /* 0x144 */ std::string textureName[6];
    /* 0x15C */ std::string carriedTextureName[6];
    /* size = 0x174 */

    // virtual
    virtual ~BlockGraphics();
    virtual bool shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
    virtual int getIconYOffset() const;
    virtual unsigned int getColor(int) const;
    virtual unsigned int getColor(BlockSource&, BlockPos const&) const;
    virtual unsigned int getColorForParticle(BlockSource&, BlockPos const&, int) const;
    virtual bool isSeasonTinted(BlockSource&, BlockPos const&) const;
    virtual void onGraphicsModeChanged(bool, bool);
    virtual BlockRenderLayer getRenderLayer(BlockSource&, BlockPos const&) const;
    virtual void* getExtraRenderLayers();
    virtual AABB const& getVisualShape(BlockSource&, BlockPos const&, AABB&, bool);
    virtual AABB const& getVisualShape(unsigned char, AABB&, bool);
    virtual void* getCarriedTexture(signed char, int) const;
    virtual void animateTick(BlockSource&, BlockPos const&, Random&);
    virtual Vec3 randomlyModifyPosition(BlockPos const&, int&) const;
    virtual Vec3 randomlyModifyPosition(BlockPos const&) const;
    virtual void setVisualShape(AABB const&);
    virtual void setVisualShape(Vec3 const&, Vec3 const&);

    // non virtual
    BlockGraphics(std::string const&);

    void setTextures(BlockGraphics&, Json::Value const&);
    void setTextureItem(std::string const&);
    void setTextureItem(std::string const&, std::string const&, std::string const&);
    void setTextureItem(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&);
    void setCarriedTextures(BlockGraphics&, Json::Value const&);
    void setCarriedTextureItem(std::string const&);
    void setCarriedTextureItem(std::string const&, std::string const&, std::string const&);
    void setCarriedTextureItem(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&);
    void setTextureIsotropic(BlockGraphics&, Json::Value const&);
    void setTextureIsotropic(unsigned int);
    void setAllFacesIsotropic();
    void setBlockShape(BlockGraphics&, Json::Value const&);
    void setBlockShape(BlockShape);
    void setBrightnessGamma(BlockGraphics&, Json::Value const&);
    void setSoundType(BlockGraphics&, Json::Value const&);
    void setSoundType(BlockSoundType);
    void setMapColor(Color const&);
    TextureAtlasItem* getTextureItem(std::string const&);
    Block* getBlock() const;
    Color getMapColor(FullBlock const&) const;
    Color getMapColor() const;
    TextureUVCoordinateSet& getTexture(signed char) const;
    TextureUVCoordinateSet& getTexture(signed char, int) const;
    TextureAtlasItem& getAtlasItem(signed char) const;
    bool isTextureIsotropic(signed char) const;
    bool isAlphaTested();
    bool isFullAndOpaque();
    bool isFullAndOpaque(Block const&);
    unsigned int getFaceTextureIsotropic();
    BlockSoundType getSoundType() const;
    BlockShape getBlockShape() const;
    BlockRenderLayer getRenderLayer() const;
    
    static void initBlocks(ResourcePackManager&);
    static void teardownBlocks();
    static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
    static void reloadBlockUVs(TextureAtlas&);
    static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&, int);
    static BlockGraphics* lookupByName(std::string const&, bool);

    // static fields
    static float SIZE_OFFSET;
    static std::shared_ptr<TextureAtlas> mTerrainTextureAtlas;
    static BlockGraphics* mBlocks[];
    static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
    static std::unordered_map<std::string, BlockGraphics*> mBlockLookupMap;

};

