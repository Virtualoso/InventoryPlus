#pragma once

#include <string>
#include <chrono>
#include <ratio>
#include <memory>
#include <vector>

class GameCallbacks;
class SkinInfoFactory;
class Vibration;
class SoundPlayer;
namespace minecraft {
	namespace api {
		class Api;
	};
};
class Whitelist;
class OpsList;
class MinecraftEventing;
enum GameType;
class Level;
class GameMode;
class Player;
namespace mce {
	class UUID;
};
class NetEventCallback;
class LevelSettings;
class ResourcePackManager;
class NetworkIdentifier;

class Minecraft {
public:

	char filler1[112];
	/* size = 0x70 */

	// non virtual
	Minecraft(GameCallbacks&, SkinInfoFactory&, Vibration&, SoundPlayer&, minecraft::api::Api&, Whitelist const&, OpsList const&, std::string const&, std::chrono::duration<long long, std::ratio<1ll, 1ll> >, MinecraftEventing&);
	~Minecraft();
	bool isModded();
	void* getCommands();
	void* getNetworkHandler();
	void* getLevel();
	void* getServerNetworkHandler();
	void* getEventing() const;
	void* getSimPaused() const;
	void* createGameMode(GameType, Level&);
	void* getLevelSource();
	void hostMultiplayer(std::unique_ptr<Level>, std::unique_ptr<GameMode>, Player*, mce::UUID const&, std::unique_ptr<NetEventCallback>, int, bool, bool, std::vector<std::string> const&, std::string, int, int, int, int);
	void* getResourceLoader();
	void* getStructureManager();
	void initAsDedicatedServer();
	void init(std::string const&, bool);
	void update();
	void createLevel(std::string const&, std::string const&, LevelSettings const&, ResourcePackManager&);
	void* getGameMode();
	void tickSimtime(int, int);
	void setLeaveGame();
	void tickRealtime(int, int);
	void* getServerName();
	void* validateLevel(std::string const&, std::string const&, LevelSettings const&);
	bool isOnlineClient();
	void* getPacketSender();
	void setGameModeReal(GameType);
	void setSimTimePause(bool);
	void setSimTimeScale(float);
	void startClientGame(std::unique_ptr<NetEventCallback>);
	void disconnectClient(NetworkIdentifier const&, std::string const&);
	void* getServerLocator();
	void resetGameSession();
	void activateWhitelist();
	void* getNetEventCallback();
	void setupServerCommands(std::string const&, std::string const&);
	void* getNetworkStatistics();
	void onClientStartedLevel(std::unique_ptr<Level>);
	void restartMultiplayerHost(int, int, int, int);
	void* getUser();
	void* getTimer();
	void stopGame();
	void teardown();
	bool isInitialized() const;
};
