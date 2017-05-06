//need to update this whole header

#pragma once

#include <memory>

#include "AbstractScreen.h"

#include "ScreenSetupStrategyId.h"

class AbstractScreenSetupCleanupStrategy;
class MinecraftClient;

class BaseScreen : public AbstractScreen {
public:
	//void** vtable; // 0
	std::unique_ptr<AbstractScreenSetupCleanupStrategy> cleanupStrategy; // 4
	
	BaseScreen();
	virtual ~BaseScreen();
	virtual std::string getScreenName();
	virtual void toGUICoordinate(int, int, int&, int&);
	void cleanupForRendering(ScreenContext&);
	void getEyeRenderingMode();
	void setScreenSetupCleanup(std::unique_ptr<AbstractScreenSetupCleanupStrategy>);
	void setupForRendering(ScreenContext&);
};

std::unique_ptr<AbstractScreenSetupCleanupStrategy> createScreenSetupStrategy(MinecraftClient&, ScreenSetupStrategyId);