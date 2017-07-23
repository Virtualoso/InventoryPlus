#pragma once

#include <string>
#include <vector>

#include "../../util/Random.h"

class EquipmentFilter;
class BlockSource;
class ItemInstance;
class EntityDamageSource;
class EnchantmentInstance;
class Item;
class Vec3;
class ItemEnchants;

class EnchantUtils
{
public:
	static bool canEnchant(ItemInstance const&, int, int);
	static int getEnchantmentId(std::string const&);
	static void combineEnchantedItems(ItemInstance const&, ItemInstance const&, ItemInstance&, bool);
	static void applyEnchant(ItemInstance&, ItemEnchants const&);
	static std::string getRandomName();
	static int getEnchantCosts(ItemInstance const&, int);
	static void selectEnchantments(Item*, int, int);
	static void getBookCasePositions(BlockSource&, Vec3 const&);
	static void randomlyEnchant(ItemInstance&, int, int);
	static int getBestEnchantLevel(int, Mob const&, EquipmentFilter);
	static void doPostHurtEffects(Mob&, Mob&);
	static int getEnchantLevel(int, ItemInstance const&);
	static bool hasEnchant(int, ItemInstance const&);
	static void getRandomItemWith(int, Mob const&, EquipmentFilter);
	static void getDamageReduction(EntityDamageSource const&, Mob const&);
	static void doPostDamageEffects(Mob&, Mob&);
	static void getMeleeDamageBonus(Mob const&, Mob&);
	static void getTotalProtectionLevels(int, Mob const&);
	static void determineCompatibility(int);
	static bool canEnchant(ItemInstance const&, EnchantmentInstance const&);
	static void applyEnchant(ItemInstance&, EnchantmentInstance const&);
	static void applyEnchant(ItemInstance&, int, int);
	static void removeEnchants(ItemInstance&);
	static void getEquipmentSet(Mob&, EquipmentFilter);
	static void getEquipmentSet(Mob const&, EquipmentFilter);
	static void randomlyEnchant(ItemInstance&);
	static int getBookcaseCount(BlockSource&, Vec3 const&);
	static void getLegalEnchants(Item*);
	static bool isCompatibleWith(int, int);
	static void _convertBookCheck(ItemInstance&);
	static void getRandomItemWith(int, Mob&, EquipmentFilter);
	static void determineActivation(int);
	static void generateEnchantedBook(ItemEnchants const&);
	static void generateEnchantedBook(EnchantmentInstance const&);
	static void getEnchantNameAndLevel(int, int);
	static void generateRandomEnchantedBook(int, int);
	static void generateRandomEnchantedBook();
	static void generateRandomEnchantedItem(Item const*, int, int);
	static void getAvailableEnchantmentResults(Item*, int);
public:
	static Random mSharedRandom;
	static std::vector<std::string> mEnchantmentNames;
	static EnchantUtils * PROTECTIONFACTOR_PRIMARYCAP;
	static EnchantUtils * PROTECTIONFACTOR_SECONDARYCAP;
};
