#pragma once

#include <vector>
#include <fstream>
class ResourcePack;
class ResourcePackRepository;
class OfferRepository;
class PackIdVersion;

struct PackPair {
    ResourcePack* pack;
    bool unknown;
};

class ResourcePackStack {

public:

    std::vector<PackPair> stack;

    // non virtual
    ResourcePackStack(std::vector<ResourcePack*, std::allocator<ResourcePack*>> const&, ResourcePackRepository const&, OfferRepository*, bool);
    void add(ResourcePack*, ResourcePackRepository const&, bool);
    void* _removeInvalidPacks(ResourcePackRepository const&, OfferRepository*);
    ResourcePackStack(std::vector<PackIdVersion, std::allocator<PackIdVersion>> const&, ResourcePackRepository const&, OfferRepository*, bool);
    void* _populateDependencies(std::vector<PackPair, std::allocator<PackPair>>&, ResourcePack&, ResourcePackRepository const&, bool);
    void* deserialize(std::basic_fstream<char, std::char_traits<char>>&, ResourcePackRepository const&, OfferRepository*, bool);
    void* getSplitStacks(ResourcePackStack&, ResourcePackStack&) const;
    void* getStack() const;
    void* getStackWithoutDependencies() const;
    void* getStackAsIdentities() const;

};

