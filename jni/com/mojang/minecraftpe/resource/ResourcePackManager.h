#pragma once

#include <string>
#include <memory>
#include <unordered_set>
#include "ResourcePackStack.h"
#include "ResourcePackListener.h"
class ResourceLocation;
class ResourcePack;

enum class PackType;
enum class ResourcePackStackType;

class ResourcePackManager {

public:

    /* 0x04 */ std::string imagesPrefix;
    /* 0x08 */ std::unordered_set<ResourcePackListener*> listener;
    /* 0x24 */ std::unique_ptr<ResourcePackStack> stackInternal; // includes the skins resource pack
    /* 0x28 */ std::unique_ptr<ResourcePackStack> stack2;
    /* 0x2C */ std::unique_ptr<ResourcePackStack> stack3;
    /* 0x30 */ std::unique_ptr<ResourcePackStack> stack4;
    /* 0x34 */ std::unique_ptr<ResourcePackStack> stackMinecraft;
    /* 0x38 */ std::unique_ptr<ResourcePackStack> fullStack;
    /* 0x3C */ std::string unknown;
    /* 0x40 */ bool unknown2, hasPendingStackChanges;
    /* size = 0x44 */

    // virtual
    virtual ~ResourcePackManager();
    virtual bool load(ResourceLocation const&, std::string&);
    virtual void* loadAllVersionsOf(ResourceLocation const&);
    virtual void* loadTexture(ResourceLocation const&);

    // non virtual
    ResourcePackManager(std::string const&);
    void* _getResource(std::string const&, std::string&) const;
    void* loadText(ResourceLocation const&, std::string&);
    void* findAllTexturesInUse() const;
    void setStack(std::unique_ptr<ResourcePackStack, std::default_delete<ResourcePackStack>>, ResourcePackStackType, bool);
    void* _handleComposeStack(bool);
    void* clearStack(ResourcePackStackType, bool);
    void* getStack(ResourcePackStackType) const;
    bool _shouldRebuildStack() const;
    void _composeFullStack();
    void* _updateLanguageSubpacks();
    void* notifyActiveResourcePackChanged();
    void* registerResourcePackListener(ResourcePackListener&);
    void* unRegisterResourcePackListener(ResourcePackListener&);
    void* notifyLanguageSubpacksChanged();
    void* getResourcesOfGroup(ResourcePack*, std::string const&) const;
    void* _getPackForResource(std::string const&) const;
    void* checkHasExtraLocaleResources(std::string const&) const;
    void onLanguageChanged();
    void handlePendingStackChanges();
    void* copyPacksToNewLevel(std::string, PackType);

};

