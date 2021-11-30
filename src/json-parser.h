#ifndef _JSON_PARSER_H
#define _JSON_PARSER_H

#include "json-data.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <any>
#include <vector>
#include <unordered_map>
#include <exception>
#include <stdexcept>
#include <optional>
#include <stack>

namespace json {

    Object parseJSON(std::string_view raw);

    std::string serializeJSON(const Object& obj);

    std::optional<std::string> fileRead(std::string_view filepath);
}

#endif 