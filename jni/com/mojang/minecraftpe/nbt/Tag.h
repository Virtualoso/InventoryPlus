#pragma once

#include <string>

class IDataInput;
class IDataOutput;
class PrintStream;

class Tag {

public:

	enum class Type;

	// Virtual
	virtual ~Tag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const = 0;
	virtual void load(IDataInput&) = 0;
	virtual std::string toString() const = 0;
	virtual int getId() const = 0;
	virtual bool equals(Tag const&) const;
	virtual void print(PrintStream&) const;
	virtual void print(std::string const&, PrintStream&) const;
	virtual void setName(std::string const&);
	virtual std::string const& getName() const;
	virtual void copy() const = 0;
	
	// Non Virtual
	Tag(std::string const&);
	
	std::string getTagName(Tag::Type);
	void newTag(Tag::Type, std::string const&);
	void readNamedTag(IDataInput&, std::string&);
	void writeNamedTag(std::string const&, Tag const&, IDataOutput&);
	
	//static
	static void* NullString;
};
