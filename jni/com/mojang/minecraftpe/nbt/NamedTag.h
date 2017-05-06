#pragma once

#include <string>

#include "Tag.h"

class NamedTag : public Tag {

public:

	// Virtual
	virtual ~NamedTag();
	virtual void setName(std::string const&);
	virtual std::string getName() const;
};
