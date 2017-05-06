#pragma once

#include "MaterialType.h"

class Color;

class Material {

public:

    class Settings;

    Material(MaterialType, Material::Settings, float);

    Color getColor() const;
    bool getBlocksMotion() const;
    float getTranslucency() const;

    bool isType(MaterialType) const;

    bool isSolidBlocking() const;
    bool isFlammable() const;
    bool isNeverBuildable() const;
    bool isAlwaysDestroyable() const;
    bool isReplaceable() const;
    bool isLiquid() const;
    bool isSolid() const;
    bool isSuperHot() const;

    void _setReplaceable();
    void _setFlammable();
    void _setNotAlwaysDestroyable();
    void _setNeverBuildable();
    void _setNotBlockingMotion();
    void _setNotSolid();
    void _setSuperHot();
    void _setMapColor(Color const&);

    static void initMaterials();
    static void _setupSurfaceMaterials();
    static void teardownMaterials();
    static Material const& getMaterial(MaterialType);
    static void addMaterial(std::unique_ptr<Material, std::default_delete<Material>>);

    // static fields
    static std::vector<std::unique_ptr<Material>> mMaterials;
    static bool mInitialized;

};
