#include "string.h"

/*
This code was originally written by MrARM
*/

struct Util {
    static mcpe::string EMPTY_STRING;
};

mcpe::string::string() {
    ptr = Util::EMPTY_STRING.ptr;
}
mcpe::string::string(const std::string &str) {
    if (str.empty()) {
        ptr = Util::EMPTY_STRING.ptr;
    } else {
        new (this)std::string(str);
    }
}
mcpe::string::string(const char *str) {
    if (str[0] == '\0') {
        ptr = Util::EMPTY_STRING.ptr;
    } else {
        new (this)std::string(str);
    }
}
mcpe::string::string(const string &str) {
    if (str.ptr == Util::EMPTY_STRING.ptr) {
        ptr = Util::EMPTY_STRING.ptr;
    } else {
        new (this)std::string(*((const std::string *) &str));
    }
}
mcpe::string::~string() {
    if (ptr == Util::EMPTY_STRING.ptr)
        return;
    ((std::string*) this)->~basic_string<char>();
}

size_t mcpe::string::length() const {
    if (ptr == Util::EMPTY_STRING.ptr)
        return 0;
    return ((std::string*) this)->length();
}

mcpe::string& mcpe::string::operator=(const mcpe::string &str) {
    if (ptr != Util::EMPTY_STRING.ptr) {
        if (str.ptr == Util::EMPTY_STRING.ptr) {
            ((std::string*) this)->~basic_string<char>();
            new (this)std::string(*((std::string*)&str));
        } else {
            *((std::string*) this) = *((const std::string*) &str);
        }
    } else {
        new (this)std::string(*((std::string*)&str));
    }
}

const char *mcpe::string::c_str() const {
    if (ptr == Util::EMPTY_STRING.ptr)
        return "";
    return ((std::string*) this)->c_str();
}