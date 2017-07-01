#include "InventoryTab.h"

#include "NinePatchLayer.h"
#include "../renderer/Tessellator.h"

InventoryTab::InventoryTab(int id, const std::string& msg, NinePatchLayer* layer, bool right)
	: ImageButton(id, msg) {
	
	isRight = right;
	layer1 = layer;
}

bool InventoryTab::isSecondImage(bool b1) {
	return false;
}

void InventoryTab::renderBg(MinecraftGame* client, int x, int y) {
	layer1->setSize((float) width, (float) height);
	layer1->draw(Tessellator::instance, xPosition, yPosition);
}