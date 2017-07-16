#pragma once

#include <set>
#include <vector>

#include "com/mojang/minecraftpe/util/String.h"
#include "com/mojang/minecraftpe/json/json/json.h"

class ResourcePackManager;
class GuiData;

class JsonLoader
{
public:
	static ResourcePackManager* manager;

	static void setup(ResourcePackManager*);
	static void registerCreativeTabs(GuiData*);
	static std::vector<mcpe::string> getLoadedFiles(GuiData*);
	static void registerTab(Json::Value&);
};