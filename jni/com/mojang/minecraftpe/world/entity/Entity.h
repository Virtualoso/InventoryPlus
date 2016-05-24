#pragma once
#include <string>
#include <memory>
#include <vector>
class BlockSource;
class Level;
class Material;
class Player;
class EntityPos;
struct BlockPos;
class CompoundTag;
class ArmorSlot;
class EntityLink;
class EntityDamageSource;
class EntityEvent;
class ItemInstance;
class ChangeDimensionPacket;
class ExplodeComponent;
class Dimension;
class Random;
class Entity;
#include "../material/Material.h"
#include "EntityType.h"
#include "EntityRendererId.h"
#include "SynchedEntityData.h"
#include "../level/dimension/dimensionId.h"
#include "../phys/AABB.h"
#include "../phys/Vec3.h"
#include "../phys/Vec2.h"
#include "../util/Color.h"
#include "../level/BlockPos.h"
#include "../../CommonTypes.h"

typedef std::vector<Entity*> EntityList;

class Entity {
public:
	void* synchedData; // 4
	Vec3 pos; // 8
	Vec3 oldPos; // 20
	Vec3 chunkPos; // 32
	Vec3 velocity; // 44
	Vec2 rotation; // 56
	Vec2 idk; // 64
	Vec2 idk1; // 72
	SynchedEntityData entityData; // 80
	char filler[16]; // 96
	DimensionId dimensionId; // 112
	bool idk_b; // 116
	Level& level; // 120
	char idec[4]; // 124
	Color lastLightColor; // 128
	AABB boundingBox; // 144
	float someFloat; // 172
	float headHeight; // 176
	char filler2[12]; // 180
	float ridingHeight; // 192
	Vec2 idk2; // 196
	char filler3[16]; // 204
	int airSupply; // 220
	int fireTicks; // 224
	char filler4[8]; // 228
	BlockID block; // 236
	BlockPos maxBlockPos; // 240
	int noclue; // 252  **ALWAYS 255**
	char filler5[4]; // 256
	EntityRendererId rendererId; // 260
	EntityList riders; // 264
	Entity& rider; // 268
	Entity& riding; // 272
	bool isRiding; // 276
	int idk5; // 280
	char filler6[12]; // 284
	bool what1; // 296
	bool what2; // 297
	bool what3; // 298
	bool what4; // 299
	bool what5; // 300
	bool what6; // 301
	bool hurtMarked; // 302
	bool noPhysics; // 303
	bool shouldRender; // 304
	bool isInvincible; // 305
	bool idk6; // 306
	bool notaclue; // 307
	bool huh; // 308
	bool noidea; // 309
	char uniqueId[8]; //  312
	int autoSend; // 320
	Vec3 someVec; // 324
	char filler7[8]; // 336
	bool what7; // 344
	bool isStuckInWeb; // 345
	bool inWater; // 346
	bool immobile; // 347
	bool changed; // 348
	ExplodeComponent* exploder; // 352
	int idk4; // 356
	bool isRemoved; // 360
	bool isGlobal; // 361
	bool isRegistered; // 362
	BlockSource& region; // 364
	
	static int mEntityCounter;
	

	Entity(BlockSource&);
	Entity(Level&);
	
	virtual ~Entity();
	virtual void _postInit();
	virtual void reset();
	virtual int getOwnerEntityType();
	virtual void remove();
	virtual void setPos(const Vec3&);
	virtual Vec3& getPos() const;
	virtual Vec3& getPosOld() const;
	virtual Vec3& getPosExtrapolated(float) const;
	virtual Vec3& getVelocity() const;
	virtual void move(const Vec3&);
	virtual void checkBlockCollisions(const AABB&);
	virtual void checkBlockCollisions();
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(const Vec3&, const Vec2&, int);
	virtual void lerpMotion(const Vec3&);
	virtual void turn(const Vec2&);
	virtual void interpolateTurn(const Vec2&);
	virtual void* getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void* positionRider(Entity&) const;
	virtual float getRidingHeight();
	virtual float getRideHeight() const;
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void removeRider(Entity&);
	virtual bool intersects(const Vec3&, const Vec3&);
	virtual bool isFree(const Vec3&, float);
	virtual bool isFree(const Vec3&);
	virtual bool isInWall() const;
	virtual bool isInvisible();
	virtual bool canShowNameTag();
	virtual void setNameTagVisible(bool);
	virtual const std::string& getNameTag() const;
	virtual void setNameTag(const std::string&);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isBaby() const;
	virtual bool isUnderLiquid(MaterialType) const;
	virtual void makeStuckInWeb();
	virtual float getHeadHeight() const;
	virtual float getShadowHeightOffs();
	virtual float getShadowRadius() const;
	virtual bool isSkyLit(float);
	virtual float getBrightness(float);
	virtual bool interactPreventDefault();
	virtual void interactWithPlayer(Player&);
	virtual bool canInteractWith(Player&);
	virtual std::string getInteractText(Player&);
	virtual void playerTouch(Player&);
	virtual void push(Entity&, bool);
	virtual void push(const Vec3&);
	virtual bool isImmobile() const;
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual void hurt(const EntityDamageSource&, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void onBounceStarted(const BlockPos&, const FullBlock&);
	virtual void handleEntityEvent(EntityEvent);
	virtual int getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance&, float);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, const ItemInstance&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(const CompoundTag&);
	virtual void loadLinks(const CompoundTag&, std::vector<EntityLink, std::allocator<EntityLink>>&);
	virtual EntityType getEntityTypeId() const = 0;
	virtual void queryEntityRenderer();
	virtual void getSourceUniqueID();
	virtual void setOnFire(int);
	virtual AABB getHandleWaterAABB() const;
	virtual void handleInsidePortal();
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual DimensionId getDimensionId() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket&);
	virtual Player* getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSound(const std::string&, float, float);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual float getEyeHeight() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual bool hasOutputSignal(signed char) const;
	virtual signed char getOutputSignal() const;
	virtual void getDebugText(std::vector<std::string,std::allocator<std::string>>&);
	virtual void setSize(float, float);
	virtual void setPos(const EntityPos&);
	virtual void outOfWorld();
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag*) = 0;
	virtual void addAdditionalSaveData(CompoundTag*) = 0;
	virtual void _playStepSound(const BlockPos&, int);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(const Vec3&);
	virtual void updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void updateInsideBlock();
	virtual void onBlockCollision(int);	
	
	void _exitRide(const Entity&, float);
	void _findRider(Entity&) const;
	void _init();
	void _manageRiders(BlockSource&);
	void _sendLinkPacket(const EntityLink&) const;
	void _tryPlaceAt(const Vec3&);
	void _updateOwnerChunk();
	void buildForward() const;
	float distanceSqrToBlockPosCenter(const BlockPos&);
	float distanceTo(const Entity&);
	float distanceTo(const Vec3&);
	float distanceToSqr(const Entity&);
	float distanceToSqr(const Vec3&);
	void enableAutoSendPosRot();
	int getAirSupply() const;
	void getCenter(float);
	Dimension& getDimension() const;
	SynchedEntityData& getEntityData() const;
	SynchedEntityData& getEntityData();
	void getEyePos();
	Vec3& getInterpolatedPosition(float) const;
	Vec3& getInterpolatedPosition2(float) const;
	Vec2& getInterpolatedRotation(float) const;
	Level& getLevel();
	std::vector<EntityLink> getLinks() const;
	Vec2& getPortalEntranceDir() const;
	Vec3& getRandomPointInAABB(Random&);
	BlockSource& getRegion() const;
};