#pragma once

#include "../../resource/ResourceLocation.h"

class TextureUVCoordinateSet {

public:

    float u1, v1, u2, v2;
    unsigned short w, h;
    ResourceLocation location;   

    TextureUVCoordinateSet();
    TextureUVCoordinateSet(float, float, float, float, unsigned short, unsigned short, ResourceLocation);

    TextureUVCoordinateSet getFlippedHorizontal() const;
    TextureUVCoordinateSet getFlippedVertically() const;
    float offsetWidth(float, float) const;
    float offsetHeight(float, float) const;
    float offsetWidthPixel(float, float) const;
    float offsetHeightPixel(float, float) const;
    float inverseOffsetWidth(float, float) const;
    float inverseOffsetHeight(float, float) const;
    TextureUVCoordinateSet offset(float) const;
    TextureUVCoordinateSet subTexture(float, float, int, int) const;

    static TextureUVCoordinateSet fromOldSystem(int);

};

