#pragma once
#include <memory>
#include <string>

#include "TextureLocation.h"

class TickingTexture;
class ResourceLoadManager;
class ResourceLocation;
class TexturePair;
class DynamicTexture;
class ResourceLoadType;
class ResourceLocationPair;

namespace mce {
class TexturePtr;
class TextureDescription;
class TextureBase;

class TextureGroup {
public:
	static void* MISSING_TEXTURE_LOCATION;
	static void* mCanLoadTextures;

	TextureGroup(ResourceLoadManager&);
	~TextureGroup();
	void _addRef(mce::TexturePtr&);
	void _getTexture(ResourceLocation const&, bool, bool);
	void _removeRef(mce::TexturePtr&);
	void addEmptyTexture(ResourceLocation const&, int, int);
	void addManualTexture(TexturePair&);
	void addTickingTexture(std::unique_ptr<TickingTexture>);
	void clearLoadedResourcesRecord();
	void createEmptyTexture(ResourceLocation const&, mce::TextureDescription const&);
	void findOrLoadTexture(ResourceLocation const&);
	void getLocationFor(DynamicTexture);
	void getManualTextureData(mce::TexturePtr const&) const;
	void getTexture(DynamicTexture);
	mce::TexturePtr getTexture(ResourceLocation const&, bool);
	void getTexturePair(ResourceLocation const&);
	void getTexturePair(mce::TextureBase const&);
	void getTexturePair(mce::TexturePtr const&);
	void getTickingTexture(int) const;
	void getTickingTextureCount() const;
	void isLoaded(ResourceLocation const&) const;
	void loadList(ResourceLocation const&, bool);
	void loadList(std::vector<ResourceLocation> const&, bool);
	void loadListAsync(ResourceLoadType, std::vector<ResourceLocation> const&, bool);
	void loadListAsync(ResourceLoadType, std::vector<ResourceLocationPair> const&, bool);
	void loadTexture(ResourceLocation const&, bool);
	void loadTexture(ResourceLocation const&, std::string&, bool);
	void loadTextures(std::vector<ResourceLocationPair>);
	void reloadAll();
	void reloadGroup();
	void removeManualTextureData(TexturePair&);
	void removeTickingTextures();
	void tick();
	void unloadAll(bool);
	void unloadTexture(ResourceLocation const&);
	void uploadTexture(ResourceLocation const&, TexturePair&&, bool);
};

};