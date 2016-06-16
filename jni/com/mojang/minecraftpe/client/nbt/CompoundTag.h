#pragma once

#include <memory>
#include <vector>

#include "NamedTag.h"

class ListTag;
class TagMemoryChunk;

class CompoundTag : public NamedTag {
public:
	CompoundTag(CompoundTag&&);
	CompoundTag(const std::string&);
	CompoundTag();
	virtual ~CompoundTag();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&);
	virtual std::string toString() const;
	virtual Tag::Type getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* copy() const;
	
	void put(const std::string&, std::unique_ptr<Tag>);
	void putByte(const std::string&, char);
	void putShort(const std::string&, short);
	void putInt(const std::string&, int);
	void putInt64(const std::string&, long long int);
	void putFloat(const std::string&, float);
	void putDouble(const std::string&, float); //Blame Mojang
	void putString(const std::string&, const std::string&);
	void putByteArray(const std::string&, TagMemoryChunk);
	void putCompound(const std::string&, std::unique_ptr<CompoundTag>);
	void putBoolean(const std::string&, bool);

	std::unique_ptr<Tag> get(const std::string&) const;

	bool contains(const std::string&) const;
	bool contains(const std::string&, Tag::Type) const;

	char getByte(const std::string&) const;
	short getShort(const std::string&) const;
	int getInt(const std::string&) const;
	long long int getInt64(const std::string&) const;
	float getFloat(const std::string&) const;
	double getDouble(const std::string&) const;
	std::string getString(const std::string&) const;
	TagMemoryChunk getByteArray(const std::string&) const;
	TagMemoryChunk getIntArray(const std::string&) const;
	CompoundTag* getCompound(const std::string&) const;
	ListTag* getList(const std::string&) const;
	bool getBoolean(const std::string&) const;
	
	void getAllTags(std::vector<Tag*>&) const;
	void remove(const std::string&);
	bool isEmpty() const;
};