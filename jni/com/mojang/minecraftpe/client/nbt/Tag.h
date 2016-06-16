#pragma once

#include <string>

class PrintStream;
class IDataInput;
class IDataOutput;

class Tag {
public:
	enum class Type : unsigned int {
		END = 0,
		BYTE,
		SHORT,
		INT,
		LONG,
		FLOAT,
		DOUBLE,
		BYTE_ARRAY,
		STRING,
		LIST,
		COMPOUND,
		INT_ARRAY,
		UNKNOWN
	};
	
	int errorState;
	std::string name;

	Tag(const std::string&);
	virtual ~Tag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const = 0;
	virtual void load(IDataInput&) = 0;
	virtual std::string toString() const = 0;
	virtual Tag::Type getId() const = 0;
	virtual bool equals(const Tag&) const;
	virtual void print(PrintStream&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual void setName(const std::string&);
	virtual std::string getName() const;
	virtual Tag* copy() const = 0;
	
	void readNamedTag(IDataInput&, const std::string&);
	void writeNamedTag(const std::string&, const Tag&, IDataOutput&);
	
	static std::string getTagName(Tag::Type);
	static Tag* newTag(Tag::Type, const std::string&);
};