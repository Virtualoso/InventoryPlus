#pragma once

#include <memory>

class BlockSource;
class Random;
class Biome;
class BlockPos;
class Feature;

class BiomeDecorator {

public:

    //TODO: Research field
    char filler[0xFC];
    /* size = 0xFC */

    // virtual
    virtual void decorate(BlockSource*, Random&, Biome*, BlockPos const&, bool, float);
    virtual void decorateOres(BlockSource*, Random&, BlockPos const&);
    virtual ~BiomeDecorator();

    // non virtual
    BiomeDecorator();
    void decorateDepthSpan(BlockSource*, Random&, BlockPos const&, int, std::unique_ptr<Feature>&, int, int);
    void decorateDepthAverage(BlockSource*, Random&, BlockPos const&, int, std::unique_ptr<Feature>&, int, int);
    void _getRandomSurfacePosition(BlockSource*, BlockPos const&, Random&);
    void _placeFeature(BlockSource*, std::unique_ptr<Feature> const&, BlockPos const&, Random&);
    void _getRandomHeight(int, int, BlockSource*, Random&, BlockPos const&);
    void _getRandomTreePosition(BlockSource*, BlockPos const&, Random&);
    void _getRandomSolidPosition(BlockSource*, BlockPos const&, Random&);
};
