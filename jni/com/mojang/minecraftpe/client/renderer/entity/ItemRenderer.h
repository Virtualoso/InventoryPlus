#pragma once

#include "EntityRenderer.h"

class ItemInstance;
class BlockTessellator;
class IconBlitGlint;

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

	virtual ~ItemRenderer();
	virtual void render(Entity&, const Vec3&, float, float);
	
	ItemRenderer(EntityRenderDispatcher&, mce::TextureGroup&);
	void _loadItemGraphics();
	void blit(mce::TexturePtr const&, float, float, float, float, float, float);
	void createSingleton(EntityRenderDispatcher&, mce::TextureGroup&);
	void fillRect(Tessellator&, float, float, float, float, int);
	void forceGraphicsLoad();
	void getAtlasPos(ItemInstance const*);
	void getGraphics(Item const&);
	void getGraphics(ItemInstance const&);
	void iconBlit(mce::TexturePtr const&, float, float, TextureUVCoordinateSet const&, float, float, float, float, int, float, IconBlitGlint);
	void renderGuiItemDecorations(ItemInstance const&, float, float);
	void renderGuiItemInChunk(ItemRenderChunkType, ItemInstance const&, float, float, float, float, float, int, bool);
	void renderGuiItemNew(ItemInstance const&, int, float, float, float, float, float, bool);

	static ItemRenderer* getInstance();
	
	static void* mItemGraphics;
	static void* instance;
};