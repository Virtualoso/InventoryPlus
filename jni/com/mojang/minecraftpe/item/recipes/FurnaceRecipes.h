#pragma once

#include <memory>

#include "../ItemInstance.h"

class FurnaceRecipes {

public:

    // TODO: Research Fields
    /* size = 0x30*/

    // non virtual
    FurnaceRecipes();
    bool isFurnaceItem(ItemInstance const*) const;
    ItemInstance getResult(ItemInstance const*) const;
    void addFurnaceRecipe(int, ItemInstance const&);
    void addFurnaceRecipeAuxData(short, short, ItemInstance const&);
    void _init();

    // static
    static void init();
    static void teardownFurnaceRecipes();
    static FurnaceRecipes* getInstance();

    // static fields
    static std::unique_ptr<FurnaceRecipes> mInstance;

};