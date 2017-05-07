#pragma once

#include "../AppPlatformListener.h"

class MinecraftClient;
class Config;

class GuiData : public AppPlatformListener {
public:
	virtual ~GuiData();
	virtual void onConfigChanged(Config const&);
	virtual void onAppSuspended();
	
	GuiData(ClientInstance&);
	void showPopupNotice(std::string const&, std::string const&);
	void flashSlot(int);
	int getNumSlots() const;
};