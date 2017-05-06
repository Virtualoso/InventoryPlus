#pragma once

#include "Entity.h"
#include "../item/ItemInstance.h"

class ItemEntity : public Entity {

public:

    /* 0xCAC */ ItemInstance item;
    /* 0xCC0 */ int unknown1;
    /* 0xCC4 */ int unknown2;
    /* 0xCC8 */ int unknown3;
    /* 0xCCC */ float unknown4;
    /* 0xCD0 */ int unknown5;
    /* 0xCD4 */ int unknown6;
    /* 0xCD8 */ bool unknown7;
    /* size = 0xCDC */

    // virtual
    virtual void reloadHardcoded(Entity::InitializationMethod, VariantParameterList const&);
    virtual ~ItemEntity();
    virtual void* getAddPacket();
    virtual void normalTick();
    virtual void playerTouch(Player&);
    virtual bool isPushable() const;
    virtual bool isInvulnerableTo(EntityDamageSource const&) const;
    virtual EntityType getEntityTypeId() const;
    virtual void getSourceUniqueID() const;
    virtual void* getHandleWaterAABB() const;
    virtual void _hurt(EntityDamageSource const&, int, bool, bool);
    virtual void readAdditionalSaveData(CompoundTag const&);
    virtual void addAdditionalSaveData(CompoundTag&);

    // non virtual
    ItemEntity(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
    ItemEntity(BlockSource&);
    ItemEntity(BlockSource&, Vec3 const&, ItemInstance const&, int, float, bool);
    void setSourceEntity(Entity const*);
    void _defineEntityData();
    void _validateItem();
};