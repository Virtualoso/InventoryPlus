#pragma once

#include <string>
#include "BaseEntityRenderer.h"
#include "../TexturePtr.h"

class EntityRenderDispatcher;
class Vec3;
class Vec2;
class Font;
class Options;
namespace mce { class TextureGroup; };

class EntityRenderer : public BaseEntityRenderer {
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

	virtual ~EntityRenderer();
	virtual int _getOffset();
	virtual Font* _getFont();
	virtual bool _isRealityFullVRMode();
	virtual void render(Entity&, Vec3 const&, float, float) = 0;
	virtual void renderDebug(Entity&, Options&);
	virtual void renderEffects(Entity&, Vec3 const&, float, float);
	virtual void renderTrading(Entity&, float, Vec3 const&, float);
	virtual void renderLeash(Entity&, Vec3 const&, float, float);
	virtual void renderWaterHole(Entity&, Vec3 const&, Vec2 const&, float);
	
	EntityRenderer(EntityRenderDispatcher&, mce::TextureGroup&, bool);
	void renderText(Entity&, std::string const&, float, float);
	void getAtlasTexture();
	void hasWaterHole() const;
	void isFancy();
};