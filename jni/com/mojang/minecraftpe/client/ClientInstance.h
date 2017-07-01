#pragma once

#include <string>
#include <memory>
#include <functional>

#include "../gamemode/GameType.h"

class MinecraftGame;
class IMinecraftApp;
class ClientPlayMode;
class SoundEngine;
class ResourcePackManager;
class Font;
class LevelRenderer;
class GameRenderer;
class LocalPlayer;
class HolographicPlatform;
class VoiceSystem;
class FilePathManager;
class MinecraftEventing;
class ToastManager;
class ScreenshotOptions;
class ClientPlayerMode;
class Vec3;
class Options;
class Player;
class ScreenChooser;
class GeometryGroup;
class Entity;
class AbstractScreen;
class GuiData;
class Screen;
class Level;
class Textures;

namespace minecraft
{
	namespace api
	{
		class Api;
	}
}
namespace ui { class GameEventNotification; }
namespace Social 
{ 
	class UserManager; 
	class Multiplayer;
	class XboxLiveGameInfo;
	class GameConnectionInfo;
	namespace Telemetry 
	{
		class TelemetryManager;
	}
}

class ClientInstance
{
public:
	virtual ~ClientInstance();
	virtual void onLevelCorrupt();
	virtual void onGameModeChanged();
	virtual void onTick(int, int);
	virtual void onInternetUpdate();
	virtual void onGameSessionReset();
	virtual void onLevelExit();
	virtual void createSkin();
public:
	ClientInstance(MinecraftGame&, IMinecraftApp&, SoundEngine&, minecraft::api::Api&, FilePathManager*, MinecraftEventing&);
	void getHoloInput() const;
	GuiData* getGuiData();
	Options* getOptions();
	void setUIWidth(int);
	void setUIHeight(int);
	void unMuteAudio();
	void releaseMouse();
	void setHoloInput(std::unique_ptr<HolographicPlatform, std::default_delete<HolographicPlatform> >);
	void forEachScreen(std::function<bool (std::shared_ptr<AbstractScreen>&)>, bool);
	void getServerData();
	void checkForPiracy();
	LocalPlayer* getLocalPlayer();
	void getScreenNames();
	void getScreenStack();
	void onPlayerLoaded(Player&);
	void setVoiceSystem(std::unique_ptr<VoiceSystem, std::default_delete<VoiceSystem> >);
	void stopDestroying();
	ToastManager* getToastManager();
	void setCameraEntity(Entity*);
	void setDisableInput(bool);
	void tickBuildAction();
	void requestScreenshot(ScreenshotOptions const&);
	void setClientGameMode(GameType);
	void setClientPlayMode(ClientPlayMode const&);
	void setUISizeAndScale(int, int, float);
	void clearInProgressBAI();
	void onDimensionChanged();
	void setDisplayPosition(bool);
	void getLocalServerLevel();
	void getMobEffectsLayout();
	void forEachVisibleScreen(std::function<void (std::shared_ptr<AbstractScreen>&)>, bool);
	void initializeTrialWorld(Player*);
	void onClientStartedLevel(std::unique_ptr<Level, std::default_delete<Level> >, std::unique_ptr<LocalPlayer, std::default_delete<LocalPlayer> >);
	void getUserAuthentication();
	void onPrepChangeDimension();
	void setCameraTargetEntity(Entity*);
	void getLastPointerLocation();
	void setLastPointerLocation(float, float, float);
	void adjustGazeCursorByMouse(float, float);
	void onGameEventNotification(ui::GameEventNotification);
	void getResourcePacksInfoData();
	void setRealityModeFrameFactor(float const&);
	void startExternalNetworkWorld(Social::GameConnectionInfo, std::string const&);
	void clearDictationDataAvailable();
	void _processNewGazeHoloScreenData();
	void currentScreenShouldStealMouse();
	void setRealityModeToggleTriggered(bool);
	void computeScreenCoordsFromScreenNormCoords(float, float, short&, short&);
	void init();
	void play(std::string const&, Vec3 const&, float, float);
	void quit();
	void stop();
	void tick();
	void playUI(std::string const&, float, float);
	void update();
	void endFrame();
	Level* getLevel();
	void resetBai(int);
	void shutdown();
	Screen* getScreen();
	void grabMouse();
	void leaveGame(bool);
	void muteAudio();
	void setPlayer(LocalPlayer*);
	int getUIWidth() const;
	bool isARClient() const;
	bool isVRClient() const;
	bool wantToQuit() const;
	MinecraftEventing* getEventing() const;
	void getRuneFont() const;
	Textures* getTextures() const;
	int getUIHeight() const;
	bool allowPicking() const;
	bool isARVRClient() const;
	bool isNotVLRMode() const;
	void getServerData() const;
	bool isInBedScreen() const;
	bool isShowingMenu() const;
	void useController() const;
	bool getMultiplayer() const;
	int getScreenWidth() const;
	SoundEngine* getSoundEngine() const;
	void getUnicodeFont() const;
	void getUserManager() const;
	void getVoiceSystem() const;
	bool isExitingLevel() const;
	bool useTouchscreen() const;
	Entity* getCameraEntity() const;
	GameRenderer* getGameRenderer() const;
	void getMouseGrabbed() const;
	int getScreenHeight() const;
	bool isPrimaryClient() const;
	bool isReadyToRender() const;
	void getDictationText() const;
	GeometryGroup* getGeometryGroup() const;
	void getInProgressBAI() const;
	LevelRenderer* getLevelRenderer() const;
	MinecraftGame* getMinecraftGame() const;
	ScreenChooser* getScreenChooser() const;
	bool isHoloscreenMode() const;
	bool isHoloviewerMode() const;
	bool isLivingroomMode() const;
	bool readyForShutdown() const;
	void getClientPlayMode() const;
	void getClientRandomId() const;
	void getSkinRepository() const;
	bool isHoloRealityMode() const;
	bool isKeyboardEnabled() const;
	bool isVRTransitioning() const;
	void getDisplayPosition() const;
	void getForceMonoscopic() const;
	void getHoloviewerScale() const;
	bool isHoloCursorNeeded() const;
	void getAutomationClient() const;
	void getCurrentInputMode() const;
	void getDevConsoleLogger() const;
	bool isRealityFullVRMode() const;
	bool isScreenReplaceable() const;
	void getHolosceneRenderer() const;
	void getSkinGeometryGroup() const;
	Entity* getCameraTargetEntity() const;
	ResourcePackManager* getResourcePackManager() const;
	void getRealityModeFrameFactor() const;
	void getResourcePackRepository() const;
	void newDictationDataAvailable() const;
	void getRealityModeToggleTriggered() const;
	void currentInputModeIsGamePadOrMotionController() const;
	Font* getFont() const;
	void getInput() const;
	Level* getLevel() const;
	bool isInGame() const;
	Screen* getScreen() const;
	bool isEduMode() const;
};