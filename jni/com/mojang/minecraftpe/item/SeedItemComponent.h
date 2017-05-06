#pragma once

#include "../item/Item.h"

namespace Json {
	class Value;
};
class ItemInstance;
class Entity;
class BlockPos;
class Vec3;

class SeedItemComponent {
public:

	/* 0x00 */ Item& item;
	/* 0x04 */ unsigned char cropResult;
	/* 0x05 */ unsigned char plantAt;
	/* 0x06 */ short whoknows;
	/* size = 0x08 */

	SeedItemComponent(Item&);

	void init(Json::Value&);
	void useOn(ItemInstance&, Entity&, BlockPos const&, signed char, Vec3 const&);

};
