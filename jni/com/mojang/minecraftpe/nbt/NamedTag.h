#pragma once

#include <string>

class IDataOutput;
class IDataInput;

class NamedTag
{
public:
	//char filler_NamedTag[UNKNOW_SIZE];
public:
	virtual ~NamedTag();
	virtual void write(IDataOutput&) const=0;
	virtual void load(IDataInput&)=0;
	virtual std::string toString() const=0;
	virtual int getId() const=0;
	virtual void setName(std::string const&);
	virtual std::string getName() const;
	virtual void copy() const=0;
};
