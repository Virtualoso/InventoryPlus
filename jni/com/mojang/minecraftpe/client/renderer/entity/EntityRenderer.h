#pragma once

#include <string>
#include "EntityShaderManager.h"
#include "../TexturePtr.h"

class EntityRenderDispatcher;
class Vec3;
class Vec2;
class Font;
class Options;
namespace mce { class TextureGroup; };

class EntityRenderer : public EntityShaderManager {
public:
	static EntityRenderDispatcher* entityRenderDispatcher;

	bool waterHole;								// 40
	char er_filler1[4];							// 44
	mce::MaterialPtr entity_alphatest2;			// 48
	mce::MaterialPtr entity_alphatest_glint;	// 60
	mce::TexturePtr terrain_atlas; 				// 72
	mce::TexturePtr glint_texture;				// 88
	mce::MaterialPtr name_tag;					// 104
	mce::MaterialPtr name_tag_depth_tested;		// 116
	mce::MaterialPtr name_tag_depth_tested2;	// 128

	EntityRenderer(mce::TextureGroup&, bool);
	virtual ~EntityRenderer();
	virtual void render(Entity&, const Vec3&, float, float) = 0;
	virtual void postRender(Entity&, const Vec3&, float, float);
	virtual void renderDebug(Entity&, Options&);
	virtual void renderWaterHole(Entity&, const Vec3&, const Vec2&, float);
	void renderText(Entity&, const std::string*, float, float);
	void renderText(const std::string&, const Vec3&, const Color&, mce::MaterialPtr*, mce::MaterialPtr*);
	static void _emitFlame(Entity &, float);
	static void _emitSmoke(Entity &, float);
	static bool isFancy();
	static Font* getFont();
	static void init(EntityRenderDispatcher*);
	bool hasWaterHole() const;
};
