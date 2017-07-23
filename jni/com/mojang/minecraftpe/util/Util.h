#pragma once

#include <string>
#include <vector>
#include <sstream>

class EntityTargetFilter;
namespace Json { class Value; }

class Util {

public:

    static std::string base64_encode(std::string const&, bool);
    static std::string base64_encode(unsigned char const*, unsigned int, bool);
    static std::string base64_decode(std::string const&);
    static void* loadEntityTargetFilter(EntityTargetFilter&, Json::Value const&);
    static void* loadTargetFilter(EntityTargetFilter&, Json::Value const&);
    static std::string compress(std::string const&);
    static std::string decompress(std::string const&);
    static std::string decompress(std::string const&, bool&);
    static char toHex(char);
    static std::string removeIllegalChars(std::string const&);
    static void stringReplace(std::string&, std::string const&, std::string const&, int);
    static bool startsWith(std::string const&, std::string const&);
    static std::string getExtension(std::string const&);
    static std::string getFileName(std::string const&);
    static std::string getFileNameWithExt(std::string const&);
    static std::string getDirectory(std::string const&);
    static bool stringIsInVector(std::vector<std::string, std::allocator<std::string>> const&, std::string const&);
    static bool endsWith(std::string const&, std::string const&);
    static std::string stringTrim(std::string const&);
    static std::string stringTrim(std::string const&, std::string const&, bool, bool);
    static void trimVectorStrings(std::vector<std::string, std::allocator<std::string>>&);
    static std::vector<std::string> split(std::string const&, char);
    static std::vector<std::string> split(std::string const&, std::vector<std::string, std::allocator<std::string>> const&, bool);
    static std::vector<std::string> splitLines(std::string const&);
    static int hashCode(std::string const&);
    static void removeAll(std::string&, char const**, int);
    static std::string removeAllColorCodes(std::string const&);
    static int utf8len(std::string const&, bool);
    static std::string utf8substring(std::string const&, int, int);
    static void appendUtf8Character(std::string&, int);
    static std::string simpleFormat(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
    static std::string format(char const*, ...);
    static std::string urlEncode(std::string const&);
    static std::string toNiceString(int);
    static std::string toString(float);
    static std::string toLower(std::string const&);
    static std::string toUpper(std::string const&);
    static bool compareNoCase(std::string const&, std::string const&);
    static void freeStringMemory(std::string&);
    static int countWordOccurrences(std::string const&, std::string const&);
    static bool isValidPath(std::string const&);
    static std::string formatTickDuration(int);
    static std::string getFilesizeString(unsigned long long);
    static void splitString(std::string const&, char, std::vector<std::string, std::allocator<std::string>>&);
    static bool stringContains(std::string const&, char);
    static void toInt(std::string const&, int&, int, int);
    static std::string boolToString(bool);
    static void toBool(std::string const&, bool&);
    static std::string toString(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>> const&);
    static std::string toString(std::string const&);
    static std::wstring toWideString(std::string const&);
    static bool isValidIPv4(std::string const&);
    static bool isValidIP(std::string const&, bool, bool);
    static bool isValidIPv6(std::string const&);
    static void normalizeLineEndings(std::string&);
    static void* cp437ToUTF8(std::string const&);
    static void* getPoint(float, float, float);
    static void* getBezier(float, float, float, float);
	static std::string toFloatString(double value)
	{
		std::stringstream stm;
		stm<<value;
		std::string str;
		stm>>str;
		return str;
	}
	static int stringToInt(const std::string& number)
	{
		std::stringstream stm;
		stm<<number;
		int ret;
		stm>>ret;
		return ret;
	}
	

    // static fields
    static void* REPLACEMENT_CHARACTER_CODE;
    static std::string EMPTY_STRING;
    static std::string NEW_LINE;
    static void* EMPTY_GUID;

};

