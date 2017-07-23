#pragma once

class EnchantmentInstance
{
public:
	int type;
	int level;
public:
	EnchantmentInstance(int, int);
	EnchantmentInstance();
public:
	void setEnchantType(int);
	void setEnchantLevel(int);
	int getEnchantType() const;
	int getEnchantLevel() const;
};
