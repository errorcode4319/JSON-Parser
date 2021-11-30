#include "json-parser.h"

namespace json {
    
    namespace {
        bool BracketSyntaxValid(std::string_view jstr);
    }

    Object parseJSON(std::string_view jstr) {
        if(!BracketSyntaxValid(jstr)) {
            throw std::runtime_error("Invalid JSON Data");
        }

        Object obj;



        return obj;
    }

    std::string serializeJSON(const Object& obj) {
        return "";
    }

    std::optional<std::string> fileRead(std::string_view filepath) {
        std::ifstream file(filepath.data());
        if(!file) 
            return std::nullopt;
        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }

    namespace {
        bool BracketSyntaxValid(std::string_view jstr) {

            std::stack<char> stk;

            for(const auto& ch: jstr) {
                if(ch == '[' || ch == '{') stk.push(ch);
                if(ch == '\"') {
                    if(stk.empty()) stk.push(ch);
                    else if(stk.top() == ch) stk.pop();
                    else stk.push(ch);
                }
                if(ch == ']') {
                    if(stk.empty()) return false;
                    else if(stk.top() != '[') return false;
                    else stk.pop();
                }
                if(ch == '}') {
                    if(stk.empty()) return false;
                    else if(stk.top() != '{') return false;
                    else stk.pop();
                }
            }
            if(!stk.empty())
                return false;
            return true;
        }
    }

}