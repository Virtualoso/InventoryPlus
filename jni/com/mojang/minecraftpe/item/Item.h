#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "CreativeItemCategory.h"
#include "UseAnimation.h"
#include "../math/Vec3.h"
#include "../block/BlockID.h"

class Level;
class BlockSource;
class Block;
class ItemInstance;
class Entity;
class Mob;
class Player;
class Container;
class TextureUVCoordinateSet;
class TextureAtlas;
class TextureAtlasItem;
class Color;
class IDataInput;
class IDataOutput;
class ResourcePackManager;
enum class CooldownType;
class FoodItemComponent;
class SeedItemComponent;
class CameraItemComponent;
class Random;
namespace Json { class Value; }

class Item {

public:

	char maxStackSize; // 4
	std::string iconAtlasName; // 8
	int frameCount; // 12
	bool animatesInToolbar; // 16
	short id; // 18
	std::string name; // 20  -   used for description id
	std::string name2; // 24
	bool mirroredArt; // 28
	short maxDamage; // 30
	bool glint; // 32
	bool handEquipped; // 33
	bool stackedByData; // 34
	bool requiresWorldBuilder; // 35
	int maxUseDuration; // 36
	int idk; // 40
	BlockID blockId; // 44
	UseAnimation useAnimation; // 45
	CreativeItemCategory category; // 48
	int unknown; // 52
	std::string const* hoverTextColor; // 56
	TextureUVCoordinateSet* icon; // 60
	TextureAtlasItem* customAtlasIcon; // 64
	bool hasRenderOffsets; // 68
	Vec3 vrHandControllerPositionAdjust; // 72
	Vec3 vrHandControllerRotationAdjust; // 84
	float vrHandControllerScale; // 96
	FoodItemComponent* foodComponent; // 100
	SeedItemComponent* seedComponent; // 104
	CameraItemComponent* cameraComponent; // 108

	// virtual
	virtual ~Item();
	virtual void setIcon(std::string const&, int);
	virtual void setIcon(TextureUVCoordinateSet const&);
	virtual void setMaxStackSize(unsigned char);
	virtual void setCategory(CreativeItemCategory);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped();
	virtual void setUseAnimation(UseAnimation);
	virtual void setMaxUseDuration(int);
	virtual void setRequiresWorldBuilder(bool);
	virtual void setExplodable(bool);
	virtual void setIsGlint(bool);
	virtual void setShouldDespawn(bool);
	virtual void* getBlockShape() const;
	virtual bool canBeDepleted() const;
	virtual bool canDestroySpecial(Block const&) const;
	virtual int getLevelDataForAuxValue(int) const;
	virtual bool isStackedByData() const;
	virtual int getMaxDamage() const;
	virtual int getAttackDamage() const;
	virtual bool isHandEquipped() const;
	virtual bool isArmor() const;
	virtual bool isDye() const;
	virtual bool isGlint(ItemInstance const&) const;
	virtual bool isThrowable() const;
	virtual bool canDestroyInCreative() const;
	virtual bool isDestructive(int) const;
	virtual bool isLiquidClipItem(int) const;
	virtual bool requiresInteract() const;
	virtual void appendFormattedHovertext(ItemInstance const&, Level&, std::string&, bool) const;
	virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&) const;
	virtual short getEnchantSlot() const;
	virtual short getEnchantValue() const;
	virtual bool isComplex() const;
	virtual bool isValidAuxValue(int) const;
	virtual int getDamageChance(int) const;
	virtual bool uniqueAuxValues() const;
	virtual Color getColor(ItemInstance const&) const;
	virtual bool isTintable() const;
	virtual bool use(ItemInstance&, Player&) const;
	virtual bool dispense(BlockSource&, Container&, int, Vec3 const&, signed char) const;
	virtual void useTimeDepleted(ItemInstance&, Level*, Player*) const;
	virtual void releaseUsing(ItemInstance&, Player*, int) const;
	virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual bool interactEnemy(ItemInstance&, Mob*, Player*) const;
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
	virtual std::string buildDescriptionName(ItemInstance const&) const;
	virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
	virtual void readUserData(ItemInstance&, IDataInput&) const;
	virtual void writeUserData(ItemInstance const&, IDataOutput&) const;
	virtual int getMaxStackSize(ItemInstance const&) const;
	virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool) const;
	virtual void onCraftedBy(ItemInstance&, Level&, Player&) const;
	virtual CooldownType getCooldownType() const;
	virtual int getCooldownTime() const;
	virtual std::string getInteractText(Player const&) const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual bool isEmissive(int) const;
	virtual TextureUVCoordinateSet const& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool isMirroredArt() const;
	virtual bool _checkUseOnPermissions(Entity&, ItemInstance&, signed char const&, BlockPos const&) const;
	virtual bool _calculatePlacePos(ItemInstance&, Entity&, signed char&, BlockPos&) const;
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;

	// non virtual
	Item(std::string const&, short);
	void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	void* initServer(Json::Value&);
	void* initClient(Json::Value&, Json::Value&);
	void* registerItems();
	void* initCreativeItems();
	void* initServerData(ResourcePackManager&);
	void* initClientData();
	void* addCreativeItem(short, short);
	void* addCreativeItem(ItemInstance const&);
	void* addCreativeItem(Block const*, short);
	void* addCreativeItem(Item*, short);
	void* addBlockItems();
	void* teardownItems();
	void* destroySpeedBonus(ItemInstance const*) const;
	void setIsMirroredArt(bool);
	void* getTextureUVCoordinateSet(std::string const&, int);
	void* getTextureItem(std::string const&);
	void* lookupByName(std::string const&, bool);
	void* _textMatch(std::string const&, std::string const&, bool);

	// static fields
	static std::string ICON_DESCRIPTION_PREFIX;
	static Random* mRandom;
	static void* mItemTextureAtlas;
	static std::unordered_map<std::string, std::unique_ptr<Item>> mItemLookupMap;
	static Item* mItems[512];
	static std::vector<ItemInstance> mCreativeList;
	static Item* mGoldIngot;
	static Item* mIronIngot;
	static Item* mDiamond;
	static Item* mShovel_iron;
	static Item* mPickAxe_iron;
	static Item* mHatchet_iron;
	static Item* mFlintAndSteel;
	static Item* mApple;
	static Item* mBow;
	static Item* mArrow;
	static Item* mCoal;
	static Item* mSword_iron;
	static Item* mSword_wood;
	static Item* mShovel_wood;
	static Item* mPickAxe_wood;
	static Item* mHatchet_wood;
	static Item* mSword_stone;
	static Item* mShovel_stone;
	static Item* mPickAxe_stone;
	static Item* mHatchet_stone;
	static Item* mSword_diamond;
	static Item* mShovel_diamond;
	static Item* mPickAxe_diamond;
	static Item* mHatchet_diamond;
	static Item* mStick;
	static Item* mBowl;
	static Item* mMushroomStew;
	static Item* mSword_gold;
	static Item* mShovel_gold;
	static Item* mPickAxe_gold;
	static Item* mHatchet_gold;
	static Item* mString;
	static Item* mFeather;
	static Item* mSulphur;
	static Item* mHoe_wood;
	static Item* mHoe_stone;
	static Item* mHoe_iron;
	static Item* mHoe_diamond;
	static Item* mHoe_gold;
	static Item* mSeeds_wheat;
	static Item* mWheat;
	static Item* mBread;
	static Item* mHelmet_cloth;
	static Item* mChestplate_cloth;
	static Item* mLeggings_cloth;
	static Item* mBoots_cloth;
	static Item* mElytra;
	static Item* mHelmet_chain;
	static Item* mChestplate_chain;
	static Item* mLeggings_chain;
	static Item* mBoots_chain;
	static Item* mHelmet_iron;
	static Item* mChestplate_iron;
	static Item* mLeggings_iron;
	static Item* mBoots_iron;
	static Item* mHelmet_diamond;
	static Item* mChestplate_diamond;
	static Item* mLeggings_diamond;
	static Item* mBoots_diamond;
	static Item* mHelmet_gold;
	static Item* mChestplate_gold;
	static Item* mLeggings_gold;
	static Item* mBoots_gold;
	static Item* mFlint;
	static Item* mPorkChop_raw;
	static Item* mPorkChop_cooked;
	static Item* mPainting;
	static Item* mChorusFruit;
	static Item* mChorusFruitPopped;
	static Item* mApple_gold;
	static Item* mApple_enchanted;
	static Item* mSign;
	static Item* mDoor_wood;
	static Item* mBucket;
	static Item* mMinecart;
	static Item* mSaddle;
	static Item* mDoor_iron;
	static Item* mRedStone;
	static Item* mSnowBall;
	static Item* mBoat;
	static Item* mMobPlacer;
	static Item* mExperiencePotionItem;
	static Item* mFireCharge;
	static Item* mPumpkinPie;
	static Item* mLeatherHorseArmor;
	static Item* mIronHorseArmor;
	static Item* mGoldHorseArmor;
	static Item* mDiamondHorseArmor;
	static Item* mLead;
	static Item* mLeather;
	static Item* mRabbitHide;
	static Item* mBrick;
	static Item* mClay;
	static Item* mReeds;
	static Item* mPaper;
	static Item* mBook;
	static Item* mSlimeBall;
	static Item* mChestMinecart;
	static Item* mEgg;
	static Item* mCompass;
	static Item* mFishingRod;
	static Item* mClock;
	static Item* mYellowDust;
	static Item* mCarrotOnAStick;
	static Item* mFish_raw_cod;
	static Item* mFish_raw_salmon;
	static Item* mFish_raw_clownfish;
	static Item* mFish_raw_pufferfish;
	static Item* mFish_cooked_cod;
	static Item* mFish_cooked_salmon;
	static Item* mMelon;
	static Item* mSpeckled_melon;
	static Item* mSeeds_pumpkin;
	static Item* mSeeds_melon;
	static Item* mDye_powder;
	static Item* mBone;
	static Item* mSugar;
	static Item* mCake;
	static Item* mBed;
	static Item* mRepeater;
	static Item* mCookie;
	static Item* mPotato;
	static Item* mPotatoBaked;
	static Item* mCarrot;
	static Item* mGoldenCarrot;
	static Item* mBeetroot;
	static Item* mSeeds_beetroot;
	static Item* mBeetrootSoup;
	static Item* mSpider_eye;
	static Item* mFermented_spider_eye;
	static Item* mPoisonous_potato;
	static Item* mSkull;
	static Item* mEnderpearl;
	static Item* mEnderEye;
	static Item* mEndCrystal;
	static Item* mBlazeRod;
	static Item* mNether_wart;
	static Item* mGold_nugget;
	static Item* mBlazePowder;
	static Item* mNetherStar;
	static Item* mShears;
	static Item* mBeef_raw;
	static Item* mBeef_cooked;
	static Item* mChicken_raw;
	static Item* mChicken_cooked;
	static Item* mMutton_raw;
	static Item* mMutton_cooked;
	static Item* mRotten_flesh;
	static Item* mRabbitRaw;
	static Item* mRabbitCooked;
	static Item* mRabbitStew;
	static Item* mRabbitFoot;
	static Item* mNameTag;
	static Item* mDoor_spruce;
	static Item* mDoor_birch;
	static Item* mDoor_jungle;
	static Item* mDoor_acacia;
	static Item* mDoor_darkoak;
	static Item* mGhast_tear;
	static Item* mMagma_cream;
	static Item* mBrewing_stand;
	static Item* mCauldron;
	static Item* mEnchanted_book;
	static Item* mComparator;
	static Item* mNetherbrick;
	static Item* mNetherQuartz;
	static Item* mTNTMinecart;
	static Item* mPrismarineShard;
	static Item* mPrismarineCrystals;
	static Item* mEmerald;
	static Item* mItemFrame;
	static Item* mFlowerPot;
	static Item* mPotion;
	static Item* mSplash_potion;
	static Item* mLingering_potion;
	static Item* mGlass_bottle;
	static Item* mDragon_breath;
	static Item* mHopperMinecart;
	static Item* mHopper;
	static Item* mFilledMap;
	static Item* mEmptyMap;
	static Item* mPortfolioBook;
	static Item* mChalkboard;
	static Item* mCamera;
	static Item* mShulkerShell;
};