#pragma once

#include "Entity.h"

class Item;
class MobEffectInstance;
class PathNavigation;
class LookControl;
class MoveControl;
class JumpControl;
class BodyControl;
class Sensing;
class MobEffect;
class EntityUniqueID;
class Attribute;
class ItemEntity;
#include "../item/ItemInstance.h"

// Size : 3178
class Mob : public Entity {
public:
	float yBodyRot; // 368
	float yBodyRotO; // 372
	float yHeadRot; // 376
	float yHeadRotO; // 380
	char mfiller[2572]; // 384
	ItemInstance armor[4]; // 2956
	char mfiller1[96]; // 3036
	bool wat; // 3132
	bool isJumping; // 3133
	int whocares; // 3136
	float speed; // 3140
	LookControl* lookControl; // 3144
	MoveControl* moveControl; // 3148
	JumpControl* jumpControl; // 3152
	BodyControl* bodyControl; // 3156
	PathNavigation* getNavigation; // 3160
	Sensing* getSensing; // 3164
	char mfiller2[32]; // 3168
	float yYa; // 3200
	char mfiller3[4]; // 3204
	bool wat1; // 3208
	bool isSurfaceMob; // 3209
	int wat2; // 3212
	char mfiller4[52]; // 3216
	bool canPickupLoot; // 3268
	bool removeWhenFarAway; // 3269
	float wat3; // 3272
	float wat4; // 3276
	int arrowCount; // 3280
	int idk_i; // 3284
	
	Mob(Level &);
	Mob(BlockSource &);
	
	virtual ~Mob();
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual bool isBaby() const;
	virtual float getHeadHeight() const;
	virtual void playerTouch(Player&);
	virtual bool isImmobile() const;
	virtual bool isPickable();
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual void hurt(const EntityDamageSource&, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(EntityEvent);
	virtual void setOnFire(int);
	virtual void causeFallDamage(float);
	virtual bool canAddRider(Entity&) const;
	virtual void buildDebugInfo(std::string &) const;
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(const BlockPos&, int);
	virtual void postInit();
	virtual void knockback(Entity *, int, float, float);
	virtual void die(const EntityDamageSource&);
	virtual void resolveDeathLoot(int);
	virtual bool canSee(const Entity&) const;
	virtual void onLadder(bool);
	virtual void spawnAnim();
	virtual bool isSleeping() const;
	virtual void setSneaking(bool);
	virtual bool isSprinting() const;
	virtual void setSprinting(bool);
	virtual float getVoicePitch();
	virtual void playAmbientSound();
	virtual int getAmbientSoundInterval();
	virtual void getItemInHandIcon(ItemInstance const *, int);
	virtual void getSpeed();
	virtual void setSpeed(float);
	virtual void getJumpPower() const;
	virtual void heal(int);
	virtual void hurtEffects(EntityDamageSource const &, int);
	virtual void getMeleeWeaponDamageBonus(Mob *);
	virtual void getMeleeKnockbackBonus();
	virtual void actuallyHurt(int, EntityDamageSource const *);
	virtual bool isInvertedHealAndHarm() const;
	virtual void travel(float, float);
	virtual void applyFinalFriction(float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual bool isLookingAtAnEntity();
	virtual bool canSpawn(bool);
	virtual void finalizeMobSpawn();
	virtual bool shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual void performRangedAttack(Mob &, float);
	virtual ItemInstance& getCarriedItem();
	virtual void setCarriedItem(const ItemInstance&);
	virtual void getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual void getMaxHeadXRot();
	virtual Mob* getLastHurtByMob();
	virtual void setLastHurtByMob(Mob*);
	virtual Player* getLastHurtByPlayer();
	virtual void setLastHurtByPlayer(Player*);
	virtual Entity* getLastHurtMob();
	virtual void setLastHurtMob(Entity*);
	virtual Mob* getTarget();
	virtual void setTarget(Mob *);
	virtual void canAttack(Mob *, bool);
	virtual bool isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual bool canBeControlledByRider();
	virtual void teleportTo(Vec3 const &);
	virtual void getMutableAttribute(const Attribute&);
	virtual void getAttribute(const Attribute&) const;
	virtual int getEquipmentCount() const;
	virtual void getArmorValue();
	virtual void getArmorCoverPercentage();
	virtual void hurtArmor(int);
	virtual void setArmor(ArmorSlot, ItemInstance const *);
	virtual ItemInstance* getArmor(ArmorSlot) const;
	virtual void getAllArmor() const;
	virtual void getAllArmor();
	virtual void getArmorTypeHash();
	virtual void dropHeldItem();
	virtual void dropAllArmor();
	virtual void dropAllGear(int);
	virtual void drop(ItemInstance const *, bool);
	virtual void sendInventory() const;
	virtual bool canBeAffected(MobEffectInstance const &);
	virtual void getDamageAfterMagicAbsorb(EntityDamageSource const &, int);
	virtual void _removeWhenFarAway();
	virtual void getDeathLoot();
	virtual void dropDeathLoot(int);
	virtual void dropRareDeathLoot();
	virtual void jumpFromGround();
	virtual void _pickUpItem(ItemEntity &);
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void _serverAiMobStep();
	virtual void _getSoundVolume();
	virtual std::string _getAmbientSound();
	virtual std::string _getHurtSound();
	virtual std::string _getDeathSound();
	virtual void getDamageAfterArmorAbsorb(EntityDamageSource const &, int);
	virtual void getExperienceReward() const;
	virtual bool useNewAi();
	virtual void onEffectAdded(MobEffectInstance&);
	virtual void onEffectUpdated(MobEffectInstance const &);
	virtual void onEffectRemoved(MobEffectInstance&);
	virtual void registerAttributes();
};
