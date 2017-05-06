#pragma once

#include <string>
#include "../../resource/ResourceLocation.h"

namespace mce {

struct RenderMaterial;
struct RenderMaterialGroup;

class MaterialPtr {

public:

    RenderMaterialGroup* group;
    RenderMaterial* material;
    std::string name;

    MaterialPtr();
    MaterialPtr(mce::MaterialPtr&&);
    MaterialPtr(mce::RenderMaterialGroup&, std::string const&);

    ~MaterialPtr();

    operator bool() const;
    mce::MaterialPtr& operator=(mce::MaterialPtr&&);

    std::wstring getNameW() const;

    void _move(mce::MaterialPtr&&);
    void _deref();

    void onGroupReloaded();

    static MaterialPtr NONE;

};

};
