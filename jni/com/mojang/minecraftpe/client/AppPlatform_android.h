#pragma once

#include "AppPlatform.h"

class ANativeActivity;

class AppPlatform_android : public AppPlatform {
public:
	AppPlatform_android();
	virtual ~AppPlatform_android();
	virtual void getDataUrl() const;
	virtual void getImagePath(const std::string&, TextureLocation);
	virtual void loadPNG(ImageData&, const std::string&, TextureLocation);
	virtual void loadTGA(ImageData&, const std::string&, TextureLocation);
	virtual void getKeyFromKeyCode(int, int, int);
	virtual void showKeyboard(const std::string&, int, bool, bool, const Vec2&);
	virtual void hideKeyboard();
	virtual void getKeyboardHeight() const;
	virtual void swapBuffers();
	virtual void discardBackBuffer();
	virtual void getSystemRegion() const;
	virtual void getGraphicsVendor();
	virtual void getGraphicsRenderer();
	virtual void getGraphicsVersion();
	virtual void getGraphicsExtensions();
	virtual void pickImage(ImagePickingCallback&);
	virtual void getExternalStoragePath();
	virtual void getInternalStoragePath();
	virtual std::string& getUserdataPath();
	virtual void getUserDataPathForLevels();
	virtual void showDialog(int);
	virtual void createUserInput();
	virtual void getUserInputStatus();
	virtual void getUserInput();
	virtual void getScreenWidth();
	virtual void getScreenHeight();
	virtual void getPixelsPerMillimeter();
	virtual void updateTextBoxText(const std::string&);
	virtual bool supportsVibration();
	virtual void vibrate(int);
	virtual std::string readAssetFile(const std::string&);
	virtual void getDateString(int);
	virtual void checkLicense();
	virtual void hasBuyButtonWhenInvalidLicense();
	virtual void uploadPlatformDependentData(int, void *);
	virtual bool isNetworkEnabled(bool);
	virtual bool isPowerVR();
	virtual void buyGame();
	virtual void finish();
	virtual void launchUri(const std::string&);
	virtual bool useMetadataDrivenScreens() const;
	virtual void getScreenType() const;
	virtual void getPlatformStringVar(int);
	virtual void getApplicationId();
	virtual void getAvailableMemory();
	virtual void getBroadcastAddresses();
	virtual void getModelName();
	virtual void getDeviceId();
	virtual std::string createUUID();
	virtual bool isFirstSnoopLaunch();
	virtual bool hasHardwareInformationChanged();
	virtual bool isTablet();
	virtual void getPlatformTempPath();
	virtual void initWithActivity(ANativeActivity*);
};
