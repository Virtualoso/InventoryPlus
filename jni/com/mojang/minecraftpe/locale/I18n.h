#pragma once

#include <string>
#include <vector>
#include <memory>

class Localization;
class ResourcePackManager;

class I18n {
  
public:

    // static
    static void getLocaleFor(std::string const&);
    static void chooseLanguage(std::string const&);
    static void _initFormatDictionary();
    static std::string get(std::string const&);
    static void _getKeyExists(std::string const&);
    static void loadLanguages(ResourcePackManager&);
    static void chooseLanguage(Localization const&);
    static void _getFormatParmas(std::string const&, std::vector<std::string>&);
    static void getCurrentLanguage();
    static void getSupportedLocales();
    static void _addFormatToDictionary(std::string const&, std::vector<std::string> const&);
    static void languageSupportsHypenSplitting();
    static void _setLanguageSupportsHypenSplitting(Localization const&);
    static std::string get(std::string const&, std::vector<std::string> const&);

    // static fields
    static std::vector<std::unique_ptr<Localization>> mLanguages;
    static std::unique_ptr<Localization> mCurrentLanguage;
    static void* mFormatDictionary;

};