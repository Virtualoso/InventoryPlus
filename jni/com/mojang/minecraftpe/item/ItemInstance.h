#pragma once

#include <string>
#include <memory>
#include <vector>

#include "../util/String.h"
#include "../block/BlockID.h"
#include "../json/json/json.h"

class Item;
class Block;
class CompoundTag;
class Level;
class Entity;
class Mob;
class Player;
class ItemEnchants;
class BlockEntity;
class BlockSource;
class IDataInput;
class IDataOutput;
enum class UseAnimation : unsigned char;

class ItemInstance {

public:
	unsigned char count;
    short data;
    bool valid;
    CompoundTag* nbt;
    Item* item;
    Block* tile;
    std::vector<const Block*> blockVec1;
	std::vector<const Block*> blockVec2;

    ItemInstance();
    ItemInstance(int, int, int);
    ItemInstance(int, int, int, CompoundTag const*);
    ItemInstance(ItemInstance const&);

    void init(int, int, int);

    int getId() const;
    void _setItem(int);
    short getDamageValue() const;
    short getAuxValue() const;
    void setAuxValue(short);
    int getIdAux() const;
    int getIdAuxEnchanted() const;

    bool isNull() const;
    void setNull();

    void set(int);
    void add(int);
    void remove(int);

    std::unique_ptr<CompoundTag>& getUserData() const;
    void setUserData(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>>);
    bool hasUserData() const;
    bool hasSameUserData(ItemInstance const&) const;

    mcpe::string toString() const;
    mcpe::string getRawNameId() const;
    mcpe::string getName() const;
    mcpe::string getHoverName() const;
    void* getFormattedHovertext(Level&, bool) const;
    mcpe::string _getHoverFormattingPrefix() const;
    void resetHoverName();
    bool hasCustomHoverName() const;
    mcpe::string getCustomName() const;
    void setCustomName(std::string const&);
    void setJustBrewed(bool);
    bool wasJustBrewed() const;
    bool isEnchanted() const;
    bool isEnchantingBook() const;
    bool isFullStack() const;
    bool isDamaged() const;
    int getBaseRepairCost() const;
    void setRepairCost(int);
    void* getEnchantsFromUserData() const;
    mcpe::string getEffectName() const;
    void* getColor() const;
    int getEnchantValue() const;

    bool isDamageableItem() const;
    bool isStackedByData() const;
    bool isGlint() const;
    bool isThrowable() const;
    bool isStackable() const;
    int getMaxStackSize() const;
    int getMaxDamage() const;
    void* getIcon(int, bool) const;
    UseAnimation getUseAnimation() const;
    int getMaxUseDuration() const;
    int getEnchantSlot() const;

    void* use(Player&);
    void* useOn(Entity&, int, int, int, signed char, float, float, float);
    void* interactEnemy(Mob*, Player*);
    void* hurtAndBreak(int, Entity*);
    void* hurtEnemy(Mob*, Mob*);
    void* mineBlock(BlockID, int, int, int, Mob*);
    void* onCraftedBy(Level&, Player&);
    void releaseUsing(Player*, int);
    void* useTimeDepleted(Level*, Player*);
    void inventoryTick(Level&, Entity&, int, bool);
    void* useAsFuel();


    void* snap(Player*);
    void setDescriptionId(std::string const&);

    void load(CompoundTag const&);
    void* saveEnchantsToUserData(ItemEnchants const&);
    std::unique_ptr<CompoundTag> getNetworkUserData() const;

    ItemInstance getStrippedNetworkItem() const;
    ItemInstance(Block const&);
    ItemInstance(Block const&, int);
    ItemInstance(Block const&, int, int);
    ItemInstance(Item const&);
    ItemInstance(Item const&, int);
    ItemInstance(Item const&, int, int);
    ItemInstance(Item const&, int, int, CompoundTag const*);
    void* _cloneComponents(ItemInstance const&);
    void* _hasComponents() const;
    void* _initComponents();
    void* addCustomUserData(BlockEntity&, BlockSource&);
    void* startCoolDown(Player*) const;
    bool isEquivalentArmor(ItemInstance const&) const;
    void* getDestroySpeed(Block const&) const;
    void* operator=(ItemInstance const&);
    bool isStackable(ItemInstance const&) const;
    void* componentsMatch(ItemInstance const&) const;
    void* getAttackDamage() const;
    bool canDestroySpecial(Block const&) const;
    bool sameItemAndAux(ItemInstance const&) const;
    bool hasComponent(std::string const&) const;
    ItemInstance clone() const;
    void* matchesItem(ItemInstance const&) const;
    void* matches(ItemInstance const&) const;
    void* save() const;
    void* _saveComponents(CompoundTag&) const;
    void* _loadComponents(CompoundTag const&);
    bool isArmorItem() const;
    bool isHorseArmorItem() const;
    bool isWearableItem() const;
    bool isOffhandItem() const;
    bool isPotionItem() const;
    bool isLiquidClipItem() const;
    bool canPlaceOn(Block const*) const;
    bool canDestroy(Block const*) const;
    void* addComponents(Json::Value const&, std::string&);
    bool isValidComponent(std::string const&);
    void* updateComponent(std::string const&, Json::Value const&);
    void* serializeComponents(IDataOutput&) const;
    void* deserializeComponents(IDataInput&);

    static ItemInstance* fromTag(CompoundTag const&);
    static int retrieveIDFromIDAux(int);
    static int retrieveEnchantFromIDAux(int);
    static int retrieveAuxValFromIDAux(int);

    static int MAX_STACK_SIZE;
    static std::string TAG_DISPLAY;
    static std::string TAG_DISPLAY_NAME;
    static std::string TAG_REPAIR_COST;
    static std::string TAG_ENCHANTS;
};

class ItemGroup {
public:
	ItemInstance item;
	int count;

	ItemGroup(ItemInstance _item, int _count) : item(_item), count(_count) { }
	ItemGroup(ItemInstance _item) : item(_item), count(_item.count) { }

	ItemInstance getItemType() const;
};
