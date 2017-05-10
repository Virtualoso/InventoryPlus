#pragma once

#include <string>

class AbstractScreenSetupCleanupStrategy {
public:

	void cleanupScreen(ScreenContext);
	int getNumberOfRenderPasses() const;
};