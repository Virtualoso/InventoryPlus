#pragma once

#include "../MemoryTracker.h"

class Vec2;
class Vec3;
class Color;
namespace mce { class Mesh; class MaterialPtr; class TexturePtr; };
namespace mce { enum class PrimitiveMode; enum class VertexFormat; }

class Tessellator : public MemoryTracker {

public:

    class CurrentVertexPointers {
        CurrentVertexPointers(unsigned char*, mce::VertexFormat const&);
        void nextVertex();
    };

    virtual ~Tessellator();
    virtual void* getStats();

    Tessellator(MemoryTracker*);
    int _allocateIndices(int);
    void _tex(Vec2 const&, int);
    void addOffset(Vec3 const&);
    void addOffset(float, float, float);
    void addRotationOffset(float, Vec3 const&);
    void begin(int);
    void begin(mce::PrimitiveMode, int);
    void beginIndices(int);
    void cancel();
    void clear();
    void color(Color const&);
    void color(float, float, float, float);
    void color(int);
    void color(int, int);
    void color(int, int, int, int);
    void color(unsigned char, unsigned char, unsigned char, unsigned char);
    void colorABGR(int);
    void draw(mce::MaterialPtr const&);
    void draw(mce::MaterialPtr const&, mce::TexturePtr const&);
    void draw(mce::MaterialPtr const&, mce::TexturePtr const&, mce::TexturePtr const&);
    void enableColor();
    mce::Mesh end(char const*, bool);
    int getByteSize();
    int getColor(); // ARGB
    int getPolygonCount();
    int getVertexCount();
    mce::VertexFormat const getVertexFormat();
    void init();
    bool isTessellating();
    void noColor();
    void normal(Vec3 const&);
    void normal(float, float, float);
    void quad(bool);
    void quad(unsigned int, bool);
    void quad(unsigned int, unsigned int, unsigned int, unsigned int);
    void quadFacing(signed char);
    void resetScale();
    void resetTilt();
    void scale2d(float, float);
    void scale3d(float, float, float);
    void setOffset(Vec3 const&);
    void setOffset(float, float, float);
    void setRotationOffset(float, Vec3 const&);
    void tex(Vec2 const&);
    void tex(float, float);
    void tex1(Vec2 const&);
    void tex1(float, float);
    void tex2(Vec2 const&);
    void tex2(float, float);
    void tilt();
    void triangle(unsigned int, unsigned int, unsigned int);
    void trim();
    void vertex(Vec3 const&);
    void vertex(float, float, float);
    void vertexUV(Vec3 const&, float, float);
    void vertexUV(float, float, float, float, float);
    void voidBeginAndEndCalls(bool);

    static Tessellator instance;

};
