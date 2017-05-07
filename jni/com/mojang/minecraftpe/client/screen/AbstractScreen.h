#pragma once

#include <string>

class BlockPos;
class ScreenContext;
class UIScreenContext;
class InputMode;
class HoloUIInputMode;
class DirectionId;
class VoiceCommand;
class RenderGraphContext;
class FocusImpact;
class RawInputType;
class ButtonState;
class PointerLocationEventData;
class AABB;
class TextCharEventData;
class Tessellator;
class RectangleArea;
namespace ui { class GameEventNotification; };

class AbstractScreen {
public:

	virtual ~AbstractScreen();
	virtual void _init(int, int) = 0;
	virtual void setSize(int, int) = 0;
	virtual void onSetKeyboardHeight(float) = 0;
	virtual void setAssociatedBlockPos(BlockPos const&) = 0;
	virtual void onInternetUpdate() = 0;
	virtual void onFocusGained() = 0;
	virtual void onFocusLost() = 0;
	virtual void terminate() = 0;
	virtual void onGameEventNotification(ui::GameEventNotification);
	virtual void _handleDirtyVisualTree(bool);
	virtual void leaveScreen();
	virtual void tick();
	virtual void tick(int, int) = 0;
	virtual void updateEvents() = 0;
	virtual void applyInput(float);
	virtual void preRenderUpdate(RenderGraphContext&);
	virtual void render(ScreenContext&) = 0;
	virtual void postRenderUpdate(RenderGraphContext&);
	virtual void setupAndRender(UIScreenContext&);
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
	virtual void handleDictationEvent(std::string const&);
	virtual void handleCommandEvent(VoiceCommand const&) = 0;
	virtual bool renderGameBehind() const = 0;
	virtual bool absorbsInput() const = 0;
	virtual bool closeOnPlayerHurt() const = 0;
	virtual bool isModal() const;
	virtual bool isShowingMenu() const;
	virtual bool shouldStealMouse() const;
	virtual bool screenIsNotFlushable() const;
	virtual bool screenDrawsLast() const;
	virtual void getFocusedControl();
	virtual bool isWorldViewer() const;
	virtual bool isPauseScreen() const;
	virtual bool isPlayScreen() const;
	virtual bool renderOnlyWhenTopMost() const;
	virtual bool lowFreqRendering() const;
	virtual bool ignoreAsTop() const;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual AABB* getRenderingAABB();
	virtual int getNumberOfRenderPasses() const;
	virtual void getEyeRenderingMode() const;
	virtual std::string getScreenName() const = 0;
	virtual std::string getScreenNameW() const = 0;
	virtual void getSendEvents();
	virtual void getEventProperties() const;
	virtual void processBufferedTextCharEvents(std::vector<TextCharEventData> const&);
	
	void drawRectangleArea(Tessellator&, RectangleArea const&, int, int, float, float);
	//the only function that isn't virtual, all alone :(
	
	static void* mEmptyRect;
};