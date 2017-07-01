#include "ModHandler.h"

#include "Mod.h"


std::vector<Mod*> ModHandler::modList;

void ModHandler::initMod(Mod* mod)
{
	modList.emplace_back(mod);
}

void ModHandler::initModBlocks()
{
	for(Mod* mod : modList)
	{
		mod->initBlocks();
	}
}

void ModHandler::initModItems()
{
	for(Mod* mod : modList)
	{
		mod->initItems();
		mod->initCustomCreativeItems();
	}
}

void ModHandler::initModCreativeItems()
{
	for(Mod* mod : modList)
	{
		mod->initVanillaCreativeItems();
	}
}