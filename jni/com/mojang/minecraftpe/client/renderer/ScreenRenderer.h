#pragma once

#include <string>
#include <vector>

class IntRectangle;
class Color;
class Font;
class BlitParams;

namespace mce {
	class TextureGroup;
	class TexturePtr;
	class MaterialPtr;
};

class ScreenRenderer {
public:
	enum class ScreenMaterial : int { };

	static void* guiTex;
	static void* mScreenMaterials;
	static ScreenRenderer* singletonPtr;
	static void* spritesheetTex2;
	static void* spritesheetTex;
	static void* touchGui2Tex;
	static void* touchGuiTex;

	ScreenRenderer();
	void blit(mce::TexturePtr const&, IntRectangle const&);
	void blit(mce::TexturePtr const&, float, float, int, int, float, float, int, int, mce::MaterialPtr*);
	void blit(mce::TexturePtr const&, int, int, int, int, int, int, int, int, mce::MaterialPtr*);
	void blit(mce::TexturePtr const&, std::vector<BlitParams> const&);
	void blitRaw(mce::TexturePtr const&, float, float, float, float, float, float, float, float, float);
	void drawCenteredString(Font*, std::string const&, int, int, Color const&);
	void drawRect(int, int, int, int, Color const&, Color const&, Color const&, Color const&, int);
	void drawRect(int, int, int, int, Color const&, int);
	void drawString(Font*, std::string const&, int, int, Color const&);
	void fill(float, float, float, float, Color const&) const;
	void fill(int, int, int, int, Color const&) const;
	void fillGradient(float, float, float, float, Color const&, Color const&);
	//void fillGradient(glm::detail::tvec2<float> const&, glm::detail::tvec2<float> const&, Color const&, Color const&);
	void fillGradient(int, int, int, int, Color const&, Color const&);
	void fillHorizontalGradient(float, float, float, float, Color const&, Color const&);
	//void fillHorizontalGradient(glm::detail::tvec2<float> const&, glm::detail::tvec2<float> const&, Color const&, Color const&);
	void fillHorizontalGradient(int, int, int, int, Color const&, Color const&);
	void fillStencil(float, float, float, float) const;
	void getMaterial(ScreenRenderer::ScreenMaterial) const;
	void reloadResources(mce::TextureGroup&);
	ScreenRenderer* singleton();
	
	//the ones commented out use opengl (which is what mcpe runs on)
};