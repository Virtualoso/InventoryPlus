#pragma once

#include <memory>

class IntArrayTag;

class BoundingBox {

public:  
    
    int minX;
    int minY;
    int minZ;
    int maxX;
    int maxY;
    int maxZ;

    void orientBox(int, int, int, int, int, int, int, int, int, int);
    std::unique_ptr<IntArrayTag> createTag() const;
};