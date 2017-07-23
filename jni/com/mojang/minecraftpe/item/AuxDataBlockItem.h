#pragma once

#include "BlockItem.h"

class AuxDataBlockItem : public BlockItem
{
public:
	char filler[10];
public:
	AuxDataBlockItem(std::string const&,int,Block const*);
};
