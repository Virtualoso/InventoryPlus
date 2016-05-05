#pragma once

#include "EntityRenderer.h"

class ItemInstance;
class BlockTessellator;

class ItemRenderer : public EntityRenderer {
public:
	BlockTessellator* blockRenderer; // 140
	char ir_vars[64]; // 144
	bool idk_b; // 208
	mce::MaterialPtr ui_fill_color; // 212
	mce::MaterialPtr ui_textured; // 224
	mce::MaterialPtr ui_texture_and_color_tint; // 236
	mce::MaterialPtr ui_item_glint; // 248
	mce::MaterialPtr entity_alphatest_change_color; // 260
	mce::MaterialPtr entity_alphatest_change_color_glint; // 272
	mce::TexturePtr icons; // 284

	ItemRenderer(mce::TextureGroup&);
	virtual ~ItemRenderer();
	virtual void render(Entity&, const Vec3&, float, float);
	
	static ItemRenderer* getInstance();
	
	void renderGuiItemNew(const ItemInstance*, int, float, float, float, float, float, bool);
};