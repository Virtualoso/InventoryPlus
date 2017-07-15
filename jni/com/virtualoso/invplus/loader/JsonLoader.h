#pragma once

#include <set>
#include <vector>

#include "com/mojang/minecraftpe/util/String.h"

class ResourcePackManager;

class JsonLoader
{
public:
	static ResourcePackManager* manager;

	static void setup(ResourcePackManager*);
	static void registerCreativeTabs();
	static std::vector<std::string> getLoadedFiles();
	static std::set<std::string> getAllRegistryFiles(const std::string&);
};