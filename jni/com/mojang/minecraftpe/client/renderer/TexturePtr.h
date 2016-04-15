#pragma once

#include <string>

class TextureGroup;

namespace mce {
	class TexturePtr {
	public:
		char filler1[12];	// 0

		MaterialPtr(TexturePtr&&);
		MaterialPtr(TextureGroup&, const std::string&);
		MaterialPtr();
	};
};