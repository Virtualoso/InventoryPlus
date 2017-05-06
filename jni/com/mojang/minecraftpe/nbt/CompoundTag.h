#pragma once

#include <string>

#include "NamedTag.h"

class IDataInput;
class IDataOutput;
class PrintStream;
class TagMemoryChunk;
class ListTag;

class CompoundTag : public NamedTag {

public:

	//Field
	char filler[0x20]; //48 (32 bytes)

	// Virtual
	virtual ~CompoundTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&);
	virtual std::string toString() const;
	virtual int getId() const;
	virtual bool equals(Tag const&) const;
	virtual void print(std::string const&, PrintStream&) const;
	virtual void copy() const;
	
	// Non Virtual
	CompoundTag();
	CompoundTag(CompoundTag&&);
	CompoundTag(std::string const&);
	
	void clone() const;
	bool contains(std::string const&) const;
	bool contains(std::string const&, Tag::Type) const;
	void get(std::string const&) const;
	Tag* getAllTags(std::vector<Tag*>&) const;
	bool getBoolean(std::string const&) const;
	char getByte(std::string const&) const;
	char[] getByteArray(std::string const&) const;
	CompoundTag* getCompound(std::string const&) const;
	double getDouble(std::string const&) const;
	float getFloat(std::string const&) const;
	int getInt(std::string const&) const;
	long long int getInt64(std::string const&) const;
	int[] getIntArray(std::string const&) const;
	ListTag* getList(std::string const&) const; //this may be something with the list header (not mcpe)
	short getShort(std::string const&) const;
	std::string getString(std::string const&) const;
	bool isEmpty() const;
	void operator=(CompoundTag&&);
	void put(std::string const&, std::unique_ptr<Tag>);
	void putBoolean(std::string const&, bool);
	void putByte(std::string const&, char);
	void putByteArray(std::string const&, TagMemoryChunk);
	void putCompound(std::string const&, std::unique_ptr<CompoundTag>);
	void putDouble(std::string const&, float);
	void putFloat(std::string const&, float);
	void putInt(std::string const&, int);
	void putInt64(std::string const&, long long);
	void putShort(std::string const&, short);
	void putString(std::string const&, std::string const&);
	void rawView() const;
	void remove(std::string const&);
	void safeRemove(std::string const&);
};