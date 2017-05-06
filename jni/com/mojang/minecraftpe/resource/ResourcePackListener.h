#pragma once

class ResourcePackManager;

class ResourcePackListener {

public:
    virtual ~ResourcePackListener() { }
    virtual void onActiveResourcePacksChanged(ResourcePackManager&) = 0;
    virtual void onLanguageSubpacksChanged();

};

