#ifndef _JSON_DATA_H
#define _JSON_DATA_H

#include <iostream>
#include <variant>
#include <map>
#include <any>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <optional>

namespace json {

    class Object {
    public:
        template<typename T> 
        std::optional<T> get(std::string_view key) {
            try {
                if(auto iter=mProps.find(key.data()); iter != std::end(mProps)) {
                    auto& optVal = iter->second;
                    if(optVal.has_value()) {
					    return std::any_cast<T>(optVal.value());
                    }
                } else {
                    throw std::runtime_error("Cannot find property");
                }
            } catch (const std::bad_any_cast& e) { // getProp Error 
                std::cerr << e.what() << std::endl;
            } catch (...) { /* ignore */ }
            return std::nullopt;
        }
        template<typename T>
        std::optional<std::vector<T>> getArr(std::string_view key) {
            return get<std::vector<T>>(key);
        }
        template<typename T>
        void set(std::string_view key, T value) {
            mProps[key.data()] = std::any(value);
        }
        template<typename T>
        void setArr(std::string_view key, std::vector<T> arr) {
            set<std::vector<T>>(key, arr);
        }
    private:
        std::unordered_map<std::string, std::optional<std::any>> mProps;
    };

    

}

#endif 