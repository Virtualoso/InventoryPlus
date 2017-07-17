#pragma once

#include <memory>
#include <string>
#include <deque>
#include "MinecraftGame.h"

class MinecraftUISoundPlayer;
class ProgressHandler;
enum class CraftingType;
class PatchNotesModel;
namespace Realms {
	class World;
};
class AbstractScreen;
enum class PlayScreenDefaultTab;
class MashupData;
enum class StoreNavigationOrigin;
enum class SettingsTabIndex;
namespace Social {
	class SignInResult;
};
class LevelSummary;
enum class StorageVersion;
class RealmsCreateParams;
class ResourceLocation;
enum class RealmsOfferTier;
class PackDependencyManager;
class BaseScreen;
class AbstractScreenSetupCleanupStrategy;
class Player;
class BlockPos;
struct EntityUniqueID;
class SignBlockEntity;
class ChalkboardBlockEntity;
class ClientInstance;

class ScreenChooser {
public:

	MinecraftGame* mcGame;
	ClientInstance* mcClient;
	std::unique_ptr<MinecraftUISoundPlayer> soundplayer;
	bool canInvite;
	char filler1[8]; // no idea what this is used for
	/* size = 0x18 */

	// non virtual
	ScreenChooser(MinecraftGame&, ClientInstance&, bool);
	~ScreenChooser();
	void schedulePopScreen(int);
	void setDisconnectScreen(std::string const&, std::string const&, std::string const&);
	void pushImportExportProgressScreen(std::string const&, std::string const&);
	void setCanInvite(bool);
	void* getPlayScreen();
	void pushChatScreen();
	void pushDebugScreen();
	void pushPauseScreen();
	void pushToastScreen();
	void pushUpsellScreen(bool);
	void pushConsoleScreen();
	void pushVRAlignScreen();
	void pushProgressScreen(std::string const&, std::deque<std::unique_ptr<ProgressHandler>>&, bool);
	void pushProgressScreen(std::string const&, std::unique_ptr<ProgressHandler>, bool);
	void setStartMenuScreen();
	void pushInventoryScreen(CraftingType);
	void pushMobEffectsScreen();
	void pushPatchNotesScreen(std::unique_ptr<PatchNotesModel>);
	void pushNoWifiWarningScreen();
	void pushRealmsWarningScreen(Realms::World const&, std::string const&, int);
	void pushXblFirstLaunchScreen();
	void pushNetworkProgressScreen(std::string const&, std::unique_ptr<ProgressHandler>);
	void pushHolographicCursorScreen();
	void pushNoInvitesOrJoiningScreen();
	void pushCellularDataWarningScreen(std::function<void (bool)>);
	void pushRealmsPendingInvitesScreen(bool);
	void pushHolographicPostRenderScreen();
	bool isInBedScreen(AbstractScreen const&) const;
	void pushRealityModeTransitionScreen();
	void pushRealityScreen();
	void pushPlaySpaceScreen();
	void pushGameViewerScreen();
	void pushHudScreen();
	void setGameplayScreen();
	void pushPlayScreen(PlayScreenDefaultTab);
	void pushStoreScreen();
	void pushInviteScreen();
	void pushMashupScreen(MashupData&, StoreNavigationOrigin);
	void pushOptionsScreen(SettingsTabIndex);
	void pushLanguageScreen();
	void pushPortfolioScreen();
	void pushUGCViewerScreen(std::function<void (std::string const&, std::string const&, std::string const&)>);
	void pushVRControlScreen(bool);
	void pushXblFailedScreen(std::function<void (Social::SignInResult)>);
	void setLeaveLevelScreen();
	void pushSkinPickerScreen();
	void pushAchievementScreen();
	void pushCreateWorldScreen();
	void pushMakeInfiniteScreen(LevelSummary const&, StorageVersion);
	void pushRealmsCreateScreen(RealmsCreateParams const&);
	void pushModalProgressScreen(std::string const&, std::unique_ptr<ProgressHandler>, bool, bool);
	void pushVRInformationScreen();
	void pushWorldTemplateScreen(bool);
	void pushRealmsSettingsScreen(Realms::World const&);
	void pushRealmsWhitelistScreen(Realms::World const&);
	void pushFileCopyProgressScreen(std::string const&, ResourceLocation const&, bool, std::string const&, bool, std::function<void (bool)>);
	void pushLocalWorldPickerScreen(std::string const&);
	void pushSkinPackPurchaseScreen(std::string const&);
	void pushCreateWorldUpsellScreen(bool, RealmsOfferTier, bool, bool, std::string const&);
	void pushXblOptionalSignInScreen(std::string const&, std::string const&, std::string const&, std::string const&, std::function<void ()>);
	void pushManifestValidationScreen(ResourceLocation const&, std::string const&, bool, PackDependencyManager const*);
	void pushRealmsJoinProgressScreen(std::string const&, std::unique_ptr<ProgressHandler>, std::unique_ptr<ProgressHandler>, bool);
	void pushFileDownloadProgressScreen(std::string const&, std::string const&);
	void pushResourcePackPurchaseScreen(std::string const&, bool);
	void pushCreateWorldFromTemplateScreen(LevelSummary const&);
	void pushOfferContentDownloadProgressScreen(std::string const&);
	bool isLevelLoadingProgressScreen(AbstractScreen&) const;
	void pushEditWorldScreen(LevelSummary const&);
	void pushFileUploadProgressScreen(std::string const&, std::string const&, bool);
	void pushAddEditExternalServerScreen(int);
	void _pushScreen(std::shared_ptr<BaseScreen>, std::unique_ptr<AbstractScreenSetupCleanupStrategy>, bool);
	void _pushScreen(std::shared_ptr<BaseScreen>, bool);
	void pushAnvilScreen(Player&, BlockPos const&);
	void pushChestScreen(Player&, EntityUniqueID);
	void pushChestScreen(Player&, BlockPos const&);
	void pushDeathScreen();
	void pushHorseScreen(Player&, EntityUniqueID const&);
	void pushInBedScreen(Player&);
	void pushBeaconScreen(Player&, BlockPos const&);
	void pushHopperScreen(Player&, EntityUniqueID const&);
	void pushHopperScreen(Player&, BlockPos const&);
	void _pushInviteScreen();
	void pushCreditsScreen(std::function<void ()>);
	void pushDropperScreen(Player&, BlockPos const&);
	void pushFurnaceScreen(Player&, BlockPos const&);
	void pushTextEditScreen(SignBlockEntity*);
	void pushDispenserScreen(Player&, BlockPos const&);
	void pushStructureEditor(Player&, BlockPos const&);
	void pushWorkbenchScreen(BlockPos const&, bool);
	void pushChalkboardScreen(ChalkboardBlockEntity&);
	void pushEnchantingScreen(Player&, BlockPos const&);
	void pushGlobalPauseScreen();
	void pushNpcInteractScreen(Player&, Entity&, bool);
	void _pushAchievementScreen();
	void pushBrewingStandScreen(Player&, BlockPos const&);
	void pushNetherProgressScreen(bool);
	void pushSkinPackUpsellScreen(std::string const&, int);
	void* _getUIScreenSetupStrategy(bool);
	void pushAcceptDeclineInvitationScreen(std::string&, std::string&, std::function<void (bool)>);
	void setActiveDirectoryAuthenticationScreen();
	void pushActiveDirectoryAuthenticationScreen();
	bool isModalScreen(AbstractScreen&) const;
	void* getSoundPlayer() const;
	void* createGlobalVars() const;
	bool isProgressScreen(AbstractScreen&) const;
	bool isAchievementsScreen(AbstractScreen&) const;
	bool isPendingInvitesScreen(AbstractScreen&) const;
	bool _isInGame() const;

};
