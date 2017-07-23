#pragma once

#include "Item.h"

class ToolItem : public Item {
public:
	float efficiencyOnProperMaterial = 4.0F; // 108
	Item::Tier* toolMaterial; // 112
	float damageVsEntity; // 116
    std::vector<Block*> validBlocks; // 120

    ToolItem(const std::string&, short, float, Item::Tier, std::vector<Block*>);
	virtual int getAttackDamage();
	virtual bool isHandEquipped() const;
	virtual void appendFormattedHovertext(const ItemInstance&, Level&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual short getEnchantValue() const;
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};