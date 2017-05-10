#pragma once

#include "Screen.h"

class InGamePlayScreen : public Screen {
public:
	
	virtual ~InGamePlayScreen();
	virtual void _init(int, int);
	virtual void onFocusGained();
	virtual void tick(int, int);
	virtual void applyInput(float);
	virtual void preRenderUpdate(RenderGraphContext&);
	virtual void render(ScreenContext&);
	virtual void postRender(UIScreenContext&);
	virtual bool renderGameBehind() const;
	virtual bool isModal() const;
	virtual bool isShowingMenu() const;
	virtual bool shouldStealMouse() const;
	virtual bool isPlayScreen() const;
	virtual bool renderOnlyWhenTopMost() const;
	virtual std::string getScreenName() const;
	virtual std::string getScreenNameW() const;
	virtual void* getSendEvents();
	virtual void handleDirection(DirectionId, float, float);
	virtual void _renderLevelPrep(ScreenContext&, LevelRenderer&, Entity&);
	virtual void _renderLevel(ScreenContext&);
	virtual void _preLevelRender(ScreenContext&);
	virtual void _postLevelRenderer(ScreenContext&);
	virtual bool _shouldRenderFirstPersonObjects(LevelRenderer&) const;
	virtual void _renderedFramedItems(ScreenContext&, LevelRenderer&, Entity&)
	virtual void _updateFreeformPickDirection(float, Vec3&, Vec3&);
	virtual void _saveMatrices();
	virtual void _renderFirstPerson3DObjects(LevelRenderer&, float);
	virtual void _renderTransparentFirstPerson3DObjects(LevelRenderer&, float);
	virtual void _renderItemInHand(Player&, bool, float);
	virtual bool _shouldClipLiquids() const;
	virtual void* _getThirdPersonSettings();
	virtual bool _isHoloViewer() const;
	virtual void _prepareCuller(FrustumData&, FrustumData&);
	virtual void _localPlayerTurned(float);
	virtual void* _getPickRange();
	virtual bool _shouldPushHUD();
	virtual void _setHoloMode();
	virtual void _updateInGameCursor();
	
	InGamePlayScreen(MinecraftGame&, ClientInstance&);
	
	
}