#pragma once

#include "../AppPlatformListener.h"
#include "../renderer/entity/EntityShaderManager.h"
#include "ScrollingPane.h"
class ItemRenderChunkType;
class ItemInstance;
class Tessellator;

namespace Touch {
	
class IInventoryPaneCallback;

class InventoryPane : public ScrollingPane, public EntityShaderManager, public AppPlatformListener {
public:
	char ip_vars[1268 - 768]; // 768
	// virtual methods
	InventoryPane(Touch::IInventoryPaneCallback*, MinecraftClient&, IntRectangle const&, int, float, int, int, int, bool, bool, bool);
	virtual ~InventoryPane();
	virtual void handleButtonPress(MinecraftClient*, short);
	virtual void renderBatch(std::vector<ScrollingPane::GridItem>&, float, float, float);
	virtual void onSelect(int, bool);
	virtual void refreshItems();
	virtual void onAppSuspended();
	virtual void onAppResumed();

	void drawRectangleOnSelectedItem(ScrollingPane::GridItem&);
	void onSelectItem();
	void setRenderDecorations(bool);
	void tick();
	void renderSelectedItem(std::vector<ScrollingPane::GridItem>&, std::vector<const ItemInstance*>, Tessellator&, ScrollingPane::GridItem*&, float&, float&);
	void setControllerDirection(StickDirection);
	void SetAdditionalMargin(int, int);
	void buildInventoryItemsChunk(std::vector<const ItemInstance*>&, ItemRenderChunkType);
};

class IInventoryPaneCallback {
public:
	virtual ~IInventoryPaneCallback();
	virtual bool addItem(Touch::InventoryPane&, int) = 0;
	virtual bool isAllowed(int) = 0;
	virtual std::vector<const ItemInstance*> getItems(const Touch::InventoryPane&) = 0;
};

};
