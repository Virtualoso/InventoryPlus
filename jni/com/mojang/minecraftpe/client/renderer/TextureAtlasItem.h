#pragma once

#include <string>
#include <vector>
#include "TextureUVCoordinateSet.h"

struct TextureAtlasItem {

    /* 0x00 */ std::string name;
    /* 0x04 */ int index;
    /* 0x08 */ std::vector<TextureUVCoordinateSet> sets;
    /* size = 0x14 */

};
