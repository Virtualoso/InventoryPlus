#include "JsonLoader.h"

#include "com/mojang/minecraftpe/resource/ResourcePackManager.h"
#include "com/mojang/minecraftpe/resource/ResourceLocation.h"
#include "com/mojang/minecraftpe/client/AppPlatform.h"
#include "com/mojang/minecraftpe/util/Util.h"

ResourcePackManager* JsonLoader::manager;

void JsonLoader::setup(ResourcePackManager* rpm)
{
	manager = rpm;
}

void JsonLoader::registerCreativeTabs()
{
	std::vector<std::string> loadedFiles = getLoadedFiles();
	// todo load each of the tabs through json
}

std::vector<std::string> JsonLoader::getLoadedFiles()
{
	std::set<std::string> files = getAllRegistryFiles("inventory_plus");
	std::vector<std::string> loadedFiles;
	for (auto it = files.begin(); it != files.end(); ++it)
	{
		mcpe::string loadedFile;
		std::string fileName = *it;
		Util::stringReplace(fileName, "//", "/", 1);
    	manager->load(ResourceLocation(fileName, ResourceFileSystem::InUserPackage), loadedFile.std());
		loadedFiles.emplace_back(mcpe::string(loadedFile).std());
	}
	return loadedFiles;
}

std::set<std::string> JsonLoader::getAllRegistryFiles(const std::string& path)
{
	return AppPlatform::singleton()->listAssetFilesIn(path, "json");
}