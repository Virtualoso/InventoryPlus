#pragma once

#include <string>
#include <memory>
#include "../block/BlockID.h"

class Item;
class Block;
class CompoundTag;
class Level;
class Entity;
class Mob;
class Player;
class ItemEnchants;
enum class UseAnimation : unsigned char;

class ItemInstance {

public:

    unsigned char count;
    short data;
    bool valid;
    CompoundTag* nbt;
    Item* item;
    Block* tile;
    /* size = 0x10 */

    ItemInstance();
    ItemInstance(bool);
    ItemInstance(Block const*);
    ItemInstance(Block const*, int);
    ItemInstance(Block const*, int, int);
    ItemInstance(Item const*);
    ItemInstance(Item const*, int);
    ItemInstance(Item const*, int, int);
    ItemInstance(Item const*, int, int, CompoundTag const*);
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

    std::string toString() const;
    std::string getRawNameId() const;
    std::string getName() const;
    std::string getHoverName() const;
    void* getFormattedHovertext(Level&, bool) const;
    std::string _getHoverFormattingPrefix() const;
    void resetHoverName();
    bool hasCustomHoverName() const;
    std::string getCustomName() const;
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
    void* getEffectName() const;
    void* getColor() const;
    int getEnchantValue() const;

    bool isDamageableItem() const;
    bool isStackedByData() const;
    bool isGlint() const;
    bool isThrowable() const;
    bool isStackable() const;
    bool isLiquidClipItem();
    int getMaxStackSize() const;
    int getMaxDamage() const;
    int getAttackDamage();
    bool canDestroySpecial(Block const*);
    int getDestroySpeed(Block const*);
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
    void* startCoolDown(Player*);
    void releaseUsing(Player*, int);
    void* useTimeDepleted(Level*, Player*);
    void inventoryTick(Level&, Entity&, int, bool);
    void* useAsFuel();

    bool matches(ItemInstance const*) const;
    bool sameItemAndAux(ItemInstance const*) const;
    bool isEquivalentArmor(ItemInstance const&);

    void* snap(Player*);
    void setDescriptionId(std::string const&);

    void load(CompoundTag const&);
    std::unique_ptr<CompoundTag> save();
    void* saveEnchantsToUserData(ItemEnchants const&);
    std::unique_ptr<CompoundTag> getNetworkUserData() const;

    ItemInstance getStrippedNetworkItem() const;

    static ItemInstance* fromTag(CompoundTag const&);
    static int retrieveIDFromIDAux(int);
    static int retrieveEnchantFromIDAux(int);
    static int retrieveAuxValFromIDAux(int);
    static bool matches(ItemInstance const*, ItemInstance const*);
    static bool matchesNulls(ItemInstance const*, ItemInstance const*);
    static ItemInstance* clone(ItemInstance const*);
    static ItemInstance* cloneSafe(ItemInstance const*);
    static bool isArmorItem(ItemInstance const*);
    static bool isHorseArmorItem(ItemInstance const*);
    static bool isWearableItem(ItemInstance const*);
    static bool isPotionItem(ItemInstance const*);
    static bool isItem(ItemInstance const*);
    static bool isStackable(ItemInstance const*, ItemInstance const*);

    static int MAX_STACK_SIZE;
    static std::string TAG_DISPLAY;
    static std::string TAG_DISPLAY_NAME;
    static std::string TAG_REPAIR_COST;
    static std::string TAG_ENCHANTS;

};

