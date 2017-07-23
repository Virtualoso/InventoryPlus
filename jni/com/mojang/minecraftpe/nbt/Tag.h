#pragma once

#include <string>

#include "NamedTag.h"

class PrintStream;
class IDataOutput;
class IDataInput;
class CompoundTag;

class Tag : public NamedTag
{
public:
	//char filler_Tag[UNKNOW_SIZE];
public:
	enum class Type : int
	{
		
	};
public:
	virtual ~Tag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const=0;
	virtual void load(IDataInput&)=0;
	virtual std::string toString() const=0;
	virtual int getId() const=0;
	virtual bool equals(Tag const&) const=0;
	virtual void print(PrintStream&) const;
	virtual void print(std::string const&, PrintStream&) const;
	virtual void setName(std::string const&);
	virtual std::string getName() const;
	virtual void copy() const =0;
public:
	Tag(std::string const&);
	void readNamedTag(IDataInput&, std::string&);
	void writeNamedTag(std::string const&, Tag const&, IDataOutput&);
	void getTagName(Tag::Type);
	void newTag(Tag::Type, std::string const&);
public:
	static std::string const NullString;
};
