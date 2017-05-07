#pragma once

class PushNotificationMessage;

class AppPlatformListener {
public:
	//Field
	/*0x04*/char apl_vars[4];
	/*0x08*/char filler[24];
	/*0x20*/char idk[4]; //something with terminate
	/*Size based on functions - 0x24*/

	//Virtual
	virtual ~AppPlatformListener();
	virtual void onLowMemory();
	virtual void onAppPaused();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onAppTerminated();
	virtual void onPushNotificationReceived(PushNotificationMessage const&);
	
	//Non Virtual
	AppPlatformListener(bool);
	AppPlatformListener();
	
	void initListener(float);
	void terminate();
};