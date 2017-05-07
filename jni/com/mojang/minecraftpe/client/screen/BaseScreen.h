//need to update this whole header

#pragma once

#include <memory>

#include "AbstractScreen.h"

#include "ScreenSetupStrategyId.h"

class AbstractScreenSetupCleanupStrategy;
class MinecraftGame;

class BaseScreen : public AbstractScreen {
public:
	//void** vtable; // 0
	std::unique_ptr<AbstractScreenSetupCleanupStrategy> cleanupStrategy; // 4
	
	virtual ~BaseScreen();
	virtual void _init(int, int) = 0;
	virtual void setSize(int, int) = 0;
	virtual void onSetKeyboardHeight(float) = 0;
	virtual void setAssociatedBlockPos(BlockPos const&);
	virtual void onInternetUpdate() = 0;
	virtual void onFocusGained() = 0;
	virtual void onFocusLost() = 0;
	virtual void terminate() = 0;
	virtual void tick(int, int);
	virtual void updateEvents() = 0;
	virtual void render(ScreenContext&) = 0;
	virtual void handleInputModeChanged(InputMode) = 0;
	virtual void handleHoloInputModeChanged(HoloUIInputMode) = 0;
	virtual void handleButtonPress(short, FocusImpact) = 0;
	virtual void handleButtonRelease(short, FocusImpact) = 0;
	virtual void handleRawInputEvent(int, RawInputType, ButtonState, bool) = 0;
	virtual void handlePointerLocation(PointerLocationEventData const&, FocusImpact) = 0;
	virtual void handlePointerPressed(bool) = 0;
	virtual void handleDirection(DirectionId, float, float, FocusImpact) = 0;
	virtual void handleBackEvent(bool) = 0;
	virtual void handleTextChar(std::string const&, bool, FocusImpact) = 0;
	virtual void handleCaretLocation(int, FocusImpact) = 0;
	virtual void setTextboxText(std::string const&) = 0;
	virtual void handleLicenseChanged() = 0;
	virtual void handleIdentityGained() = 0;
	virtual void handleIdentityLost() = 0;
	virtual void handleGazeGestureInput(short, float, float, float, FocusImpact) = 0;
	virtual void handleCommandEvent(VoiceCommand const&) = 0;
	virtual bool renderGameBehind() const = 0;
	virtual bool absorbsInput() const = 0;
	virtual bool closeOnPlayerHurt() const = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void getEyeRenderingMode() const;
	virtual std::string getScreenName() const;
	virtual std::string getScreenNameW() const;
	virtual void toGUICoordinate(int, int, int&, int&);
	
	BaseScreen();
	void cleanupForRendering(ScreenContext&);
	void setScreenSetupCleanup(std::unique_ptr<AbstractScreenSetupCleanupStrategy, std::default_delete<AbstractScreenSetupCleanupStrategy> >);
	void setupForRendering(ScreenContext&);
};

std::unique_ptr<AbstractScreenSetupCleanupStrategy> createScreenSetupStrategy(MinecraftGame&, ScreenSetupStrategyId);