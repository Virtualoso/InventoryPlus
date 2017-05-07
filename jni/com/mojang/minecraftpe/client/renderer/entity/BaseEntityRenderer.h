#pragma once

#include "EntityShaderManager.h"

class Vec3;

class BaseEntityRenderer : public EntityShaderManager {

public:

	// Virtual
	virtual ~BaseEntityRenderer();
	virtual int _getOffset() = 0;
	virtual Font* _getFont() = 0;
	virtual bool _isRealityFullVRMode() = 0;
	//not sure about the abstract functions due to there being nothing after it in the vtable

	// Non Virtual
	BaseEntityRenderer();
	void _forceTessellateIntercept() const;
	void _renderTextInternal(std::string const&, Vec3 const&, Color const&, mce::MaterialPtr*, mce::MaterialPtr*, Color const&);
	void getDepthTestedNameTagMat();
	void getDepthTestedNameTextMat();
	void renderText(std::string const&, Vec3 const&, Color const&);
	

	// Static

	// Field
	static void* NAME_TAG_COLOR;

};