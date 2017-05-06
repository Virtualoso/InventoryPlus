#pragma once

#include "../level/BlockPos.h"

class PacketSender;
class Level;
class SoundPlayer;
class Vibration;
class Entity;
class Player;
class ItemInstance;
class Vec3;
enum class InputMode;

class GameMode {

public:

    // virtual
    virtual ~GameMode();
    virtual bool startDestroyBlock(Player&, BlockPos, signed char);
    virtual bool destroyBlock(Player&, BlockPos, signed char);
    virtual bool continueDestroyBlock(Player&, BlockPos, signed char);
    virtual void stopDestroyBlock(Player&);
    virtual void startBuildBlock(Player&, BlockPos, signed char);
    virtual bool buildBlock(Player&, BlockPos, signed char);
    virtual bool continueBuildBlock(Player&, BlockPos, signed char);
    virtual void stopBuildBlock(Player&);
    virtual void tick();
    virtual float getPickRange(Player*, InputMode const&, bool);
    virtual bool useItem(Player&, ItemInstance&);
    virtual bool useItemOn(Player&, ItemInstance*, BlockPos const&, signed char, Vec3 const&);
    virtual bool interact(Player&, Entity&);
    virtual void attack(Player&, Entity&);
    virtual void releaseUsingItem(Player&);
    virtual void setTrialMode(bool);
    virtual bool isInTrialMode();
    virtual void registerUpsellScreenCallback(std::function<void (bool)>);

    // non virtual
    GameMode(PacketSender&, Level&, SoundPlayer&, Vibration&);
    bool _canDestroy(Player&, BlockPos, signed char);
    bool _creativeDestroyBlock(Player&, BlockPos, signed char);
    bool _destroyBlockInternal(Player&, BlockPos, signed char);
    void _releaseUsingItemInternal(Player&);
    float getOldDestroyProgress();
    float getDestroyProgress();
    float getHitProgress(float);
    void toggleLongPickRange();

};

