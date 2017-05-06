#pragma once

namespace mce {

class RenderContext;
class MaterialPtr;
class TexturePtr;
enum class PrimitiveMode;
enum class VertexFormat;
enum class IndexBufferUsageMode;

class Mesh {

public:

    char filler[0x60];

    Mesh(mce::Mesh&&);
    Mesh(mce::VertexFormat const&, unsigned int, unsigned int, unsigned char, mce::PrimitiveMode, unsigned char*, bool);
    Mesh();
    ~Mesh();

    bool hasIndices();
    bool isTemporary();
    bool isValid();

    void reset();
    void clearGlobalBuffers();
    void releaseIndexBuffer();

    void render(mce::MaterialPtr const&, mce::TexturePtr const&, mce::TexturePtr const&, mce::TexturePtr const&, unsigned int, unsigned int);
    void render(mce::MaterialPtr const&, mce::TexturePtr const&, mce::TexturePtr const&, unsigned int, unsigned int);
    void render(mce::MaterialPtr const&, mce::TexturePtr const&, unsigned int, unsigned int);
    void render(mce::MaterialPtr const&, unsigned int, unsigned int);

    void loadIndexBuffer(unsigned int, void const*, unsigned int);
    bool loadRawData(mce::RenderContext&, unsigned char*);
    void setIndexBufferUsageMode(mce::IndexBufferUsageMode);

    void _move(mce::Mesh&);

    mce::Mesh& operator=(mce::Mesh&&);

};

};
