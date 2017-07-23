#pragma once

#include <string>

#include "EnchantmentInstance.h"

class ListTag;

class ItemEnchants
{
public:
	int size;
	char filler[500];
public:
	ItemEnchants(ItemEnchants&&);
	ItemEnchants(int);
	ItemEnchants(int, ListTag const&);
public:
	std::vector<std::string> getEnchantNames() const;
	int count() const;
	void addEnchant(EnchantmentInstance);
	bool canEnchant(EnchantmentInstance);
	void addEnchants(ItemEnchants const&);
	bool hasEnchant(int) const;
	EnchantmentInstance getEnchants(int) const;
	int getTotalValue(bool) const;
	EnchantmentInstance& getSlot() const;
	void _fromList(ListTag const&);
	std::vector<EnchantmentInstance> getAllEnchants() const;
	ListTag _toList() const;
	bool isEmpty() const;
};
