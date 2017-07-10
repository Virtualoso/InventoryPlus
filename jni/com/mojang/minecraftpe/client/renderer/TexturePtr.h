#pragma once

#include <string>
#include "../../resource/ResourceLocation.h"

namespace mce {

struct Texture;
struct TextureGroup;

class TexturePtr {

public:

    TextureGroup* group;
    Texture* texture;
    char filler[sizeof(ResourceLocation)];

    TexturePtr();
    TexturePtr(mce::TexturePtr&&);
    TexturePtr(mce::TextureGroup&, ResourceLocation const&, bool);

    ~TexturePtr();

    operator bool() const;
    mce::TexturePtr& operator=(mce::TexturePtr&&);
    mce::Texture* operator->();
    mce::Texture const* operator->() const;
    mce::Texture& operator*();
    mce::Texture const& operator*() const;

    mce::Texture* get() const;
    mce::TextureGroup* getGroup() const;
    int hashCode() const;

    TexturePtr clone() const;
    void _move(mce::TexturePtr&&);
    void _deref();

    void onGroupReloaded();
    void onGroupDestroyed();

    static TexturePtr makeTemporaryWrapper(mce::Texture&);

    static TexturePtr NONE;

};

};
