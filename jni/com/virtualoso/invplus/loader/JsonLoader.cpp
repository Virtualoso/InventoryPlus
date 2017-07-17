#include "JsonLoader.h"

#include "../creative/CreativeTab.h"

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
	std::vector<mcpe::string> loadedFiles = getLoadedFiles();
	for(mcpe::string file : loadedFiles)
	{
		Json::Value root;
		Json::Reader parser;
		if(parser.parse(file.std(), root))
		{
			handleFile(root);
		}
	}
}

std::vector<mcpe::string> JsonLoader::getLoadedFiles()
{
	std::set<std::string> files = AppPlatform::singleton()->listAssetFilesIn("inventory_plus", "json");
	std::vector<mcpe::string> loadedFiles;
	for (auto it = files.begin(); it != files.end(); ++it)
	{
		mcpe::string loadedFile;
		std::string fileName = *it;
		Util::stringReplace(fileName, "//", "/", 1);
    	manager->load(ResourceLocation(fileName, ResourceFileSystem::InUserPackage), loadedFile.std());
		loadedFiles.emplace_back(mcpe::string(loadedFile));
	}
	return loadedFiles;
}

void JsonLoader::handleFile(Json::Value& root)
{
	Json::Value tabs = root["tabs"];
	if(!tabs.isNull())
	{
		Json::ValueIterator start = tabs.begin();
		Json::ValueIterator end = tabs.end();
		while(start != end)
		{
			registerTab(*start);
			start++;
		}
	}
}

void JsonLoader::registerTab(Json::Value& root)
{
	CreativeTab* tab = new CreativeTab();
	Json::Value tabIcon = root["tab_icon"];
	if(!tabIcon.isNull())
	{
		int id = tabIcon["id"].asInt();
		int data = tabIcon["data"].asInt();
		tab->setTabIcon(id, data);
	}
	Json::Value items = root["items"];
	if(!items.isNull())
	{
		Json::ValueIterator start = items.begin();
		Json::ValueIterator end = items.end();
		while(start != end)
		{
			Json::Value item = *start;
			int id = item["id"].asInt();
			int data = tabIcon["data"].asInt();
			tab->addItem(id, data);
			start++;
		}
	}
	tab->addToTabsList();
}