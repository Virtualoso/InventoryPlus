#pragma once

#include "Tag.h"
#include "NamedTag.h"

class TagMemoryChunk;

class CompoundTag : public Tag
{
public:
	char filler_CompoundTag[5000];
public:
	virtual ~CompoundTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&);
	virtual std::string toString() const;
	virtual int getId() const;
	virtual bool equals(Tag const&) const;
	virtual void print(std::string const&, PrintStream&) const;
	virtual void copy() const;
public:
	CompoundTag(CompoundTag&&);
	CompoundTag(std::string const&);
	CompoundTag();
	void putBoolean(std::string const&, bool);
	void putCompound(std::string const&, std::unique_ptr<CompoundTag, std::default_delete<CompoundTag> >);
	void putByteArray(std::string const&, TagMemoryChunk);
	void put(std::string const&, std::unique_ptr<Tag, std::default_delete<Tag> >);
	void putInt(std::string const&, int);
	void remove(std::string const&);
	void putByte(std::string const&, char);
	void putFloat(std::string const&, float);
	void putInt64(std::string const&, long long);
	void putShort(std::string const&, short);
	void putDouble(std::string const&, float);
	void putString(std::string const&, std::string const&);
	void operator=(CompoundTag&&);
	void getAllTags(std::vector<Tag*, std::allocator<Tag*> >&) const;
	bool getBoolean(std::string const&) const;
	void getCompound(std::string const&) const;
	std::vector<int> getIntArray(std::string const&) const;
	std::vector<char> getByteArray(std::string const&) const;
	void get(std::string const&) const;
	CompoundTag clone() const;
	int getInt(std::string const&) const;
	char getByte(std::string const&) const;
	void getList(std::string const&) const;
	bool isEmpty() const;
	void rawView() const;
	bool contains(std::string const&) const;
	bool contains(std::string const&, Tag::Type) const;
	float getFloat(std::string const&) const;
	long long getInt64(std::string const&) const;
	short getShort(std::string const&) const;
	double getDouble(std::string const&) const;
	std::string getString(std::string const&) const;
};
