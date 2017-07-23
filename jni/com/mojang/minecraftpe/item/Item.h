#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "CreativeItemCategory.h"
#include "UseAnimation.h"
#include "../math/Vec3.h"
#include "../block/BlockID.h"
#include "../util/Util.h"

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
	class Tier {
	public:
		static Tier DIAMOND;
		static Tier GOLD;
		static Tier IRON;
		static Tier STONE;
		static Tier WOOD;		

		int harvestLevel;
		int maxUses;
		float efficiencyOnProperMaterial;
		float damageVsEntity;
		int enchantability;

		Tier(int a, int b, float c, float d, float e) : harvestLevel(a), maxUses(b), efficiencyOnProperMaterial(c), damageVsEntity(d), enchantability(e) {};
		ItemInstance getTierItem() const;
	};

	char maxStackSize; // 4
	std::string iconAtlasName; // 8
	int frameCount; // 12
	bool animatesInToolbar; // 16
	short itemId; // 18
	std::string name; // 20  -   used for description id
	std::string simpleName; // 24
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
	std::unique_ptr<FoodItemComponent> foodComponent; // 100
	std::unique_ptr<SeedItemComponent> seedComponent; // 104
	std::unique_ptr<CameraItemComponent> cameraComponent; // 108

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
static Item* lookupByName(std::string const&, bool);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&, int);
	static TextureUVCoordinateSet getTextureItem(std::string const&);
	static void addBlockItems();
	static void registerItems();
	static void teardownItems();
	static void initClientData();
	static void initServerData(ResourcePackManager&);
	static void addCreativeItem(Block const*, short);
	static void addCreativeItem(Item*, short);
	static void addCreativeItem(ItemInstance const&);
	static void addCreativeItem(short, short);
	static void initCreativeItems();
public:
	float destroySpeedBonus(const ItemInstance&) const;
	void _textMatch(std::string const&, std::string const&, bool);
	void initClient(Json::Value&, Json::Value&);
	void initServer(Json::Value&);
	void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	void setIsMirroredArt(bool);
public:
	static Item* mItems[4096];
	static std::vector<ItemInstance> mCreativeList;
	static std::unordered_map<std::string,std::pair<std::string const,std::unique_ptr<Item>>> mItemLookupMap;
public:
	static Item* mDye_powder;	//_ZN4Item11mDye_powderE
	static Item* mBucket;	//_ZN4Item7mBucketE
	static Item* mGoldHorseArmor;	//_ZN4Item15mGoldHorseArmorE
	static Item* mIronHorseArmor;	//_ZN4Item15mIronHorseArmorE
	static Item* mDiamondHorseArmor;	//_ZN4Item18mDiamondHorseArmorE
	static Item* mLeatherHorseArmor;	//_ZN4Item18mLeatherHorseArmorE
	static Item* mSaddle;	//_ZN4Item7mSaddleE
	static Item* mFilledMap;	//_ZN4Item10mFilledMapE
	static Item* mPaper;	//_ZN4Item6mPaperE
	static Item* mGoldIngot;	//_ZN4Item10mGoldIngotE
	static Item* mIronIngot;	//_ZN4Item10mIronIngotE
	static Item* mBeef_cooked;	//_ZN4Item12mBeef_cookedE
	static Item* mNetherbrick;	//_ZN4Item12mNetherbrickE
	static Item* mPotatoBaked;	//_ZN4Item12mPotatoBakedE
	static Item* mNetherQuartz;	//_ZN4Item13mNetherQuartzE
	static Item* mRabbitCooked;	//_ZN4Item13mRabbitCookedE
	static Item* mMutton_cooked;	//_ZN4Item14mMutton_cookedE
	static Item* mChicken_cooked;	//_ZN4Item15mChicken_cookedE
	static Item* mFish_cooked_cod;	//_ZN4Item16mFish_cooked_codE
	static Item* mFish_cooked_salmon;	//_ZN4Item19mFish_cooked_salmonE
	static Item* mCoal;	//_ZN4Item5mCoalE
	static Item* mBrick;	//_ZN4Item6mBrickE
	static Item* mDiamond;	//_ZN4Item8mDiamondE
	static Item* mEmerald;	//_ZN4Item8mEmeraldE
	static Item* mRedStone;	//_ZN4Item9mRedStoneE
	static Item* mSeeds_wheat;	//_ZN4Item12mSeeds_wheatE
	static Item* mSeeds_beetroot;	//_ZN4Item15mSeeds_beetrootE
	static Item* mCarrot;	//_ZN4Item7mCarrotE
	static Item* mPotato;	//_ZN4Item7mPotatoE
	static Item* mHelmet_iron;	//_ZN4Item12mHelmet_ironE
	static Item* mWheat;	//_ZN4Item6mWheatE
	static Item* mEgg;	//_ZN4Item4mEggE
	static Item* mApple_gold;	//_ZN4Item11mApple_goldE
	static Item* mGoldenCarrot;	//_ZN4Item13mGoldenCarrotE
	static Item* mApple;	//_ZN4Item6mAppleE
	static Item* mBread;	//_ZN4Item6mBreadE
	static Item* mSugar;	//_ZN4Item6mSugarE
	static Item* mFish_raw_cod;	//_ZN4Item13mFish_raw_codE
	static Item* mFish_raw_salmon;	//_ZN4Item16mFish_raw_salmonE
	static Item* mBeetroot;	//_ZN4Item9mBeetrootE
	static Item* mFlintAndSteel;	//_ZN4Item14mFlintAndSteelE
	static Item* mShears;	//_ZN4Item7mShearsE
	static Item* mLead;	//_ZN4Item5mLeadE
	static Item* mNameTag;	//_ZN4Item8mNameTagE
	static Item* mFishingRod;	//_ZN4Item11mFishingRodE
	static Item* mRotten_flesh;	//_ZN4Item13mRotten_fleshE
	static Item* mLeggings_cloth;	//_ZN4Item15mLeggings_clothE
	static Item* mFish_raw_clownfish;	//_ZN4Item19mFish_raw_clownfishE
	static Item* mFish_raw_pufferfish;	//_ZN4Item20mFish_raw_pufferfishE
	static Item* mBow;	//_ZN4Item4mBowE
	static Item* mBone;	//_ZN4Item5mBoneE
	static Item* mBook;	//_ZN4Item5mBookE
	static Item* mBowl;	//_ZN4Item5mBowlE
	static Item* mStick;	//_ZN4Item6mStickE
	static Item* mPotion;	//_ZN4Item7mPotionE
	static Item* mString;	//_ZN4Item7mStringE
	static Item* mLeather;	//_ZN4Item8mLeatherE
	static Item* mBoat;	//_ZN4Item5mBoatE
	static Item* mEnderEye;	//_ZN4Item9mEnderEyeE
	static Item* mMinecart;	//_ZN4Item9mMinecartE
	static Item* mHopper;	//_ZN4Item7mHopperE
	static Item* mHelmet_cloth;	//_ZN4Item13mHelmet_clothE
	static Item* mEnchanted_book;	//_ZN4Item15mEnchanted_bookE
	static Item* mSkull;	//_ZN4Item6mSkullE
	static Item* mPainting;	//_ZN4Item9mPaintingE
	static Item* mArrow;	//_ZN4Item6mArrowE
	static Item* mGhast_tear;	//_ZN4Item11mGhast_tearE
	static Item* mRabbitFoot;	//_ZN4Item11mRabbitFootE
	static Item* mSpider_eye;	//_ZN4Item11mSpider_eyeE
	static Item* mYellowDust;	//_ZN4Item11mYellowDustE
	static Item* mBlazePowder;	//_ZN4Item12mBlazePowderE
	static Item* mMagma_cream;	//_ZN4Item12mMagma_creamE
	static Item* mNether_wart;	//_ZN4Item12mNether_wartE
	static Item* mDragon_breath;	//_ZN4Item14mDragon_breathE
	static Item* mSplash_potion;	//_ZN4Item14mSplash_potionE
	static Item* mSpeckled_melon;	//_ZN4Item15mSpeckled_melonE
	static Item* mLingering_potion;	//_ZN4Item17mLingering_potionE
	static Item* mFermented_spider_eye;	//_ZN4Item21mFermented_spider_eyeE
	static Item* mSulphur;	//_ZN4Item8mSulphurE
	static Item* mBoots_gold;	//_ZN4Item11mBoots_goldE
	static Item* mBoots_iron;	//_ZN4Item11mBoots_ironE
	static Item* mBoots_chain;	//_ZN4Item12mBoots_chainE
	static Item* mBoots_cloth;	//_ZN4Item12mBoots_clothE
	static Item* mHelmet_gold;	//_ZN4Item12mHelmet_goldE
	static Item* mHelmet_chain;	//_ZN4Item13mHelmet_chainE
	static Item* mBoots_diamond;	//_ZN4Item14mBoots_diamondE
	static Item* mLeggings_gold;	//_ZN4Item14mLeggings_goldE
	static Item* mLeggings_iron;	//_ZN4Item14mLeggings_ironE
	static Item* mHelmet_diamond;	//_ZN4Item15mHelmet_diamondE
	static Item* mLeggings_chain;	//_ZN4Item15mLeggings_chainE
	static Item* mChestplate_gold;	//_ZN4Item16mChestplate_goldE
	static Item* mChestplate_iron;	//_ZN4Item16mChestplate_ironE
	static Item* mChestplate_chain;	//_ZN4Item17mChestplate_chainE
	static Item* mChestplate_cloth;	//_ZN4Item17mChestplate_clothE
	static Item* mLeggings_diamond;	//_ZN4Item17mLeggings_diamondE
	static Item* mChestplate_diamond;	//_ZN4Item19mChestplate_diamondE
	static Item* mElytra;	//_ZN4Item7mElytraE
	static Item* mPumpkinPie;	//_ZN4Item11mPumpkinPieE
	static Item* mSeeds_melon;	//_ZN4Item12mSeeds_melonE
	static Item* mBeetrootSoup;	//_ZN4Item13mBeetrootSoupE
	static Item* mMushroomStew;	//_ZN4Item13mMushroomStewE
	static Item* mSeeds_pumpkin;	//_ZN4Item14mSeeds_pumpkinE
	static Item* mMelon;	//_ZN4Item6mMelonE
	static Item* mCookie;	//_ZN4Item7mCookieE
	static Item* mRabbitRaw;	//_ZN4Item10mRabbitRawE
	static Item* mMutton_raw;	//_ZN4Item11mMutton_rawE
	static Item* mChicken_raw;	//_ZN4Item12mChicken_rawE
	static Item* mChorusFruit;	//_ZN4Item12mChorusFruitE
	static Item* mPorkChop_raw;	//_ZN4Item13mPorkChop_rawE
	static Item* mPorkChop_cooked;	//_ZN4Item16mPorkChop_cookedE
	static Item* mChorusFruitPopped;	//_ZN4Item18mChorusFruitPoppedE
	static Item* mClay;	//_ZN4Item5mClayE
	static Item* mBeef_raw;	//_ZN4Item9mBeef_rawE
	static Item* mEmptyMap;	//_ZN4Item9mEmptyMapE
	static Item* mCompass;	//_ZN4Item8mCompassE
	static Item* mGold_nugget;	//_ZN4Item12mGold_nuggetE
	static Item* mDoor_iron;	//_ZN4Item10mDoor_ironE
	static Item* mDoor_wood;	//_ZN4Item10mDoor_woodE
	static Item* mFlowerPot;	//_ZN4Item10mFlowerPotE
	static Item* mItemFrame;	//_ZN4Item10mItemFrameE
	static Item* mSlimeBall;	//_ZN4Item10mSlimeBallE
	static Item* mComparator;	//_ZN4Item11mComparatorE
	static Item* mDoor_birch;	//_ZN4Item11mDoor_birchE
	static Item* mEndCrystal;	//_ZN4Item11mEndCrystalE
	static Item* mEnderpearl;	//_ZN4Item11mEnderpearlE
	static Item* mFireCharge;	//_ZN4Item11mFireChargeE
	static Item* mRabbitHide;	//_ZN4Item11mRabbitHideE
	static Item* mRabbitStew;	//_ZN4Item11mRabbitStewE
	static Item* mDoor_acacia;	//_ZN4Item12mDoor_acaciaE
	static Item* mDoor_jungle;	//_ZN4Item12mDoor_jungleE
	static Item* mDoor_spruce;	//_ZN4Item12mDoor_spruceE
	static Item* mShovel_wood;	//_ZN4Item12mShovel_woodE
	static Item* mTNTMinecart;	//_ZN4Item12mTNTMinecartE
	static Item* mDoor_darkoak;	//_ZN4Item13mDoor_darkoakE
	static Item* mGlass_bottle;	//_ZN4Item13mGlass_bottleE
	static Item* mBrewing_stand;	//_ZN4Item14mBrewing_standE
	static Item* mChestMinecart;	//_ZN4Item14mChestMinecartE
	static Item* mCarrotOnAStick;	//_ZN4Item15mCarrotOnAStickE
	static Item* mHopperMinecart;	//_ZN4Item15mHopperMinecartE
	static Item* mApple_enchanted;	//_ZN4Item16mApple_enchantedE
	static Item* mPrismarineShard;	//_ZN4Item16mPrismarineShardE
	static Item* mPrismarineCrystals;	//_ZN4Item19mPrismarineCrystalsE
	static Item* mBed;	//_ZN4Item4mBedE
	static Item* mCake;	//_ZN4Item5mCakeE
	static Item* mSign;	//_ZN4Item5mSignE
	static Item* mClock;	//_ZN4Item6mClockE
	static Item* mFlint;	//_ZN4Item6mFlintE
	static Item* mReeds;	//_ZN4Item6mReedsE
	static Item* mBlazeRod;	//_ZN4Item9mBlazeRodE
	static Item* mCauldron;	//_ZN4Item9mCauldronE
	static Item* mRepeater;	//_ZN4Item9mRepeaterE
	static Item* mSnowBall;	//_ZN4Item9mSnowBallE
	static Item* mNetherStar;	//_ZN4Item11mNetherStarE
	static Item* mHoe_stone;	//_ZN4Item10mHoe_stoneE
	static Item* mHoe_diamond;	//_ZN4Item12mHoe_diamondE
	static Item* mShovel_gold;	//_ZN4Item12mShovel_goldE
	static Item* mShovel_iron;	//_ZN4Item12mShovel_ironE
	static Item* mHatchet_gold;	//_ZN4Item13mHatchet_goldE
	static Item* mHatchet_iron;	//_ZN4Item13mHatchet_ironE
	static Item* mHatchet_wood;	//_ZN4Item13mHatchet_woodE
	static Item* mPickAxe_gold;	//_ZN4Item13mPickAxe_goldE
	static Item* mPickAxe_iron;	//_ZN4Item13mPickAxe_ironE
	static Item* mPickAxe_wood;	//_ZN4Item13mPickAxe_woodE
	static Item* mShovel_stone;	//_ZN4Item13mShovel_stoneE
	static Item* mHatchet_stone;	//_ZN4Item14mHatchet_stoneE
	static Item* mPickAxe_stone;	//_ZN4Item14mPickAxe_stoneE
	static Item* mShovel_diamond;	//_ZN4Item15mShovel_diamondE
	static Item* mHatchet_diamond;	//_ZN4Item16mHatchet_diamondE
	static Item* mPickAxe_diamond;	//_ZN4Item16mPickAxe_diamondE
	static Item* mHoe_gold;	//_ZN4Item9mHoe_goldE
	static Item* mHoe_iron;	//_ZN4Item9mHoe_ironE
	static Item* mHoe_wood;	//_ZN4Item9mHoe_woodE
	static Item* mSword_gold;	//_ZN4Item11mSword_goldE
	static Item* mSword_iron;	//_ZN4Item11mSword_ironE
	static Item* mSword_wood;	//_ZN4Item11mSword_woodE
	static Item* mSword_stone;	//_ZN4Item12mSword_stoneE
	static Item* mSword_diamond;	//_ZN4Item14mSword_diamondE
	static Item* mFeather;	//_ZN4Item8mFeatherE
	static Item* mMobPlacer;	//_ZN4Item10mMobPlacerE
	static Item* mChalkboard;	//_ZN4Item11mChalkboardE
	static Item* mShulkerShell;	//_ZN4Item13mShulkerShellE
	static Item* mPortfolioBook;	//_ZN4Item14mPortfolioBookE
	static Item* mItemTextureAtlas;	//_ZN4Item17mItemTextureAtlasE
	static Item* mPoisonous_potato;	//_ZN4Item17mPoisonous_potatoE
	static Item* mExperiencePotionItem;	//_ZN4Item21mExperiencePotionItemE
	static Item* mCamera;	//_ZN4Item7mCameraE
};

template <typename ItemType,typename...Args>
ItemType& registerItem(std::string const&name,int id,const Args&...rest)
{
	std::string const item_name = Util::toLower(name);
	if(Item::mItemLookupMap.count(item_name)!=0)
		return *(ItemType*)Item::mItems[id + 0x100];
	
	ItemType* new_instance = new ItemType(name,id,rest...);
	Item::mItems[id + 0x100] = new_instance;
	Item::mItemLookupMap.emplace(item_name,std::pair<std::string const,std::unique_ptr<Item> >(item_name,std::unique_ptr<Item>((Item*)new_instance)));
	return *new_instance;
}