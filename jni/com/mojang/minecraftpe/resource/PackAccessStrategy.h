#pragma once

#include <memory>
#include <string>

class ResourceLocation;

class PackAccessStrategy {

public:
    virtual ~PackAccessStrategy() { }
    virtual unsigned int getPackSize() const = 0;
    virtual ResourceLocation const& getPackLocation() const = 0;
    virtual std::string const& getPackName() const = 0;
    virtual bool hasAsset(std::string const&) const = 0;
    virtual bool getAsset(std::string const&, std::string&) const = 0;
    virtual void forEachIn(std::string const&, std::function<void (std::string const&)>) const = 0;
    virtual int getStrategyType() const = 0;
    virtual std::unique_ptr<PackAccessStrategy> createSubPack(std::string const&) const = 0;

};

