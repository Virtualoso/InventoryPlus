#pragma once

#include "../AppPlatformListener.h"
#include "../renderer/entity/EntityShaderManager.h"
#include "ScrollingPane.h"
class ItemRenderChunkType;
class ItemInstance;
class Tessellator;
class Block;
class ItemGroup;

namespace Touch {
	
class IInventoryPaneCallback;

class InventoryPane : public ScrollingPane, public EntityShaderManager, public AppPlatformListener {
public:
	char ip_vars[1356 - 768]; // 768
	
	// virtual methods
	virtual ~InventoryPane();
	virtual void tick();
	virtual void handleButtonPress(MinecraftGame*, short);
	virtual void renderBatch(std::vector<ScrollingPane::GridItem>&, float, float, float);
	virtual void onSelect(int, bool);
	virtual void refreshItems();
	virtual void onAppSuspended();
	virtual void onAppResumed();

	InventoryPane(Touch::IInventoryPaneCallback*, MinecraftGame&, IntRectangle const&, int, float, int, int, int, bool, bool, bool);
	void SetAdditionalMargin(int, int);
	void _usesTerrainAtlas(Block const*);
	void buildInventoryItemsChunk(std::vector<ItemGroup> const&, ItemRenderChunkType);
	void drawRectangleOnSelectedItem(ScrollingPane::GridItem&, bool);
	void onSelectItem();
	void renderSelectedItem(std::vector<ScrollingPane::GridItem>&, std::vector<ItemGroup>, Tessellator&, ScrollingPane::GridItem*&, float&, float&);
	void setControllerDirection(StickDirection);
	void setRenderDecorations(bool);
};

class IInventoryPaneCallback {
public:
	virtual ~IInventoryPaneCallback() { };
	virtual bool addItem(Touch::InventoryPane&, int) = 0;
	virtual bool isAllowed(int) = 0;
	virtual std::vector<ItemGroup> getItems(const Touch::InventoryPane&) = 0;
};

};