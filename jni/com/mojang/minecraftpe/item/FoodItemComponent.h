#pragma once

#include <vector>
#include "../item/Item.h"

namespace Json {
	class Value;
};
class ItemInstance;
class Player;
class Level;
class Entity;
class BlockPos;
class Vec3;

class FoodItemComponent {
public:

	class Effect {
	public:

	};

	/* 0x00 */ Item& item;
	/* 0x04 */ int nutrition;
	/* 0x08 */ float saturationModifier;
	/* 0x0C */ bool isMeat;
	/* 0x10 */ std::string eatSound;
	/* 0x14 */ std::string usingConvertsTo;
	/* 0x18 */ std::vector<FoodItemComponent::Effect>& effects;
	/* size = 0x24 */

	FoodItemComponent(Item&);

	int getNutrition() const;
	float getSaturationModifier() const;
	void _loadEffects(std::vector<FoodItemComponent::Effect>&, Json::Value&);
	void useTimeDepleted(ItemInstance&, Player&, Level&);
	void _applyEatEffects(ItemInstance&, Player&, Level&);
	void use(ItemInstance&, Player&);
	void init(Json::Value&);
	void useOn(ItemInstance&, Entity&, BlockPos const&, signed char, Vec3 const&);

};
