#pragma once

#include "Tag.h"

class ListTag : public Tag {
public:
	ListTag(const std::string&);
	ListTag();
	virtual ~ListTag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&);
	virtual std::string toString() const;
	virtual Tag::Type getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* copy() const;
};
