#pragma once

#include "Item.h"

class BlockItem : public Item {

public:

    virtual ~BlockItem();
    virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
    virtual std::string buildDescriptionName(ItemInstance const&) const;
    virtual bool isEmissive(int) const;
    virtual TextureUVCoordinateSet const& getIcon(int, int, bool) const;
    virtual int getIconYOffset() const;

    BlockItem(std::string const&, int);

};

