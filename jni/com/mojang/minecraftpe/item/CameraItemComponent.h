#pragma once

#include "../item/Item.h"

class ItemInstance;
class Player;
class Entity;
namespace Json {
	class Value;
};
class BlockPos;
class Vec3;

class CameraItemComponent {
public:

	/* 0x04 */ float blackBarsDuration;
	/* 0x08 */ float blackBarsScreenRatio;
	/* 0x0C */ Item& item;
	/* 0x10 */ float shutterDuration;
	/* 0x14 */ float pictureDuration;
	/* 0x18 */ float slideAwayDuration;
	/* 0x1C */ bool whoknows2;
	/* 0x20 */ int whoknows3;
	/* size = 0x24 */

	virtual ~CameraItemComponent();

	CameraItemComponent(Item&);

	void releaseUsing(ItemInstance&, Player&, int);
	void takePictureNow(Player&, Entity*, Entity*);
	void use(ItemInstance&, Player&);
	void init(Json::Value&);
	void useOn(ItemInstance&, Entity&, BlockPos const&, signed char, Vec3 const&);

};
