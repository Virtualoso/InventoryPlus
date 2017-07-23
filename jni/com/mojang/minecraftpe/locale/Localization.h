#pragma once

#include <string>
#include <memory>
#include <vector>

class ResourcePackManager;
class PackAccessStrategy;

class Localization {
public:

	unsigned char commaSeperator; // 0
	std::string langCode; // 4
	char filler[0x23];
	/* size = 0x28 */

	// non virtual
	Localization(std::string const&);
	Localization(std::string const&, Localization*);
	std::string getLanguageCode(std::string const&);
	std::string getLanguageCode() const;
	std::string getStringIdExists(std::string const&) const;
	std::string get(std::string const&, std::string&, std::vector<std::string> const&) const;
	std::string getRegionCode(std::string const&);
	bool isFormattedString(std::string const&);
	void* _getSimple(std::string const&) const;
	void _replaceTokens(std::string&, std::vector<std::string> const&) const;
	unsigned char getCommaSeperator() const;
	std::string _get(std::string const&, std::vector<std::string> const&) const;
	std::string getFullLanguageCode() const;
	void appendTranslations(Localization const&);
	void* _getStrings() const;
	void _parseFormattedString(std::string const&) const;
	void loadFromPack(std::string const&, PackAccessStrategy&, std::vector<std::string> const&);
	void loadFromResourcePackManager(ResourcePackManager&, std::vector<std::string> const&);

	// static fields
	static std::unique_ptr<Localization> fallbackLocale;
	
};