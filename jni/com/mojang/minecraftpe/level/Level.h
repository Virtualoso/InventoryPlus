#pragma once
#include <memory>
class AABB;
class Player;
class Random;
class EntityDamageSource;
class Difficulty;
class LightLayer;
class LevelChunk;

class Level  {
public:
	virtual ~Level();
	Random* getRandom() const;
	int getSeaLevel();
	void setTime(int);
	bool isClientSide() const;
};

