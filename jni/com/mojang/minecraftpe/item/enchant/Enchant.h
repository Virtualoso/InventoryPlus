#pragma once

#include <string>

class ItemInstance;
class Mob;
class Entity;
class EntityDamageSource;

class Enchant
{
public:
	void ** vtable;  //0
public:
	virtual ~Enchant();
	virtual int getMinCost(int) const;
	virtual int getMaxCost(int) const;
	virtual int getMinLevel() const;
	virtual int getMaxLevel() const;
	virtual void getDamageProtection(int, EntityDamageSource const&) const;
	virtual void getDamageBonus(int, Entity const&) const;
	virtual void doPostAttack(Mob&, Mob&, int) const;
	virtual void doPostHurt(ItemInstance&, Mob&, Mob&, int) const;
	virtual bool isMeleeDamageEnchant() const;
	virtual bool isProtectionEnchant() const;
public:
	Enchant(int, int, std::string const&, std::string const&, int, int);
	std::string getStringId() const;
	bool canEnchant(ItemInstance const&) const;
	bool canEnchant(int) const;
	int getFrequency() const;
	std::string getDescription() const;
	bool isCompatibleWith(int) const;
	bool canPrimaryEnchant(ItemInstance const&) const;
	bool canPrimaryEnchant(int) const;
	bool canSecondaryEnchant(ItemInstance const&) const;
	bool canSecondaryEnchant(int) const;
public:
	static void initEnchants();
	static void teardownEnchants();
public:
	static Enchant* mEnchants[72];
};
