#pragma once

#include <string>

namespace mce {
	class UUID {
	public:
		static mce::UUID* fromString(const std::string&);
		std::string toString();
	};
};