#pragma once

#include <string>
#include <memory>

#include "../../entity/EntityType.h"

class Feature;
class Random;
class BlockPos;
class BlockSource;
class BlockVolume;
class LevelStorage;
class BiomeDecorator;

class Biome {

public:

    struct BiomeHeight {
        float depth;
        float scale;
    };
    
    // TODO: Need testing
    enum class BiomeType : int { Beach, Desert, ExtremeHills, Flat, Forest, Hell, Ice, Jungle, Mesa, MushroomIsland, Ocean, Plain, River, Savanna, StoneBeach, Swamp, Taiga, TheEnd };
    
    // TODO: Research fields
    char filler[0x9C];
    /* size = 0x9C */

    // virtual
    virtual void setColor(int);
    virtual void setColor(int, bool);
    virtual ~Biome();
    virtual std::unique_ptr<Feature> getTreeFeature(Random*);
    virtual std::unique_ptr<Feature> getGrassFeature(Random*);
    virtual void getTemperature();
    virtual void adjustScale(float);
    virtual void adjustDepth(float);
    virtual unsigned int getSkyColor(float);
    virtual void* getMobs(EntityType);
    virtual void getCreatureProbability();
    virtual unsigned int getFoliageColor();
    virtual unsigned int getBirchFoliageColor();
    virtual unsigned int getEvergreenFoliageColor();
    virtual void* getMapFoliageColor();
    virtual void* getMapBirchFoliageColor();
    virtual void* getMapEvergreenFoliageColor();
    virtual void getRandomFlowerTypeAndData(Random&, BlockPos const&);
    virtual void decorate(BlockSource*, Random&, BlockPos const&, bool, float);
    virtual void buildSurfaceAt(Random&, BlockVolume&, BlockPos const&, float, short);
    virtual unsigned int getGrassColor(BlockPos const&);
    virtual void* getMapGrassColor(BlockPos const&);
    virtual void refreshBiome(unsigned int);
    virtual void getTemperatureCategory() const;
    virtual bool isSame(Biome*);
    virtual bool isHumid();
    virtual Biome* createMutatedCopy(int);

    // non virtual
    Biome(int, Biome::BiomeType, std::unique_ptr<BiomeDecorator>);
    void LoadInstanceData(LevelStorage &);
    void ResetInstanceData();
    void SaveInstanceData(LevelStorage &);
    void _placeBedrock(Random &,BlockVolume &,BlockPos const&);
    void buildSurfaceAtDefault(Random &,BlockVolume &,BlockPos const&,float,short);
    void clearMobs(bool,bool,bool);
    Biome* createMutatedCopy();
    BiomeType getBiomeType();
    float getDownfall();
    int getDownfallInt();
    void getSnowAccumulationLayers();
    bool isSnowCovered();
    void refreshBiomes(unsigned int);
    void setDepthAndScale(Biome::BiomeHeight const&);
    void setLeafColor(int);
    void setName(std::string const&);
    void setNoRain();
    void setOddColor(int);
    void setSnowAccumulation(float,float);
    void setSnowCovered();
    void setTemperatureAndDownfall(float,float);

    // static
    static void initBiomes();
    static Biome* getBiome(int);
    static Biome* getBiome(int, Biome*);

};