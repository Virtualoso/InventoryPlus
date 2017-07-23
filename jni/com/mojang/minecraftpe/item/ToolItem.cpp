#include "ToolItem.h"

#include <algorithm>

#include "enchant/EnchantUtils.h"
#include "../locale/I18n.h"
#include "../block/Block.h"
#include "ItemInstance.h"

ToolItem::ToolItem(const std::string& name, short id, float damage, Item::Tier tier, std::vector<Block*> blocks)
    : Item(name, id) {
    
    toolMaterial = &tier;
    validBlocks = blocks;
    maxStackSize = 1;
    setMaxDamage(tier.maxUses);
    efficiencyOnProperMaterial = tier.efficiencyOnProperMaterial;
    damageVsEntity = damage + tier.damageVsEntity;
}

int ToolItem::getAttackDamage() {
    return damageVsEntity;
}

bool ToolItem::isHandEquipped() const {
    return true;
}

void ToolItem::appendFormattedHovertext(const ItemInstance& item, Level& level, std::string& name, bool b) const {
    Item::appendFormattedHovertext(item, level, name, b);
	name += "§9\n\n+5 " + I18n::get("attribute.name.generic.attackDamage"); // todo
}

bool ToolItem::isValidRepairItem(const ItemInstance& item, const ItemInstance& repairItem) {
    return toolMaterial->getTierItem().item == repairItem.item ? true : Item::isValidRepairItem(item, repairItem);
}

short ToolItem::getEnchantValue() const {
    return toolMaterial->enchantability;
}

float ToolItem::getDestroySpeed(ItemInstance* item, const Block* block) {
    if(block && std::find(validBlocks.begin(), validBlocks.end(), block) != validBlocks.end())
        return efficiencyOnProperMaterial + destroySpeedBonus(*item);
    return 1.0F;
}

bool ToolItem::mineBlock(ItemInstance* item, BlockID blockId, int x, int y, int z, Entity* miner) {
    if(Block::mBlocks[blockId.id] && Block::mBlocks[blockId.id]->canHurtAndBreakItem())
        item->hurtAndBreak(1, miner);
    return true;
}