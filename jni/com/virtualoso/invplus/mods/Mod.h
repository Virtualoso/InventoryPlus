#pragma once

class Mod
{
public:
	Mod();
	virtual void initBlocks();
	virtual void initItems();
	virtual void initVanillaCreativeItems();
	virtual void initCustomCreativeItems();
};