#pragma once

#include <functional>
#include "ResourceLocation.h"
class PackManifest;
class PackAccessStrategy;
class PackManifest;
enum class ResourcePackLocation;

class ResourcePack {

public:

    char filler[0x1C];

    enum class PackType;

    ResourcePack(std::unique_ptr<PackAccessStrategy, std::default_delete<PackAccessStrategy>>, ResourcePack::PackType, ResourcePackLocation, bool);
    std::string const& getPackId() const;
    std::string const& getVersion() const;
    PackManifest* getManifest() const;
    ResourceLocation const& getResourceLocation() const;
    ResourceFileSystem getFileSystem() const;
    void* getFolderName() const;
    void* getZipFolder() const;
    bool isZipped() const;

    void* _generateIconPath();
    void* getIconPath() const;
    void* getDefaultItemIconPath();
    void* getDefaultItemFileSystem();
    void* getDefaultBugItemIconPath();
    void* getDefaultBugItemFileSystem();

    bool hasResource(std::string const&) const;
    bool hasExtraResourcesForLocale(std::string const&) const;

    bool getFile(std::string const&, std::string&) const;
    bool getResource(std::string const&, std::string&) const;

    void forEachIn(std::string const&, std::function<void (std::string const&)>) const;

    void setLocale(std::string const&);
    void setError();

    // static fields
    static std::string RESOURCE_PACK_ICON_PATH;

};

