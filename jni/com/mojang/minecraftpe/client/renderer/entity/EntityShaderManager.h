//need to update this whole header

#pragma once

#include "../MaterialPtr.h"

class Entity;
class Color;
class Vec2;
class TextureUVCoordinateSet;
class BlockSource;
class BlockPos;
class Vec4;

class EntityShaderManager {
public:
	mce::MaterialPtr entity; // 4
	mce::MaterialPtr entity_transparent; // 16
	mce::MaterialPtr entity_static; // 28

	virtual ~EntityShaderManager();
	virtual void _getOverlayColor(Entity&, float) const;
	
	EntityShaderManager();
	void _setupFoilShaderParameters(Color const&, Color const&, Vec2 const&);
	void _setupFoilShaderParameters(Color const&, Vec2 const&);
	void _setupFoilShaderParameters(Entity&, Color const&, TextureUVCoordinateSet const&, float);
	void _setupFoilShaderParameters(Entity&, Color const&, Vec2 const&, float, bool);
	void _setupFoilShaderParameters(Entity&, TextureUVCoordinateSet const&, float);
	void _setupFoilShaderParameters(TextureUVCoordinateSet const&);
	void _setupFoilShaderParameters(Vec2 const&);
	void _setupShaderParameters(BlockSource&, BlockPos const&, Color const&, float, Vec2 const&);
	void _setupShaderParameters(BlockSource&, BlockPos const&, float, Vec2 const&);
	void _setupShaderParameters(Color const&, Color const&, Color const&, float, float, float, float, Vec2 const&, Vec4 const&, float);
	void _setupShaderParameters(Entity&, Color const&, Color const&, Color const&, float, float, float, float, Vec2 const&, Vec4 const&, float, bool);
	void _setupShaderParameters(Entity&, Color const&, Color const&, Vec4 const&, float, float);
	void _setupShaderParameters(Entity&, Color const&, Color const&, float, bool);
	void _setupShaderParameters(Entity&, Color const&, Color const&, float, float, float, float, Vec2 const&, float);
	void _setupShaderParameters(Entity&, Color const&, float, Vec4 const&);
	void _setupShaderParameters(Entity&, Color const&, float, bool);
	void _setupShaderParameters(Entity&, float);
	void _setupShaderParameters(float, Color const&, bool);
	mce::MaterialPtr getEntityMaterial();
	mce::MaterialPtr getStaticMaterial();
	mce::MaterialPtr getTransparentEntityMaterial();
	
	static void* GLINT_TEXTURE_LOCATION;
	static void* GLINT_SCROLL_SCALE_L1;
	static void* GLINT_SCROLL_SCALE_L2;
};