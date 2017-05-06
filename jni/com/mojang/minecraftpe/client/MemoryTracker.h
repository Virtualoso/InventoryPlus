#pragma once

#include <string>

class MemoryTracker {

public:

    virtual ~MemoryTracker();
    virtual void* getStats(void) = 0;

    MemoryTracker(std::string const&, MemoryTracker*);
    void memoryStats();

    static void* root;

};
