#pragma once

#include <string>
#include <vector>
#include <set>
#include <functional>
#include "InputHandler.h"

class TextureData;
class Vec2;
class Vec3;
class AppPlatformListener;
class ImagePickingCallback;
class FilePickerSettings;
class PushNotificationMessage;
class UriListener;
class ActivationUri;
class ResourceLocation;
class PermissionRequestReason;
class FileStorageDirectory;
enum class ControllerType;
enum class FullscreenMode;

namespace mce { class ImageBuffer; }

enum class UIScalingRules {
	Desktop, PocketApple, PocketAndroid, PocketWindows
};

class AppPlatform {

public:

	class HardwareInformation {

	public:
		HardwareInformation();
		~HardwareInformation();

	};

	// virtual
	virtual ~AppPlatform();
	virtual std::string getDataUrl() const = 0;
	virtual std::string getUserDataUrl() const = 0;
	virtual std::string getAlternateDataUrl() const;
	virtual std::string getPackagePath() = 0;
	virtual void* loadPNG(mce::ImageBuffer&, std::string const&);
	virtual void* loadTGA(mce::ImageBuffer&, std::string const&);
	virtual void* loadJPEG(mce::ImageBuffer&, std::string const&);
	virtual int getKeyFromKeyCode(int, int, int);
	virtual void showKeyboard(std::string const&, int, bool, bool, bool, Vec2 const&);
	virtual void hideKeyboard();
	virtual bool isFullScreenKeyboard() const;
	virtual float getKeyboardHeight() const;
	virtual void hideMousePointer();
	virtual void showMousePointer();
	virtual bool getPointerFocus();
	virtual void setPointerFocus(bool);
	virtual void toggleSimulateTouchWithMouse();
	virtual void _fireLowMemory();
	virtual void _fireAppSuspended();
	virtual void _fireAppResumed();
	virtual void _fireAppFocusLost();
	virtual void _fireAppFocusGained();
	virtual void _fireAppTerminated();
	virtual void _fireAppConfigurationChanged();
	virtual void _fireAppPaused();
	virtual void swapBuffers() = 0;
	virtual void discardBackbuffer();
	virtual std::string const& getSystemRegion() const = 0;
	virtual bool getGraphicsTearingSupport() = 0;
	virtual void pickImage(ImagePickingCallback&) = 0;
	virtual void pickFile(FilePickerSettings&);
	virtual bool hasHardwareBackButton();
	virtual bool supportsMSAA() const;
	virtual bool supportsFilePicking() const;
	virtual bool supportsClipboard() const;
	virtual void setClipboard(std::string const&) const;
	virtual bool supportsBeiHai() const;
	virtual void* pushNotificationReceived(PushNotificationMessage const&);
	virtual void* openStoragePermissionRequest(PermissionRequestReason, std::function<void (void)>);
	virtual void setStorageDirectory(FileStorageDirectory, bool);
	virtual void setInitialStorageDirectory(FileStorageDirectory);
	virtual void* getStorageDirectory() const;
	virtual void setStorageDirectoryChangeDenied(std::function<void (FileStorageDirectory)>);
	virtual void setStorageDirectoryChanged(std::function<void (std::string)>);
	virtual void runStoragePermissionResultCallback();
	virtual bool hasExternalStoragePermission();
	virtual void* createHolographicPlatform(bool) const;
	virtual void* createAndroidLaunchIntent();
	virtual void* getModalErrorMessageProc();
	virtual void updateLocalization(std::string const&);
	virtual void setSleepEnabled(bool);
	virtual std::string const& getCurrentStoragePath() = 0;
	virtual std::string const& getExternalStoragePath() = 0;
	virtual std::string const& getInternalStoragePath() = 0;
	virtual std::string const& getUserdataPath() = 0;
	virtual std::string const& getSettingsPath();
	virtual std::string const& getUserdataPathForLevels();
	virtual void* getApiEnvironmentPath();
	virtual void showDialog(int);
	virtual void* createUserInput();
	virtual void* getUserInputStatus();
	virtual void* getUserInput();
	virtual void* getFileInterface(ResourceLocation const&);
	virtual void copyImportFileToTempFolder(std::string const&);
	virtual int getScreenWidth();
	virtual int getScreenHeight();
	virtual void setScreenSize(int, int);
	virtual void setWindowSize(int, int);
	virtual void setWindowText(std::string const&);
	virtual float getPixelsPerMillimeter();
	virtual void queueForMainThread(std::function<void (void)>) = 0;
	virtual void updateTextBoxText(std::string const&);
	virtual bool isKeyboardVisible();
	virtual bool supportsVibration();
	virtual void vibrate(int);
	virtual std::string getAssetFileFullPath(std::string const&);
	virtual std::string readAssetFile(std::string const&);
	virtual std::string readAssetFileZipped(std::string const&, std::string const&);
	virtual std::set<std::string> listAssetFilesIn(std::string const&, std::string const&) const;
	virtual std::string getFomattedDateString(const long&) const;
	virtual void* getFileTimestamp(const long&) const;
	virtual int checkLicense();
	virtual bool hasBuyButtonWhenInvalidLicense();
	virtual void uploadPlatformDependentData(int, void*);
	virtual bool isNetworkEnabled(bool);
	virtual void buyGame();
	virtual void finish();
	virtual void launchUri(std::string const&);
	virtual bool useXboxControlHelpers() const;
	virtual bool showPointMenuCursor() const;
	virtual void* getPlatformType() const;
	virtual void* getBuildPlatform() const; //done until here
	virtual void setControllerType(ControllerType);
	virtual ControllerType getControllerType() const;
	virtual bool hasIDEProfiler();
	virtual std::string getPlatformStringVar(int);
	virtual std::string getApplicationId() = 0;
	virtual long long getAvailableMemory();
	virtual long long getTotalMemory();
	virtual long long getUsedMemory();
	virtual std::vector<std::string> getBroadcastAddresses();
	virtual std::vector<std::string> getIPAddresses();
	virtual std::string getModelName();
	virtual std::string getDeviceId() = 0;
	virtual std::string createUUID() = 0;
	virtual bool isFirstSnoopLaunch() = 0;
	virtual bool hasHardwareInformationChanged() = 0;
	virtual bool isTablet() = 0;
	virtual void registerUriListener(UriListener&);
	virtual void registerUriListener(std::string const&, UriListener&);
	virtual void unregisterUriListener(UriListener const&);
	virtual void notifyUriListeners(ActivationUri const&);
	virtual void notifyUriListenerRegistrationDone();
	virtual void setFullscreenMode(FullscreenMode);
	virtual bool isNetworkThrottled();
	virtual void collectGraphicsHardwareDetails();
	virtual std::string getEdition() const;
	virtual bool realmsBeta() const;
	virtual bool isFireTV() const;
	virtual InputMode getDefaultInputMode() const;
	virtual long long calculateAvailableDiskFreeSpace(std::string const&) = 0;
	virtual void speakTextToSpeech(std::string const&);
	virtual void setTextToSpeechEnabled(bool);
	virtual void stopTextToSpeech();
	virtual bool isTextToSpeechSpeaking();
	virtual void _notifyUriListeners(ActivationUri const&, bool);
	virtual void* getPlatformDpi() const;
	virtual UIScalingRules getPlatformUIScalingRules() const;
	virtual std::string const& getPlatformTempPath() = 0;

	// non virtual
	AppPlatform();

	void initialize();
	bool isInitialized();
	void teardown();

	bool isReadyForGameUpdate() const;

	void loadImage(TextureData&, std::string const&);
	void loadImageFromStream(TextureData&, std::string const&);
	void* loadTexture(std::string const&);
	void* loadTextureFromStream(std::string const&);

	void setPendingProtocolActivation(ActivationUri const&);
	void setAllowLostFocusToasts(bool);
	void setShowLostFocusToasts(bool);
	bool getShowLostFocusToasts();

	int getDpi() const;
	void setDpi(int);
	UIScalingRules getUIScalingRules() const;
	void setUIScalingRules(UIScalingRules);

	HardwareInformation const& getHardwareInformation() const;
	HardwareInformation& getHardwareInformationToModify();

	void* getAppLifecycleContext();
	bool getTextToSpeechEnabled();
	void* getFocusState();
	std::string getTempPath();
	void createUserInput(int);
	static std::string const& StringizeUIScalingRules(UIScalingRules);

	void addListener(AppPlatformListener*, float);
	void removeListener(AppPlatformListener*);
	void queueInitializerTask(std::function<void ()> const&);

	static AppPlatform* singleton();

	// static fields
	static void* HOME_PATH;
	static void* mSingleton;
	static void* mPendingProtocolActivation;
	static void* mProtocolMutex;

};
