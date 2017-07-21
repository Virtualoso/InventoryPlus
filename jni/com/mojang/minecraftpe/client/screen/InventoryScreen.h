#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Screen.h"
#include "../gui/InventoryPane.h"
#include "../CraftingType.h"
#include "../../level/BlockPos.h"
#include "../../item/ItemInstance.h"

class Tessellator;
class ItemPack;
class Recipe;
class ArmorSlot;
class ImageButton;
class CategoryButton;
class NinePatchLayer;
class Label;
class BlankButton;
class ImageWithBackground;
class Button;
class ClientInstance;
class MinecraftGame;
class StickDirection;

class InventoryScreen : public Screen {

public:

	//classes and fields are from old header and probably need to be updated

	struct TabButtonWithMeta;
	struct IngredientSlotStatus;

	enum class InventoryPaneType : unsigned int { 
		INVENTORY,
		CRAFTING,
		ARMOR,
		BLOCKS,
		DECORATIONS,
		TOOLS,
		ITEMS
	};
	
	// Field
	// No need to update these for now, they aren't of use to us
	/*char is_vars[56]; // 140
	void* somethingOfImportance; // 196 
	char is_vars0[60]; // 200
	std::shared_ptr<ImageWithBackground> closeButton; // 260;
	std::shared_ptr<NinePatchLayer> layer_0; // 268
	std::shared_ptr<NinePatchLayer> layer_1; // 276
	std::shared_ptr<NinePatchLayer> layer_2; // 284
	std::shared_ptr<NinePatchLayer> layer_3; // 292
	std::shared_ptr<NinePatchLayer> layer_4; // 300
	std::shared_ptr<NinePatchLayer> layer_5; // 308
	std::shared_ptr<NinePatchLayer> layer_6; // 316
	std::shared_ptr<NinePatchLayer> layer_7; // 324
	std::shared_ptr<Touch::InventoryPane> inventory; // 332
	std::shared_ptr<Touch::InventoryPane> armor; // 340
	std::shared_ptr<Touch::InventoryPane> crafting; // 348
	std::shared_ptr<Touch::InventoryPane> creativePanes[4]; // 356
	std::shared_ptr<BlankButton> blankButton; // 388
	std::shared_ptr<BlankButton> blankButton2; // 396
	std::shared_ptr<BlankButton> blankButton3; // 404
	std::shared_ptr<BlankButton> blankButton4; // 412
	std::shared_ptr<Touch::TButton> someButton; // 420
	char is_vars1[512 - 428]; // 428
	std::vector<InventoryScreen::TabButtonWithMeta*> buttonTabs; // 512
	char is_vars2[100]; // 516
	InventoryScreen::InventoryPaneType selectedPaneType; // 616
	char is_vars3[656 - 620]; // 620*/

	char is_vars[684 - 140]; // 140

	//now these do matter
	ItemInstance item; // 688
	bool hasDumpedArmor; // 732
	char is_vars4[784 - 736]; // 736
	std::shared_ptr<Label> recipesName; // 784
	std::shared_ptr<Label> noRecipesName; // 792
	CraftingType craftingType; // 800
	char is_vars5[920 - 804]; // 804
	std::string cannotCreateString; // 920
	bool idk_b; // 924
	char is_vars6[8]; // 928
	BlockPos blockPos; // 936

	// Virtual
	virtual ~InventoryScreen();
	virtual void onInternetUpdate();
	virtual void tick();
	virtual void handleBackEvent(bool);
	virtual bool renderGameBehind() const;
	virtual bool closeOnPlayerHurt() const;
	virtual bool isModal() const;
	virtual std::string getScreenName() const;
	virtual std::string getScreenNameW() const;
	virtual void getSendEvents();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void handleButtonPress(short);
	virtual void handleButtonRelease(short);
	virtual void handleScrollWheel(float);
	virtual void _updateTabButtonSelection();
	virtual void _buttonClicked(Button&);
	virtual void _pointerReleased(int, int);
	virtual void _controllerDirectionChanged(int, StickDirection);
	virtual void _controllerDirectionHeld(int, StickDirection);
	virtual void addItem(Touch::InventoryPane&, int);
	virtual bool isAllowed(int);
	virtual std::vector<const ItemInstance*> getItems(Touch::InventoryPane const&);
	
	// Non Virtual
	InventoryScreen(MinecraftGame&, ClientInstance&, CraftingType, BlockPos const&);
	
	void _addItemArmorScreen(int);
	void _addItemCraftingScreen(int);
	void _addItemCreativeScreen(ItemInstance&, bool, bool);
	void _addItemCreativeScreen(int, int, bool, bool);
	void _addItemForInventoryPane(int&);
	void _closeWindow();
	void _drawSlotItemAt(Tessellator&, int, ItemInstance const&, int, int, bool);
	void _entityCheck();
	void _filterRecipeList(std::vector<std::unique_ptr<Recipe>> const&);
	int _getNumberOfIngredients(ItemInstance&, ItemPack&);
	ItemPack& _getPlayerInventoryItemPack();
	void _handleAddItem(Touch::InventoryPane&, int, bool);
	void _handleArmorInventoryNavigation(StickDirection);
	void _handleArmorJoyStickNavigation(StickDirection);
	void _handleArmorSlotNavigation(StickDirection);
	void _onBulkSelectCreativePane();
	void _putItemInToolbar(ItemInstance const&);
	void _refreshCraftingGrid(Recipe*);
	void _refreshCraftingItemList(std::vector<Recipe*> const&);
	void _renderArmorScreen(Tessellator&, int, int, float);
	void _renderCraftingScreen(Tessellator&, int, int, float);
	void _renderGridItem(ItemInstance const&, InventoryScreen::IngredientSlotStatus, int, int);
	void _renderPlayer(float, float, float);
	void _selectInDirection(StickDirection);
	void _setCurrentRecipe(Recipe*);
	void _takeAndClearArmorSlot(ArmorSlot);
	void _takeAndClearOffhandSlot();
	void _updateArmorItems();
	void _updateCraftableItems(bool);
	void _updateCraftingButtonVisiblity();
	void _updateIngredientCountFromRecipe(Recipe*, bool, ItemPack&);
	void clearPopulatedItems();
	std::shared_ptr<CategoryButton> createInventoryTabButton(int, bool);
	void drawIcon(InventoryScreen::InventoryPaneType, std::shared_ptr<ImageButton>, bool, bool);
	ItemInstance getItemFromType(InventoryScreen::InventoryPaneType);

	// Static
	static void* mFilteredItems;
	static void* NUM_ARMORBUTTONS;
	static std::vector<ItemGroup> mItems[5];
	static void _populateFilteredItems();
	static void _populateItem(ItemInstance const&);
	static void _populateItems();

};
