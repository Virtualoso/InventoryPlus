//need to update this whole header

#pragma once

#include <vector>

#include "GuiElement.h"
#include "IntRectangle.h"
#include "../../math/Vec3.h"
#include "../../math/RectangleArea.h"

class ScrollBar {
public:
	enum class RenderColorType : int {
		
	};
	
	float x; // 0
	float y; // 4
	float w; // 8
	float h; // 12
	float scale; // 16
	float alpha; // 20
	char filler[16]; // 24
	bool idk_b; // 40
	RenderColorType colorType; // 44
	int idk_i; // 48
	RectangleArea rect; // 52
	char filler1[16]; // 68
	
	ScrollBar();
	void render(MinecraftGame*, bool);
	void update(IntRectangle const&, float, int);
	void updateScale(float);
	void createMouseScrollBars();
	void setMarginsPixelOffsets(float, float, float);
	void setRenderColorType(ScrollBar::RenderColorType);
};

class ScrollingPane : public GuiElement {
public:
	struct GridItem {
		int id;
		int x;
		int y;
		float xf;
		float yf;
		bool selected;
	};
	
	int flags; // 48
	int columns; // 52
	int rows; // 56
	int numItems; // 60
	int px; // 64
	int py; // 68
	float fpx; // 72
	float fpy; // 76
	float screenScale; // 80
	float invScreenScale; // 84
	IntRectangle bbox; // 88
	IntRectangle itemRect; // 104
	IntRectangle itemBBox; // 120
	RectangleArea area; // 136
	RectangleArea bboxArea; // 152
	char filler[476 - 168]; // 168
	ScrollBar bar1; // 476
	ScrollBar bar2; // 560
	char filler1[720 - 644]; //644

	virtual ~ScrollingPane();
	virtual void tick();
	virtual void renderBatch(std::vector<ScrollingPane::GridItem>&, float, float, float);
	virtual void renderItem(ScrollingPane::GridItem&, float);
	virtual void didEndDragging();
	virtual void didEndDecelerating();
	virtual void willBeginDecelerating();
	virtual void willBeginDragging();
	virtual void onSelect(int, bool);
	virtual void refreshItems();

	ScrollingPane(int, IntRectangle const&, IntRectangle const&, int, int, float, IntRectangle const&);
	void UpdateHighlightItem(float, float);
	int _getAdditionalScrollBarWidth();
	void _handleMouseInput(float, bool);
	void _onSelect(int);
	void addDeltaPos(float, float, float, int);
	void addFlag(int);
	void adjustContentSize();
	void beginTracking(float, float, int);
	void calculateAndSetCurrentMouseScrollT();
	int contentOffset();
	int getAdditionalScrollBarWidth() const;
	int getAdditionalScrollBarWidth(MinecraftGame*);
	int getColumns();
	int getContentOffset();
	GridItem* getGridItemFor_slow(int, ScrollingPane::GridItem&);
	GridItem* getItemForPos(float, float, bool);
	int getNumItems();
	int getRows();
	int getScrollT() const;
	ScrollBar& getSelectedItemId();
	void getVerticleScrollBar();
	void handleMouseInput(float);
	void handleUserInput(bool);
	void hideScrollIndicators();
	void onHoldItem();
	void onNavigate(int);
	void queryHoldTime(int*, int*);
	void recalculateRows(int);
	void refreshPane();
	void renderPane(int, int, float, MinecraftGame*);
	void resetHoldTime();
	void scrollDownBy(float);
	void scrollUpBy(float);
	void setContentOffset(Vec3);
	void setContentOffset(float, float);
	void setContentOffsetWithAnimation(Vec3, bool);
	void setNumItems(int);
	void setRenderSelected(bool);
	void setScrollT(float);
	void setSelected(int, bool);
	bool shouldRenderSelected();
	bool shouldUseMouseScrollbarLayout(MinecraftGame*);
	void snapContentOffsetToBounds(bool);
	void startDecelerationAnimation(bool);
	void stepThroughDecelerationAnimation(bool);
	void stopDecelerationAnimation();
	bool thereAreMoreItemsToDisplay() const;
	bool thereAreMoreItemsToDisplay(int, int, int);
	void touchesBegan(float, float, int);
	void touchesCancelled(float, float, int);
	void touchesEnded(float, float, int);
	void touchesMoved(float, float, int);
	void translate(float, float);
	void updateHorizontalScrollIndicator();
	void updateScrollBarScale(int, int, int, int);
	void updateScrollBoxSize(float);
	void updateScrollFade(ScrollBar&);
	void updateVerticalScrollIndicator();
};