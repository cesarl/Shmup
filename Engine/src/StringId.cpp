#include "StringId.hpp"

// initializer lists are not ready yen on VS12
std::unordered_map<std::string, unsigned int> Utils::Tag::list_ = init();