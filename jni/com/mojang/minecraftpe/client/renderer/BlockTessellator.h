#pragma once

#include "TextureUVCoordinateSet.h"
#include "../../math/AABB.h"
#include "MaterialPtr.h"
#include "../../block/Block.h"
#include "block/BlockShape.h"
#include "../../level/BlockSource.h"
#include "Tessellator.h"
#include "../../level/BlockPos.h"
#include "block/BlockGraphics.h"
class Vec3;
typedef unsigned char uchar;

namespace mce
{
	class TexturePtr;
};

class ThinFenceBlock;
class DoublePlantBlock;
class BrewingStandBlock;
class EndPortalFrameBlock;
class StemBlock;
class FlowerPotBlock;
class FenceGateBlock;
class StairBlock;
class LiquidBlock;
class CocoaBlock;
class AnvilBlock;
class ChorusPlantBlock;
class FenceBlock;
class WallBlock;
class BaseRailBlock;
class AnvilPart;
class BrightnessPair;
enum class BlockRenderLayer;
class BlockOccluder;

class BlockTessellator
{
public:
	bool forceOpaque; // 0
	bool otherb[3]; // 1
	BlockSource* blockSource; // 4
	TextureUVCoordinateSet forcedUV; // 8
	bool useForcedUV; // 36
	bool idk; // 37
	int renderLayer; // 40
	char filler[84]; // 44
	int rotBottom; // 128
	int rotTop; // 132
	int rotNorth; // 136
	int rotSouth; // 140
	int rotWest; // 144
	int rotEast; // 148
	char filler1[500]; // 152
	mce::MaterialPtr material; // 652
	Tessellator& tessellator; // 664
	AABB aabb; // 668
public:
	BlockTessellator(Tessellator&, BlockSource*);
	~BlockTessellator();
	bool canRender(BlockShape);
	float _findDepth(BlockPos const&, float);
	void renderEast(Block const&, Vec3 const&, TextureUVCoordinateSet const&);
	void renderWest(Block const&, Vec3 const&, TextureUVCoordinateSet const&);
	void resetCache(BlockPos const&, BlockSource&);
	void renderNorth(Block const&, Vec3 const&, TextureUVCoordinateSet const&);
	void renderSouth(Block const&, Vec3 const&, TextureUVCoordinateSet const&);
	void renderFaceUp(Block const&, Vec3 const&, TextureUVCoordinateSet const&);
	Color getLightColor(BlockPos const&);
	bool isSolidRender(Block const&);
	bool isTranslucent(Block const&);
	Color _getBlockColor(BlockPos const&, Block const&);
	Color _getBlockColor(BlockPos const&, Block const&, unsigned char);
	Tessellator& getTessellator();
	float getWaterHeight(BlockPos const&, Material const&);
	void renderFaceDown(Block const&, Vec3 const&, TextureUVCoordinateSet const&);
	void renderGuiBlock(FullBlock const&, mce::TexturePtr const&, float, float);
	void setForceOpaque(bool);
	void setRenderLayer(int);
	void _renderAllFaces(Block const&, BlockPos const&, int);
	void clearBlockCache();
	void getMeshForBlock(FullBlock const&);
	void tessellateTorch(Block const&, Vec3 const&, float, float);
	float getLightEmission(Block const&);
	void tessellateBeacon(Block const&, float, Vec3 const&);
	void _preparePolyCross(BlockPos const&, Block const&);
	void renderFaceWithUVs(Block const&, Vec3 const&, TextureUVCoordinateSet const&, float, float, float, float, int);
	void tessellateInWorld(Block const&, BlockPos const&, unsigned char, TextureUVCoordinateSet const&);
	void tessellateInWorld(Block const&, BlockPos const&, unsigned char, bool);
	void tessellateEndRodUp(BlockPos const&, TextureUVCoordinateSet const&);
	void tessellateDragonEgg(Block const&, BlockPos const&, int, bool);
	void tessellateEndRodGui(Block const&, BlockGraphics const&);
	void renderVerticesAndUVs(TextureUVCoordinateSet const&, Vec3 const&, Vec3 const&, Vec2&, Vec2&, Vec2&, Vec2&, int);
	void tessellateAnvilPiece(AnvilBlock const&, BlockPos const&, AnvilPart, float, float, float, float, bool, bool, int, int*, int);
	void tessellateBedInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateEndRodDown(BlockPos const&, TextureUVCoordinateSet const&);
	void tessellateEndRodEast(BlockPos const&, TextureUVCoordinateSet const&);
	void tessellateEndRodWest(BlockPos const&, TextureUVCoordinateSet const&);
	void tessellateRowInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateRowTexture(Block const&, unsigned char, float, float, float);
	void tessellateDoorInWorld(Block const&, BlockPos const&, int);
	void tessellateDustInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateEndRodNorth(BlockPos const&, TextureUVCoordinateSet const&);
	void tessellateEndRodSouth(BlockPos const&, TextureUVCoordinateSet const&);
	void tessellateFireInWorld(Block const&, BlockPos);
	void tessellateRailInWorld(BaseRailBlock const&, BlockPos const&, int);
	void tessellateStemInWorld(StemBlock const&, BlockPos const&);
	void tessellateStemTexture(Block const&, unsigned char, float, float, float, float);
	void tessellateTreeInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateVineInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateWallInWorld(WallBlock const&, BlockPos const&, int);
	Color _getLightColorForWater(BlockPos const&, BrightnessPair);
	void _setShapeAndTessellate(Vec3 const&, Vec3 const&, Block const&, BlockPos const&, int);
	void appendTessellatedBlock(FullBlock const&);
	void getMeshForBlockInWorld(FullBlock const&, BlockPos&, BlockRenderLayer, void const*);
	void tessellateAnvilInWorld(AnvilBlock const&, BlockPos const&);
	void tessellateAnvilInWorld(AnvilBlock const&, BlockPos const&, int);
	void tessellateAnvilInWorld(AnvilBlock const&, BlockPos const&, int, bool);
	void tessellateBlockInWorld(Block const&, BlockPos const&, int);
	void tessellateCocoaInWorld(CocoaBlock const&, BlockPos const&, unsigned char);
	void tessellateCrossInWorld(Block const&, BlockPos const&, unsigned char, bool);
	void tessellateCrossTexture(TextureUVCoordinateSet const&, Vec3 const&, bool, Block const&, float);
	void tessellateCrossTexture(Block const&, unsigned char, Vec3 const&, bool, float);
	void tessellateDiodeInWorld(Block const&, BlockPos const&, int);
	void tessellateFenceInWorld(FenceBlock const&, BlockPos const&, int);
	void tessellateLeverInWorld(Block const&, BlockPos const&, int);
	void tessellateTorchInWorld(Block const&, BlockPos const&, unsigned char);
	void _randomizeFaceDirection(Block const&, signed char, BlockPos const&);
	void tessellateBeaconInWorld(Block const&, BlockPos const&, int);
	void tessellateCactusInWorld(Block const&, BlockPos const&, int);
	void tessellateEndRodInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateHopperInWorld(Block const&, BlockPos const&, int);
	void tessellateHopperInWorld(Block const&, BlockPos const&, int, bool);
	void tessellateLadderInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateLiquidInWorld(LiquidBlock const&, BlockPos const&, unsigned char);
	void tessellatePistonInWorld(Block const&, BlockPos const&, int);
	void tessellateStairsInWorld(StairBlock const&, BlockPos const&, int);
	void tessellateEndRodAppended(Block const&, BlockGraphics const&);
	void tessellateLilypadInWorld(Block const&, BlockPos const&);
	void tessellateStemDirTexture(StemBlock const&, unsigned char, int, float, Vec3 const&);
	void tessellateTopSnowInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateCauldronInWorld(Block const&, BlockPos const&, unsigned char);
	void tessellateRepeaterInWorld(Block const&, BlockPos const&, int);
	void tessellateTripwireInWorld(Block const&, BlockPos const&, int);
	void tessellateBlockInWorldFlat(Block const&, BlockPos const&, int, Color const&, BlockOccluder*);
	void tessellateCrossPolyInWorld(Block const&, BlockPos const&, unsigned char, bool);
	void tessellateCrossPolyTexture(TextureUVCoordinateSet const&, Vec3 const&, bool, Block const&);
	void tessellateEndPortalInWorld(Block const&, BlockPos const&, int);
	void tessellateExtraDataInWorld(Block const&, BlockPos const&);
	void tessellateFenceGateInWorld(FenceGateBlock const&, BlockPos const&, unsigned char);
	void tessellateFlowerPotInWorld(FlowerPotBlock const&, BlockPos const&, int);
	void tessellateThinFenceInWorld(ThinFenceBlock const&, BlockPos const&, unsigned char);
	void tessellateComparatorInWorld(Block const&, BlockPos const&, int);
	void tessellateEndGatewayInWorld(Block const&, BlockPos const&, int);
	void tessellateSlimeBlockInWorld(Block const&, BlockPos const&, int);
	void tessellateChorusPlantInWorld(ChorusPlantBlock const&, BlockPos const&, int);
	void tessellateDoublePlantInWorld(DoublePlantBlock const&, BlockPos const&, unsigned char, bool, bool);
	void tessellateBrewingStandInWorld(BrewingStandBlock const&, BlockPos const&, int);
	void tessellateChorusFlowerInWorld(Block const&, BlockPos const&, int, bool);
	void tessellateTripwireHookInWorld(Block const&, BlockPos const&, int);
	void tessellateStructureVoidInWorld(Block const&, BlockPos const&, int, bool);
	void tessellateEndPortalFrameInWorld(EndPortalFrameBlock const&, BlockPos const&, unsigned char);
	void tessellateBlockInWorldWithAmbienceOcclusion(Block const&, BlockPos, int, Color const&, BlockOccluder*);
	void _tex1(Vec2 const&);
	void blend(int, int, int, int);
	void offsetUVs(TextureUVCoordinateSet const&, Vec2*, Vec2*, Vec2*, Vec2*);
	void renderAll(Block const&, Vec3 const&, TextureUVCoordinateSet const&);
	void setRegion(BlockSource&);
	void _occlusion(BlockPos const&) const;
	TextureUVCoordinateSet _getTexture(Block const&, signed char, int) const;
	int getData(BlockPos const&) const;
	BlockSource& getRegion() const;
public:
	static Vec3 TEXTURE_OFFSET;
};
